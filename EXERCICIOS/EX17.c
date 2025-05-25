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

// Inserção ordenada (reaproveitando do exercício 16)
void inserirOrdenado(Node **inicio, int valor) {
    Node *novo = criarNo(valor);

    if (*inicio == NULL || valor < (*inicio)->valor) {
        novo->prox = *inicio;
        *inicio = novo;
        return;
    }

    Node *atual = *inicio;
    while (atual->prox != NULL && atual->prox->valor < valor) {
        atual = atual->prox;
    }

    novo->prox = atual->prox;
    atual->prox = novo;
}

// Função para remover um elemento
void removerElemento(Node **inicio, int valor) {
    if (*inicio == NULL) {
        return; // Lista vazia
    }

    Node *atual = *inicio;
    Node *anterior = NULL;

    // Caso o valor esteja logo no primeiro nó
    if (atual->valor == valor) {
        *inicio = atual->prox;
        free(atual);
        return;
    }

    // Procurar o valor na lista
    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->prox;
    }

    // Se não encontrou o valor
    if (atual == NULL) {
        return;
    }

    // Remover o nó
    anterior->prox = atual->prox;
    free(atual);
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

    // Inserindo elementos
    inserirOrdenado(&lista, 10);
    inserirOrdenado(&lista, 5);
    inserirOrdenado(&lista, 20);
    inserirOrdenado(&lista, 15);
    inserirOrdenado(&lista, 1);

    printf("Lista original: ");
    imprimirLista(lista);

    // Remover alguns elementos
    removerElemento(&lista, 15);
    removerElemento(&lista, 1);
    removerElemento(&lista, 99); // Valor que não existe

    printf("Lista após remoções: ");
    imprimirLista(lista);

    liberarLista(lista);
    return 0;
}
