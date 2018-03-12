// burbuja recursivo

void burbuja(int * v, int n){
    if(n==1)
        return -1;

    for(int i = 0; i < n-1; i++)
        if(v[i] > v[i+1]){
            int aux = v[i];
            v[i] = v[i+1];
            v[i+1] = aux;
        }
    burbuja(v, n-1);
}



// T(n) -> 1 si n = 1
// T(n) -> n+T(n-1) si n > 1
