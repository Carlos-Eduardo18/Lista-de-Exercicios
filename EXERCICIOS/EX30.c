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

Node* intercalarListas(Node *l1, Node *l2) {
    Node *resultado = NULL, **ptr = &resultado;

    while (l1 != NULL && l2 != NULL) {
        *ptr = criarNo(l1->valor);
        ptr = &((*ptr)->prox);
        l1 = l1->prox;

        *ptr = criarNo(l2->valor);
        ptr = &((*ptr)->prox);
        l2 = l2->prox;
    }

    while (l1 != NULL) {
        *ptr = criarNo(l1->valor);
        ptr = &((*ptr)->prox);
        l1 = l1->prox;
    }

    while (l2 != NULL) {
        *ptr = criarNo(l2->valor);
        ptr = &((*ptr)->prox);
        l2 = l2->prox;
    }

    return resultado;
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
    inserirFinal(&lista1, 3);
    inserirFinal(&lista1, 5);

    inserirFinal(&lista2, 2);
    inserirFinal(&lista2, 4);
    inserirFinal(&lista2, 6);
    inserirFinal(&lista2, 8);

    printf("Lista 1:\n");
    imprimirLista(lista1);

    printf("Lista 2:\n");
    imprimirLista(lista2);

    Node *intercalada = intercalarListas(lista1, lista2);
    printf("Lista intercalada:\n");
    imprimirLista(intercalada);

    liberarLista(lista1);
    liberarLista(lista2);
    liberarLista(intercalada);

    return 0;
}
