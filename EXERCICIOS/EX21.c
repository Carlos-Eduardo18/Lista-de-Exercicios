#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node *prox;
} Node;

Node* criarNo(int valor) {
    Node *novo = (Node*) malloc(sizeof(Node));
    if (novo == NULL) {
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
        return;
    }

    Node *atual = *inicio;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    atual->prox = novo;
}

void inverterLista(Node **inicio) {
    Node *anterior = NULL;
    Node *atual = *inicio;
    Node *prox = NULL;

    while (atual != NULL) {
        prox = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = prox;
    }

    *inicio = anterior;
}

void imprimirLista(Node *inicio) {
    Node *atual = inicio;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
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

    inverterLista(&lista);

    printf("Lista invertida:\n");
    imprimirLista(lista);

    liberarLista(lista);
    return 0;
}
