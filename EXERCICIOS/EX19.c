#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node *prox;
} Node;

// Cria um novo no
Node* criarNo(int valor) {
    Node *novo = (Node*) malloc(sizeof(Node));
    if (novo == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }
    novo->valor = valor;
    novo->prox = NULL;
    return novo;
}

// Insere no final da lista
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

// Conta quantos elementos existem na lista
int contarElementos(Node *inicio) {
    int contador = 0;
    Node *atual = inicio;
    while (atual != NULL) {
        contador++;
        atual = atual->prox;
    }
    return contador;
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

// Libera memoria da lista
void liberarLista(Node *inicio) {
    Node *temp;
    while (inicio != NULL) {
        temp = inicio;
        inicio = inicio->prox;
        free(temp);
    }
}

// Funcao principal
int main() {
    Node *lista = NULL;

    inserirFinal(&lista, 2);
    inserirFinal(&lista, 4);
    inserirFinal(&lista, 6);
    inserirFinal(&lista, 8);

    imprimirLista(lista);

    int total = contarElementos(lista);
    printf("A lista tem %d elemento(s).\n", total);

    liberarLista(lista);
    return 0;
}
