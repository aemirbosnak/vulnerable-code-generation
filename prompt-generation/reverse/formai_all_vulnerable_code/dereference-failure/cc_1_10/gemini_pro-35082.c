//GEMINI-pro DATASET v1.0 Category: Educational ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Node {
    int data;
    struct Node *next;
};

struct Stack {
    struct Node *top;
};

struct Stack *createStack() {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

void push(struct Stack *stack, int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
}

int pop(struct Stack *stack) {
    if (stack->top == NULL) {
        return -1;
    }
    int data = stack->top->data;
    struct Node *temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

int peek(struct Stack *stack) {
    if (stack->top == NULL) {
        return -1;
    }
    return stack->top->data;
}

int isEmpty(struct Stack *stack) {
    return stack->top == NULL;
}

int main() {
    struct Stack *stack = createStack();
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    printf("%d\n", peek(stack));
    pop(stack);
    printf("%d\n", peek(stack));
    pop(stack);
    printf("%d\n", peek(stack));
    pop(stack);
    printf("%d\n", isEmpty(stack));
    return 0;
}