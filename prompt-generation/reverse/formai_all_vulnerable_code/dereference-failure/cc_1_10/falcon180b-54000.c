//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum capacity of the stack
#define MAX_SIZE 100

// Define the node structure for the stack
typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

// Define the stack structure
typedef struct Stack {
    StackNode* top;
    int size;
} Stack;

// Initialize the stack
void init(Stack* stack) {
    stack->top = NULL;
    stack->size = 0;
}

// Check if the stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Check if the stack is full
bool isFull(Stack* stack) {
    return stack->size == MAX_SIZE;
}

// Push an element onto the stack
void push(Stack* stack, int data) {
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    node->data = data;
    node->next = stack->top;
    stack->top = node;
    stack->size++;
}

// Pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    StackNode* node = stack->top;
    int data = node->data;
    stack->top = node->next;
    free(node);
    stack->size--;
    return data;
}

// Peek at the top element of the stack
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->top->data;
}

// Print the stack
void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    StackNode* node = stack->top;
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    // Initialize the stack
    Stack stack;
    init(&stack);

    // Push some elements onto the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // Print the stack
    printStack(&stack);

    // Pop an element from the stack
    int poppedElement = pop(&stack);
    printf("Popped element: %d\n", poppedElement);

    // Print the stack again
    printStack(&stack);

    // Peek at the top element of the stack
    int topElement = peek(&stack);
    printf("Top element: %d\n", topElement);

    return 0;
}