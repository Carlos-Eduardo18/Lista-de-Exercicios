#include <stdio.h>
#define MAX 100

typedef struct {
    int itens[MAX];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int esta_vazia(Pilha *p) {
    return p->topo == -1;
}

int esta_cheia(Pilha *p) {
    return p->topo == MAX - 1;
}

void push(Pilha *p, int valor) {
    if (!esta_cheia(p)) {
        p->itens[++p->topo] = valor;
    }
}

int pop(Pilha *p) {
    if (!esta_vazia(p)) {
        return p->itens[p->topo--];
    }
    return -1; // valor inválido se vazia
}

int topo(Pilha *p) {
    if (!esta_vazia(p)) {
        return p->itens[p->topo];
    }
    return -1;
}

void ordenar_pilha(Pilha *p) {
    Pilha aux;
    inicializar(&aux);
    
    while (!esta_vazia(p)) {
        int temp = pop(p);
        
        while (!esta_vazia(&aux) && topo(&aux) > temp) {
            push(p, pop(&aux));
        }
        
        push(&aux, temp);
    }
    
    // Copiar de volta para a pilha original (ordenada)
    while (!esta_vazia(&aux)) {
        push(p, pop(&aux));
    }
}

void imprimir(Pilha *p) {
    for (int i = 0; i <= p->topo; i++) {
        printf("%d ", p->itens[i]);
    }
    printf("\n");
}

int main() {
    Pilha p;
    inicializar(&p);

    // Inserindo valores desordenados
    push(&p, 34);
    push(&p, 3);
    push(&p, 31);
    push(&p, 98);
    push(&p, 92);
    push(&p, 23);

    printf("Pilha antes da ordenacao:\n");
    imprimir(&p);

    ordenar_pilha(&p);

    printf("Pilha depois da ordenacao:\n");
    imprimir(&p);

    return 0;
}
