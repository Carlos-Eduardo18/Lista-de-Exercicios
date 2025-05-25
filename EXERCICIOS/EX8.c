#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *proximo;
} No;

typedef struct Pilha {
    int *dados;
    int topo;
    int capacidade;
} Pilha;

// Cria uma pilha
Pilha* criar_pilha(int capacidade) {
    Pilha *p = malloc(sizeof(Pilha));
    p->dados = malloc(capacidade * sizeof(int));
    p->topo = -1;
    p->capacidade = capacidade;
    return p;
}

void push(Pilha *p, int valor) {
    if (p->topo < p->capacidade - 1) {
        p->dados[++(p->topo)] = valor;
    }
}

int pop(Pilha *p) {
    if (p->topo >= 0) {
        return p->dados[(p->topo)--];
    }
    return -1;
}

int esta_vazia(Pilha *p) {
    return p->topo == -1;
}

// Função que imprime a lista na ordem reversa
void imprimir_reverso(No *lista) {
    int tamanho = 0;
    No *temp = lista;
    while (temp != NULL) {
        tamanho++;
        temp = temp->proximo;
    }

    Pilha *p = criar_pilha(tamanho);

    temp = lista;
    while (temp != NULL) {
        push(p, temp->valor);
        temp = temp->proximo;
    }

    printf("Lista na ordem reversa:\n");
    while (!esta_vazia(p)) {
        printf("%d -> ", pop(p));
    }
    printf("NULL\n");

    free(p->dados);
    free(p);
}

// Função para criar um novo nó
No* criar_no(int valor) {
    No *novo = malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;
    return novo;
}

int main() {
    // Criando uma lista simples: 1 -> 2 -> 3 -> NULL
    No *head = criar_no(1);
    head->proximo = criar_no(2);
    head->proximo->proximo = criar_no(3);

    imprimir_reverso(head);

    // Liberar memória (exemplo simples)
    No *temp;
    while (head != NULL) {
        temp = head;
        head = head->proximo;
        free(temp);
    }

    return 0;
}
