//Falcon-180B DATASET v1.0 Category: Memory management ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Node structure for linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function prototypes
void push(Node** top_ref, int new_data);
int pop(Node** top_ref);
int peek(Node* top);
int is_empty(Node* top);
void print_list(Node* node);

int main() {
    Node* stack = NULL; // Initialize empty stack

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);

    printf("Stack elements are: ");
    print_list(stack);

    printf("\nPopped element is: %d", pop(&stack));
    printf("\nStack elements after popping an element are: ");
    print_list(stack);

    printf("\nPeeked element is: %d", peek(stack));

    return 0;
}

// Function to push an element onto the stack
void push(Node** top_ref, int new_data) {
    Node* new_node = (Node*) malloc(sizeof(Node)); // Dynamically allocate memory for new node

    if (new_node == NULL) {
        printf("Stack overflow \n");
        exit(0);
    }

    new_node->data = new_data;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
}

// Function to pop an element from the stack
int pop(Node** top_ref) {
    char ch;
    Node* top = *top_ref; // Save the top node

    if (is_empty(top)) {
        printf("Stack underflow \n");
        exit(0);
    }

    printf("Popped element is: %d", top->data);

    free(top); // Free the memory allocated for the top node

    top = top->next;
    (*top_ref) = top;

    return top->data;
}

// Function to check if the stack is empty
int is_empty(Node* top) {
    if (top == NULL)
        return 1;
    else
        return 0;
}

// Function to peek at the top element of the stack
int peek(Node* top) {
    if (is_empty(top)) {
        printf("Stack is empty \n");
        exit(0);
    }

    return top->data;
}

// Function to print the elements in the stack
void print_list(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}