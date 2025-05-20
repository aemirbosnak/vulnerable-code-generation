//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the stack
#define MAX_SIZE 100

// Stack node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Stack structure
typedef struct {
    Node* top;
} Stack;

// Function to create a new stack
Stack* create_stack() {
    Stack* new_stack = (Stack*) malloc(sizeof(Stack));
    if (new_stack == NULL) {
        printf("Error: Stack creation failed.\n");
        exit(1);
    }
    new_stack->top = NULL;
    return new_stack;
}

// Function to push an element onto the stack
void push(Stack* stack, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Stack overflow.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Error: Stack underflow.\n");
        exit(1);
    }
    int data = stack->top->data;
    Node* temp_node = stack->top;
    stack->top = stack->top->next;
    free(temp_node);
    return data;
}

// Function to print the stack
void print_stack(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack: ");
    Node* current_node = stack->top;
    while (current_node!= NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Create a new stack
    Stack* my_stack = create_stack();

    // Push some elements onto the stack
    push(my_stack, 10);
    push(my_stack, 20);
    push(my_stack, 30);

    // Print the stack
    print_stack(my_stack);

    // Pop an element from the stack
    int popped_element = pop(my_stack);
    printf("Popped element: %d\n", popped_element);

    // Print the stack again
    print_stack(my_stack);

    // Free the stack memory
    free(my_stack);

    return 0;
}