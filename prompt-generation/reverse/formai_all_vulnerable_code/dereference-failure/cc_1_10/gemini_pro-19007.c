//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Global variables
int *stack;
int stack_size;
int stack_pointer;

// Function to push an element onto the stack
void push(int element) {
    if (stack_pointer == stack_size) {
        // Double the size of the stack
        stack_size *= 2;
        stack = (int *)realloc(stack, stack_size * sizeof(int));
    }
    stack[stack_pointer++] = element;
}

// Function to pop an element from the stack
int pop() {
    if (stack_pointer == 0) {
        // Stack is empty
        return -1;
    }
    return stack[--stack_pointer];
}

// Function to print the stack
void print_stack() {
    for (int i = 0; i < stack_pointer; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

// Main function
int main() {
    // Initialize the stack
    stack_size = 10;
    stack = (int *)malloc(stack_size * sizeof(int));
    stack_pointer = 0;

    // Push some elements onto the stack
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    // Print the stack
    printf("Stack: ");
    print_stack();

    // Pop some elements from the stack
    int popped_element = pop();
    printf("Popped element: %d\n", popped_element);
    popped_element = pop();
    printf("Popped element: %d\n", popped_element);

    // Print the stack again
    printf("Stack: ");
    print_stack();

    // Free the stack
    free(stack);

    return 0;
}