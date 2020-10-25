#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaEncadeada.h"

int criar_dado(aluno *dado);
void menu(Lista **li, aluno dado);

// funcao principal
int main(void) {
    // no início as listas estão vazias, logo, o ponteiro inicio tem valor NULL
    //o ponteiro inicio conterá o endereço do primeiro elemento da lista
    Lista *li1 = NULL;
    Lista *li2 = NULL;
    Lista *lista_concatenada = NULL;
    int opcao;
    aluno dado;

    // primeiro menu de opções para execuções de operações sobre as listas
    do {
        printf("\n\n\n		Menu de opções:");
        printf("\n\n1. Manipular Lista 1;");
        printf("\n2. Manipular Lista 2;");
        printf("\n3. Concatenar lista 1 e lista 2;");
        printf("\n4. Lista 1 sem matriculas repetidas;");
        printf("\n5. Lista 1 invertida armazenada na Lista 2;");
        printf("\n6. Verificar se a Lista 1 esta ordenada;");
        printf("\n7. Verificar se a Lista 2 esta ordenada;");
        printf("\n8. Tamanho da Lista 1;");
        printf("\n9. Tamanho da Lista 2;");
        printf("\n0. Sair.");
        printf("\n\n			Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // exibe menu crud da lista1
                menu(&li1, dado);
                imprimir_lista(li1);
                break;
            case 2:
                // exibe menu crud da lista2
                menu(&li2, dado);
                break;
            case 3:
                // concatena e coloca na terceira lista
                lista_concatenada = criar_lista();
                lista_concatenada = concatenar(li1, li2);
                printf("\nLista concatenada: ");
                imprimir_lista(lista_concatenada);
                break;
            case 4:
                // aloca espaço pra terceira lista
                liberar_lista(li2);
                li2 = criar_lista();
                retorna_copia(li1, &li2);
                printf("\nL2 sem os valores repetidos entre as listas: \n");
                imprimir_lista(li2);
                break;
            case 5:
                // libera espaço da lista 2, aloca novo espaço e L2 recebe
                // L1 invertido
                liberar_lista(li2);
                li2 = criar_lista();
                inverte_lista(li1, &li2);
                printf("\nL2 sem os valores repetidos entre as listas: \n");
                imprimir_lista(li2);
                break;
            case 6:
                // verifica a ordenação da L1 e retorna um int de controle
                printf("\nValores da L1: \n");
                imprimir_lista(li1);
                if (verifica_ordenacao(li1))
                    printf("\nA lista esta ordenada.");
                else
                    printf("\nA lista não esta ordenada.");

                break;
            case 7:
                // verifica a ordenação da L1 e retorna um int de controle
                printf("\nValores da L2: \n");
                imprimir_lista(li2);
                if (verifica_ordenacao(li2))
                    printf("\nA lista esta ordenada.");
                else
                    printf("\nA lista não esta ordenada.");

                break;
            case 8:
                // verifica a ordenação da L1 e retorna um int de controle
                printf("\nTamanho da lista: ");
                printf("\n%d", tamanho_lista(*li1));
                break;
            case 9:
                // verifica a ordenação da L1 e retorna um int de controle
                printf("\nTamanho da lista: ");
                printf("\n%d", tamanho_lista(*li2));
                break;
            case 0:
                // libera memória e finaliza programa
                liberar_lista(li1);
                liberar_lista(li2);
                printf("\nFinalizando...");
                break;
            default:
                printf("\nOpção inválida!");
                break;
        }

    } while (opcao != 0);

    return 0;
}

void menu(Lista **li, aluno dado) {
    int opcaoMenu = 0, pos;

    do {
        printf("\n\n\n		Menu de opções:");
        printf("\n\n1. Criar lista;");
        printf("\n2. Liberar lista;");
        printf("\n3. Inserir elemento no início;");
        printf("\n4. Inserir elemento no final;");
        printf("\n5. Inserir elemento (ordenado);");
        printf("\n6. Remover elemento do início;");
        printf("\n7. Remover elemento do final;");
        printf("\n8. Remover elemento (qualquer);");
        printf("\n9. Buscar elemento pela posição;");
        printf("\n10. Buscar elemento pelo dado;");
        printf("\n11. Imprimir lista;");
        printf("\n12. Voltar.");
        printf("\n\n			Opção: ");
        scanf("%d", &opcaoMenu);

        switch (opcaoMenu) {
            case 1:
                // criar lista
                *li = criar_lista();
                if (li != NULL)
                    printf("\n Lista criada com sucesso!");
                else
                    printf("\n Lista não criada!");

                break;
            case 2:
                // liberar lista
                if (liberar_lista(*li))
                    printf("\n Lista liberada com sucesso!");
                else
                    printf("\n Lista não liberada!");

                break;
            case 3:
                // inserir elemento no início
                criar_dado(&dado);
                if (inserir_lista_inicio(*li, dado))
                    printf("\n Inserção realizada com sucesso!");
                else
                    printf("\n Falha na inserção!");

                break;
            case 4:
                // inserir elemento no final
                criar_dado(&dado);
                if (inserir_lista_final(*li, dado))
                    printf("\n Inserção realizada com sucesso!");
                else
                    printf("\n Falha na inserção!");

                break;
            case 5:
                // inserir elemento de forma ordenada
                criar_dado(&dado);
                if (inserir_lista_ordenada(*li, dado))
                    printf("\n Inserção realizada com sucesso!");
                else
                    printf("\n Falha na inserção!");

                break;
            case 6:
                // remover elemento do início
                if (remover_lista_inicio(*li))
                    printf("\n Remoção realizada com sucesso!");
                else
                    printf("\n Falha na remoção!");

                break;
            case 7:
                // remover elemento do final
                if (remover_lista_final(*li))
                    printf("\n Remoção realizada com sucesso!");
                else
                    printf("\n Falha na remoção!");

                break;
            case 8:
                // remover elemento do meio pela matricula
                printf("\n Matricula a ser removida: ");
                scanf("%d", &dado.matricula);

                if (remover_lista_meio(*li, dado))
                    printf("\n Remoção realizada com sucesso!");
                else
                    printf("\n Falha na remoção!");

                break;
            case 9:
                // busca elemento pela posicao
                printf("\n Posição do elemento a ser buscado: ");
                scanf("%d", &pos);
                if (buscar_lista_posicao(*li, pos, dado)) {
                    printf("\n Busca realizada com sucesso!");
                    printf("\n Elemento da %dª posição: ", pos);
                    printf("%d", dado.matricula);
                    printf("\n%s", dado.nome);
                    printf("\n%f", dado.nota);
                } else
                    printf("\n Posição não existe!");

                break;
            case 10:
                // busca elemento pelo dado
                printf("\n Matricula a ser buscada: ");
                scanf("%d", &dado.matricula);

                if (buscar_lista_dado(*li, dado, &pos)) {
                    printf("\n Busca realizada com sucesso!");
                    printf("\n Elemento da %dª posição: ", pos);
                    printf("%d", dado.matricula);
                    printf("\n%s", dado.nome);
                    printf("\n%f", dado.nota);
                } else
                    printf("\n Elemento não encontrado!");

                break;
            case 11:
                // imprime a lista
                printf("\n Lista encadeada: \n");
                if (!imprimir_lista(*li))
                    printf("\n Lista não encontrada!");

                break;
            case 12:
                // retorna ao menu anterior
                printf("\nVoltando ao menu...\n");
                break;
            default:
                printf("\nOpção inválida!");
                break;
        }
    } while (opcaoMenu != 12);

    return;
}

int criar_dado(aluno *dado) {
    printf("\nDigite a matricula do aluno: ");
    scanf("%d", &dado->matricula);
    printf("\nDigite o nome do aluno: ");
    scanf("%s", dado->nome);
    printf("\nDigite a nota do aluno: ");
    scanf("%f", &dado->nota);

    return 1;
}