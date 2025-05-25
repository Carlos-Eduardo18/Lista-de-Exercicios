#include <stdio.h>
#include <string.h>

#define MAX 100

// Pilha simples para caracteres
typedef struct {
    char itens[MAX];
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

void push(Pilha *p, char c) {
    if (!esta_cheia(p)) {
        p->itens[++p->topo] = c;
    }
}

char pop(Pilha *p) {
    if (!esta_vazia(p)) {
        return p->itens[p->topo--];
    }
    return '\0'; // Retorno inválido se vazia
}

int verificar_balanceamento(const char *str) {
    Pilha p;
    inicializar(&p);
    for (int i = 0; i < strlen(str); i++) {
        char c = str[i];
        if (c == '(' || c == '{' || c == '[') {
            push(&p, c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (esta_vazia(&p)) return 0; // Fechando sem abrir
            char topo = pop(&p);
            if ((c == ')' && topo != '(') ||
                (c == '}' && topo != '{') ||
                (c == ']' && topo != '[')) {
                return 0; // Parênteses não correspondem
            }
        }
    }
    return esta_vazia(&p) ? 1 : 0; // Se pilha vazia, está balanceado
}

int main() {
    char str[100];
    printf("Digite a string: ");
    scanf("%s", str);

    if (verificar_balanceamento(str)) {
        printf("String balanceada.\n");
    } else {
        printf("String nao balanceada.\n");
    }
    return 0;
}
