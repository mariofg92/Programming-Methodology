#!/bin/bash

make

if [ ! -d datos/imagenes/resultados ]
	then
		mkdir datos/imagenes/resultados
	fi

I=2
J=0

while [ $I -le 13 ]
	do
		if [ $I -eq 10 ]
			then
				J=''
			fi
	./bin/buscar_Wally datos/imagenes/${J}${I}.pgm datos/imagenes/${J}${I}_wally.pgm datos/filtros/laplaciana_bin.fil datos/imagenes/resultados/encontrado${J}${I}BIN.pgm &
	./bin/buscar_Wally datos/imagenes/${J}${I}.pgm datos/imagenes/${J}${I}_wally.pgm datos/filtros/laplaciana_txt.fil datos/imagenes/resultados/encontrado${J}${I}TXT.pgm &

	let I++
done