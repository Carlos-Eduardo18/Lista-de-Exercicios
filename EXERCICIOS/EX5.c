#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *proximo;
} No;

// Insere no fim (para testes)
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

// Remove a primeira ocorrência do valor na lista
int remover_valor(No **lista, int valor) {
    if (*lista == NULL) return 0; // lista vazia

    No *atual = *lista;
    No *anterior = NULL;

    while (atual != NULL) {
        if (atual->valor == valor) {
            if (anterior == NULL) {
                // Remover o primeiro nó
                *lista = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            return 1; // valor removido com sucesso
        }
        anterior = atual;
        atual = atual->proximo;
    }

    return 0; // valor não encontrado
}

// Imprime a lista
void imprimir_lista(No *lista) {
    No *atual = lista;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

// Libera a memória da lista
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

    inserir_fim(&lista, 10);
    inserir_fim(&lista, 20);
    inserir_fim(&lista, 30);
    inserir_fim(&lista, 20);

    printf("Lista original:\n");
    imprimir_lista(lista);

    int removido = remover_valor(&lista, 20);
    if (removido)
        printf("Valor 20 removido da lista.\n");
    else
        printf("Valor 20 nao encontrado.\n");
    imprimir_lista(lista);

    removido = remover_valor(&lista, 40);
    if (removido)
        printf("Valor 40 removido da lista.\n");
    else
        printf("Valor 40 nao encontrado.\n");
    imprimir_lista(lista);

    liberar_lista(&lista);
    return 0;
}
