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

Node* clonarLista(Node *inicio) {
    if (inicio == NULL) return NULL;

    Node *clonada = NULL;
    Node *atual = inicio;

    while (atual != NULL) {
        inserirFinal(&clonada, atual->valor);
        atual = atual->prox;
    }

    return clonada;
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
    inserirFinal(&lista, 7);
    inserirFinal(&lista, 14);
    inserirFinal(&lista, 21);

    printf("Lista original:\n");
    imprimirLista(lista);

    Node *clonada = clonarLista(lista);
    printf("Lista clonada:\n");
    imprimirLista(clonada);

    liberarLista(lista);
    liberarLista(clonada);
    return 0;
}
