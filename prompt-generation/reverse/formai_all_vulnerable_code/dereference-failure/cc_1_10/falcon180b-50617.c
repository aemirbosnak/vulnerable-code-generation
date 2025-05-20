//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the stack
#define MAX_SIZE 100

// Define the node structure for the stack
typedef struct node {
    int data;
    struct node *next;
} Node;

// Initialize an empty stack
void init(Node **stack) {
    (*stack) = NULL;
}

// Push an element onto the stack
void push(Node **stack, int data) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Stack overflow\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = (*stack);
    (*stack) = new_node;
}

// Pop an element from the stack
int pop(Node **stack) {
    if (*stack == NULL) {
        printf("Stack underflow\n");
        exit(1);
    }
    int data = (*stack)->data;
    Node *temp = (*stack);
    (*stack) = (*stack)->next;
    free(temp);
    return data;
}

// Print the stack
void print_stack(Node *stack) {
    if (stack == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    while (stack!= NULL) {
        printf("%d ", stack->data);
        stack = stack->next;
    }
    printf("\n");
}

// Main function
int main() {
    Node *stack = NULL;
    init(&stack);
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    print_stack(stack);
    int popped_data = pop(&stack);
    printf("Popped data: %d\n", popped_data);
    print_stack(stack);
    return 0;
}