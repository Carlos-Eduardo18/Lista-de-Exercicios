#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node *prox;
} Node;

Node* criarNo(int valor) {
    Node *novo = (Node*) malloc(sizeof(Node));
    novo->valor = valor;
    novo->prox = NULL;
    return novo;
}

void inserirFinal(Node **inicio, int valor) {
    Node *novo = criarNo(valor);
    if (*inicio == NULL) {
        *inicio = novo;
        return;
    }

    Node *atual = *inicio;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    atual->prox = novo;
}

void rotacionarDireita(Node **inicio) {
    if (*inicio == NULL || (*inicio)->prox == NULL)
        return;

    Node *segundoUltimo = NULL;
    Node *ultimo = *inicio;

    while (ultimo->prox != NULL) {
        segundoUltimo = ultimo;
        ultimo = ultimo->prox;
    }

    segundoUltimo->prox = NULL;
    ultimo->prox = *inicio;
    *inicio = ultimo;
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
    Node *lista = NULL;

    inserirFinal(&lista, 1);
    inserirFinal(&lista, 2);
    inserirFinal(&lista, 3);
    inserirFinal(&lista, 4);

    printf("Lista original:\n");
    imprimirLista(lista);

    rotacionarDireita(&lista);

    printf("Lista apos rotacao a direita:\n");
    imprimirLista(lista);

    liberarLista(lista);
    return 0;
}
