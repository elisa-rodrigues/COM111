/*
Escreva um programa que leia um número l de linhas e um número c de colunas. Em seguida, um vetor V de tamanho l*c e uma matriz M com l linhas e
c colunas devem ser alocados dinamicamente. Seu programa deve executar as tarefas abaixo sequencialmente, através de chamadas de funções:
a) Preencher o vetor V com valores inteiros digitados pelo usuário.
b) Imprimir o vetor V na tela.
c) Preencher a matriz M, sequencialmente, com os valores do vetor $V$.
d) Imprimir a matriz M na tela. 
*/

// Autor: Elisa de Cássia Silva Rodrigues
// Setembro de 2020




// ***********************************************************
#include <stdio.h>
#include <stdlib.h>

// *********************************************************** 
// Protótipos das funções auxiliares
// *********************************************************** 
void preencherVetor(int n, int *V);
void imprimirVetor(int n, int *V);
void preencherMatriz(int l, int c, int **M, int *V);
void imprimirMatriz(int l, int c, int **M);
int *alocarVetor(int n);
int **alocarMatriz(int l, int c);


// *********************************************************** 
// Implementação da função principal
// ***********************************************************
int main(void) {
  
  int l, c;
  int *V, **M;

  printf("\nDigite número de linhas e colunas: \n");
  scanf("%d %d", &l, &c);
  
  // aloca memória para o vetor e para a matriz
  V = alocarVetor(l*c);
  M = alocarMatriz(l, c);
  
  if(V == NULL || M == NULL){      
      return 0;
  }
  
  // preenche o vetor
  printf("\nPreencha o vetor V com %d números inteiros: \n", l*c);
  preencherVetor(l*c, V);

  // imprime valores do vetor
  printf("\nVetor com %d elementos: \n", l*c);
  imprimirVetor(l*c, V);

  // preenche matriz
  preencherMatriz(l, c, M, V);

  // imprime valores do matriz
  printf("\n\nMatriz %d x %d preenchida com elementos do vetor: \n", l, c);
  imprimirMatriz(l, c, M);
  
  // libera memória alocada para o vetor
  free(V);  
  
  // libera memória alocada para as linhas da matriz
  for (int i = 0; i < l; i++)
      free(M[i]); 
  
  // libera memória alocada para a matriz (vetor de ponteiros)
  free(M);        
  
  return 0;
}



// ***********************************************************
// Implementação das funções auxiliares
// ***********************************************************

void preencherVetor(int n, int *V){
  for(int i=0; i<n; i++){
    scanf("%d", &V[i]);
  }
}

void imprimirVetor(int n, int *V){
  for(int i=0; i<n; i++){
    printf(" %d", V[i]);
  }
}

void preencherMatriz(int l, int c, int **M, int *V){
  for(int i=0; i<l; i++){
    for(int j=0; j<c; j++){
      M[i][j] = V[i*c+j];
    }  
  }
}

void imprimirMatriz(int l, int c, int **M){
  for(int i=0; i<l; i++){
    for(int j=0; j<c; j++){
      printf(" %d", M[i][j]);
    }  
    printf("\n");
  }
}

int *alocarVetor(int n){
  
  int *V = (int*) malloc(n*sizeof(int));
  
  if(V == NULL){
    printf("\nMemória insuficiente!\n");
    return NULL;
  }
  
  return V;
}
  
int **alocarMatriz(int l, int c){
  
  int **M = (int**) malloc(l*sizeof(int*));

  if(M == NULL){ 
    printf("\nMemória insuficiente!\n");
    return NULL;
  }

  for(int i=0; i<l; i++){
    M[i] = (int*) malloc(c*sizeof(int));
    
    if(M[i] == NULL){
      printf("\nMemória insuficiente!\n");
      return NULL;
    }
  }

  return M;
}
