//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a node structure for linked lists
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define a stack structure using linked lists
typedef struct stack {
    Node* top;
} Stack;

// Create an empty stack
Stack* create_stack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

// Check if the stack is empty
bool is_empty(Stack* s) {
    return s->top == NULL;
}

// Push a value onto the stack
void push(Stack* s, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = s->top;
    s->top = new_node;
}

// Pop a value off the stack
int pop(Stack* s) {
    if (is_empty(s)) {
        printf("Stack is empty!\n");
        exit(1);
    }
    Node* temp = s->top;
    int value = temp->data;
    s->top = temp->next;
    free(temp);
    return value;
}

// Print the stack
void print_stack(Stack* s) {
    Node* curr = s->top;
    while (curr!= NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

// Main function to demonstrate stack operations
int main() {
    Stack* s = create_stack();
    push(s, 1);
    push(s, 2);
    push(s, 3);
    print_stack(s);
    int x = pop(s);
    print_stack(s);
    int y = pop(s);
    print_stack(s);
    int z = pop(s);
    print_stack(s);
    return 0;
}