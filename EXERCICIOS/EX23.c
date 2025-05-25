#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node *prox;
} Node;

Node* criarNo(int valor) {
    Node *novo = (Node*) malloc(sizeof(Node));
    if (!novo) {
        printf("Erro de memoria.\n");
        exit(1);
    }
    novo->valor = valor;
    novo->prox = NULL;
    return novo;
}

void inserirFinal(Node **inicio, int valor) {
    Node *novo = criarNo(valor);
    if (*inicio == NULL) {
        *inicio = novo;
    } else {
        Node *atual = *inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

void concatenarListas(Node **lista1, Node *lista2) {
    if (*lista1 == NULL) {
        *lista1 = lista2;
        return;
    }

    Node *atual = *lista1;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    atual->prox = lista2;
}

void imprimirLista(Node *inicio) {
    while (inicio != NULL) {
        printf("%d -> ", inicio->valor);
        inicio = inicio->prox;
    }
    printf("NULL\n");
}

void liberarLista(Node *inicio) {
    Node *temp;
    while (inicio != NULL) {
        temp = inicio;
        inicio = inicio->prox;
        free(temp);
    }
}

int main() {
    Node *lista1 = NULL;
    Node *lista2 = NULL;

    inserirFinal(&lista1, 1);
    inserirFinal(&lista1, 2);
    inserirFinal(&lista2, 3);
    inserirFinal(&lista2, 4);

    printf("Lista 1:\n");
    imprimirLista(lista1);
    printf("Lista 2:\n");
    imprimirLista(lista2);

    concatenarListas(&lista1, lista2);

    printf("Lista concatenada:\n");
    imprimirLista(lista1);

    liberarLista(lista1);
    return 0;
}
