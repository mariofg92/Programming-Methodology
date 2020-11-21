#include <iostream>
#include <cstring>
#include "imagenES.h"
#include "imagen.h"
#include "procesar.h"

using namespace std;

/**
@brief Devuelve el bit de una posicion concreta de un unsigned char.
		Bit menos significativo en pos = 0.
@param pos Esta es la posicion de la cual queremos obtener el bit.
@param letra Este es el char BYTE del que queremos obtener el bit de la posicion pos.
@return Devuelve el bit leido en forma de unsigned char.
*/
unsigned char LeerBit(unsigned char letra, int pos){
   letra = letra << (7-pos);
   letra = letra >> 7;

   return letra;
}

/**
@brief Devuelve el resultado de escribir bit en una posicion pos en byte
@return Devuelve un unsigned char a modo de BYTE.
*/
unsigned char EscribirBit(unsigned char byte, unsigned char bit, int pos){
	
    if (bit == 1)
    	byte = byte | (1 << pos);
    else
    	byte = byte & (255 ^ (1 << pos));

    return byte;
}



bool Ocultar(Imagen & ima, const char mensaje[]){
	int ima_index=0;
	int tama_mensaje = strlen(mensaje);
	unsigned char bit_leido, bit_a_escribir;
	int tama_imagen = ima.Filas()*ima.Columnas();

	if ((tama_mensaje*8+8) <= tama_imagen){

		for(int men_index=0; men_index <= tama_mensaje; men_index++){ // es <= para añadir el '\0'

			for(int pos_bit_letra=7; pos_bit_letra >= 0; pos_bit_letra--){

				bit_leido = LeerBit(mensaje[men_index], pos_bit_letra);

				bit_a_escribir = EscribirBit(ima.Get(ima_index), bit_leido, 0);

				ima.Set(ima_index, bit_a_escribir);
				ima_index++;
				
			}
		}

		return true;

	}else{
		return false;
	}
}

bool Revelar(const Imagen & ima, unsigned char mensaje[], int tama_mensaje){
	int ima_index=0;
	unsigned char bit_leido;
	bool fin = false;
	int tama_imagen = ima.Filas()*ima.Columnas();

	if((tama_imagen/8) <= tama_mensaje){
		for(int men_index=0; men_index < tama_mensaje & !fin; men_index++){ 

			for(int pos_bit_letra=7; pos_bit_letra >= 0 && ima_index < tama_imagen; pos_bit_letra--){

				bit_leido = LeerBit(ima.Get(ima_index), 0);

				mensaje[men_index] = EscribirBit(mensaje[men_index], bit_leido, pos_bit_letra);
				ima_index++;
					
			}


			if (mensaje[men_index] == '\0')
				fin = true;
		}

		if (!fin){ // Si no encuentra '\0' al final del mensaje codificado en la imagen 
			return false;
		}else{
			return true;
		}
	}else{
		return false;
	}
}