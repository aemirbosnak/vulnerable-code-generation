//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define the node structure for our linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the stack structure using linked lists
typedef struct stack {
    Node* top;
} Stack;

// Function to create a new node with the given data
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

// Function to push an element onto the stack
void push(Stack* stack, int data) {
    Node* new_node = create_node(data);
    new_node->next = stack->top;
    stack->top = new_node;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    int data = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

// Function to print the elements in the stack
void print_stack(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    Node* temp = stack->top;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to reverse the elements in the stack
void reverse_stack(Stack* stack) {
    Node* prev = NULL;
    Node* current = stack->top;
    while (current!= NULL) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    stack->top = prev;
}

int main() {
    Stack stack;
    stack.top = NULL;

    // Test pushing elements onto the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // Test popping elements from the stack
    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));

    // Test printing the elements in the stack
    print_stack(&stack);

    // Test reversing the elements in the stack
    reverse_stack(&stack);

    // Test printing the elements in the stack after reversal
    print_stack(&stack);

    return 0;
}