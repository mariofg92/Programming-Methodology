#include <iostream>
#include "conversiones.h"
#include "imagen.h"
#include "signal.h"
#include "correlacion.h"

using namespace std;

int main(int argc, char *argv[]){

	if (argc == 4){
		Imagen ima;
		Imagen resul_ima;
		Signal ima_sig;
		Signal fil;
		Signal resul_sig;

	
		if(ima.LeerImagen(argv[1])){

			ima_sig = ImagenToSignal(ima);
			if(fil.LeerSignal(argv[2])){

				resul_sig = Correlacion(ima_sig, fil);
	
				resul_ima = SignalToImagen(resul_sig);

				if(!resul_ima.EscribirImagen(argv[3]))
					cerr << "No se ha podido crear: " << argv[3] << endl;
			}else{
				cerr << "No se puede leer el filtro: " << argv[2] << endl;
			}
		}else{
			cerr << "No se puede leer la imagen: " << argv[1] << endl;
		}
	}else{
		cerr << "El formato correcto es: filtar <nombre_img> <nombre_filtro> <nombre_img_salida>" << endl;
	}
}