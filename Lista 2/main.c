
/*
Implemente um TAD para representar números complexos (complex.h e complex.c). Sabe-se
que um número complexo é representado por a + bi, onde a e b são números reais e i a unidade
imaginária. O TAD deve implementar as seguintes operações:
(a) Função para criar um número complexo, dados a e b.
(b) Função para liberar um número complexo previamente criado.
(c) Função para somar dois números complexos, retornando um novo número com o resultado
da operação. 
*/

#include <stdio.h>
#include "complex.h"

int main(void) {
  double a,b,c,d;

  // Realiza a leitura dos valores dos númerors complexos
  printf("Digite os valores de a e b do primeiro numero complexo:\n");
  scanf("%lf %lf", &a, &b);
  printf("Digite os valores de a e b do segundo numero complexo:\n");
  scanf("%lf %lf", &c, &d);

  // Cria os números complexos;
  Complexo c1 = criarComplexo(a, b);
  Complexo c2 = criarComplexo(c, d);

  // Demonstra os números complexos criados
  printf("\n[VALORES]\n");
  imprimirComplexo("Complexo 1: ", c1);
  imprimirComplexo("Complexo 2: ", c2);

  // Resultados das operações 
  Complexo soma = somarComplexo(c1, c2);
  Complexo subtracao = subtrairComplexo(c1, c2);
  Complexo multiplicacao = multiplicarComplexo(c1, c2);
  Complexo divisao = dividirComplexo(c1, c2);

  // Demonstra os resultados na tela
  printf("\n[RESULTADOS]\n");
  imprimirComplexo("Soma: ", soma);
  imprimirComplexo("Subtracao: ", subtracao);
  imprimirComplexo("Multiplicacao: ", multiplicacao);
  imprimirComplexo("Divisao: ", divisao);

  // Libera toda a memória alocada
  liberarComplexo(c1);
  liberarComplexo(c2);
  liberarComplexo(soma);
  liberarComplexo(subtracao);
  liberarComplexo(multiplicacao);
  liberarComplexo(divisao);

  return 0;
}