SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c --std=c++11

all:$(BIN)/prueba $(BIN)/prueba_sp

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************


$(BIN)/prueba: $(OBJ)/prueba.o 
	$(CXX) -o $(BIN)/prueba $(OBJ)/prueba.o

$(OBJ)/prueba.o: $(SRC)/prueba.cpp 
	$(CXX) $(CPPFLAGS)  $(SRC)/prueba.cpp -o  $(OBJ)/prueba.o 
	

$(BIN)/prueba_sp: $(OBJ)/prueba_sp.o $(OBJ)/sopa_letras.o
	$(CXX) -o $(BIN)/prueba_sp $(OBJ)/prueba_sp.o $(OBJ)/sopa_letras.o $(OBJ)/matriz_dispersa.o
	
	
$(OBJ)/prueba_sp.o: $(SRC)/prueba_sp.cpp $(INC)/matriz_dispersa.h 
	$(CXX) $(CPPFLAGS)  $(SRC)/prueba_sp.cpp -o  $(OBJ)/prueba_sp.o 
		
	
$(OBJ)/sopa_letras.o: $(SRC)/sopa_letras.cpp $(INC)/sopa_letras.h
	$(CXX) $(CPPFLAGS)  $(SRC)/sopa_letras.cpp -o  $(OBJ)/sopa_letras.o 	
	
#Ejemplo para compilar matriz_dispersa usando como tipo rep vector dinamico
$(OBJ)/matriz_dispersa.o: $(SRC)/matriz_dispersa.cpp $(INC)/matriz_dispersa.h  $(INC)/vd.h $(INC)/vd.cpp 
	$(CXX) $(CPPFLAGS)  $(SRC)/matriz_dispersa.cpp -o  $(OBJ)/matriz_dispersa.o 	
	
			
# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
