//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// Define the maximum size of the stack
#define MAX_STACK_SIZE 100

// Define the structure of a stack
typedef struct stack {
    int top;
    int *stack_array;
} Stack;

// Function to initialize the stack
void init_stack(Stack *stack) {
    stack->top = -1;
    stack->stack_array = (int *) malloc(MAX_STACK_SIZE * sizeof(int));
}

// Function to push an element onto the stack
void push(Stack *stack, int element) {
    if (stack->top >= MAX_STACK_SIZE - 1) {
        printf("Stack is full!\n");
        return;
    }
    stack->top++;
    stack->stack_array[stack->top] = element;
}

// Function to pop an element from the stack
int pop(Stack *stack) {
    if (stack->top < 0) {
        printf("Stack is empty!\n");
        return -1;
    }
    int element = stack->stack_array[stack->top];
    stack->top--;
    return element;
}

// Function to display the contents of the stack
void display_stack(Stack *stack) {
    if (stack->top < 0) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack contents:\n");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d\n", stack->stack_array[i]);
    }
}

// Main function to test the stack implementation
int main() {
    Stack stack;
    init_stack(&stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    display_stack(&stack);
    int element = pop(&stack);
    printf("Popped element: %d\n", element);
    display_stack(&stack);
    return 0;
}