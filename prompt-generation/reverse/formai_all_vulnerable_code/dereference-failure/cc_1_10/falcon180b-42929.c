//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a node structure for linked lists
struct Node {
    int data;
    struct Node* next;
};

// Define a stack structure using linked lists
struct Stack {
    struct Node* top;
};

// Initialize an empty stack
void init(struct Stack* stack) {
    stack->top = NULL;
}

// Push an integer onto the stack
void push(struct Stack* stack, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
}

// Pop an integer from the stack
int pop(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Error: Stack is empty\n");
        exit(1);
    }
    int data = stack->top->data;
    struct Node* temp_node = stack->top;
    stack->top = stack->top->next;
    free(temp_node);
    return data;
}

// Print the current state of the stack
void print_stack(struct Stack* stack) {
    struct Node* current_node = stack->top;
    while (current_node!= NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Main function to demonstrate stack operations
int main() {
    struct Stack my_stack;
    init(&my_stack);

    push(&my_stack, 10);
    push(&my_stack, 20);
    push(&my_stack, 30);

    print_stack(&my_stack);

    int popped_data = pop(&my_stack);
    printf("Popped data: %d\n", popped_data);

    print_stack(&my_stack);

    return 0;
}