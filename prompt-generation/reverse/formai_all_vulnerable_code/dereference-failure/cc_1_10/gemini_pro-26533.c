//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100
#define NUM_TOWERS 3

// Cyberpunk-themed stack data structure
typedef struct cyberstack {
    int *data;
    int top;
    int size;
} cyberstack;

// Function to initialize a stack
cyberstack *init_stack(int size) {
    cyberstack *stack = malloc(sizeof(cyberstack));
    stack->data = malloc(sizeof(int) * size);
    stack->top = -1;
    stack->size = size;
    return stack;
}

// Function to push an element onto the stack
void push(cyberstack *stack, int element) {
    if (stack->top == stack->size - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack->data[++stack->top] = element;
}

// Function to pop an element from the stack
int pop(cyberstack *stack) {
    if (stack->top == -1) {
        printf("Stack underflow!\n");
        return -1;
    }
    return stack->data[stack->top--];
}

// Function to print the stack
void print_stack(cyberstack *stack) {
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

// Function to perform the Tower of Hanoi algorithm
void tower_of_hanoi(cyberstack *from, cyberstack *to, cyberstack *aux, int n) {
    if (n == 1) {
        push(to, pop(from));
        return;
    }
    tower_of_hanoi(from, aux, to, n - 1);
    push(to, pop(from));
    tower_of_hanoi(aux, to, from, n - 1);
}

// Main function
int main() {
    // Initialize the towers
    cyberstack *tower1 = init_stack(STACK_SIZE);
    cyberstack *tower2 = init_stack(STACK_SIZE);
    cyberstack *tower3 = init_stack(STACK_SIZE);

    // Push the disks onto the first tower
    for (int i = NUM_TOWERS; i >= 1; i--) {
        push(tower1, i);
    }

    // Perform the Tower of Hanoi algorithm
    tower_of_hanoi(tower1, tower3, tower2, NUM_TOWERS);

    // Print the final configuration of the towers
    printf("Tower 1: ");
    print_stack(tower1);
    printf("Tower 2: ");
    print_stack(tower2);
    printf("Tower 3: ");
    print_stack(tower3);

    return 0;
}