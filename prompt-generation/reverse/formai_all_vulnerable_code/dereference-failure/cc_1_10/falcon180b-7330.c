//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct stack {
    Node* top;
    int size;
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

bool isEmpty(Stack* stack) {
    return stack->top == NULL;
}

bool push(Stack* stack, int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = stack->top;
    stack->top = node;
    stack->size++;
    return true;
}

bool pop(Stack* stack) {
    if (isEmpty(stack)) {
        return false;
    }
    Node* top = stack->top;
    stack->top = stack->top->next;
    free(top);
    stack->size--;
    return true;
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->top->data;
}

void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    Node* curr = stack->top;
    while (curr!= NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    Stack* stack = createStack();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    printStack(stack);
    pop(stack);
    pop(stack);
    printStack(stack);
    int topElement = peek(stack);
    printf("Top element is: %d\n", topElement);
    free(stack);
    return 0;
}