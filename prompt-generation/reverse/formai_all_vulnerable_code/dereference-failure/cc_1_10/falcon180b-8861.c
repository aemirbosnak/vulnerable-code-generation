//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum size of the stack
#define MAX_STACK_SIZE 100

// Define the node structure for the stack
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the stack structure
typedef struct stack {
    Node* top;
    int size;
} Stack;

// Function to create a new stack
Stack* createStack() {
    Stack* newStack = (Stack*) malloc(sizeof(Stack));
    newStack->top = NULL;
    newStack->size = 0;
    return newStack;
}

// Function to push an element onto the stack
void push(Stack* stack, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (stack->top == NULL) {
        stack->top = newNode;
    } else {
        newNode->next = stack->top;
        stack->top = newNode;
    }
    stack->size++;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }
    int data = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    return data;
}

// Function to check if the stack is empty
bool isEmpty(Stack* stack) {
    return (stack->top == NULL);
}

// Function to print the stack
void printStack(Stack* stack) {
    printf("Stack: ");
    Node* temp = stack->top;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    Stack* stack = createStack();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    printStack(stack);
    int poppedElement = pop(stack);
    printf("Popped element: %d\n", poppedElement);
    printStack(stack);
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack is not empty.\n");
    }
    return 0;
}