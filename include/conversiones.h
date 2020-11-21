#ifndef _CONVERSIONES_H_
#define _CONVERSIONES_H_

#include "imagen.h"
#include "signal.h"

/**
@brief Devulve un objeto de tipo signal correspondiente a la conversion de la imagen a signal.
@param sig Este es el signal a partir del cual se genera la imagen.
@return Devuelve el signal convertido a un objeto de tipo imagen.
*/
Imagen SignalToImagen(const Signal &sig);

/**
@brief Devulve un objeto de tipo imagen correspondiente a la conversion del signal a imagen.
@param img Esta es la imagen a partir de la cual se genera el signal.
@return Devuelve la imagen convertida a un objeto de tipo signal.
*/
Signal ImagenToSignal(const Imagen &img);

#endif