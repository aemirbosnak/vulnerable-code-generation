//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the size of the stack
#define STACK_SIZE 100

// Define the stack structure
typedef struct {
    int *stack;
    int top;
    int size;
} Stack;

// Create a new stack
Stack *create_stack() {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    stack->stack = (int *) malloc(STACK_SIZE * sizeof(int));
    stack->top = -1;
    stack->size = STACK_SIZE;
    return stack;
}

// Push an element onto the stack
void push(Stack *stack, int element) {
    if (stack->top >= stack->size - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->top++;
    stack->stack[stack->top] = element;
}

// Pop an element from the stack
int pop(Stack *stack) {
    if (stack->top < 0) {
        printf("Stack underflow\n");
        return -1;
    }
    int element = stack->stack[stack->top];
    stack->top--;
    return element;
}

// Display the contents of the stack
void display(Stack *stack) {
    if (stack->top < 0) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->stack[i]);
    }
    printf("\n");
}

// Main function
int main() {
    Stack *stack = create_stack();

    // Push elements onto the stack
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    // Display the contents of the stack
    display(stack);

    // Pop elements from the stack
    int element = pop(stack);
    printf("Popped element: %d\n", element);
    display(stack);

    return 0;
}