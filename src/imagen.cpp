#include <iostream>
#include "imagen.h"
#include "imagenES.h"

using namespace std;

//METODOS PRIVADOS

void Imagen::Reservar(int f, int c){
	if (f != 0 && c != 0){
		filas = f;
		columnas = c;

		vec = new unsigned char*[f];
		vec[0] = new unsigned char[f*c];
		for(int i=1; i<f; i++)
			vec[i] = vec[0] + i*c;
	}
}

void Imagen::Liberar(){
	if (vec != 0){
		delete [] vec[0];
		delete [] vec;

		filas = 0;
		columnas = 0;
		vec = 0;
	}
}

void Imagen::Copiar(const Imagen & M){
	Reservar(M.filas, M.columnas);

	for(int i=0; i<filas; i++)
		for(int j=0; j<columnas; j++)
			vec[i][j] = M.vec[i][j];
}

//CONSTRUCTORES

Imagen::Imagen(){
	filas = 0;
	columnas = 0;
	vec = 0;	
}

Imagen::Imagen(int nf, int nc){
	Reservar(nf, nc);
}

Imagen::Imagen(const Imagen & M){
	Copiar(M);
}

//DESTRUCTOR
Imagen::~Imagen(){
	Liberar();
}


//METODOS PÚBLICOS Y OPERADORES

int Imagen::Filas () const{
	return filas;
}

int Imagen::Columnas () const{
	return columnas;
}

void Imagen::Set(int f, int c, unsigned char v){
	vec[f][c] = v;
}

void Imagen::Set(int i, unsigned char v){
	vec[0][i] = v;
}

unsigned char Imagen::Get(int f, int c) const{
	return vec[f][c];
}

unsigned char Imagen::Get(int i) const{
	return vec[0][i];
}

bool Imagen::LeerImagen(const char file[]){
	int nf, nc;
	TipoImagen tipo;
	bool a_devolver;
	tipo = LeerTipoImagen(file, nf, nc);

	if (tipo == IMG_PGM){
		Liberar();
		Reservar(nf, nc);
		
		a_devolver = LeerImagenPGM (file, nf, nc, vec[0]);

		if (a_devolver == false)
			Liberar();

		return a_devolver;

	}else{

		return false;
	}

}

bool Imagen::EscribirImagen(const char file[]) const{
	return EscribirImagenPGM (file, vec[0], filas, columnas);
}

Imagen & Imagen::operator=(const Imagen & M){
	if (&M != this){
		Liberar();
		Copiar(M);
	}

	return *this;
}
