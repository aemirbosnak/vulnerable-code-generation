//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

struct stack {
    char *array;
    int top;
    int capacity;
};

typedef struct stack Stack;

void init(Stack *s) {
    s->array = (char *)malloc(MAX_SIZE * sizeof(char));
    s->top = -1;
    s->capacity = MAX_SIZE;
}

int is_empty(Stack *s) {
    return s->top == -1;
}

int is_full(Stack *s) {
    return s->top == s->capacity - 1;
}

void push(Stack *s, char c) {
    if (is_full(s)) {
        printf("Stack is full!\n");
        return;
    }
    s->array[++s->top] = c;
}

char pop(Stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty!\n");
        return '\0';
    }
    return s->array[s->top--];
}

void reverse(Stack *s) {
    char c;
    while (!is_empty(s)) {
        c = pop(s);
        push(s, c);
    }
}

int main() {
    Stack stack;
    init(&stack);
    char input[MAX_SIZE];
    int i, j;
    printf("Enter a string: ");
    fgets(input, MAX_SIZE, stdin);
    for (i = 0, j = strlen(input) - 1; i < j; i++, j--) {
        push(&stack, input[i]);
        push(&stack, input[j]);
    }
    if (i == j) {
        push(&stack, input[i]);
    }
    reverse(&stack);
    printf("Reversed string: ");
    while (!is_empty(&stack)) {
        printf("%c", pop(&stack));
    }
    printf("\n");
    return 0;
}