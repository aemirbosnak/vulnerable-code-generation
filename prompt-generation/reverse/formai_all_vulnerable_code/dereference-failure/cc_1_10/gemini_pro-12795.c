//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a stack
typedef struct Stack {
    int top;
    unsigned capacity;
    int* array;
} Stack;

// Function to create a stack of given capacity
Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to push an item to the stack
void push(Stack* stack, int item) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack is full\n");
        return;
    }
    stack->array[++stack->top] = item;
}

// Function to pop an item from the stack
int pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->array[stack->top--];
}

// Function to print the contents of the stack
void printStack(Stack* stack) {
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

// Function to perform the Tower of Hanoi moves
void towerOfHanoi(int n, Stack* from, Stack* to, Stack* aux) {
    if (n == 1) {
        push(to, pop(from));
        return;
    }
    towerOfHanoi(n - 1, from, aux, to);
    push(to, pop(from));
    towerOfHanoi(n - 1, aux, to, from);
}

// Main function to test the program
int main() {
    int n = 3;
    Stack* from = createStack(n);
    Stack* to = createStack(n);
    Stack* aux = createStack(n);

    // Push the initial disks onto the 'from' stack
    for (int i = n; i >= 1; i--) {
        push(from, i);
    }

    // Print the initial state of the stacks
    printf("Initial state of the stacks:\n");
    printStack(from);
    printStack(to);
    printStack(aux);

    // Perform the Tower of Hanoi moves
    towerOfHanoi(n, from, to, aux);

    // Print the final state of the stacks
    printf("\nFinal state of the stacks:\n");
    printStack(from);
    printStack(to);
    printStack(aux);

    return 0;
}