#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *proximo;
} No;

// Insere no fim (pra ajudar nos testes)
void inserir_fim(No **lista, int valor) {
    No *novo = malloc(sizeof(No));
    if (!novo) {
        printf("Erro de alocacao\n");
        return;
    }
    novo->valor = valor;
    novo->proximo = NULL;

    if (*lista == NULL) {
        *lista = novo;
    } else {
        No *aux = *lista;
        while (aux->proximo != NULL)
            aux = aux->proximo;
        aux->proximo = novo;
    }
}

// Função que insere na posição específica (0-indexada)
void inserir_posicao(No **lista, int valor, int posicao) {
    No *novo = malloc(sizeof(No));
    if (!novo) {
        printf("Erro de alocacao\n");
        return;
    }
    novo->valor = valor;

    if (posicao <= 0 || *lista == NULL) {
        // Insere no início se posição <=0 ou lista vazia
        novo->proximo = *lista;
        *lista = novo;
        return;
    }

    No *atual = *lista;
    int i = 0;

    // Percorre até o nó anterior à posição desejada ou até o fim
    while (i < posicao - 1 && atual->proximo != NULL) {
        atual = atual->proximo;
        i++;
    }

    // Inserção do novo nó
    novo->proximo = atual->proximo;
    atual->proximo = novo;
}

// Função para imprimir a lista
void imprimir_lista(No *lista) {
    No *atual = lista;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

// Função para liberar lista
void liberar_lista(No **lista) {
    No *atual = *lista;
    while (atual != NULL) {
        No *prox = atual->proximo;
        free(atual);
        atual = prox;
    }
    *lista = NULL;
}

int main() {
    No *lista = NULL;

    // Inserções iniciais
    inserir_fim(&lista, 10);
    inserir_fim(&lista, 20);
    inserir_fim(&lista, 30);

    printf("Lista original:\n");
    imprimir_lista(lista);

    // Inserir 15 na posição 1 (entre 10 e 20)
    inserir_posicao(&lista, 15, 1);
    printf("Depois de inserir 15 na posicao 1:\n");
    imprimir_lista(lista);

    // Inserir 5 na posição 0 (no início)
    inserir_posicao(&lista, 5, 0);
    printf("Depois de inserir 5 na posicao 0:\n");
    imprimir_lista(lista);

    // Inserir 40 na posição 10 (posição além do fim, insere no final)
    inserir_posicao(&lista, 40, 10);
    printf("Depois de inserir 40 na posicao 10:\n");
    imprimir_lista(lista);

    liberar_lista(&lista);
    return 0;
}
