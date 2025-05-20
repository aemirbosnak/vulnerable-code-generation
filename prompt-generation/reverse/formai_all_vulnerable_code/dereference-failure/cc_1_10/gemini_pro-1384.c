//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a stack
struct Stack {
    int top;
    int capacity;
    int *array;
};

// Function to create a stack of given capacity
struct Stack* createStack(int capacity) {
    struct Stack *stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to push an element on the stack
void push(struct Stack *stack, int item) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->array[stack->top--];
}

// Function to print the contents of the stack
void printStack(struct Stack *stack) {
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

// Function to perform the Tower of Hanoi problem
void towerOfHanoi(int n, struct Stack *source, struct Stack *destination, struct Stack *auxiliary) {
    // If there are no more disks to move, return
    if (n == 0) {
        return;
    }

    // Move the top disk from the source stack to the auxiliary stack
    push(auxiliary, pop(source));

    // Recursively call the towerOfHanoi function to move the remaining disks from the source stack to the destination stack using the auxiliary stack
    towerOfHanoi(n - 1, source, destination, auxiliary);

    // Move the top disk from the auxiliary stack to the destination stack
    push(destination, pop(auxiliary));

    // Recursively call the towerOfHanoi function to move the remaining disks from the auxiliary stack to the source stack using the destination stack
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

// Main function
int main() {
    // Create three stacks to represent the source, destination, and auxiliary stacks
    struct Stack *source = createStack(10);
    struct Stack *destination = createStack(10);
    struct Stack *auxiliary = createStack(10);

    // Push the disks onto the source stack in ascending order
    for (int i = 1; i <= 4; i++) {
        push(source, i);
    }

    // Print the contents of the source stack
    printf("Source Stack: ");
    printStack(source);

    // Perform the Tower of Hanoi problem
    towerOfHanoi(4, source, destination, auxiliary);

    // Print the contents of the destination stack
    printf("Destination Stack: ");
    printStack(destination);

    return 0;
}