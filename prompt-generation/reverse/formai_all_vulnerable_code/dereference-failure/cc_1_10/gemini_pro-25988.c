//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define NO_OF_TOWERS 3
#define NO_OF_DISKS 5

// Structure to represent a stack
typedef struct Stack {
    int top;
    int capacity;
    int *array;
} Stack;

// Function to create a stack of given capacity
Stack* createStack(int capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to push an element onto the stack
void push(Stack *stack, int item) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
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

// Function to perform the Tower of Hanoi move
void towerOfHanoi(int n, Stack *from, Stack *to, Stack *aux) {
    if (n == 1) {
        push(to, pop(from));
        return;
    }
    // Move n-1 disks from the 'from' tower to the 'aux' tower using 'to' as the intermediate tower
    towerOfHanoi(n - 1, from, aux, to);
    // Move the remaining disk from the 'from' tower to the 'to' tower
    push(to, pop(from));
    // Move n-1 disks from the 'aux' tower to the 'to' tower using 'from' as the intermediate tower
    towerOfHanoi(n - 1, aux, to, from);
}

// Main function
int main() {
    // Create three stacks
    Stack *from = createStack(NO_OF_DISKS);
    Stack *to = createStack(NO_OF_DISKS);
    Stack *aux = createStack(NO_OF_DISKS);

    // Push the disks onto the 'from' stack
    for (int i = NO_OF_DISKS; i >= 1; i--) {
        push(from, i);
    }

    // Print the initial state of the stacks
    printf("Initial state of the stacks:\n");
    printf("From: ");
    printStack(from);
    printf("To: ");
    printStack(to);
    printf("Aux: ");
    printStack(aux);

    // Perform the Tower of Hanoi move
    towerOfHanoi(NO_OF_DISKS, from, to, aux);

    // Print the final state of the stacks
    printf("\nFinal state of the stacks:\n");
    printf("From: ");
    printStack(from);
    printf("To: ");
    printStack(to);
    printf("Aux: ");
    printStack(aux);

    // Free the memory allocated to the stacks
    free(from->array);
    free(from);
    free(to->array);
    free(to);
    free(aux->array);
    free(aux);

    return 0;
}