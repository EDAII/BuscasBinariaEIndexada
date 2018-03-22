#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int total = 0;

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

bool buscaIndexada (int num, int vetor[], int tabela_de_indices[], int aux){
  int j = 0;
  for (size_t i = 0; i < total; i++) {
    j = i;
    if(tabela_de_indices[i] > num){
      break;
    } else if (tabela_de_indices[i] == num){
        return true;
    }
  }
  int p = (aux/8)*j;

  if (num < vetor[p]){
    while (num < vetor[p]){
      p--;
      if(num == vetor[p])
        return true;
    }
  } else {
    while (num > vetor[p]){
      p++;
      if(num == vetor[p])
        return true;
    }
  }
  return false;
}

void preenche_tabela(int vetor[], int aux, int tabela_de_indices[]){
  int i=0;

  while(i < (aux/8)){
    if(i*(aux/8)< aux){
      total++;
      tabela_de_indices[i] = vetor[i*(aux/8)];
    } else{
      total++;
      tabela_de_indices[i] = vetor[aux-1];
    }
    i++;
  }
}

int main(){

  struct rusage tempo_inicial, tempo_final;
  double tempo,tempo2;
  int aux;
  int num;

  cout << "Informe o tamanho do vetor (se < 20, aparecerá no console)" << endl;
  cout << "Ps: o número 2000 sempre estará no vetor" << endl;
  cin >> aux;

  int tabela_de_indices[aux/8];
  int vetor[aux];
  vetor[0]= 2000; //2000 sempre deverá ser encontrado
  srand((unsigned)time(NULL));
  for (int i=1; i < aux; i++){
    vetor[i] = rand()%10000;
  }
  sort (vetor, vetor+aux);

  if (aux <= 20){
    for (size_t i = 0; i < aux; i++)
      cout << vetor[i] << " ";
  }

  cout << endl;
  cout << "Número a ser procurado no vetor: ";
  cin >> num;
  cout << endl;

  getrusage(RUSAGE_SELF, &tempo_inicial);
  bool resposta = buscaBinaria(num, aux, vetor);
  if (resposta)
    cout << "Encontrado na busca binária" << endl;
  else
    cout << "Não encontrado na busca binária" << endl;
  getrusage(RUSAGE_SELF, &tempo_final);
  tempo = calcula_tempo(&tempo_inicial, &tempo_final);

  getrusage(RUSAGE_SELF, &tempo_inicial);
  preenche_tabela(vetor, aux, tabela_de_indices);
  if(buscaIndexada(num, vetor, tabela_de_indices, aux)){
    printf("Encontrado na busca sequencial indexada\n");
  }
  else{
    printf("Não encontrado na busca sequencial indexada\n");
  }
  getrusage(RUSAGE_SELF, &tempo_final);
  tempo2 = calcula_tempo(&tempo_inicial, &tempo_final);

  cout << endl;

  printf("Tempo busca binária: %lf\n",tempo);
  printf("Tempo busca sequencial indexada: %lf\n",tempo2);

  return 0;
}
