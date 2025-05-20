//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Define the node structure for the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the stack structure using linked lists
typedef struct stack {
    Node* top;
} Stack;

// Function to create an empty stack
Stack* createStack() {
    Stack* newStack = (Stack*) malloc(sizeof(Stack));
    newStack->top = NULL;
    return newStack;
}

// Function to check if the stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Function to push an element onto the stack
void push(Stack* stack, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1;
    }
    int data = stack->top->data;
    Node* tempNode = stack->top;
    stack->top = stack->top->next;
    free(tempNode);
    return data;
}

// Function to print the stack
void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return;
    }
    Node* tempNode = stack->top;
    while (tempNode!= NULL) {
        printf("%d ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("\n");
}

int main() {
    Stack* myStack = createStack();

    // Test pushing elements onto the stack
    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);

    // Test popping elements from the stack
    int poppedElement = pop(myStack);
    printf("Popped element: %d\n", poppedElement);

    // Test printing the stack
    printStack(myStack);

    // Test checking if the stack is empty
    if (isEmpty(myStack)) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack is not empty!\n");
    }

    return 0;
}