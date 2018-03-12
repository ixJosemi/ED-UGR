
SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c -std=c++11


all: $(BIN)/pruebadiccionario 
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************
$(BIN)/pruebadiccionario: $(OBJ)/pruebadiccionario.o  $(OBJ)/diccionario.o 
	$(CXX) -o $(BIN)/pruebadiccionario $(OBJ)/pruebadiccionario.o $(OBJ)/diccionario.o 
	
$(OBJ)/pruebadiccionario.o:$(SRC)/pruebadiccionario.cpp $(INC)/diccionario.h 
	$(CXX) $(CPPFLAGS) $(SRC)/pruebadiccionario.cpp -o $(OBJ)/pruebadiccionario.o
	
$(OBJ)/diccionario.o:$(SRC)/diccionario.cpp $(INC)/diccionario.h 
	$(CXX) $(CPPFLAGS) $(SRC)/diccionario.cpp -o $(OBJ)/diccionario.o
		

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
