#ifndef _debayer_
#define _debayer_

/* None debayer, just copy data to something visible */
void debayerNone(uint16_t * __restrict debayerto, float * __restrict bayerdata, int width, int height, int threads);
/* Quite quick bilinear debayer, floating point sadly; threads argument is unused */
void debayerBasic(uint16_t * __restrict debayerto, float * __restrict bayerdata, int width, int height, int threads);
/* More useable amaze, threads number should be the number of cores(or threads if >= i7) your cpu has */
void debayerAmaze(uint16_t * __restrict debayerto, float * __restrict bayerdata, int width, int height, int threads);

/* None debayer structure for multithread */
typedef struct {
    uint16_t * __restrict debayerto; //output
    float * __restrict bayerdata; //input
    int width; //complete width
    int height; //cropped height to render
    int offsetY; //start of crop for thread in height
} nonedebayerinfo_t;

/* AMaZe input as struct for posixz */
typedef struct {
    float ** __restrict rawData;    /* holds preprocessed pixel values, rawData[i][j] corresponds to the ith row and jth column */
    float ** __restrict red;        /* the interpolated red plane */
    float ** __restrict green;      /* the interpolated green plane */
    float ** __restrict blue;       /* the interpolated blue plane */
    int winx; int winy; /* crop window for demosaicing */
    int winw; int winh;
    int cfa;
} amazeinfo_t;

/* Amaze demosaic */
void
#ifdef __MINGW32__
/* Needed for win32/mingw (might need include gaurd with another compiler) */
__attribute__ ((force_align_arg_pointer))
#endif
demosaic(amazeinfo_t * inputdata);

#endif
