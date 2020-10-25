#ifndef _LISTA_ENCADEADA
#define _LISTA_ENCADEADA

//typedef struct elemento* Lista;
typedef struct aluno {
    int matricula;
    char nome[30];
    float nota;
} aluno;

typedef struct elemento {
    aluno dado;
    struct elemento *prox;
} Elemento;

typedef struct elemento *Lista;
// funções para alocar e desalocar memória
Lista *criar_lista();
int liberar_lista(Lista *li);

// funções para obter informações da lista
int tamanho_lista(Elemento *elemento);
int lista_vazia(Lista *li);

// funções para inserção de elementos da lista
int inserir_lista_inicio(Lista *li, aluno dado);
int inserir_lista_final(Lista *li, aluno dado);
int inserir_lista_ordenada(Lista *li, aluno dado);

// funções para remoção de elementos da lista
int remover_lista_inicio(Lista *li);
int remover_lista_final(Lista *li);
int remover_lista_meio(Lista *li, aluno dado);

// funções para buscar elementos na lista
int buscar_lista_posicao(Lista *li, int pos, aluno dado);
int buscar_lista_dado(Lista *li, aluno dado, int *pos);

int imprimir_lista(Lista *li);

Lista *concatenar(Lista *li1, Lista *li2);
void retorna_copia(Lista *li1, Lista **li2);
void inverte_lista(Lista *li1, Lista **li2);
int verifica_ordenacao(Lista *li);

#endif