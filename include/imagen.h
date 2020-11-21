#ifndef _IMAGEN_H_
#define _IMAGEN_H_

class Imagen { 
private:
	int filas;
	int columnas;
	unsigned char **vec;
	/**
	@brief Reserva memoria en vec y da valor a filas y a columas.
	@param f Este es el numero de filas a reservar.
	@param c Este es el numero de columnas a reservar.
	*/
	void Reservar(int f, int c);
	//* @brief libera la memoria de vec y asigna 0 a las variabes filas y columnas.
	void Liberar();
	/**
	@brief Copia los elemtos de una matriz M así como sus variables filas y columnas.
	*/
	void Copiar(const Imagen & M);

public:
	//* @brief Constructor por defecto (inicializa todas las variables privadas a 0)
	Imagen();
	//* @brief Construye el objeto con nf filas y nc columnas.
	Imagen(int nf, int nc);
	//* @brief Construye copiando los elementos y numero de filas y columnas de M.
	Imagen(const Imagen & M);
	//* @brief Destructor (librera toda la mem dinamica y pone todo a 0).
	~Imagen();

	
	//* @brief Devuelve el número de filas de la imagen.
	int Filas () const;
	//* @brief Devuelve el número de columnas de la imagen.
	int Columnas () const; 
	//* @brief Hace vec(i,j)=v
	void Set (int f, int c, unsigned char v);
	//* @brief Hace vec[0][i]=v
	void Set (int i, unsigned char v);
	//* @brief Devuelve vec(i,j) 
	unsigned char Get (int f, int c) const;
	//* @brief Devielve vec[0][i]
	unsigned char Get (int i) const;
	//* @brief Carga imagen de file
	bool LeerImagen(const char file[]);
	//* @brief Salva la imagen en file
	bool EscribirImagen(const char file[]) const;


	//* @brief Copia los elementos y el numero de filas y columnas de M.
	Imagen & operator=(const Imagen & M);
	};

#endif