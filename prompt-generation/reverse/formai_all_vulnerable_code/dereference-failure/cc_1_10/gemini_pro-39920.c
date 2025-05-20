//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a stack
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

// A utility function to create a stack of given capacity
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// A utility function to push a value onto a stack
void push(struct Stack* stack, int value) {
    stack->array[++stack->top] = value;
}

// A utility function to pop a value from a stack
int pop(struct Stack* stack) {
    return stack->array[stack->top--];
}

// A utility function to print a stack
void printStack(struct Stack* stack) {
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

// The main function to solve the Tower of Hanoi problem
void towerOfHanoi(int n, struct Stack* from, struct Stack* to, struct Stack* aux) {
    if (n == 1) {
        push(to, pop(from));
        return;
    }

    towerOfHanoi(n - 1, from, aux, to);
    printf("Move disk %d from rod %d to rod %d\n", n, from->array[from->top], to->array[to->top]);
    push(to, pop(from));
    towerOfHanoi(n - 1, aux, to, from);
}

// Driver program to test the above functions
int main() {
    int n = 4; // The number of disks

    // Create three stacks of size n
    struct Stack* from = createStack(n);
    struct Stack* to = createStack(n);
    struct Stack* aux = createStack(n);

    // Push the disks onto the from stack in descending order
    for (int i = n; i >= 1; i--) {
        push(from, i);
    }

    // Print the initial state of the stacks
    printf("Initial state of the stacks:\n");
    printStack(from);
    printStack(to);
    printStack(aux);

    // Solve the Tower of Hanoi problem
    towerOfHanoi(n, from, to, aux);

    // Print the final state of the stacks
    printf("Final state of the stacks:\n");
    printStack(from);
    printStack(to);
    printStack(aux);

    return 0;
}