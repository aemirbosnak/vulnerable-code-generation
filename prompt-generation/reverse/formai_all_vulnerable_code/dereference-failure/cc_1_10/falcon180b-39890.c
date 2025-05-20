//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum size of the stack
#define MAX 100

// Node structure for stack implementation using linked list
struct node {
    int data;
    struct node* next;
};

// Stack structure
struct stack {
    struct node* top;
};

// Function to create a new node with given data
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to create an empty stack
struct stack* createStack() {
    struct stack* stack = (struct stack*)malloc(sizeof(struct stack));
    stack->top = NULL;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct stack* stack) {
    return!stack->top;
}

// Function to push an element onto the stack
void push(struct stack* stack, int data) {
    struct node* node = newNode(data);
    node->next = stack->top;
    stack->top = node;
}

// Function to pop an element from the stack
int pop(struct stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    struct node* node = stack->top;
    int data = node->data;
    stack->top = node->next;
    free(node);
    return data;
}

// Function to print the stack
void printStack(struct stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    struct node* node = stack->top;
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct stack* stack = createStack();

    // Test push function
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    printStack(stack);

    // Test pop function
    int popped = pop(stack);
    printf("Popped element: %d\n", popped);
    printStack(stack);

    // Test push function again
    push(stack, 40);
    push(stack, 50);
    printStack(stack);

    return 0;
}