//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a stack
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

// Function to create a stack of given capacity
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to push an element into a stack
void push(struct Stack* stack, int item) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack is full\n");
        return;
    }
    stack->array[++stack->top] = item;
}

// Function to pop an element from a stack
int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->array[stack->top--];
}

// Function to move a disk from one stack to another
void moveDisk(struct Stack* from, struct Stack* to) {
    int disk = pop(from);
    push(to, disk);
}

// Function to perform the Tower of Hanoi puzzle
void towerOfHanoi(int numDisks, struct Stack* from, struct Stack* to, struct Stack* aux) {
    if (numDisks == 1) {
        moveDisk(from, to);
        return;
    }
    towerOfHanoi(numDisks - 1, from, aux, to);
    moveDisk(from, to);
    towerOfHanoi(numDisks - 1, aux, to, from);
}

// Function to print the contents of a stack
void printStack(struct Stack* stack) {
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

// Driver program to test the Tower of Hanoi puzzle
int main() {
    int numDisks = 4;

    // Create three stacks
    struct Stack* from = createStack(numDisks);
    struct Stack* to = createStack(numDisks);
    struct Stack* aux = createStack(numDisks);

    // Initialize the from stack with disks
    for (int i = numDisks; i >= 1; i--) {
        push(from, i);
    }

    // Print the initial state of the stacks
    printf("Initial state of the stacks:\n");
    printStack(from);
    printStack(to);
    printStack(aux);

    // Perform the Tower of Hanoi puzzle
    towerOfHanoi(numDisks, from, to, aux);

    // Print the final state of the stacks
    printf("Final state of the stacks:\n");
    printStack(from);
    printStack(to);
    printStack(aux);

    return 0;
}