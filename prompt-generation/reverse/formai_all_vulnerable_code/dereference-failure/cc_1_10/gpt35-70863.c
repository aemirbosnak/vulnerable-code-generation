//FormAI DATASET v1.0 Category: Data structures visualization ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100 // Maximum size of stack

struct Stack {
    int* data; // Pointer to stack data
    int top; // Index of top element in stack
};

// Function to initialize the stack
void initStack(struct Stack* S) {
    S->data = (int*)malloc(sizeof(int) * MAX_STACK_SIZE); // Allocate memory for stack
    S->top = -1; // Initialize top index to -1 to indicate empty stack
}

// Function to free memory used by stack
void freeStack(struct Stack* S) {
    free(S->data); // Free memory allocated for stack
}

// Function to check if stack is empty
int isEmpty(struct Stack* S) {
    return S->top == -1; // Return true if top index is -1, indicating empty stack
}

// Function to check if stack is full
int isFull(struct Stack* S) {
    return S->top == MAX_STACK_SIZE - 1; // Return true if top index is at maximum size, indicating full stack
}

// Function to push an element onto the top of the stack
void push(struct Stack* S, int val) {
    if (isFull(S)) { // Check if stack is full before pushing
        printf("Error: Stack is full\n");
        return;
    }
    S->data[++S->top] = val; // Increment top index and assign new value
}

// Function to pop the top element from the stack
int pop(struct Stack* S) {
    if (isEmpty(S)) { // Check if stack is empty before popping
        printf("Error: Stack is empty\n");
        return 0;
    }
    return S->data[S->top--]; // Return top value and decrement top index
}

// Function to print the current state of the stack
void printStack(struct Stack* S) {
    if (isEmpty(S)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    for (int i = 0; i <= S->top; i++) {
        printf("%d ", S->data[i]); // Print each element in the stack
    }
    printf("\n");
}

int main() {
    struct Stack myStack; // Declare stack variable
    initStack(&myStack); // Initialize stack

    // Push and pop elements onto the stack
    push(&myStack, 1);
    push(&myStack, 2);
    push(&myStack, 3);
    printStack(&myStack);

    int popped = pop(&myStack);
    printf("Popped element: %d\n", popped);
    printStack(&myStack);

    freeStack(&myStack); // Free memory used by stack
    return 0;
}