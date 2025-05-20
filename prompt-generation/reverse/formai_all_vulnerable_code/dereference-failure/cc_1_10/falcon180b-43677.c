//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure of a node in the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the structure of a stack
typedef struct stack {
    Node* top;
} Stack;

// Function to initialize the stack
void init(Stack* s) {
    s->top = NULL;
}

// Function to check if the stack is empty
bool is_empty(Stack* s) {
    return s->top == NULL;
}

// Function to push an element onto the stack
void push(Stack* s, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = s->top;
    s->top = new_node;
}

// Function to pop an element from the stack
int pop(Stack* s) {
    if (is_empty(s)) {
        printf("Stack is empty\n");
        exit(0);
    }
    Node* temp = s->top;
    s->top = s->top->next;
    int data = temp->data;
    free(temp);
    return data;
}

// Function to print the elements of the stack
void print_stack(Stack* s) {
    if (is_empty(s)) {
        printf("Stack is empty\n");
        return;
    }
    Node* temp = s->top;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the stack implementation
int main() {
    Stack s;
    init(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Stack after pushing 10, 20, 30:\n");
    print_stack(&s);

    int popped_data = pop(&s);
    printf("Popped element: %d\n", popped_data);

    printf("Stack after popping an element:\n");
    print_stack(&s);

    popped_data = pop(&s);
    printf("Popped element: %d\n", popped_data);

    printf("Stack after popping another element:\n");
    print_stack(&s);

    popped_data = pop(&s);
    printf("Popped element: %d\n", popped_data);

    printf("Stack after popping all elements:\n");
    print_stack(&s);

    return 0;
}