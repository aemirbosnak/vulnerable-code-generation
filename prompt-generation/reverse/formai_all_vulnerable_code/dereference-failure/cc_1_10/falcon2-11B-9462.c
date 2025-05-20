//Falcon2-11B DATASET v1.0 Category: Performance-Critical Component ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

Stack* createStack() {
    Stack* stack = malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void push(Stack* stack, int value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack* stack) {
    int value = stack->top->value;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return value;
}

int peek(Stack* stack) {
    return stack->top->value;
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

int main() {
    Stack* myStack = createStack();
    push(myStack, 1);
    push(myStack, 2);
    push(myStack, 3);
    printf("Top element: %d\n", peek(myStack));
    printf("Pop: %d\n", pop(myStack));
    printf("Is empty? %s\n", isEmpty(myStack)? "true" : "false");
    return 0;
}