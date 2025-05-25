#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *proximo;
} No;

// Função para inserir no fim da lista
void inserir_fim(No **lista, int valor) {
    No *novo = malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;

    if (*lista == NULL) {
        *lista = novo;
    } else {
        No *temp = *lista;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novo;
    }
}

// Função para encontrar o nó do meio
No* encontrar_meio(No *lista) {
    if (lista == NULL) return NULL;

    No *lento = lista;
    No *rapido = lista;

    while (rapido != NULL && rapido->proximo != NULL) {
        lento = lento->proximo;           // avança 1 nó
        rapido = rapido->proximo->proximo; // avança 2 nós
    }

    return lento;
}

// Função para imprimir a lista
void imprimir_lista(No *lista) {
    No *temp = lista;
    while (temp != NULL) {
        printf("%d -> ", temp->valor);
        temp = temp->proximo;
    }
    printf("NULL\n");
}

// Função principal para teste
int main() {
    No *lista = NULL;

    inserir_fim(&lista, 10);
    inserir_fim(&lista, 20);
    inserir_fim(&lista, 30);
    inserir_fim(&lista, 40);
    inserir_fim(&lista, 50);

    printf("Lista:\n");
    imprimir_lista(lista);

    No *meio = encontrar_meio(lista);

    if (meio != NULL)
        printf("No do meio: %d\n", meio->valor);
    else
        printf("Lista vazia.\n");

    return 0;
}
