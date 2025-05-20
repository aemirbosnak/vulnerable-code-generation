//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the stack
#define STACK_SIZE 1024

// Define the stack structure
typedef struct stack {
    int *data;
    int top;
} stack;

// Initialize the stack
void init_stack(stack *s) {
    s->data = malloc(STACK_SIZE * sizeof(int));
    s->top = -1;
}

// Push an element onto the stack
void push(stack *s, int data) {
    if (s->top == STACK_SIZE - 1) {
        printf("Stack overflow!\n");
        return;
    }
    s->data[++s->top] = data;
}

// Pop an element from the stack
int pop(stack *s) {
    if (s->top == -1) {
        printf("Stack underflow!\n");
        return -1;
    }
    return s->data[s->top--];
}

// Print the stack
void print_stack(stack *s) {
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

// Free the stack
void free_stack(stack *s) {
    free(s->data);
}

// Main function
int main() {
    // Create a stack
    stack s;
    init_stack(&s);

    // Push some elements onto the stack
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);

    // Print the stack
    print_stack(&s);

    // Pop some elements from the stack
    int popped_element = pop(&s);
    printf("Popped element: %d\n", popped_element);

    popped_element = pop(&s);
    printf("Popped element: %d\n", popped_element);

    // Print the stack
    print_stack(&s);

    // Free the stack
    free_stack(&s);

    return 0;
}