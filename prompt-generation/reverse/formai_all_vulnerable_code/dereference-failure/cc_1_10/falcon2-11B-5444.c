//Falcon2-11B DATASET v1.0 Category: Memory management ; Style: genius
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct stack {
    Node* top;
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

int isFull(Stack* stack) {
    return stack->top == NULL;
}

void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(stack)) {
        stack->top = newNode;
    } else {
        newNode->next = stack->top;
        stack->top = newNode;
    }
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        return -1;
    } else {
        Node* temp = stack->top;
        int data = temp->data;
        stack->top = temp->next;
        free(temp);
        return data;
    }
}

int main() {
    Stack* stack = createStack();

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);

    printf("Top element: %d\n", pop(stack));
    printf("Top element: %d\n", pop(stack));
    printf("Top element: %d\n", pop(stack));
    printf("Top element: %d\n", pop(stack));

    return 0;
}