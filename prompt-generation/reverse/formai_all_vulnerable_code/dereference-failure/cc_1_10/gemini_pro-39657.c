//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a stack
struct Stack {
    int top;
    int capacity;
    int* array;
};

// Function to create a stack of given capacity
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int item) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->array[stack->top--];
}

// Function to perform the Tower of Hanoi problem
void towerOfHanoi(int n, struct Stack* from, struct Stack* to, struct Stack* aux) {
    // Base case: only one disk to move
    if (n == 1) {
        push(to, pop(from));
        return;
    }
    
    // Move n-1 disks from the 'from' stack to the 'aux' stack
    towerOfHanoi(n-1, from, aux, to);
    
    // Move the largest disk from the 'from' stack to the 'to' stack
    push(to, pop(from));
    
    // Move n-1 disks from the 'aux' stack to the 'to' stack
    towerOfHanoi(n-1, aux, to, from);
}

// Main function
int main() {
    // Create three stacks of capacity 3
    struct Stack* from = createStack(3);
    struct Stack* to = createStack(3);
    struct Stack* aux = createStack(3);
    
    // Push the disks onto the 'from' stack
    for (int i = 3; i >= 1; i--) {
        push(from, i);
    }
    
    // Perform the Tower of Hanoi problem
    towerOfHanoi(3, from, to, aux);
    
    // Print the disks on the 'to' stack
    printf("The disks on the 'to' stack are:\n");
    while (to->top != -1) {
        printf("%d\n", pop(to));
    }
    
    return 0;
}