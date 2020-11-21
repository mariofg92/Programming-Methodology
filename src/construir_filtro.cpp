#include <iostream>
#include <fstream>

using namespace std;
int main(int argc, char *argv[]){
	if(argc==5){
		int filas = atoi(argv[2]);
		int col = atoi(argv[3]);

		if(argv[1][0]=='-' && argv[1][1]=='b'){
			
			ofstream dest(argv[4], ios::out);
			if(dest){
				dest << "MP-FILTRO-B\n" << filas << ' ' << col << '\n';

				dest.close();
				dest.open(argv[4], ios::out | ios::binary | ios::app);

				double * datos = new double[filas*col];
				for(int i = 0; i < filas; i++){
					for(int j = 0; j < col; j++){
						cin >> datos[i*col + j];
					}
				}
			
				dest.write(reinterpret_cast<const char *>(datos), sizeof(double)*filas*col);
				dest.close();
			}else
				cerr << "Error al crear: " << argv[4] << endl;
		}else if(argv[1][0]=='-' && argv[1][1]=='t'){
			
			ofstream dest(argv[4], ios::out);
			if(dest){
				dest << "MP-FILTRO-T\n" << filas << ' ' << col << '\n';

				double dato;
				for(int i = 0; i < filas; i++){
					for(int j = 0; j < col; j++){
						cin >> dato;
						dest << dato << '\t';
					}
					dest << '\n';
				}

				dest.close();
			}else
				cerr << "Error al crear: " << argv[4] << endl;
		}else
			cerr << " El segundo parametro debe ser -b para binario o -t para texto" << endl;

	}else{
		cerr << "El formato correcto es: construir_filtro <-b / -t> <filas> <columnas> <nombre_salida>" << endl;
	}
}
