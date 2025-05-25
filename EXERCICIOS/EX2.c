#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* proximo;
} No;

void inserir_inicio(No** lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = *lista;
    *lista = novo;
}

void inserir_fim(No** lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;

    if (*lista == NULL) {
        *lista = novo;
    } else {
        No* atual = *lista;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
}

void imprimir_lista(No* lista) {
    No* atual = lista;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

int contar_nos(No* lista) {
    int contador = 0;
    No* atual = lista;

    while (atual != NULL) {
        contador++;
        atual = atual->proximo;
    }

    return contador;
}

int main() {
    No* lista = NULL;

    inserir_fim(&lista, 10);
    inserir_inicio(&lista, 5);
    inserir_fim(&lista, 20);

    imprimir_lista(lista);

    int total = contar_nos(lista);
    printf("Número de nós na lista: %d\n", total);

    return 0;
}
