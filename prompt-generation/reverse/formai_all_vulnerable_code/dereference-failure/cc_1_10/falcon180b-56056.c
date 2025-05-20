//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the stack
#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} node;

// Define the stack data structure
typedef struct {
    node* top;
    int size;
} stack;

// Create a new stack
stack* create_stack() {
    stack* new_stack = (stack*) malloc(sizeof(stack));
    new_stack->top = NULL;
    new_stack->size = 0;
    return new_stack;
}

// Push an integer onto the stack
void push(stack* stack, int value) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->data = value;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}

// Pop an integer off the stack
int pop(stack* stack) {
    if (stack->top == NULL) {
        printf("Error: Stack is empty.\n");
        exit(1);
    }
    int value = stack->top->data;
    node* temp_node = stack->top;
    stack->top = stack->top->next;
    free(temp_node);
    stack->size--;
    return value;
}

// Print the top element of the stack
void peek(stack* stack) {
    if (stack->top == NULL) {
        printf("Error: Stack is empty.\n");
        exit(1);
    }
    printf("Top element: %d\n", stack->top->data);
}

// Check if the stack is empty
int is_empty(stack* stack) {
    return (stack->top == NULL);
}

// Get the size of the stack
int get_size(stack* stack) {
    return stack->size;
}

// Free memory used by the stack
void destroy_stack(stack* stack) {
    while (!is_empty(stack)) {
        pop(stack);
    }
    free(stack);
}

// Example usage
int main() {
    stack* my_stack = create_stack();
    push(my_stack, 10);
    push(my_stack, 20);
    push(my_stack, 30);
    printf("Size of stack: %d\n", get_size(my_stack));
    peek(my_stack);
    pop(my_stack);
    pop(my_stack);
    printf("Size of stack: %d\n", get_size(my_stack));
    destroy_stack(my_stack);
    return 0;
}