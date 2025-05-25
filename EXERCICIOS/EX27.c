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

Node* encontrarMeio(Node *inicio) {
    if (inicio == NULL) return NULL;
    Node *lento = inicio;
    Node *rapido = inicio;

    while (rapido != NULL && rapido->prox != NULL) {
        lento = lento->prox;
        rapido = rapido->prox->prox;
    }

    return lento;
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
    inserirFinal(&lista, 10);
    inserirFinal(&lista, 20);
    inserirFinal(&lista, 30);
    inserirFinal(&lista, 40);
    inserirFinal(&lista, 50);

    Node *meio = encontrarMeio(lista);
    if (meio != NULL) {
        printf("Elemento do meio: %d\n", meio->valor);
    } else {
        printf("Lista vazia.\n");
    }

    liberarLista(lista);
    return 0;
}
