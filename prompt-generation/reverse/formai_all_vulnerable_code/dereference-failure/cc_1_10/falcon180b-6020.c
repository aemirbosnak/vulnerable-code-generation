//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node structure for our linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define a stack structure using linked lists
typedef struct stack {
    Node* top;
} Stack;

// Initialize an empty stack
void init_stack(Stack* s) {
    s->top = NULL;
}

// Push a value onto the stack
void push(Stack* s, int value) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: could not allocate memory for new node\n");
        exit(1);
    }
    new_node->data = value;
    new_node->next = s->top;
    s->top = new_node;
}

// Pop a value off the stack
int pop(Stack* s) {
    if (s->top == NULL) {
        printf("Error: stack is empty\n");
        exit(1);
    }
    int value = s->top->data;
    Node* temp = s->top;
    s->top = s->top->next;
    free(temp);
    return value;
}

// Print the current state of the stack
void print_stack(Stack* s) {
    Node* current = s->top;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function to demonstrate the stack operations
int main() {
    Stack s;
    init_stack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    print_stack(&s);

    int value = pop(&s);
    printf("Popped value: %d\n", value);

    print_stack(&s);

    value = pop(&s);
    printf("Popped value: %d\n", value);

    print_stack(&s);

    value = pop(&s);
    printf("Popped value: %d\n", value);

    print_stack(&s);

    return 0;
}