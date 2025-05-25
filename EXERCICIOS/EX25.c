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

int listasIguais(Node *l1, Node *l2) {
    while (l1 != NULL && l2 != NULL) {
        if (l1->valor != l2->valor)
            return 0;
        l1 = l1->prox;
        l2 = l2->prox;
    }
    return (l1 == NULL && l2 == NULL);
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

    inserirFinal(&lista1, 5);
    inserirFinal(&lista1, 10);
    inserirFinal(&lista2, 5);
    inserirFinal(&lista2, 10);

    if (listasIguais(lista1, lista2)) {
        printf("As listas sao iguais.\n");
    } else {
        printf("As listas sao diferentes.\n");
    }

    liberarLista(lista1);
    liberarLista(lista2);
    return 0;
}
