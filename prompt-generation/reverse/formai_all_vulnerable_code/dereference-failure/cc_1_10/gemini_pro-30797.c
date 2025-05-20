//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a stack
struct Stack {
    int *arr;
    int top;
    int capacity;
};

// Function to create a stack of given capacity
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->arr = (int*)malloc(sizeof(int) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->arr[++stack->top] = data;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

// Function to perform the Tower of Hanoi
void towerOfHanoi(int n, struct Stack* from, struct Stack* to, struct Stack* aux) {
    if (n == 1) {
        push(to, pop(from));
        return;
    }
    towerOfHanoi(n - 1, from, aux, to);
    push(to, pop(from));
    towerOfHanoi(n - 1, aux, to, from);
}

// Function to print the contents of the stack
void printStack(struct Stack* stack) {
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

// Driver code
int main() {
    int n = 3;

    // Create three stacks of size n
    struct Stack* from = createStack(n);
    struct Stack* to = createStack(n);
    struct Stack* aux = createStack(n);

    // Push n elements onto the from stack
    for (int i = n; i >= 1; i--) {
        push(from, i);
    }

    // Print the contents of the stacks
    printf("Initial state:\n");
    printf("From: ");
    printStack(from);
    printf("To: ");
    printStack(to);
    printf("Aux: ");
    printStack(aux);

    // Perform the Tower of Hanoi
    towerOfHanoi(n, from, to, aux);

    // Print the contents of the stacks
    printf("Final state:\n");
    printf("From: ");
    printStack(from);
    printf("To: ");
    printStack(to);
    printf("Aux: ");
    printStack(aux);

    return 0;
}