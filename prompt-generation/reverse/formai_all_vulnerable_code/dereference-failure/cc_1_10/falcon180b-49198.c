//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure definition for linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Stack structure definition using linked list
typedef struct stack {
    Node* top;
} Stack;

// Function prototypes
Stack* createStack();
void push(Stack* stack, int value);
int pop(Stack* stack);
int peek(Stack* stack);
int isEmpty(Stack* stack);
void printStack(Stack* stack);

// Main function
int main() {
    Stack* myStack = createStack();

    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);

    printStack(myStack);

    int topValue = peek(myStack);
    printf("Top value: %d\n", topValue);

    pop(myStack);
    printStack(myStack);

    if (isEmpty(myStack)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack is not empty.\n");
    }

    free(myStack);
    return 0;
}

// Function to create an empty stack
Stack* createStack() {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

// Function to push a value onto the stack
void push(Stack* stack, int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop a value off the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    }

    Node* tempNode = stack->top;
    int value = tempNode->data;
    stack->top = tempNode->next;
    free(tempNode);

    return value;
}

// Function to peek at the top value of the stack
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    }

    return stack->top->data;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    if (stack->top == NULL) {
        return 1;
    } else {
        return 0;
    }
}

// Function to print the stack
void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
    } else {
        Node* tempNode = stack->top;
        while (tempNode!= NULL) {
            printf("%d ", tempNode->data);
            tempNode = tempNode->next;
        }
        printf("\n");
    }
}