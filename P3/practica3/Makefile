SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c -std=c++11


all: $(BIN)/sopa
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Compilación de módulos ************
$(BIN)/sopa: $(OBJ)/sopa.o  $(OBJ)/diccionario.o $(OBJ)/sopa_letras.o
	$(CXX) -o $(BIN)/sopa $(OBJ)/sopa.o $(OBJ)/diccionario.o $(OBJ)/sopa_letras.o

$(OBJ)/sopa.o:$(SRC)/sopa.cpp $(INC)/diccionario.h $(INC)/sopaletras.h $(INC)/colormod.h
	$(CXX) $(CPPFLAGS) $(SRC)/sopa.cpp -o $(OBJ)/sopa.o

$(OBJ)/diccionario.o:$(SRC)/diccionario.cpp $(INC)/diccionario.h
	$(CXX) $(CPPFLAGS) $(SRC)/diccionario.cpp -o $(OBJ)/diccionario.o

$(OBJ)/sopa_letras.o: $(SRC)/sopaletras.cpp $(INC)/sopaletras.h  $(INC)/colormod.h $(INC)/matrizdispersa.h $(INC)/matrizdispersa.cpp
	$(CXX) $(CPPFLAGS)  $(SRC)/sopaletras.cpp -o  $(OBJ)/sopa_letras.o

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
