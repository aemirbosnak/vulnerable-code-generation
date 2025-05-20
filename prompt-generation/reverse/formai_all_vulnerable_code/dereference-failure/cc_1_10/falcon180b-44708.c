//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Node structure definition
typedef struct node {
    int data;
    struct node* next;
} Node;

// Stack structure definition using linked list
typedef struct stack {
    Node* top;
} Stack;

// Function declarations
void push(Stack* stack, int data);
int pop(Stack* stack);
int peek(Stack* stack);
int is_empty(Stack* stack);

// Main function
int main() {
    Stack stack;
    stack.top = NULL;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element is: %d\n", peek(&stack));

    pop(&stack);
    printf("Top element after pop is: %d\n", peek(&stack));

    return 0;
}

// Push function to add an element to the stack
void push(Stack* stack, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Stack overflow\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
}

// Pop function to remove and return the top element from the stack
int pop(Stack* stack) {
    if (is_empty(stack)) {
        printf("Stack underflow\n");
        exit(0);
    }
    Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

// Peek function to return the top element without removing it
int peek(Stack* stack) {
    if (is_empty(stack)) {
        printf("Stack is empty\n");
        exit(0);
    }
    return stack->top->data;
}

// Check if the stack is empty
int is_empty(Stack* stack) {
    return stack->top == NULL;
}