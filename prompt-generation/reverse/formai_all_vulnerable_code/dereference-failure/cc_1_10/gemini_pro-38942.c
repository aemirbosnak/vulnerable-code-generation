//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: expert-level
#include <stdio.h>

// Structure to represent a stack
typedef struct Stack {
    int top;
    unsigned int capacity;
    int *array;
} Stack;

// Function to create a stack of given capacity
Stack* createStack(unsigned int capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to push an element onto the stack
void push(Stack *stack, int item) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack is full\n");
    } else {
        stack->array[++stack->top] = item;
    }
}

// Function to pop an element from the stack
int pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return stack->array[stack->top--];
    }
}

// Function to move n disks from one tower to another using a third tower
void towerOfHanoi(int n, Stack *source, Stack *destination, Stack *helper) {
    // Base case: if there is only one disk, move it directly to the destination tower
    if (n == 1) {
        push(destination, pop(source));
        return;
    }

    // Recursive case: move n - 1 disks from the source tower to the helper tower
    towerOfHanoi(n - 1, source, helper, destination);

    // Move the remaining disk from the source tower to the destination tower
    push(destination, pop(source));

    // Recursive case: move n - 1 disks from the helper tower to the destination tower
    towerOfHanoi(n - 1, helper, destination, source);
}

// Function to print the state of the towers
void printTowers(Stack *source, Stack *destination, Stack *helper) {
    printf("Source: ");
    for (int i = 0; i <= source->top; i++) {
        printf("%d ", source->array[i]);
    }
    printf("\n");

    printf("Destination: ");
    for (int i = 0; i <= destination->top; i++) {
        printf("%d ", destination->array[i]);
    }
    printf("\n");

    printf("Helper: ");
    for (int i = 0; i <= helper->top; i++) {
        printf("%d ", helper->array[i]);
    }
    printf("\n");
}

int main() {
    // Create three stacks to represent the towers
    Stack *source = createStack(3);
    Stack *destination = createStack(3);
    Stack *helper = createStack(3);

    // Push the disks onto the source tower
    for (int i = 3; i >= 1; i--) {
        push(source, i);
    }

    // Print the initial state of the towers
    printTowers(source, destination, helper);

    // Move the disks from the source tower to the destination tower
    towerOfHanoi(3, source, destination, helper);

    // Print the final state of the towers
    printTowers(source, destination, helper);

    // Free the memory allocated to the stacks
    free(source);
    free(destination);
    free(helper);

    return 0;
}