#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do nó da lista
typedef struct No {
    int valor;
    struct No* proximo;
} No;

// Função para inserir no início da lista
void inserir_inicio(No** lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }
    novo->valor = valor;
    novo->proximo = *lista;
    *lista = novo;
}

// Função para inserir no fim da lista
void inserir_fim(No** lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }
    novo->valor = valor;
    novo->proximo = NULL;

    if (*lista == NULL) {
        // Lista vazia: o novo nó será o primeiro
        *lista = novo;
    } else {
        No* atual = *lista;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
}

// Função para imprimir a lista
void imprimir_lista(No* lista) {
    No* atual = lista;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

// Função principal
int main() {
    No* lista = NULL;

    inserir_fim(&lista, 10);
    inserir_inicio(&lista, 5);
    inserir_fim(&lista, 20);
    inserir_inicio(&lista, 2);

    imprimir_lista(lista);

    return 0;
}
