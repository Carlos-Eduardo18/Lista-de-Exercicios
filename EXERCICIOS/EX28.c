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

int detectarCiclo(Node *inicio) {
    Node *lento = inicio;
    Node *rapido = inicio;

    while (rapido != NULL && rapido->prox != NULL) {
        lento = lento->prox;
        rapido = rapido->prox->prox;

        if (lento == rapido)
            return 1; // Ciclo detectado
    }
    return 0; // Sem ciclo
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

    // Criar ciclo manualmente para teste
    lista->prox->prox->prox = lista->prox; 

    if (detectarCiclo(lista)) {
        printf("Ciclo detectado na lista.\n");
    } else {
        printf("Nenhum ciclo detectado.\n");
    }

    // Nao chamar liberarLista aqui porque tem ciclo
    return 0;
}
