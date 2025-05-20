//GEMINI-pro DATASET v1.0 Category: Educational ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum number of elements in the stack
#define MAX_STACK_SIZE 100

// Define the stack structure
typedef struct {
    int *elements;
    int top;
} Stack;

// Create a new stack
Stack *create_stack() {
    Stack *stack = malloc(sizeof(Stack));
    stack->elements = malloc(sizeof(int) * MAX_STACK_SIZE);
    stack->top = -1;
    return stack;
}

// Push an element onto the stack
void push(Stack *stack, int element) {
    if (stack->top == MAX_STACK_SIZE - 1) {
        printf("Error: stack overflow\n");
        return;
    }
    stack->elements[++stack->top] = element;
}

// Pop an element from the stack
int pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Error: stack underflow\n");
        return -1;
    }
    return stack->elements[stack->top--];
}

// Check if the stack is empty
bool is_empty(Stack *stack) {
    return stack->top == -1;
}

// Print the stack
void print_stack(Stack *stack) {
    printf("Stack: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->elements[i]);
    }
    printf("\n");
}

// Reverse the stack using recursion
void reverse_stack(Stack *stack) {
    if (!is_empty(stack)) {
        int top_element = pop(stack);
        reverse_stack(stack);
        push(stack, top_element);
    }
}

// Driver function
int main() {
    // Create a stack
    Stack *stack = create_stack();

    // Push some elements onto the stack
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);

    // Print the stack
    print_stack(stack);

    // Reverse the stack
    reverse_stack(stack);

    // Print the stack
    print_stack(stack);

    // Free the stack
    free(stack->elements);
    free(stack);

    return 0;
}