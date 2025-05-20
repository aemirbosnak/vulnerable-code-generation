//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum size of the stack
#define MAX_SIZE 100

// Define the node structure for the stack
typedef struct node {
    int data;
    struct node* next;
} Node;

// Create an empty stack
void create_stack(Node** stack) {
    *stack = NULL;
}

// Check if the stack is empty
bool is_empty(Node* stack) {
    return stack == NULL;
}

// Push an element onto the stack
void push(Node** stack, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Stack overflow\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = *stack;
    *stack = new_node;
}

// Pop an element from the stack
int pop(Node** stack) {
    if (is_empty(*stack)) {
        printf("Error: Stack underflow\n");
        exit(1);
    }
    Node* temp_node = *stack;
    int data = temp_node->data;
    *stack = temp_node->next;
    free(temp_node);
    return data;
}

// Display the elements of the stack
void display(Node* stack) {
    if (is_empty(stack)) {
        printf("Empty stack\n");
        return;
    }
    printf("Stack elements: ");
    Node* temp_node = stack;
    while (temp_node!= NULL) {
        printf("%d ", temp_node->data);
        temp_node = temp_node->next;
    }
    printf("\n");
}

int main() {
    Node* stack = NULL;
    create_stack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);

    display(stack);

    int popped_element = pop(&stack);
    printf("Popped element: %d\n", popped_element);

    display(stack);

    popped_element = pop(&stack);
    printf("Popped element: %d\n", popped_element);

    display(stack);

    popped_element = pop(&stack);
    printf("Popped element: %d\n", popped_element);

    display(stack);

    popped_element = pop(&stack);
    printf("Popped element: %d\n", popped_element);

    display(stack);

    return 0;
}