#include <bits/stdc++.h>

using namespace std;

#define TAM 11
#define TAM2 21

int tabela_de_indices[TAM];
int vetor_ordenado[TAM2] = {3,6,8,10,12,15,25,30,33,34,40,45,46,48,50,52,56,57,60,64,68};
void preenche_tabela(){
  int i=0;
  while(i<TAM){
    tabela_de_indices[i] = vetor_ordenado[i*2];
    i++;
  }
}

int busca(int num){
  int i=0,j=0;
  if(num ==0){
    return 0;
  }
  while(num > tabela_de_indices[i] && i<TAM){
    i++;
  }
  if(num == tabela_de_indices[i]){
    return 1;
  }
  else if(num < tabela_de_indices[i]){
    j = (i*2);
    while(num < vetor_ordenado[j]){
      j--;
    }
    if(num ==vetor_ordenado[j]){
      return 1;
    }
    else{
      return 0;
    }
  }
}

int main(){
  int cont1=0,cont2=0;
  int num;
  preenche_tabela();
  while(cont1<TAM){
    printf("%d\n",tabela_de_indices[cont1]);
    cont1++;
  }
  printf("\n");
  while(cont2<TAM2){
    printf("%d\n",vetor_ordenado[cont2]);
    cont2++;
  }

  printf("Digite um numero: ");
  scanf("%d",&num);

  if(busca(num)){
    printf("Encontrado\n");
  }
  else{
    printf("Não encontrado\n");
  }
  return 0;
}
