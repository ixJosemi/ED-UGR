#include <iostream>
#include <ctime> // Recursos para medir tiempos
#include <cstdlib> // Para generacion de numeros aleatorios

using namespace std;

void ordenar(int * v, int n){
    bool cambio = true;

    for(int i = 0; i < n-1 && cambio; i++){
        cambio = false;

        for(int j = 0; j < n-i-1; j++)
            if(v[j] > v[j+1]){
                cambio = true;
                int aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
    }
}

void sintaxis(){
    cerr << "Sintaxis: " << endl;
    cerr << "  TAM:  Tamanio del vector (>0)" << endl;
    cerr << "  VMAX: Valor maximo (>0)" << endl;
    cerr << "Genera un vector de TAM numeros aleatorios en [0, VMAX[" << endl;
    exit(EXIT_FAILURE);
}

int main(int argc, char * argv[]){

    if(argc != 3) // Lectura de parametros
        sintaxis();

    int tam = atoi(argv[1]);  // Tamanio del vector
    int vmax = atoi(argv[2]); // Valor maximo

    if(tam <= 0 || vmax <= 0)
        sintaxis();

    // Generamos el vector aleatorio
    int * v = new int[tam];  // Reserva de memoria
    srand(time(0));          // Inicializamos el generador de numeros aleatorios

    for(int i = 0; i < tam; i++) // Recorrer vector
        v[i] = rand() % vmax;    // Generar aleatorio [0, VMAX[

    clock_t tini;  // Anotamos tiempo de inicio
    tini = clock();

    ordenar(v, tam); // Ordenamos el vector

    clock_t tfin; // Anotamos el tiempo de finalizacion
    tfin = clock();

    // Mostramos resultados (Tam del vector y tiempo de ejecucion en seg.)
    cout << tam << "\t" << (tfin-tini) / (double) CLOCKS_PER_SEC << endl;

    delete[] v; // Liberamos memoria dinamica
}
