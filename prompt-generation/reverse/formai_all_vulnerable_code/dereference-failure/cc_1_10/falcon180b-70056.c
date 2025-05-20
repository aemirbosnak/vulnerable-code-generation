//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Node structure definition
typedef struct node {
    int data;
    struct node* next;
} Node;

// Stack structure definition using linked list
typedef struct stack {
    Node* top;
} Stack;

// Stack initialization
void init(Stack* stack) {
    stack->top = NULL;
}

// Push operation
void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Stack overflow\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Pop operation
int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack underflow\n");
        exit(0);
    }
    Node* tempNode = stack->top;
    int data = tempNode->data;
    stack->top = tempNode->next;
    free(tempNode);
    return data;
}

// Peek operation
int peek(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        exit(0);
    }
    return stack->top->data;
}

// Display stack elements
void display(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    Node* tempNode = stack->top;
    printf("Stack elements are: ");
    while (tempNode!= NULL) {
        printf("%d ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("\n");
}

int main() {
    Stack stack;
    init(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    display(&stack);

    int poppedElement = pop(&stack);
    printf("Popped element is: %d\n", poppedElement);

    display(&stack);

    int peekedElement = peek(&stack);
    printf("Peeked element is: %d\n", peekedElement);

    return 0;
}