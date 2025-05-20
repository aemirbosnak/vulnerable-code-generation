//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a stack
typedef struct Stack {
    int top;
    unsigned int capacity;
    int* array;
} Stack;

// Function to create a stack of given capacity
Stack* createStack(unsigned int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to push an element into the stack
void push(Stack* stack, int item) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->array[stack->top--];
}

// Function to print the contents of the stack
void printStack(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

// Function to solve the Tower of Hanoi problem
void towerOfHanoi(int n, Stack* from, Stack* to, Stack* aux) {
    // Base case: Only one disk
    if (n == 1) {
        push(to, pop(from));
        return;
    }

    // Move n-1 disks from the 'from' stack to the 'aux' stack
    towerOfHanoi(n - 1, from, aux, to);

    // Move the largest disk from the 'from' stack to the 'to' stack
    push(to, pop(from));

    // Move n-1 disks from the 'aux' stack to the 'to' stack
    towerOfHanoi(n - 1, aux, to, from);
}

// Main function to test the Tower of Hanoi program
int main() {
    int n = 4; // Number of disks
    Stack* from = createStack(n);
    Stack* to = createStack(n);
    Stack* aux = createStack(n);

    // Push the disks onto the 'from' stack
    for (int i = n; i >= 1; i--) {
        push(from, i);
    }

    printf("Initial state of the 'from' stack:\n");
    printStack(from);

    // Solve the Tower of Hanoi problem
    towerOfHanoi(n, from, to, aux);

    printf("\nFinal state of the 'to' stack:\n");
    printStack(to);

    return 0;
}