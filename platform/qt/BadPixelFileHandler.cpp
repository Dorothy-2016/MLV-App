/*!
 * \file BadPixelFileHandler.cpp
 * \author masc4ii
 * \copyright 2019
 * \brief Operations needed for bad pixel file handling
 */

#include "BadPixelFileHandler.h"
#include "MoveToTrash.h"

#include <QApplication>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include <QDebug>

//Constructor
BadPixelFileHandler::BadPixelFileHandler()
{

}

//Add a pixel to bpm file
void BadPixelFileHandler::addPixel(mlvObject_t *pMlvObject, uint32_t x, uint32_t y)
{
    QString fileName = getFileName( pMlvObject );
    uint32_t xCor = getRealX( pMlvObject, x );
    uint32_t yCor = getRealY( pMlvObject, y );
    //qDebug() << x << y << xCor << yCor << pMlvObject->VIDF.cropPosX << pMlvObject->VIDF.cropPosY;
    QFile file( fileName );
    file.open( QIODevice::WriteOnly | QIODevice::Append );
    QTextStream ts(&file);
    ts << getPixelLine( xCor, yCor );
    file.close();
}

//Delete a pixel from bpm file
void BadPixelFileHandler::removePixel(mlvObject_t *pMlvObject, uint32_t x, uint32_t y)
{
    QString fileName = getFileName( pMlvObject );
    uint32_t xCor = getRealX( pMlvObject, x );
    uint32_t yCor = getRealY( pMlvObject, y );

    QFile file( fileName );
    file.open( QIODevice::ReadOnly );
    QString txt = file.readAll();
    file.close();

    if( !txt.contains( getPixelLine( xCor, yCor ) ) ) return;
    txt.remove( getPixelLine( xCor, yCor ) );

    file.open( QIODevice::WriteOnly );
    QTextStream ts(&file);
    ts << txt;
    file.close();
}

//Delete the current bad pixel map
void BadPixelFileHandler::deleteCurrentMap(mlvObject_t *pMlvObject)
{
    QString fileName = getFileName( pMlvObject );
    if( QFileInfo( fileName ).exists() ) MoveToTrash( QFileInfo( fileName ).absoluteFilePath() );
}

//Is pixel included in the bpm file?
bool BadPixelFileHandler::isPixelIncluded(mlvObject_t *pMlvObject, uint32_t x, uint32_t y)
{
    QString fileName = getFileName( pMlvObject );
    if( !QFileInfo( fileName ).exists() ) return false;

    uint32_t xCor = getRealX( pMlvObject, x );
    uint32_t yCor = getRealY( pMlvObject, y );

    QFile file( fileName );
    file.open( QIODevice::ReadOnly );
    QString txt = file.readAll();
    file.close();

    return txt.contains( getPixelLine( xCor, yCor ) );
}

//How should be the bpm file be named?
QString BadPixelFileHandler::getFileName(mlvObject_t *pMlvObject)
{
    return QString( "%1_%2x%3.bpm" ).arg( pMlvObject->IDNT.cameraModel, 0, 16 )
                                    .arg( pMlvObject->RAWI.raw_info.width )
                                    .arg( pMlvObject->RAWI.raw_info.height );
}

//Calc the pixel x depending on raw buffer
uint32_t BadPixelFileHandler::getRealX(mlvObject_t *pMlvObject, uint32_t x)
{
    return x+pMlvObject->VIDF.cropPosX;
}

//Calc the pixel y depending on raw buffer
uint32_t BadPixelFileHandler::getRealY(mlvObject_t *pMlvObject, uint32_t y)
{
    return y+pMlvObject->VIDF.cropPosY;
}

//A line in the bpm file
QString BadPixelFileHandler::getPixelLine(uint32_t x, uint32_t y)
{
    return QString( "%1 %2\n" ).arg( x ).arg( y );
}