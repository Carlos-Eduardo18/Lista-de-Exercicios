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

int detectarECorrigirCiclo(Node *inicio) {
    Node *lento = inicio;
    Node *rapido = inicio;

    while (rapido != NULL && rapido->prox != NULL) {
        lento = lento->prox;
        rapido = rapido->prox->prox;

        if (lento == rapido) {
            // Ciclo detectado, agora remover
            lento = inicio;
            Node *prev = NULL;
            while (lento != rapido) {
                prev = rapido;
                lento = lento->prox;
                rapido = rapido->prox;
            }
            // prev aponta para o nodo antes do ponto de encontro
            prev->prox = NULL;
            return 1;
        }
    }
    return 0;
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

    // Criar ciclo manual para teste
    lista->prox->prox->prox->prox = lista->prox;

    if (detectarECorrigirCiclo(lista)) {
        printf("Ciclo detectado e removido.\n");
    } else {
        printf("Nenhum ciclo detectado.\n");
    }

    printf("Lista apos remover ciclo:\n");
    imprimirLista(lista);

    liberarLista(lista);
    return 0;
}
