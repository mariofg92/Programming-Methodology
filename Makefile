
SRC = ./src
INC = ./include
OBJ = ./obj
BIN = ./bin
LIB = ./lib

CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

SL = @echo " "

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************
all: $(BIN)/ocultar $(BIN)/revelar $(BIN)/filtrar $(BIN)/construir_filtro $(BIN)/buscar_Wally


#OBJETOS Y BIBLIOTECAS:
$(OBJ)/imagenES.o: $(SRC)/imagenES.cpp $(INC)/imagenES.h
	@echo "Generando imagenES.o: "
	$(CXX) $(CPPFLAGS) $(SRC)/imagenES.cpp -o $(OBJ)/imagenES.o
	$(SL)

$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INC)/imagenES.h $(INC)/imagen.h
	@echo "Generando imagen.o: "
	$(CXX) $(CPPFLAGS) $(SRC)/imagen.cpp -o $(OBJ)/imagen.o
	$(SL)

$(OBJ)/procesar.o: $(SRC)/procesar.cpp $(INC)/procesar.h $(INC)/imagenES.h $(INC)/imagen.h
	@echo "Generando procesar.o: "
	$(CXX) $(CPPFLAGS) $(SRC)/procesar.cpp -o $(OBJ)/procesar.o
	$(SL)

$(LIB)/libimagen.a: $(OBJ)/imagenES.o $(OBJ)/imagen.o $(OBJ)/procesar.o
	@echo "Generando BIBLIOTECA libimagen.a: "
	ar rvs $(LIB)/libimagen.a $(OBJ)/imagenES.o $(OBJ)/imagen.o $(OBJ)/procesar.o
	$(SL)

$(OBJ)/signal.o: $(SRC)/signal.cpp $(INC)/signal.h
	@echo "Generando signal.o: "
	$(CXX) $(CPPFLAGS) $(SRC)/signal.cpp -o $(OBJ)/signal.o
	$(SL)

$(OBJ)/conversiones.o: $(SRC)/conversiones.cpp $(INC)/conversiones.h $(INC)/signal.h
	@echo "Generando conversiones.o: "
	$(CXX) $(CPPFLAGS) $(SRC)/conversiones.cpp -o $(OBJ)/conversiones.o
	$(SL)

$(OBJ)/correlacion.o: $(SRC)/correlacion.cpp $(INC)/correlacion.h $(INC)/conversiones.h $(INC)/signal.h
	@echo "Generando correlacion.o: "
	$(CXX) $(CPPFLAGS) $(SRC)/correlacion.cpp -o $(OBJ)/correlacion.o
	$(SL)

$(LIB)/libsignal.a: $(OBJ)/signal.o $(OBJ)/conversiones.o $(OBJ)/correlacion.o
	@echo "Generando BIBLIOTECA libimagen.a: "
	ar rvs $(LIB)/libsignal.a $(OBJ)/signal.o $(OBJ)/conversiones.o $(OBJ)/correlacion.o
	$(SL)

#EJECUTABLES:
$(BIN)/ocultar: $(LIB)/libimagen.a $(SRC)/ocultar.cpp
	@echo "Generando EJECUTABLE ocultar: "
	$(CXX) $(CPPFLAGS) $(SRC)/ocultar.cpp -o $(OBJ)/ocultar.o
	$(CXX) $(OBJ)/ocultar.o -limagen -o $(BIN)/ocultar -Llib
	$(SL)

$(BIN)/revelar: $(LIB)/libimagen.a $(SRC)/revelar.cpp
	@echo "Generando EJECUTABLE revelar: "
	$(CXX) $(CPPFLAGS) $(SRC)/revelar.cpp -o $(OBJ)/revelar.o
	$(CXX) $(OBJ)/revelar.o -limagen -o $(BIN)/revelar -Llib
	$(SL)

$(BIN)/filtrar: $(LIB)/libimagen.a $(LIB)/libsignal.a $(SRC)/filtrar.cpp
	@echo "Generando EJECUTABLE filtrar: "
	$(CXX) $(CPPFLAGS) $(SRC)/filtrar.cpp -o $(OBJ)/filtrar.o
	$(CXX) $(OBJ)/filtrar.o -limagen -lsignal -o $(BIN)/filtrar -Llib
	$(SL)

$(BIN)/construir_filtro: $(LIB)/libimagen.a $(LIB)/libsignal.a $(SRC)/construir_filtro.cpp
	@echo "Generando EJECUTABLE construir_filtro: "
	$(CXX) $(CPPFLAGS) $(SRC)/construir_filtro.cpp -o $(OBJ)/construir_filtro.o
	$(CXX) $(OBJ)/construir_filtro.o -limagen -lsignal -o $(BIN)/construir_filtro -Llib
	$(SL)

$(BIN)/buscar_Wally: $(LIB)/libimagen.a $(LIB)/libsignal.a $(SRC)/buscar_Wally.cpp
	@echo "Generando EJECUTABLE buscar_Wally: "
	$(CXX) $(CPPFLAGS) $(SRC)/buscar_Wally.cpp -o $(OBJ)/buscar_Wally.o
	$(CXX) $(OBJ)/buscar_Wally.o -limagen -lsignal -o $(BIN)/buscar_Wally -Llib -O3
	$(SL)

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/* datos/imagenes/resultados/*
