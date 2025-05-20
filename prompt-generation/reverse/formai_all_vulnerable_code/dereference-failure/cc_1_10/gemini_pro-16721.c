//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a stack
typedef struct Stack {
    int data;
    struct Stack *next;
} Stack;

// Function to create a new stack
Stack *createStack() {
    Stack *newStack = (Stack *)malloc(sizeof(Stack));
    newStack->data = 0;
    newStack->next = NULL;
    return newStack;
}

// Function to push an element onto the stack
void push(Stack **stack, int data) {
    Stack *newElement = (Stack *)malloc(sizeof(Stack));
    newElement->data = data;
    newElement->next = *stack;
    *stack = newElement;
}

// Function to pop an element from the stack
int pop(Stack **stack) {
    int poppedElement = (*stack)->data;
    *stack = (*stack)->next;
    return poppedElement;
}

// Function to perform the Tower of Hanoi algorithm
void towerOfHanoi(int numDisks, Stack **source, Stack **destination, Stack **auxiliary) {
    // Base case: if there is only one disk, move it to the destination
    if (numDisks == 1) {
        push(destination, pop(source));
        return;
    }
    // Recursive case:
    // 1. Move the top n-1 disks from the source to the auxiliary tower
    towerOfHanoi(numDisks - 1, source, auxiliary, destination);
    // 2. Move the remaining disk from the source to the destination
    push(destination, pop(source));
    // 3. Move the n-1 disks from the auxiliary tower to the destination
    towerOfHanoi(numDisks - 1, auxiliary, destination, source);
}

// Function to print the contents of the stack
void printStack(Stack *stack) {
    while (stack != NULL) {
        printf("%d ", stack->data);
        stack = stack->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Initialize the stacks
    Stack *source = createStack();
    Stack *destination = createStack();
    Stack *auxiliary = createStack();

    // Push the disks onto the source stack in descending order
    int numDisks;
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);
    for (int i = numDisks; i >= 1; i--) {
        push(&source, i);
    }

    // Perform the Tower of Hanoi algorithm
    towerOfHanoi(numDisks, &source, &destination, &auxiliary);

    // Print the contents of the destination stack
    printf("The contents of the destination stack are: ");
    printStack(destination);

    return 0;
}