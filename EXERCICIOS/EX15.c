#include <stdio.h>
#define MAX 5

typedef struct {
    int fila[MAX];
    int inicio;
    int fim;
    int tamanho;
} Fila;

void inicializar(Fila *f) {
    f->inicio = 0;
    f->fim = -1;
    f->tamanho = 0;
}

int esta_vazia(Fila *f) {
    return f->tamanho == 0;
}

int esta_cheia(Fila *f) {
    return f->tamanho == MAX;
}

void enfileirar(Fila *f, int valor) {
    if (esta_cheia(f)) {
        printf("Fila cheia! Nao e possivel enfileirar.\n");
        return;
    }
    f->fim = (f->fim + 1) % MAX;
    f->fila[f->fim] = valor;
    f->tamanho++;
}

int desenfileirar(Fila *f) {
    if (esta_vazia(f)) {
        printf("Fila vazia! Nao ha elementos para desenfileirar.\n");
        return -1;  // valor inválido
    }
    int valor = f->fila[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->tamanho--;
    return valor;
}

int frente(Fila *f) {
    if (esta_vazia(f)) {
        printf("Fila vazia! Nao ha elemento na frente.\n");
        return -1;
    }
    return f->fila[f->inicio];
}

void imprimir(Fila *f) {
    if (esta_vazia(f)) {
        printf("Fila vazia!\n");
        return;
    }
    printf("Fila: ");
    int i = f->inicio;
    for (int count = 0; count < f->tamanho; count++) {
        printf("%d ", f->fila[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Fila f;
    inicializar(&f);

    enfileirar(&f, 10);
    enfileirar(&f, 20);
    enfileirar(&f, 30);
    enfileirar(&f, 40);
    enfileirar(&f, 50);

    imprimir(&f);

    printf("Desenfileirando: %d\n", desenfileirar(&f));
    printf("Elemento da frente: %d\n", frente(&f));

    imprimir(&f);

    enfileirar(&f, 60);  // Testa fila circular

    imprimir(&f);

    return 0;
}
