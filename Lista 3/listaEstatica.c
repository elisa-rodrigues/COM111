#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaEncadeada.h"

// função para alocar memória do tipo Lista
Lista *criar_lista() {
    return (Lista *)malloc(sizeof(Lista));
}

// função para liberar memória
int liberar_lista(Lista *li) {
    if (li == NULL) return 0;

    // libera todos os nós da lista que foram alocados
    Elemento *no;
    while (*li != NULL) {
        no = *li;
        *li = (*li)->prox;
        free(no);
    }

    // libera o ponteiro da lista
    free(li);

    return 1;
}

// função para verificar se a lista está vazia
int lista_vazia(Lista *li) {
    // verifica se houve problema na criação da lista
    // ou seja, li não é uma lista válida
    if (li == NULL) return -1;

    // verifica se a lista foi criada corretamente
    // mas não contém nenhum valor
    if (*li == NULL) return 1;

    // se houver elementos, retorna 0
    return 0;
}

// função para alocar memória do tipo Elemento
Elemento *criar_elemento() {
    return (Elemento *)malloc(sizeof(Elemento));
}

// função para inserir elemento no início da lista
int inserir_lista_inicio(Lista *li, aluno dado) {
    if (li == NULL) return 0;

    // cria um elemento novo
    Elemento *no;
    no = criar_elemento();
    if (no == NULL) return 0;

    // atribui valores ao elemento novo
    no->dado = dado;
    no->prox = (*li);

    // insere elemento no início da lista
    *li = no;
    return 1;
}

// função para inserir elemento no final da lista
int inserir_lista_final(Lista *li, aluno dado) {
    if (li == NULL) return 0;

    // cria um elemento novo
    Elemento *no;
    no = criar_elemento();
    if (no == NULL) return 0;

    // atribui valores ao elemento novo
    no->dado = dado;

    // se a lista estiver vazia, insere no início da lista
    if ((*li) == NULL)
        *li = no;
    else {
        // senão percorre a lista até o fim e insere no final
        Elemento *aux;
        aux = *li;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

// função para inserir elemento na lista de forma ordenada
int inserir_lista_ordenada(Lista *li, aluno dado) {
    if (li == NULL) return 0;

    // cria um elemento novo
    Elemento *no;
    no = criar_elemento();
    if (no == NULL) return 0;

    // atribui valores ao elemento novo
    no->dado = dado;
    // se a lista estiver vazia, insere no início da lista
    if ((*li) == NULL)
        *li = no;
    else {
        // senão percorre a lista até achar o local correto e insere
        Elemento *anterior, *atual;
        atual = *li;
        while (atual != NULL && atual->dado.matricula < dado.matricula) {
            anterior = atual;
            atual = atual->prox;
        }
        // insere na primeira posição
        if (atual == (*li)) {
            no->prox = (*li);
            *li = no;
        } else {
            no->prox = atual;
            anterior->prox = no;
        }
    }
    return 1;
}

// função para remover elemento do início da lista
int remover_lista_inicio(Lista *li) {
    if (li == NULL) return 0;

    // lista vazia, não remove nada
    if ((*li) == NULL) return 0;

    // muda inicio para o proximo elemento
    Elemento *atual;
    atual = *li;
    *li = atual->prox;
    // libera Elemento atual
    free(atual);
    return 1;
}

// função para remover elemento do final da lista
int remover_lista_final(Lista *li) {
    if (li == NULL) return 0;

    // lista vazia, não remove nada
    if ((*li) == NULL) return 0;

    // percorre lista até o final
    Elemento *anterior, *atual;
    atual = *li;
    while (atual->prox != NULL) {
        anterior = atual;
        atual = atual->prox;
    }

    // remove o primeiro elemento, se este for o único da lista
    if (atual == (*li))
        *li = atual->prox;
    else
        anterior->prox = atual->prox;

    //libera Elemento atual
    free(atual);
    return 1;
}

// função para remover elemento do meio da lista
int remover_lista_meio(Lista *li, aluno dado) {
    if (li == NULL) return 0;

    // lista vazia, não remove nada
    if ((*li) == NULL) return 0;

    // percorre a lista até achar o elemento e remove
    Elemento *anterior, *atual;
    atual = *li;
    while (atual != NULL && atual->dado.matricula != dado.matricula) {
        anterior = atual;
        atual = atual->prox;
    }

    // elemento não foi encontrado
    if (atual == NULL) return 0;

    // remove o primeiro elemento
    if (atual == (*li))
        *li = atual->prox;
    else
        anterior->prox = atual->prox;

    //libera Elemento atual
    free(atual);
    return 1;
}

// função para obter um determinado elemento da lista de acordo com a posição
int buscar_lista_posicao(Lista *li, int pos, aluno dado) {
    // verifica se a lista foi criada corretamente, se não está vazia e se a posição é válida (note que é a posição na lista e não o índice do vetor)
    if (li == NULL || (*li) == NULL || pos < 0) return 0;

    Elemento *no = *li;
    int i = 0;
    while (no != NULL && i < pos) {
        no = no->prox;
        i++;
    }

    // posição não existe na lista
    if (no == NULL) return 0;

    // copia o*dado da posição desejada (parâmetro passado por referência)
    dado = no->dado;
    return 1;
}

// função para buscar um determinado elemento da lista de acordo com o dado
int buscar_lista_dado(Lista *li, aluno dado, int *pos) {
    // verifica se a lista foi criada corretamente
    if (li == NULL || (*li) == NULL) return 0;

    // procura a posição no vetor onde o*dado desejado se encontra
    Elemento *no = *li;
    int i = 1;
    while (no != NULL && no->dado.matricula != dado.matricula) {
        no = no->prox;
        i++;
    }

    // verifica se elemento não foi encontrado
    if (no == NULL) return 0;

    // copia a posição da lista onde o*dado foi encontrado (parâmetro passado por referência)
    *pos = i;
    return 1;
}

// função para imprimir a lista dinâmica
int imprimir_lista(Lista *li) {
    if (li == NULL || (*li) == NULL) return 0;

    for (Elemento *aux = *li; aux != NULL; aux = aux->prox)
        printf("%s - %d: Nota %.2f\n", aux->dado.nome, aux->dado.matricula, aux->dado.nota);

    return 1;
}

// função para concatenar duas listas
Lista *concatenar(Lista *li1, Lista *li2) {
    if ((li1 == NULL || (*li1) == NULL) || (li2 == NULL || (*li2) == NULL)) return 0;

    // cria uma terceira lista
    Lista *lista_concatenada = criar_lista();

    // insere os elementos da primeira lista
    for (Elemento *aux = *li1; aux != NULL; aux = aux->prox)
        inserir_lista_final(lista_concatenada, aux->dado);

    // insere os elementos da segunda lista
    for (Elemento *aux = *li2; aux != NULL; aux = aux->prox)
        inserir_lista_final(lista_concatenada, aux->dado);

    return lista_concatenada;
}

void retorna_copia(Lista *li1, Lista **li2) {
    int ok, contador = 0;

    if ((li1 == NULL || (*li1) == NULL)) return;

    Elemento *atual = (*li1);
    Elemento *proximo = atual->prox;
    do {
        while (proximo->prox != NULL) {
            if (atual->dado.matricula == proximo->dado.matricula) {
                contador++;
                break;
            }
            proximo = proximo->prox;
            printf("%d", proximo->dado.matricula);
        }
        if (contador == 0) {
            ok = inserir_lista_final(*li2, atual->dado);
        }
        contador = 0;
        atual = atual->prox;
        if (atual->prox == NULL) {
            break;
        }
        proximo = atual->prox;
    } while (atual->prox != NULL);
}

// função para inverter os elementos de uma lista
void inverte_lista(Lista *li1, Lista **li2) {
    if ((li1 == NULL || (*li1) == NULL)) return;

    for (Elemento *aux = *li; aux != NULL; aux = aux->prox)
        inserir_lista_inicio(*li2, aux->dado);
}

int verifica_ordenacao(Lista *li) {
    Elemento *aux = *li;
    int flag = 0;      // se 1 crescente, se 2 decrescente
    int ordenado = 1;  // se 1 ordenado, se 0 nao ordenado

    while (aux->prox != NULL) {
        if (aux->dado.matricula != aux->prox->dado.matricula) {
            if (flag == 0) {
                if (aux->dado.matricula > aux->prox->dado.matricula) {
                    flag = 2;
                } else {
                    flag = 1;
                }
            } else {
                if (flag == 1) {
                    if (aux->dado.matricula > aux->prox->dado.matricula) {
                        ordenado = 0;
                        break;
                    }
                } else {
                    if (aux->dado.matricula < aux->prox->dado.matricula) {
                        ordenado = 0;
                        break;
                    }
                }
            }
            aux = aux->prox;
        } else {
            aux = aux->prox;
        }
    }

    return ordenado;
}

// função recursiva para obter o tamanho de uma lista
int tamanho_lista(Elemento *elemento) {
    if (elemento == NULL) return 0;
    return tamanho_lista(elemento->prox) + 1;
}