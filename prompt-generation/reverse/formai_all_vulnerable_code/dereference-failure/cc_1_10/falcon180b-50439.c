//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a node in the linked list
typedef struct node {
    int data;
    struct node *next;
} Node;

// Define a structure for a stack
typedef struct stack {
    Node *top;
    int size;
} Stack;

// Function to create a new node
Node *create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Unable to allocate memory for new node.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to push a node onto the stack
void push(Stack *stack, int data) {
    Node *new_node = create_node(data);
    if (stack->top == NULL) {
        stack->top = new_node;
    } else {
        new_node->next = stack->top;
        stack->top = new_node;
    }
    stack->size++;
}

// Function to pop a node from the stack
int pop(Stack *stack) {
    if (stack->top == NULL) {
        printf("Error: Stack is empty.\n");
        exit(1);
    }
    Node *temp_node = stack->top;
    int popped_data = temp_node->data;
    stack->top = temp_node->next;
    free(temp_node);
    stack->size--;
    return popped_data;
}

// Function to print the stack
void print_stack(Stack *stack) {
    if (stack->top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack:\n");
    Node *temp_node = stack->top;
    while (temp_node!= NULL) {
        printf("%d ", temp_node->data);
        temp_node = temp_node->next;
    }
    printf("\n");
}

// Main function to test the stack implementation
int main() {
    Stack stack;
    stack.top = NULL;
    stack.size = 0;

    // Test push function
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    printf("Stack after pushing 1, 2, and 3:\n");
    print_stack(&stack);

    // Test pop function
    int popped_data = pop(&stack);
    printf("Popped data: %d\n", popped_data);
    printf("Stack after popping:\n");
    print_stack(&stack);

    // Test push function again
    push(&stack, 4);
    printf("Stack after pushing 4:\n");
    print_stack(&stack);

    // Test pop function again
    popped_data = pop(&stack);
    printf("Popped data: %d\n", popped_data);
    printf("Stack after popping:\n");
    print_stack(&stack);

    return 0;
}