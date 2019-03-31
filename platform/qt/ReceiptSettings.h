/*!
 * \file ReceiptSettings.h
 * \author masc4ii
 * \copyright 2017
 * \brief Holds slider settings
 */

#ifndef RECEIPTSETTINGS_H
#define RECEIPTSETTINGS_H

#include <QObject>

class ReceiptSettings
{
public:
    enum DebayerAlgorithm{ None = 0, Simple, Bilinear, LMMSE, IGV, AMaZE, AHD };

    ReceiptSettings();
    void setLoaded( void )          {m_neverLoaded = false;}

    void setExposure( int value )   {m_exposure = value;}
    void setContrast( int value )   {m_contrast = value;}
    void setTemperature( int value ){m_temperature = value;}
    void setTint( int value )       {m_tint = value;}
    void setClarity( int value )    {m_clarity = value;}
    void setVibrance( int value )   {m_vibrance = value;}
    void setSaturation( int value ) {m_saturation = value;}
    void setDr( int value )         {m_dr = value;}
    void setDs( int value )         {m_ds = value;}
    void setLr( int value )         {m_lr = value;}
    void setLs( int value )         {m_ls = value;}
    void setLightening( int value ) {m_lightening = value;}
    void setShadows( int value )    {m_shadows = value;}
    void setHighlights( int value ) {m_highlights = value;}
    void setGradationCurve( QString curve ){m_gradationCurve = curve;}
    void setHueVsHue( QString curve ){m_hueVsHue = curve;}
    void setHueVsSaturation( QString curve ){m_hueVsSat = curve;}
    void setHueVsLuminance( QString curve ){m_hueVsLuma = curve;}

    void setGradientEnabled( bool on ){m_isGradientEnabled = on;}
    void setGradientExposure( int value ){m_gradientExposure = value;}
    void setGradientContrast( int value ){m_gradientContrast = value;}
    void setGradientStartX( int value ){m_gradientX1 = value;}
    void setGradientStartY( int value ){m_gradientY1 = value;}
    void setGradientLength( int value ){m_gradientLength = value;}
    void setGradientAngle( int value ){m_gradientAngle = value;}

    void setSharpen( int value )    {m_sharpen = value;}
    void setChromaBlur( int value ) {m_chromaBlur = value;}
    void setDenoiserWindow( int value ){m_denoiserWindow = value;}
    void setDenoiserStrength( int value ){m_denoiserStrength = value;}
    void setRbfDenoiserLuma( int value ){m_rbfDenoiserLuma = value;}
    void setRbfDenoiserChroma( int value ){m_rbfDenoiserChroma = value;}
    void setRbfDenoiserRange( int value ){m_rbfDenoiserRange = value;}
    void setHighlightReconstruction( bool on ){m_highlightReconstruction = on;}
    void setCamMatrixUsed( uint8_t val )      {m_useCamMatrix = val;}
    void setChromaSeparation( bool on )       {m_chromaSeparation = on;}
    void setProfile( uint8_t num )            {m_profile = num;}
    void setTonemappingFunction( uint8_t num ){m_tonemappingFunction = num;}
    void setProcessingGamut( uint8_t num )    {m_processingGamut = num;}
    void setOutputGamut( uint8_t num )        {m_outputGamut = num;}
    void setGamma( int val )                  {m_gamma = val;}
    void setAllowCreativeAdjustments( bool on ){m_creativeAdjustments = on;}
    void setRawWhite( int value )             {m_rawWhite = value;}
    void setRawBlack( int value )             {m_rawBlack = value;}
    void setTone( uint8_t value )             {m_tone = value;}
    void setToningStrength( uint8_t value )   {m_toningStrength = value;}
    void setFileName( QString fileName )      {m_fileName = fileName;}
    void setExportFileName( QString fileName ){m_exportFileName = fileName;}
    void setRawFixesEnabled( bool on )        {m_rawFixesEnabled = on;}
    void setVerticalStripes( int mode )       {m_vertical_stripes = mode;}
    void setFocusPixels( int mode )           {m_focus_pixels = mode;}
    void setFpiMethod( int mode )             {m_fpi_method = mode;}
    void setBadPixels( int mode )             {m_bad_pixels = mode;}
    void setBpsMethod( int mode )             {m_bps_method = mode;}
    void setBpiMethod( int mode )             {m_bpi_method = mode;}
    void setChromaSmooth( int mode )          {m_chroma_smooth = mode;}
    void setPatternNoise( int on )            {m_pattern_noise = on;}
    void setDeflickerTarget( int value )      {m_deflicker_target = value;}
    void setDualIsoForced( int value )        {m_dualIsoForced = value;}
    void setDualIso( int mode )               {m_dualIsoOn = mode;}
    void setDualIsoInterpolation( int mode )  {m_dualIsoInt = mode;}
    void setDualIsoAliasMap( int on )         {m_dualIsoAliasMap = on;}
    void setDualIsoFrBlending( int on )       {m_dualIsoFrBlending = on;}
    void setDualIsoWhite( uint32_t level )    {m_dualIsoWhite = level;}
    void setDualIsoBlack( uint32_t level )    {m_dualIsoBlack = level;}
    void setDarkFrameEnabled( int on )        {m_darkFrameSubtractionMode = on;}
    void setDarkFrameFileName( QString name ) {m_darkFrameSubtractionName = name;}
    void setStretchFactorX( double factor )   {m_stretchFactorX = factor;}
    void setStretchFactorY( double factor )   {m_stretchFactorY = factor;}
    void setUpsideDown( bool on )             {m_upsideDown = on;}
    void setLutEnabled( bool on )             {m_lutEnabled = on;}
    void setLutName( QString name )           {m_lutName = name;}
    void setLutStrength( uint8_t value )      {m_lutStrength = value;}
    void setFilterEnabled( bool on )          {m_filterEnabled = on;}
    void setFilterIndex( uint8_t idx )        {m_filterIndex = idx;}
    void setFilterStrength( int value )       {m_filterStrength = value;}
    void setVignetteStrength( int value )     {m_vignetteStrength = value;}
    void setVignetteRadius( int value )       {m_vignetteRadius = value;}
    void setCutIn( uint32_t frame )           {m_cutIn = frame;}
    void setCutOut( uint32_t frame )          {m_cutOut = frame;}

    void setLastPlaybackPosition( uint32_t pos ){m_lastPlaybackPosition = pos;}

    void setDebayer( uint8_t algorithm )      {m_debayer = algorithm;}

    bool wasNeverLoaded( void ){return m_neverLoaded;}

    int exposure( void )   {return m_exposure;}
    int contrast( void )   {return m_contrast;}
    int temperature( void ){return m_temperature;}
    int tint( void )       {return m_tint;}
    int clarity( void )    {return m_clarity;}
    int vibrance( void )   {return m_vibrance;}
    int saturation( void ) {return m_saturation;}
    int dr( void )         {return m_dr;}
    int ds( void )         {return m_ds;}
    int lr( void )         {return m_lr;}
    int ls( void )         {return m_ls;}
    int lightening( void ) {return m_lightening;}
    int shadows( void )    {return m_shadows;}
    int highlights( void ) {return m_highlights;}
    QString gradationCurve( void ){return m_gradationCurve;}
    QString hueVsHue( void ){return m_hueVsHue;}
    QString hueVsSaturation( void ){return m_hueVsSat;}
    QString hueVsLuminance( void ){return m_hueVsLuma;}

    bool isGradientEnabled( void ){return m_isGradientEnabled;}
    int gradientExposure( void ){return m_gradientExposure;}
    int gradientContrast( void ){return m_gradientContrast;}
    int gradientStartX( void ){return m_gradientX1;}
    int gradientStartY( void ){return m_gradientY1;}
    int gradientLength( void ){return m_gradientLength;}
    int gradientAngle( void ){return m_gradientAngle;}

    int sharpen( void )    {return m_sharpen;}
    int chromaBlur( void ) {return m_chromaBlur;}
    int denoiserWindow( void ){return m_denoiserWindow;}
    int denoiserStrength( void ){return m_denoiserStrength;}
    int rbfDenoiserLuma( void ){return m_rbfDenoiserLuma;}
    int rbfDenoiserChroma( void ){return m_rbfDenoiserChroma;}
    int rbfDenoiserRange( void ){return m_rbfDenoiserRange;}
    bool isHighlightReconstruction( void ){return m_highlightReconstruction;}
    uint8_t camMatrixUsed( void ){return m_useCamMatrix;}
    bool isChromaSeparation( void ){return m_chromaSeparation;}
    bool rawFixesEnabled( void ){return m_rawFixesEnabled;}
    int verticalStripes( void ){return m_vertical_stripes;}
    int focusPixels( void ){return m_focus_pixels;}
    int fpiMethod( void )  {return m_fpi_method;}
    int badPixels( void )  {return m_bad_pixels;}
    int bpsMethod( void )  {return m_bps_method;}
    int bpiMethod( void )  {return m_bpi_method;}
    int chromaSmooth( void ){return m_chroma_smooth;}
    int patternNoise( void ){return m_pattern_noise;}
    int deflickerTarget( void ){return m_deflicker_target;}
    int dualIsoForced( void ){return m_dualIsoForced;}
    int dualIso( void )    {return m_dualIsoOn;}
    int dualIsoInterpolation( void ){return m_dualIsoInt;}
    int dualIsoAliasMap( void ){return m_dualIsoAliasMap;}
    int dualIsoFrBlending( void ){return m_dualIsoFrBlending;}
    uint32_t dualIsoWhite( void ){return m_dualIsoWhite;}
    uint32_t dualIsoBlack( void ){return m_dualIsoBlack;}
    int darkFrameEnabled( void ) {return m_darkFrameSubtractionMode;}
    QString darkFrameFileName( void ){return m_darkFrameSubtractionName;}
    double stretchFactorX( void ){return m_stretchFactorX;}
    double stretchFactorY( void ){return m_stretchFactorY;}
    bool upsideDown( void ){return m_upsideDown;}
    bool lutEnabled( void ){return m_lutEnabled;}
    QString lutName( void ){return m_lutName;}
    uint8_t lutStrength( void ){return m_lutStrength;}
    bool filterEnabled( void ){return m_filterEnabled;}
    uint8_t filterIndex( void ){return m_filterIndex;}
    int filterStrength( void ){return m_filterStrength;}
    int vignetteStrength( void ){return m_vignetteStrength;}
    int vignetteRadius( void ){return m_vignetteRadius;}
    uint32_t cutIn( void ) {return m_cutIn;}
    uint32_t cutOut( void ){return m_cutOut;}
    uint8_t profile( void ){return m_profile;}
    uint8_t tonemappingFunction( void ){return m_tonemappingFunction;}
    uint8_t processingGamut( void ){return m_processingGamut;}
    uint8_t outputGamut( void ){return m_outputGamut;}
    int gamma( void ){return m_gamma;}
    bool allowCreativeAdjustments( void ){return m_creativeAdjustments;}
    int rawWhite( void ) {return m_rawWhite;}
    int rawBlack( void ) {return m_rawBlack;}
    uint8_t tone( void ) {return m_tone;}
    uint8_t toningStrength( void ){return m_toningStrength;}
    QString fileName( void ){return m_fileName;}
    QString exportFileName( void ){return m_exportFileName;}
    uint32_t lastPlaybackPosition( void ){return m_lastPlaybackPosition;}
    uint8_t debayer( void ){return m_debayer;}

private:
    bool m_neverLoaded;

    int m_exposure;
    int m_contrast;
    int m_temperature;
    int m_tint;
    int m_clarity;
    int m_vibrance;
    int m_saturation;
    int m_dr;
    int m_ds;
    int m_lr;
    int m_ls;
    int m_lightening;
    int m_shadows;
    int m_highlights;
    QString m_gradationCurve;
    QString m_hueVsHue;
    QString m_hueVsSat;
    QString m_hueVsLuma;

    bool m_isGradientEnabled;
    int m_gradientExposure;
    int m_gradientContrast;
    int m_gradientX1;
    int m_gradientY1;
    int m_gradientLength;
    int m_gradientAngle;

    int m_vignetteStrength;
    int m_vignetteRadius;

    int m_sharpen;
    int m_chromaBlur;
    int m_denoiserWindow;
    int m_denoiserStrength;
    int m_rbfDenoiserLuma;
    int m_rbfDenoiserChroma;
    int m_rbfDenoiserRange;
    bool m_highlightReconstruction;
    uint8_t m_useCamMatrix;
    bool m_chromaSeparation;
    bool m_rawFixesEnabled; // Enable/Disable all raw fixes
    int m_vertical_stripes; // fix vertical stripes, 0 - do not fix", 1 - fix, 2 - calculate for every frame
    int m_focus_pixels;     // fix focus pixels, false - do not fix, true - fix
    int m_fpi_method;       // focus pixel interpolation method: 0 - mlvfs, 1 - raw2dng
    int m_bad_pixels;       // fix bad pixels, 0 - do not fix, 1 - fix, 2 - makes algorithm aggresive to reveal more bad pixels
    int m_bps_method;       // bad pixel search method: 0 - normal, 1 - force
    int m_bpi_method;       // bad pixel interpolation method: 0 - mlvfs, 1 - raw2dng
    int m_chroma_smooth;    // chroma smooth, 2 - cs2x2, 3 cs3x3, 5 - cs5x5
    int m_pattern_noise;    // fix pattern noise (0, 1)
    int m_deflicker_target; // deflicker value
    int m_dualIsoForced;    // -1 = uninitialized, 0 = DISO_INVALID, 1 = DISO_FORCED, 2 = DISO_VALID
    int m_dualIsoOn;        // DualISO, 0 = off, 1 = on, 2 = preview
    int m_dualIsoInt;       // DualIsoInterpolation method, 0 - amaze-edge, 1 - mean23
    int m_dualIsoAliasMap;  // flag for Alias Map switchin on/off
    int m_dualIsoFrBlending;// flag for Fullres Blending switching on/off
    uint32_t m_dualIsoWhite;
    uint32_t m_dualIsoBlack;
    int m_darkFrameSubtractionMode; // 0 = off, 1 = External, 2 = Internal
    QString m_darkFrameSubtractionName; // FileName
    double m_stretchFactorX;
    double m_stretchFactorY;
    bool m_upsideDown;
    bool m_lutEnabled;
    QString m_lutName;
    uint8_t m_lutStrength;
    bool m_filterEnabled;
    uint8_t m_filterIndex;
    int m_filterStrength;
    uint32_t m_cutIn;
    uint32_t m_cutOut;
    uint8_t m_profile;
    uint8_t m_tonemappingFunction;
    uint8_t m_processingGamut;
    uint8_t m_outputGamut;
    int m_gamma;
    bool m_creativeAdjustments;
    int m_rawWhite;
    int m_rawBlack;
    uint8_t m_tone;
    uint8_t m_toningStrength;
    QString m_fileName;
    QString m_exportFileName;
    uint32_t m_lastPlaybackPosition;
    uint8_t m_debayer;
};

#endif // RECEIPTSETTINGS_H
