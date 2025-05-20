//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node struct for linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Stack struct using linked list
typedef struct stack {
    Node* top;
} Stack;

// Function to push an element onto the stack
void push(Stack* stack, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack Underflow\n");
        exit(0);
    }
    int data = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    if (stack->top == NULL) {
        return 1;
    } else {
        return 0;
    }
}

// Function to print the stack
void printStack(Stack* stack) {
    Node* temp = stack->top;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to demonstrate stack operations
int main() {
    Stack stack;
    stack.top = NULL;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    printStack(&stack);

    int poppedElement = pop(&stack);
    printf("Popped element: %d\n", poppedElement);
    printStack(&stack);

    if (isEmpty(&stack)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack is not empty\n");
    }

    return 0;
}