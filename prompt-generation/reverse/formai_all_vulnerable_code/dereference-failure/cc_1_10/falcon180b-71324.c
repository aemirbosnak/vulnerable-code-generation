//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Node structure definition
typedef struct node {
    int data;
    struct node* next;
} Node;

// Stack structure definition
typedef struct stack {
    Node* top;
} Stack;

// Function to create a new node with given data
Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to push a node onto the stack
void push(Stack* stack, int data) {
    Node* new_node = create_node(data);
    new_node->next = stack->top;
    stack->top = new_node;
}

// Function to pop a node from the stack
int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack underflow\n");
        exit(0);
    }
    Node* temp_node = stack->top;
    int popped_data = temp_node->data;
    stack->top = temp_node->next;
    free(temp_node);
    return popped_data;
}

// Function to display the stack
void display(Stack stack) {
    Node* temp_node = stack.top;
    while (temp_node!= NULL) {
        printf("%d ", temp_node->data);
        temp_node = temp_node->next;
    }
    printf("\n");
}

// Main function
int main() {
    Stack stack;
    stack.top = NULL;

    // Push elements onto the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);

    // Display the stack
    printf("Stack: ");
    display(stack);

    // Pop elements from the stack
    int popped_element1 = pop(&stack);
    int popped_element2 = pop(&stack);

    // Display the stack after popping elements
    printf("Stack after popping 2 elements: ");
    display(stack);

    return 0;
}