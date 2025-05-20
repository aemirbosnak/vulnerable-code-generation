//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Node structure for linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Stack structure using linked list
typedef struct stack {
    Node* top;
} Stack;

// Function to create a new node with given data
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
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
        exit(0);
    }
    int data = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

// Function to display the elements in the stack
void display(Stack* stack) {
    Node* temp = stack->top;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the stack operations
int main() {
    Stack stack;
    stack.top = NULL;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    display(&stack);

    int popped_data = pop(&stack);
    printf("Popped element: %d\n", popped_data);

    display(&stack);

    return 0;
}