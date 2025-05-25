#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char items[MAX];
    int top;
} Pilha;

void init(Pilha *p) {
    p->top = -1;
}

int esta_vazia(Pilha *p) {
    return p->top == -1;
}

int push(Pilha *p, char c) {
    if (p->top == MAX - 1) return 0; // pilha cheia
    p->items[++(p->top)] = c;
    return 1;
}

int pop(Pilha *p, char *c) {
    if (esta_vazia(p)) return 0;
    *c = p->items[(p->top)--];
    return 1;
}

int verificar_balanceamento(const char *str) {
    Pilha pilha;
    init(&pilha);

    for (int i = 0; i < strlen(str); i++) {
        char ch = str[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(&pilha, ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            char topo;
            if (!pop(&pilha, &topo)) return 0;  // pilha vazia, mas fechando

            // verifica se o topo da pilha combina com o fechamento
            if ((ch == ')' && topo != '(') ||
                (ch == '}' && topo != '{') ||
                (ch == ']' && topo != '[')) {
                return 0;
            }
        }
    }

    return esta_vazia(&pilha) ? 1 : 0;
}

int main() {
    char entrada[MAX];
    printf("Digite a string para verificar balanceamento: ");
    fgets(entrada, MAX, stdin);
    entrada[strcspn(entrada, "\n")] = '\0';  // remove o '\n'

    if (verificar_balanceamento(entrada))
        printf("String balanceada!\n");
    else
        printf("String nao balanceada!\n");

    return 0;
}
