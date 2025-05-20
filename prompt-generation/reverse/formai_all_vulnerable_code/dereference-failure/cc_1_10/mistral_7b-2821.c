//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_LEN 100

typedef struct {
    char data;
    struct Stack *next;
} StackElement;

typedef struct Stack {
    StackElement *top;
    int size;
} Stack;

Stack *createStack(int size) {
    Stack *stack = (Stack *)calloc(1, sizeof(Stack));
    stack->size = size;
    stack->top = NULL;
    return stack;
}

void push(Stack *stack, char data) {
    StackElement *newElement = (StackElement *)malloc(sizeof(StackElement));
    newElement->data = data;
    newElement->next = stack->top;
    stack->top = newElement;
}

char pop(Stack *stack) {
    if (stack->top == NULL) {
        fprintf(stderr, "Error: Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    char data = stack->top->data;
    StackElement *temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

int is_alpha(char c) {
    return isalpha(tolower(c));
}

void reverseString(char *str, Stack *stack) {
    int i = 0;
    while (str[i] != '\0') {
        if (is_alpha(str[i])) {
            push(stack, str[i]);
        }
        i++;
    }

    i = 0;
    while (stack->top != NULL) {
        str[i++] = pop(stack);
    }

    str[i] = '\0';
}

int main() {
    char str[MAX_LEN];
    Stack *stack = createStack(MAX_LEN);

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    reverseString(str, stack);

    printf("Reversed string: %s\n", str);

    free(stack);
    return 0;
}