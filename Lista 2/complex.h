typedef struct complexo* Complexo;

// Escopo das funções utilizadas no programa
Complexo criarComplexo(double a, double b);
void imprimirComplexo(char prefixo[], Complexo c);
void liberarComplexo(Complexo c);
Complexo somarComplexo(Complexo c1, Complexo c2);
Complexo subtrairComplexo(Complexo c1, Complexo c2);
Complexo multiplicarComplexo(Complexo c1, Complexo c2);
Complexo dividirComplexo(Complexo c1, Complexo c2);