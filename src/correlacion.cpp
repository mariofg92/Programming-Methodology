#include <iostream>
#include "correlacion.h"
#include "signal.h"

using namespace std;

Signal Correlacion(const Signal & img, const Signal & filtro){
	Signal aux(img.Filas(), img.Columnas());

	int mitadF = (filtro.Filas()/2);
	int mitadC = (filtro.Columnas()/2);

	//Definicion del entorno donde se aplicará la correlación
	int fila_inicio = mitadF, fila_fin = (img.Filas()-1-mitadF);
	int columna_inicio = mitadC, columna_fin = (img.Columnas()-1-mitadC);
	double suma;

	for(int i = fila_inicio; i <= fila_fin; i++){
		for(int j = columna_inicio; j <= columna_fin; j++){
			suma = 0.0;
			for(int k = -mitadF; k < filtro.Filas()-mitadF; k++){
				for(int l = -mitadC; l < filtro.Columnas()-mitadC; l++){
					suma+=img.Get(i+k, j+l)*filtro.Get(k+mitadF, l+mitadC);
				}
			}
			aux.Set(i, j, suma);
		}
	}

	return aux;

}