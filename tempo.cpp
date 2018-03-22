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

int buscaIndexada(int num, int vetor[], int tabela_de_indices[], int aux){
  int i=0,j=0;
  if(num ==0){
    return 0;
  }
  while(num > tabela_de_indices[i] && i<(aux/4)){
    i++;
  }
  if(num == tabela_de_indices[i]){
    return 1;
  }
  else if(num < tabela_de_indices[i]){
    j = (i*(aux/4));
    while(num < vetor[j]){
      j--;
    }
    if(num ==vetor[j]){
      return 1;
    }
    else{
      return 0;
    }
  }
}

void preenche_tabela(int vetor[], int aux, int tabela_de_indices[]){
  int i=0;

  while(i < (aux/4)){
    tabela_de_indices[i] = vetor[i*(aux/4)];
    i++;
  }
}

int main(){

struct rusage tempo_inicial, tempo_final;
double tempo;
int aux;
int num;

cout << "Informe o tamanho do vetor (caso menor que 20, os valores irão aparecer no console) = ";
cin >> aux;

int tabela_de_indices[aux/4];
int vetor[aux];

  for (int i=0; i < aux; i++){
    vetor[i] = numeroAleatorio(0, 10000);
  }
  sort (vetor, vetor+aux);

  if (aux <= 20){
    for (size_t i = 0; i < aux; i++)
      cout << vetor[i] << " ";
    }
  cout << endl;
  cout << "Número a ser procurado no vetor: ";
  cin >> num;

  getrusage(RUSAGE_SELF, &tempo_inicial);


  bool resposta = buscaBinaria(num, aux, vetor);
  if (resposta)
    cout << "Achou na busca binária" << endl;
  else
    cout << "Não achou na busca binária" << endl;

  getrusage(RUSAGE_SELF, &tempo_final);

  tempo = calcula_tempo(&tempo_inicial, &tempo_final);

  getrusage(RUSAGE_SELF, &tempo_inicial);

  preenche_tabela(vetor, aux, tabela_de_indices);

  if(buscaIndexada(num, vetor, tabela_de_indices, aux)){
    printf("Encontrado\n");
  }
  else{
    printf("Não encontrado\n");
  }
  getrusage(RUSAGE_SELF, &tempo_final);

  double tempo2 = calcula_tempo(&tempo_inicial, &tempo_final);
  printf("%lf\n",tempo);
  printf("%lf\n",tempo2);
return 0;
}
