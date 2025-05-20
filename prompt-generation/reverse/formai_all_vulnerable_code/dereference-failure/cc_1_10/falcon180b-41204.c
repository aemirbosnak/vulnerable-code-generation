//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SIZE 1000

typedef struct {
    int top;
    int capacity;
    char **stack;
} Stack;

void init_stack(Stack *stack) {
    stack->top = -1;
    stack->capacity = MAX_SIZE;
    stack->stack = (char **)malloc(stack->capacity * sizeof(char *));
}

void push_stack(Stack *stack, char *value) {
    if (stack->top >= stack->capacity - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->top++;
    stack->stack[stack->top] = value;
}

char *pop_stack(Stack *stack) {
    if (stack->top < 0) {
        printf("Stack underflow\n");
        return NULL;
    }
    char *value = stack->stack[stack->top];
    stack->top--;
    return value;
}

bool is_empty_stack(Stack *stack) {
    return stack->top == -1;
}

bool is_full_stack(Stack *stack) {
    return stack->top >= stack->capacity - 1;
}

int main() {
    FILE *file;
    char *filename = "example.txt";
    char ch;
    Stack stack;

    init_stack(&stack);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Cannot open file\n");
        exit(1);
    }

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            char *word = (char *)malloc(2 * sizeof(char));
            word[0] = ch;
            word[1] = '\0';
            push_stack(&stack, word);
        }
    }

    fclose(file);

    while (!is_empty_stack(&stack)) {
        char *word = pop_stack(&stack);
        printf("%s ", word);
    }

    return 0;
}