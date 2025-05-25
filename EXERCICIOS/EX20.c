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

// Busca um elemento na lista
Node* buscarElemento(Node *inicio, int valor) {
    Node *atual = inicio;
    while (atual != NULL) {
        if (atual->valor == valor) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
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

    inserirFinal(&lista, 10);
    inserirFinal(&lista, 20);
    inserirFinal(&lista, 30);
    inserirFinal(&lista, 40);

    imprimirLista(lista);

    int alvo = 30;
    Node *encontrado = buscarElemento(lista, alvo);
    if (encontrado != NULL) {
        printf("Elemento %d encontrado na lista.\n", alvo);
    } else {
        printf("Elemento %d nao encontrado na lista.\n", alvo);
    }

    alvo = 50;
    encontrado = buscarElemento(lista, alvo);
    if (encontrado != NULL) {
        printf("Elemento %d encontrado na lista.\n", alvo);
    } else {
        printf("Elemento %d nao encontrado na lista.\n", alvo);
    }

    liberarLista(lista);
    return 0;
}
