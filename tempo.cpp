#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

double calcula_tempo(const struct rusage *b, const struct rusage *a) {
    if (b == NULL || a == NULL)
        return 0;
    else
        return ((((a->ru_utime.tv_sec * 1000000 + a->ru_utime.tv_usec) -
                 (b->ru_utime.tv_sec * 1000000 + b->ru_utime.tv_usec)) +
                ((a->ru_stime.tv_sec * 1000000 + a->ru_stime.tv_usec) -
                 (b->ru_stime.tv_sec * 1000000 + b->ru_stime.tv_usec)))
                / 1000000.0);
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

int numeroAleatorio(int menor, int maior) {
  return rand()%(maior-menor+1) + menor;
}

int funcao(int x, int y,int z){
int i,j;
for(i=0;i<x;i++){
	for(j=0;j<y;j++){
		z++;
}
}
return z;
}

int main(){

struct rusage tempo_inicial, tempo_final;
double tempo;
int z;
int aux = 10000000;
int vetor[aux];



for (int i=0; i < aux; i++){
  vetor[i] = numeroAleatorio(0, 10000);
}

getrusage(RUSAGE_SELF, &tempo_inicial);
  //   z = funcao(10000,10000,z);
    z = buscaBinaria(111, aux, vetor);
    getrusage(RUSAGE_SELF, &tempo_final);

tempo = calcula_tempo(&tempo_inicial, &tempo_final);
printf("%d\n",z);
printf("%lf\n",tempo);
return 0;
}
