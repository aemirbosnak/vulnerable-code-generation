//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a node structure for a linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define a stack structure using linked lists
typedef struct stack {
    Node* top;
} Stack;

// Initialize a new empty stack
Stack* initStack() {
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    if (newStack == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    newStack->top = NULL;
    return newStack;
}

// Check if the stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Push an element onto the stack
void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack is empty\n");
        exit(1);
    }
    Node* tempNode = stack->top;
    int poppedData = tempNode->data;
    stack->top = tempNode->next;
    free(tempNode);
    return poppedData;
}

// Print the stack
void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    Node* tempNode = stack->top;
    while (tempNode!= NULL) {
        printf("%d ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("\n");
}

int main() {
    Stack* myStack = initStack();
    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);
    printStack(myStack);
    int poppedData = pop(myStack);
    printf("Popped data: %d\n", poppedData);
    printStack(myStack);
    return 0;
}