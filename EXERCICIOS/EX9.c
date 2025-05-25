#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

typedef struct {
    No *topo;
} Pilha;

// Inicializa a pilha (topo = NULL)
void inicializar(Pilha *p) {
    p->topo = NULL;
}

// Verifica se a pilha está vazia
int esta_vazia(Pilha *p) {
    return p->topo == NULL;
}

// Adiciona elemento no topo (push)
void push(Pilha *p, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    if (!novo) {
        printf("Erro: sem memoria!\n");
        return;
    }
    novo->valor = valor;
    novo->prox = p->topo;
    p->topo = novo;
}

// Remove e retorna o elemento do topo (pop)
int pop(Pilha *p) {
    if (esta_vazia(p)) {
        printf("Erro: pilha vazia!\n");
        return -1;
    }
    No *temp = p->topo;
    int val = temp->valor;
    p->topo = temp->prox;
    free(temp);
    return val;
}

// Retorna o valor do topo sem remover
int topo(Pilha *p) {
    if (esta_vazia(p)) {
        printf("Erro: pilha vazia!\n");
        return -1;
    }
    return p->topo->valor;
}

int main() {
    Pilha p;
    inicializar(&p);

    push(&p, 10);
    push(&p, 20);
    push(&p, 30);

    printf("Topo: %d\n", topo(&p));  // 30

    printf("Pop: %d\n", pop(&p));    // 30
    printf("Pop: %d\n", pop(&p));    // 20

    printf("Topo atual: %d\n", topo(&p));  // 10

    return 0;
}
