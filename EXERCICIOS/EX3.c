#include <stdio.h>
#include <stdlib.h>

// Definição do nó
typedef struct No {
    int valor;
    struct No *proximo;
} No;

// Função para inserir no fim da lista (pra facilitar os testes)
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

// Função para buscar elemento na lista
int buscar_elemento(No *lista, int valor) {
    No *atual = lista;
    while (atual != NULL) {
        if (atual->valor == valor)
            return 1;  // encontrou
        atual = atual->proximo;
    }
    return 0;  // não encontrou
}

// Função para imprimir a lista (para teste)
void imprimir_lista(No *lista) {
    No *atual = lista;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

// Função para liberar a memória da lista
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

    // Inserindo alguns elementos
    inserir_fim(&lista, 10);
    inserir_fim(&lista, 20);
    inserir_fim(&lista, 30);

    imprimir_lista(lista);

    int valor_buscar = 20;
    if (buscar_elemento(lista, valor_buscar))
        printf("Valor %d encontrado na lista.\n", valor_buscar);
    else
        printf("Valor %d nao encontrado na lista.\n", valor_buscar);

    valor_buscar = 25;
    if (buscar_elemento(lista, valor_buscar))
        printf("Valor %d encontrado na lista.\n", valor_buscar);
    else
        printf("Valor %d nao encontrado na lista.\n", valor_buscar);

    liberar_lista(&lista);

    return 0;
}
