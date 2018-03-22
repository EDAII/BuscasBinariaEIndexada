#include <bits/stdc++.h>

using namespace std;
bool buscaBinaria (int x, int n, int v[]);

int main(int argc, char const *argv[]) {

  int vetor[100];
  int aux;
  int contador=0;

  aux = 100;

  while (aux--){
    vetor[aux] = aux;
    contador++;
  }

  bool resultado = buscaBinaria (101, contador ,vetor);

  if (resultado == true)
    cout << "achou" << endl;
  else
    cout << "não achou" << endl;
  return 0;
}

// x = número a ser procurado
// n = tamanho do vector
// v[] = vetor
bool buscaBinaria (int x, int n, int v[]) {
   int e, m, d;
   e = 0; d = n-1;
   while (e <= d) {
      m = (e + d)/2;
      if (v[m] == x) return true;
      if (v[m] < x) e = m + 1;
      else d = m - 1;
   }
   return false;
}
