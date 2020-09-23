#include "complex.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Estrutura dos números complexoss
struct complexo{
  double a;
  double b;
};

// Aloca um espaço na memória para o número complexo
Complexo criarComplexo(double a, double b){
  Complexo c = (Complexo) malloc(sizeof(Complexo)); // realiza a locação dinâmica

  // Verifica se foi possível alocar o número complexo
  if (c== NULL) exit(EXIT_FAILURE);

  // Define os valores do número complexo
  c->a =a;
  c->b=b;
  return c;
}

// Libera a memória alocada para número complexo
void liberarComplexo(Complexo c){
  free(c);
}

// Imprime o número complexo de acordo com a positividade do segundo elemento e com um prefixo
void imprimirComplexo(char prefixo[], Complexo c){
  // Imprime 
  if (c->b <0) 
    printf("%s %.2lf - %.2lfi\n", prefixo, c->a, fabs(c->b));
  else
    printf("%s %.2lf + %.2lfi\n",prefixo, c->a,c->b);
}

/* Retorna a soma de dois números complexos dado pela seguinte função:
   (a + bi) + (c + di) = (a + c) + (b + d)i */
Complexo somarComplexo(Complexo c1, Complexo c2){
  double a=c1->a + c2->a;
  double b=c1->b + c2->b;
  return criarComplexo(a,b);
}

/* Retorna a subtração de dois números complexos dado pela seguinte função:
   (a + bi) − (c + di) = (a − c) + (b − d)i */
Complexo subtrairComplexo(Complexo c1, Complexo c2){
  double a=c1->a - c2->a;
  double b=c1->b - c2->b;
  return criarComplexo(a,b);
}

/* Retorna a multiplicação de dois números complexos dado pela seguinte função:
   (a + bi)(c + di) = (ac − bd) + (bc + ad)i */
Complexo multiplicarComplexo(Complexo c1, Complexo c2){
  double a= (c1->a * c2->a) - (c1->b * c2->b);
  double b= (c1->b * c2->a) + (c1->a * c2->b);
  return criarComplexo(a,b);
}

/* Retorna a multiplicação de dois números complexos dado pela seguinte função:
   (a + bi)/(c + di) = ((ac + bd)/(c^2 + d^2)) + ((bc − ad)/(c^2 + d^2))i */
Complexo dividirComplexo(Complexo c1, Complexo c2){
  double a = ((c1->a * c2->a) + (c1->b * c2->b)) / (pow(c2->a, 2) + pow(c2->b,2));
  double b = ((c1->b * c2->a) - (c1->a * c2->b)) / (pow(c2->a, 2) + pow(c2->b,2));
  return criarComplexo(a,b);
}