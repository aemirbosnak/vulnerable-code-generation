//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the maximum size of the stack
#define MAX_SIZE 100

// Define the node structure for the stack
typedef struct node {
    int data;
    struct node *next;
} Node;

// Define the stack structure
typedef struct {
    Node *top;
    int size;
} Stack;

// Initialize the stack
void init_stack(Stack *stack) {
    stack->top = NULL;
    stack->size = 0;
}

// Push an element onto the stack
void push(Stack *stack, int data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}

// Pop an element from the stack
int pop(Stack *stack) {
    if (stack->top == NULL) {
        printf("Error: Stack is empty\n");
        exit(1);
    }
    int data = stack->top->data;
    Node *temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    return data;
}

// Display the elements in the stack
void display(Stack *stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    Node *temp = stack->top;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    Stack stack;
    init_stack(&stack);

    // Push elements onto the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);

    // Display the elements in the stack
    printf("Stack after pushing elements:\n");
    display(&stack);

    // Pop elements from the stack
    int popped_element = pop(&stack);
    printf("Popped element: %d\n", popped_element);

    // Display the elements in the stack
    printf("Stack after popping an element:\n");
    display(&stack);

    return 0;
}