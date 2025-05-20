//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a stack
typedef struct Stack {
    int top;
    unsigned capacity;
    int *array;
} Stack;

// Function to create a stack of given capacity
Stack *createStack(unsigned capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to push an item to the stack
void push(Stack *stack, int item) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack is full\n");
        return;
    }
    stack->array[++stack->top] = item;
}

// Function to pop an item from the stack
int pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->array[stack->top--];
}

// Function to print the contents of the stack
void printStack(Stack *stack) {
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

// Function to move the top disk from one stack to another
void moveDisk(Stack *from, Stack *to) {
    int disk = pop(from);
    push(to, disk);
}

// Function to perform the Tower of Hanoi algorithm
void towerOfHanoi(int n, Stack *from, Stack *to, Stack *aux) {
    // Base case: When there is only one disk
    if (n == 1) {
        moveDisk(from, to);
        return;
    }

    // Recursively move the top n-1 disks from the `from` stack to the `aux` stack
    towerOfHanoi(n - 1, from, aux, to);

    // Move the remaining disk from the `from` stack to the `to` stack
    moveDisk(from, to);

    // Recursively move the n-1 disks from the `aux` stack to the `to` stack
    towerOfHanoi(n - 1, aux, to, from);
}

// Main function
int main() {
    // Create three stacks
    Stack *from = createStack(3);
    Stack *to = createStack(3);
    Stack *aux = createStack(3);

    // Push 3 disks onto the `from` stack
    for (int i = 3; i >= 1; i--) {
        push(from, i);
    }

    // Print the initial state of the stacks
    printf("Initial state:\n");
    printStack(from);
    printStack(to);
    printStack(aux);

    // Perform the Tower of Hanoi algorithm
    towerOfHanoi(3, from, to, aux);

    // Print the final state of the stacks
    printf("Final state:\n");
    printStack(from);
    printStack(to);
    printStack(aux);

    return 0;
}