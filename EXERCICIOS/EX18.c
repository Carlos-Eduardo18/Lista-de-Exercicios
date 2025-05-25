#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node *prox;
} Node;

// Cria um novo nó
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

// Insere no final da lista (sem ordenar)
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

// Verifica se a lista está em ordem crescente
int listaOrdenada(Node *inicio) {
    if (inicio == NULL || inicio->prox == NULL) {
        return 1; // Lista vazia ou com um único elemento está ordenada
    }

    Node *atual = inicio;
    while (atual->prox != NULL) {
        if (atual->valor > atual->prox->valor) {
            return 0; // Encontrou um valor fora de ordem
        }
        atual = atual->prox;
    }

    return 1; // Lista ordenada
}

// Imprime a lista
void imprimirLista(Node *inicio) {
    Node *atual = inicio;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");
}

// Libera memória da lista
void liberarLista(Node *inicio) {
    Node *temp;
    while (inicio != NULL) {
        temp = inicio;
        inicio = inicio->prox;
        free(temp);
    }
}

// Função principal
int main() {
    Node *lista = NULL;

    // Lista ordenada
    inserirFinal(&lista, 1);
    inserirFinal(&lista, 3);
    inserirFinal(&lista, 5);

    imprimirLista(lista);
    if (listaOrdenada(lista)) {
        printf("A lista está ordenada.\n");
    } else {
        printf("A lista NÃO está ordenada.\n");
    }

    // Inserindo um número fora de ordem
    inserirFinal(&lista, 2);

    imprimirLista(lista);
    if (listaOrdenada(lista)) {
        printf("A lista está ordenada.\n");
    } else {
        printf("A lista NÃO está ordenada.\n");
    }

    liberarLista(lista);
    return 0;
}
