#ifndef _CORRELACION_H_
#define _CORRELACION_H_

#include "signal.h"

/**
@brief Esta función realiza la operacion de correlación sobre 2 signal.
@param img Esta es la imagen (de tipo signal) encima de la cual se correla.
@param filtro Este es el filtro que se aplica sobre la imagen mediante la correlación.
@return Devuelve el resultado (como objeto signal) de correlar el filtro sobre la imagen.
*/
Signal Correlacion(const Signal & img, const Signal & filtro);

#endif