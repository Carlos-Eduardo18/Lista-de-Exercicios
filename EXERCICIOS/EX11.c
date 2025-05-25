#include <stdio.h>
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

void inverter_string(char *str) {
    Pilha pilha;
    init(&pilha);

    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        push(&pilha, str[i]);
    }

    for (int i = 0; i < len; i++) {
        char c;
        pop(&pilha, &c);
        str[i] = c;
    }
}

int main() {
    char str[MAX];

    printf("Digite uma string: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0'; // remove newline

    inverter_string(str);

    printf("String invertida: %s\n", str);

    return 0;
}
