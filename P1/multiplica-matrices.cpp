#include <iostream>
#include <stdlib.h> // Incluye srand() y rand()
#include <time.h>

using namespace std;

float ** multiplica_matrices(int ** m1, int ** m2, int tam){

    // Creamos la matriz resultado
    float ** resultado = new float * [tam];

    for(int i = 0; i < tam; i++)
        resultado[i] = new float [tam];

    // Multiplicamos las matrices
    for(int i = 0; i < tam; i++)
        for(int j = 0; j < tam; j++)
            for(int k = 0; k < tam; k++)
                resultado[i][j] += m1[i][k] * m2[k][j];

    return resultado;
}

void sintaxis()
{
  cerr << "Sintaxis:" << endl;
  cerr << "  TAM: Tamaño de la matriz (>0)" << endl;
  cerr << "  MAX: Valor maximo de la matriz (>=0)" << endl;
  cerr << "Se genera una matriz de tamaño TAM con elementos aleatorios" << endl;
  exit(EXIT_FAILURE);
}

int main(int argc, char ** argv){

    // Lectura de parámetros
    if (argc!=3)
      sintaxis();
    int tam = atoi(argv[1]);     // Tamaño de las matrices
    int max = atoi(argv[2]);
    if (tam<=0)
      sintaxis();

    // Generacion de dos matrices aleatorias
    int ** m1 = new int * [tam];
    int ** m2 = new int * [tam];

    for(int i = 0; i < tam; i++)
        m1[i] = new int [tam];

    for(int i = 0; i < tam; i++)
        m2[i] = new int [tam];

    // Relleamos las dos matrices con numeros aleatorios
    srand(time(0));

    // m1
    for(int i = 0; i < tam; i++)
        for(int j = 0; j < tam; j++)
            m1[i][j] = rand() % max;

    // m2
    for(int i = 0; i < tam; i++)
        for(int j = 0; j < tam; j++)
            m2[i][j] = rand() % max;

    // Generamos la matriz resultante
    float ** resultado = new float * [tam];

    for(int i = 0; i < tam; i++)
        resultado[i] = new float [tam];

    clock_t t_ini; // Anotamos tiempo de inicio
    t_ini = clock();

    resultado = multiplica_matrices(m1, m2, tam); // Multiplicamos las matrices

    clock_t t_fin; // Anotamos tiempo de finalizacion
    t_fin = clock();

    // Mostramos resultados (Tam de la matriz y tiempo de ejecucion en seg)
    cout << tam << "\t" << (t_fin - t_ini) / (double) CLOCKS_PER_SEC << endl;

    return 0;
}
