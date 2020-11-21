#include <iostream>
#include "imagen.h"
#include "signal.h"
#include "conversiones.h"
#include "correlacion.h"

using namespace std;

int main(int argc, char * argv[]){
	if(argc==5){
		Imagen Igrande, Ipeque, Iout;
		Signal Sgrande, Speque, filtro, Sout;

		if(Igrande.LeerImagen(argv[1])){
			if(Ipeque.LeerImagen(argv[2])){
				if(filtro.LeerSignal(argv[3])){

					Sgrande = ImagenToSignal(Igrande);
					Speque = ImagenToSignal(Ipeque);

					Sgrande = Correlacion(Sgrande, filtro);
					Speque = Correlacion(Speque, filtro);
					Sout = Correlacion(Sgrande, Speque);

					//Obtencion de Pmax
					int f_max=0, c_max=0;
					double val_max=0, aux;
					for(int i=0; i < Sout.Filas(); i++){
						for(int j=0; j < Sout.Columnas(); j++){
							aux = Sout.Get(i, j);
							if (aux >= val_max){
								f_max = i;
								c_max = j;
								val_max = aux;
							}
						}
					}

					//Resaltamos el lugar donde se encuentra Wally
					Sgrande = ImagenToSignal(Igrande);
					Speque = ImagenToSignal(Ipeque);
					Sgrande = Sgrande*0.5;
					int f_inicio = f_max-(Speque.Filas()/2);
					int c_inicio = c_max-(Speque.Columnas()/2);

					for(int i = 0; i < Speque.Filas(); i++){
						for(int j = 0; j < Speque.Columnas(); j++){
							aux = Speque.Get(i,j);
							Sgrande.Set(f_inicio+i, c_inicio+j, aux);
						}
					}

					Iout = SignalToImagen(Sgrande);

					if(!Iout.EscribirImagen(argv[4])){
						cerr << "No se ha podido escribir: " << argv[4] << endl;
					}
				}else{
					cerr << "El archivo: [" << argv[3] << "] no se ha podido leer o no corresponde a un filtro" << endl;
				}
			}else{
				cerr << "No se ha podido leer la imagen de Wally: " << argv[2] << endl;
			}
		}else{
			cerr << "No se ha podido leer la imagen donde buscar a Wally: " << argv[1] << endl;
		}

	}else{
		cerr << "Usa el formato: buscar_Wally <imagen> <imagen_Wally> <filtro> <salida>" << endl;

	}
}