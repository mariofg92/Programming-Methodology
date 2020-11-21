#include "conversiones.h"
#include "imagen.h"
#include "signal.h"

using namespace std;

Signal ImagenToSignal(const Imagen &img){
	Signal aux(img.Filas(), img.Columnas());

	for (int i=0; i < img.Filas(); i++){
		for (int j=0; j < img.Columnas(); j++){
			unsigned char dato = img.Get(i, j);

			aux.Set(i, j, dato*(1.0/255.0)); // Siempre 0 <= dato <= 255
		}
	}

	return aux;
}

Imagen SignalToImagen(const Signal &sig){
	Imagen aux(sig.Filas(), sig.Columnas());

	for (int i=0; i < sig.Filas(); i++){
		for (int j=0; j < sig.Columnas(); j++){
			double dato = sig.Get(i, j);

			if (dato<0){
				aux.Set(i, j, 0);
			}else if(dato <= 1){
				aux.Set(i, j, dato*255);
			}else{
				aux.Set(i, j, 255);
			}
		}
	}

	return aux;
}