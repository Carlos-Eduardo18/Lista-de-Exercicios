#include <stdio.h>
#include <stdlib.h>

// Definição do nó da lista
typedef struct No {
    int valor;
    struct No *proximo;
} No;

// Função para inserir no fim da lista (ajuda a testar)
void inserir_fim(No **lista, int valor) {
    No *novo = malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;

    if (*lista == NULL) {
        *lista = novo;
    } else {
        No *temp = *lista;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novo;
    }
}

// Função para imprimir a lista (para verificar resultado)
void imprimir_lista(No *lista) {
    No *temp = lista;
    while (temp != NULL) {
        printf("%d -> ", temp->valor);
        temp = temp->proximo;
    }
    printf("NULL\n");
}

// Função que inverte a lista iterativamente
void inverter_lista(No **lista) {
    No *anterior = NULL;
    No *atual = *lista;
    No *proximo = NULL;

    while (atual != NULL) {
        proximo = atual->proximo;  // guarda o próximo nó
        atual->proximo = anterior; // inverte o ponteiro
        anterior = atual;           // avança 'anterior'
        atual = proximo;            // avança 'atual'
    }
    *lista = anterior; // novo início da lista
}

// Função principal para testar
int main() {
    No *lista = NULL;

    inserir_fim(&lista, 1);
    inserir_fim(&lista, 2);
    inserir_fim(&lista, 3);
    inserir_fim(&lista, 4);

    printf("Lista original:\n");
    imprimir_lista(lista);

    inverter_lista(&lista);

    printf("Lista invertida:\n");
    imprimir_lista(lista);

    return 0;
}
