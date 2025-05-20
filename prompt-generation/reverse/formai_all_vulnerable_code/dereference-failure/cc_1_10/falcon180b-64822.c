//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 10000

typedef struct {
    int top;
    int capacity;
    char *stack;
} Stack;

void init_stack(Stack *s) {
    s->top = -1;
    s->capacity = MAX_SIZE;
    s->stack = (char *)malloc(s->capacity * sizeof(char));
}

void push_stack(Stack *s, char c) {
    if (s->top >= s->capacity - 1) {
        printf("Stack Overflow!\n");
        exit(1);
    }
    s->top++;
    s->stack[s->top] = c;
}

char pop_stack(Stack *s) {
    if (s->top < 0) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    char c = s->stack[s->top];
    s->top--;
    return c;
}

int is_empty_stack(Stack s) {
    return s.top == -1;
}

int main() {
    FILE *fp;
    char ch;
    int i, j;
    Stack input_stack;
    init_stack(&input_stack);

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            push_stack(&input_stack, ch);
        } else if (isdigit(ch)) {
            push_stack(&input_stack, ch);
        } else if (isalnum(ch)) {
            push_stack(&input_stack, ch);
        } else {
            printf("Invalid Character: %c\n", ch);
        }
    }

    fclose(fp);

    while (!is_empty_stack(input_stack)) {
        ch = pop_stack(&input_stack);
        printf("%c", ch);
    }

    return 0;
}