//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the maximum size of the stack
#define MAX_STACK_SIZE 100

// Define the node structure for the stack
typedef struct {
    int data;
    struct node* next;
} Node;

// Define the stack structure
typedef struct {
    Node* top;
    int size;
} Stack;

// Create an empty stack
Stack* createStack() {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("Error: Could not create stack\n");
        exit(1);
    }
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

// Push an integer value onto the stack
void push(Stack* stack, int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Could not create node\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

// Pop a value off the stack and return it
int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Error: Stack is empty\n");
        exit(1);
    }
    int value = stack->top->data;
    Node* tempNode = stack->top;
    stack->top = stack->top->next;
    free(tempNode);
    stack->size--;
    return value;
}

// Print the current state of the stack
void printStack(Stack* stack) {
    printf("Stack: ");
    Node* currentNode = stack->top;
    while (currentNode!= NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

// Free the memory used by the stack
void freeStack(Stack* stack) {
    Node* currentNode = stack->top;
    while (currentNode!= NULL) {
        Node* tempNode = currentNode;
        currentNode = currentNode->next;
        free(tempNode);
    }
    free(stack);
}

// Main function to demonstrate stack operations
int main() {
    Stack* myStack = createStack();
    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);
    printStack(myStack);
    int poppedValue = pop(myStack);
    printf("Popped value: %d\n", poppedValue);
    printStack(myStack);
    freeStack(myStack);
    return 0;
}