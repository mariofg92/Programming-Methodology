#ifndef _SIGNAL_H_
#define _SIGNAL_H_

class Signal { 
private:
	int filas;
	int columnas;
	double **vec;
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
	void Copiar(const Signal & M);

public:
	//* @brief Constructor por defecto (inicializa todas las variables privadas a 0)
	Signal();
	//* @brief Construye el objeto con nf filas y nc columnas.
	Signal(int nf, int nc);
	//* @brief Construye copiando los elementos y numero de filas y columnas de M.
	Signal(const Signal & M);
	//* @brief Destructor (librera toda la mem dinamica y pone todo a 0).
	~Signal();

	//* @brief Devuelve el número de filas del signal.
	int Filas () const; 
	//* @brief Devuelve el número de columnas del signal.
	int Columnas () const;
	//* @brief Hace vec(i,j)=v
	void Set (int f, int c, double v); 
	//* @brief Devuelve vec(i,j) 
	double Get (int f, int c) const;
	//* @brief Carga el signal de file
	bool LeerSignal(const char file[]);
	//* @brief Salva el signal en file
	bool EscribirSignal(const char file[]) const; //Salva img en file 

	//* @brief Copia los elementos y el numero de filas y columnas de M.
	Signal & operator=(const Signal & M);
	//* @brief multiplica todos los elementos de vec por un double (esc).
	Signal operator*(double esc) const;
	};

#endif