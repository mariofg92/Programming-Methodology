#include <iostream>
#include <fstream>
#include <string>
#include "signal.h"

using namespace std;

//METODOS PRIVADOS

void Signal::Reservar(int f, int c){
	if (f != 0 && c != 0){
		filas = f;
		columnas = c;

		vec = new double*[f];
		vec[0] = new double[f*c];
		for(int i=1; i<f; i++)
			vec[i] = vec[0] + i*c;
		for(int i=0; i < f*c; i++)
			vec[0][i] = 0.0;
	}
}

void Signal::Liberar(){
	if (vec != 0){
		delete [] vec[0];
		delete [] vec;

		filas = 0;
		columnas = 0;
		vec = 0;
	}
}

void Signal::Copiar(const Signal & M){
	Reservar(M.filas, M.columnas);

	for(int i=0; i<filas; i++)
		for(int j=0; j<columnas; j++)
			vec[i][j] = M.vec[i][j];
}

//CONSTRUCTORES

Signal::Signal(){
	filas = 0;
	columnas = 0;
	vec = 0;	
}

Signal::Signal(int nf, int nc){
	Reservar(nf, nc);
}

Signal::Signal(const Signal & M){
	Copiar(M);
}

//DESTRUCTOR
Signal::~Signal(){
	Liberar();
}


//METODOS PÚBLICOS Y OPERADORES

int Signal::Filas () const{
	return filas;
}

int Signal::Columnas () const{
	return columnas;
}

void Signal::Set(int f, int c, double v){
	vec[f][c] = v;
}

double Signal::Get(int f, int c) const{
	return vec[f][c];
}

bool Signal::LeerSignal(const char file[]){
	ifstream f(file, ios::in);
	string cabecera;

	if(f){
		getline(f, cabecera);
		if(cabecera=="MP-FILTRO-T"){
			if(f.peek()=='#')
			{
				while(f.get()!= '\n');
			}
			f >> filas;
			f >> columnas;
			f.ignore();

			Reservar(filas, columnas);
			for(int i=0; i<filas; i++){
				for(int j=0; j<columnas; j++){
					f >> vec[i][j];
				}
			}

			f.close();
			return true;
		}else if(cabecera=="MP-FILTRO-B"){
			if(f.peek()=='#')
			{
				while(f.get()!= '\n');
			}
			f >> filas;
			f >> columnas;
			f.ignore();

			int pos = f.tellg();
			
			f.close();
			f.open(file, ios::in | ios::binary);
			f.seekg(pos*sizeof(char));

			Reservar(filas, columnas);
			f.read(reinterpret_cast<char *>(vec[0]), sizeof(double)*filas*columnas);
			return true;
		}else{
			//El signal a leer no se corresponde con un filtro.
			return false;
		}
	}else{
		//No se ha podido abrir.
		return false;
	}
}

bool Signal::EscribirSignal(const char file[]) const{
	ofstream f(file, ios::out);
	if(f){
		for(int i = 0; i < filas; i++){
			for(int j = 0; j < columnas; j++){
				f << vec[i][j] << '\t';
			}
			f << '\n';
		}

		f.close();
		return true;
	}else{
		//No se ha podido guardar.
		return false;
	}
}

Signal & Signal::operator=(const Signal & M){
	if (&M != this){
		Liberar();
		Copiar(M);
	}

	return *this;
}

Signal Signal::operator*(double esc) const{
	Signal aux(*this);

	for(int i=0; i<filas; i++)
		for(int j=0; j<columnas; j++)
			aux.vec[i][j] *= esc;

	return aux;
}
