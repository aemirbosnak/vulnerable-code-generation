//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct stack {
    Node* top;
} Stack;

void push(Stack* stack, int value);
int pop(Stack* stack);
int peek(Stack* stack);
int isEmpty(Stack* stack);
void display(Stack* stack);

int main() {
    Stack stack;
    stack.top = NULL;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);

    display(&stack);

    int poppedValue = pop(&stack);
    printf("Popped value: %d\n", poppedValue);

    display(&stack);

    int topValue = peek(&stack);
    printf("Top value: %d\n", topValue);

    if (isEmpty(&stack)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack is not empty\n");
    }

    return 0;
}

void push(Stack* stack, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory error\n");
        return;
    }

    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }

    Node* tempNode = stack->top;
    int poppedValue = tempNode->data;
    stack->top = tempNode->next;
    free(tempNode);

    return poppedValue;
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }

    return stack->top->data;
}

int isEmpty(Stack* stack) {
    return (stack->top == NULL);
}

void display(Stack* stack) {
    Node* tempNode = stack->top;

    printf("Stack: ");

    while (tempNode!= NULL) {
        printf("%d ", tempNode->data);
        tempNode = tempNode->next;
    }

    printf("\n");
}