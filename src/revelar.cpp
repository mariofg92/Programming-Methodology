#include <iostream>
#include <cstring>
#include "procesar.h"
#include "imagen.h"
#include "imagenES.h"

using namespace std;

int main(int argc, char * argv[]){
   string tipo_error;
   bool todo_OK = true;

   if (argc==2){
      int filas, columnas;

      TipoImagen tipo;
      unsigned char * mensaje;
      int tama_max_mensaje;
      Imagen ima;

      tipo = LeerTipoImagen(argv[1], filas, columnas);

      tama_max_mensaje = (filas*columnas/8)+1;


      if(tipo == IMG_DESCONOCIDO || tipo == IMG_PPM){
         todo_OK = false;
         tipo_error = "Tipo de imagen no permitido o imagen inexistente.";
      }   
         
      mensaje = new unsigned char[tama_max_mensaje];
      if (todo_OK == true){
     
         ima.LeerImagen(argv[1]);
            
         todo_OK = Revelar(ima, mensaje, tama_max_mensaje);
         tipo_error = "Error al revelar.";

         if(todo_OK==true)
            cerr << "Revelando...\n";
            cout << mensaje;
      }
   }else{
      todo_OK = false;
      tipo_error = "el formato de ejecución debe ser [revelar <nombre_ima>.pgm]";
   }

   if(todo_OK == false){
      cerr << "\nError: " << tipo_error << endl;
   }
}