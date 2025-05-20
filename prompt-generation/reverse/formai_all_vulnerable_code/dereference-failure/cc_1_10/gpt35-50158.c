//FormAI DATASET v1.0 Category: Memory management ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of integers that can be stored in the stack
#define MAX_SIZE 10

// Custom struct to store integers
typedef struct int_stack {
    int* stack;
    int top;
} int_stack;

// Function to allocate memory for the integer stack
void create_stack(int_stack* stack) {
    stack->stack = (int*)malloc(sizeof(int) * MAX_SIZE);
    stack->top = -1;
}

// Function to add an integer to the stack
void push(int_stack* stack, int data) {
    if (stack->top < MAX_SIZE - 1) {
        stack->top++;
        stack->stack[stack->top] = data;
    }
    else {
        printf("Stack Overflow!\n");
    }
}

// Function to remove an integer from the stack
int pop(int_stack* stack) {
    if (stack->top > -1) {
        int data = stack->stack[stack->top];
        stack->top--;
        return data;
    }
    else {
        printf("Stack Underflow!\n");
        return -999;
    }
}

// Function to print the integer stack
void print_stack(int_stack* stack) {
    printf("Stack: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->stack[i]);
    }
    printf("\n");
}

int main() {
    int_stack stack;
    create_stack(&stack);

    // Push some integers onto the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);

    // Print the stack
    print_stack(&stack);

    // Pop two integers from the stack
    pop(&stack);
    pop(&stack);

    // Print the stack again
    print_stack(&stack);

    // Deallocate the memory allocated for the stack
    free(stack.stack);

    return 0;
}