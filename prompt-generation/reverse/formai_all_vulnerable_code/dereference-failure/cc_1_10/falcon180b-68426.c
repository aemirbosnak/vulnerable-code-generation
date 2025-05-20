//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum size of the stack
#define MAX_SIZE 100

// Define the structure for the stack
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// Function to create a new stack
Stack* createStack() {
    Stack* newStack = (Stack*) malloc(sizeof(Stack));
    if (newStack == NULL) {
        printf("Error: Unable to create stack.\n");
        exit(1);
    }
    newStack->top = -1;
    return newStack;
}

// Function to push an element onto the stack
void push(Stack* stack, int value) {
    if (stack->top >= MAX_SIZE - 1) {
        printf("Error: Stack overflow.\n");
        exit(1);
    }
    stack->top++;
    stack->data[stack->top] = value;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (stack->top < 0) {
        printf("Error: Stack underflow.\n");
        exit(1);
    }
    int value = stack->data[stack->top];
    stack->top--;
    return value;
}

// Function to display the current state of the stack
void displayStack(Stack* stack) {
    printf("Current state of the stack:\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

// Main function to test the stack operations
int main() {
    Stack* myStack = createStack();
    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);
    displayStack(myStack);
    int poppedValue = pop(myStack);
    printf("Popped value: %d\n", poppedValue);
    displayStack(myStack);
    return 0;
}