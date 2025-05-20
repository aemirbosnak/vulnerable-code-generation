//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
typedef struct node {
    int data;
    struct node *next;
} Node;

// Stack structure using linked list
typedef struct stack {
    Node *top;
} Stack;

// Function to push element onto stack
void push(Stack *stack, int value) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = stack->top;
    stack->top = new_node;
}

// Function to pop element from stack
int pop(Stack *stack) {
    if (stack->top == NULL)
        return -1;
    int value = stack->top->data;
    Node *temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return value;
}

// Function to check if stack is empty
int is_empty(Stack *stack) {
    return stack->top == NULL;
}

// Function to display elements in stack
void display(Stack *stack) {
    Node *current = stack->top;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Stack stack;
    stack.top = NULL;

    // Push elements onto stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // Display elements in stack
    printf("Elements in stack:\n");
    display(&stack);

    // Pop elements from stack
    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));

    // Display elements in stack after popping
    printf("Elements in stack after popping:\n");
    display(&stack);

    // Check if stack is empty
    if (is_empty(&stack))
        printf("Stack is empty.\n");
    else
        printf("Stack is not empty.\n");

    return 0;
}