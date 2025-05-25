#include <stdio.h>
#include <stdlib.h>

// Definição do nó
typedef struct Node {
    int valor;
    struct Node *prox;
} Node;

// Função para criar um novo nó
Node* criarNo(int valor) {
    Node *novo = (Node*) malloc(sizeof(Node));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    novo->valor = valor;
    novo->prox = NULL;
    return novo;
}

// Inserção ordenada (ordem crescente)
void inserirOrdenado(Node **inicio, int valor) {
    Node *novo = criarNo(valor);

    // Caso a lista esteja vazia ou o novo valor é menor que o primeiro
    if (*inicio == NULL || valor < (*inicio)->valor) {
        novo->prox = *inicio;
        *inicio = novo;
        return;
    }

    // Procurar posição correta
    Node *atual = *inicio;
    while (atual->prox != NULL && atual->prox->valor < valor) {
        atual = atual->prox;
    }

    novo->prox = atual->prox;
    atual->prox = novo;
}

// Função para imprimir a lista
void imprimirLista(Node *inicio) {
    Node *atual = inicio;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");
}

// Função para liberar memória da lista
void liberarLista(Node *inicio) {
    Node *temp;
    while (inicio != NULL) {
        temp = inicio;
        inicio = inicio->prox;
        free(temp);
    }
}

// Função principal para testar
int main() {
    Node *lista = NULL;

    inserirOrdenado(&lista, 10);
    inserirOrdenado(&lista, 5);
    inserirOrdenado(&lista, 20);
    inserirOrdenado(&lista, 15);
    inserirOrdenado(&lista, 1);

    printf("Lista ordenada: ");
    imprimirLista(lista);

    liberarLista(lista);
    return 0;
}
