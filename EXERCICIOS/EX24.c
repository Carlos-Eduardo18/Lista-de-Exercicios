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

void removerDuplicados(Node *inicio) {
    Node *atual = inicio;

    while (atual != NULL) {
        Node *anterior = atual;
        Node *comparador = atual->prox;

        while (comparador != NULL) {
            if (comparador->valor == atual->valor) {
                anterior->prox = comparador->prox;
                free(comparador);
                comparador = anterior->prox;
            } else {
                anterior = comparador;
                comparador = comparador->prox;
            }
        }

        atual = atual->prox;
    }
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
    inserirFinal(&lista, 2);
    inserirFinal(&lista, 3);
    inserirFinal(&lista, 1);

    printf("Lista original:\n");
    imprimirLista(lista);

    removerDuplicados(lista);

    printf("Lista sem duplicados:\n");
    imprimirLista(lista);

    liberarLista(lista);
    return 0;
}
