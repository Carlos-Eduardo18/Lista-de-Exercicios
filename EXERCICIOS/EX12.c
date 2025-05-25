#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

int eh_palindromo(char *str) {
    Pilha pilha;
    init(&pilha);

    int len = strlen(str);

    // Empilha todos os caracteres (ignorando case e espaços)
    for (int i = 0; i < len; i++) {
        if (isalnum(str[i])) {
            push(&pilha, tolower(str[i]));
        }
    }

    // Compara desempilhando
    for (int i = 0; i < len; i++) {
        char c;
        if (isalnum(str[i])) {
            if (!pop(&pilha, &c)) return 0; // erro ao desempilhar
            if (tolower(str[i]) != c) return 0; // não é palíndromo
        }
    }
    return 1;
}

int main() {
    char str[MAX];

    printf("Digite uma string: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0'; // remove newline

    if (eh_palindromo(str)) {
        printf("'%s' é palíndromo.\n", str);
    } else {
        printf("'%s' não é palíndromo.\n", str);
    }

    return 0;
}
