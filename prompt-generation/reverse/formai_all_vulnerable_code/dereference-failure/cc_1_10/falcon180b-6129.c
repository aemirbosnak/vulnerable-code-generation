//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the stack
#define MAX_SIZE 100

// Define the Stack structure
typedef struct Stack {
    int top;
    int *elements;
} Stack;

// Initialize the stack
void initialize(Stack *stack) {
    stack->top = -1;
    stack->elements = (int *) malloc(MAX_SIZE * sizeof(int));
}

// Check if the stack is empty
int is_empty(Stack *stack) {
    return stack->top == -1;
}

// Check if the stack is full
int is_full(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Push an element onto the stack
void push(Stack *stack, int element) {
    if (is_full(stack)) {
        printf("Stack is full! Cannot push %d.\n", element);
        return;
    }
    stack->top++;
    stack->elements[stack->top] = element;
}

// Pop an element from the stack
int pop(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is empty! Cannot pop.\n");
        return -1;
    }
    int element = stack->elements[stack->top];
    stack->top--;
    return element;
}

// Print the stack
void print_stack(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->elements[i]);
    }
    printf("\n");
}

int main() {
    Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);

    print_stack(&stack);

    int popped_element = pop(&stack);
    printf("Popped element: %d\n", popped_element);

    print_stack(&stack);

    return 0;
}