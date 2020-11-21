#include <iostream>
#include <cstring>
#include "procesar.h"
#include "imagen.h"
#include "imagenES.h"

using namespace std;

int main(int argc, char * argv[]){
   bool todo_OK = true;
   string tipo_error;

   if(argc==3){
      const int MAXBUFFER= 1000000;
      int filas, columnas;
      char mensaje[MAXBUFFER];
      
      TipoImagen tipo;
      Imagen ima;

      tipo = LeerTipoImagen(argv[1], filas, columnas);


      if(tipo == IMG_DESCONOCIDO || tipo==IMG_PPM){
         todo_OK = false;
         tipo_error = "Tipo de imagen no permitido o imagen inexistente.";
      }
             

      if (todo_OK == true){
         
         cin.getline(mensaje, MAXBUFFER, '\0');
         cerr << "Ocultando..." << endl;

         ima.LeerImagen(argv[1]);
            
         Ocultar(ima, mensaje);

         todo_OK = ima.EscribirImagen(argv[2]);
         tipo_error = "Error al ocultar";

      }
   }else{
      todo_OK = false;
      tipo_error = "el formato de ejecución debe ser [ocultar <entrada>.pgm <salida>.pgm]";
   }

   if(todo_OK == false){
      cerr << "\nError: " << tipo_error << endl;
   }
}
