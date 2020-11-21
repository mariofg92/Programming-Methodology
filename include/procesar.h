#ifndef _PROCESAR_H_
#define _PROCESAR_H_

#include <iostream>
#include <cstring>
#include "imagenES.h"
#include "imagen.h"

using namespace std;

/** 
@brief Oculta un mensaje en un objeto de tipo Imagen.
@pre mensaje[] debe ser obligatoriamente una cadena C.
@return Devuelve true si se ha conseguido hacer correctamente y false en caso contrario.
*/
bool Ocultar(Imagen & ima, const char mensaje[]);

	
/** 
@brief Revela un mensaje de un objeto de tipo Imagen.
@return Devuelve true si se ha conseguido hacer correctamente y false en caso contrario.
*/
bool Revelar(const Imagen & ima, unsigned char mensaje[], int tama_mensaje);

#endif