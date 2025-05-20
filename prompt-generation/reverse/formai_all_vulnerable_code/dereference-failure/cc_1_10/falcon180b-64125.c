//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the maximum size of the stack
#define MAX_SIZE 100

// Define the node structure for the stack
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the stack structure
typedef struct {
    Node* top;
    int size;
} Stack;

// Function to initialize the stack
void initStack(Stack* stack) {
    stack->top = NULL;
    stack->size = 0;
}

// Function to check if the stack is empty
bool isEmpty(Stack* stack) {
    return (stack->top == NULL);
}

// Function to check if the stack is full
bool isFull(Stack* stack) {
    return (stack->size == MAX_SIZE);
}

// Function to push an element onto the stack
void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(stack)) {
        stack->top = newNode;
    } else {
        newNode->next = stack->top;
        stack->top = newNode;
    }

    stack->size++;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }

    int data = stack->top->data;
    Node* tempNode = stack->top;
    stack->top = stack->top->next;
    free(tempNode);

    stack->size--;

    return data;
}

// Function to print the stack
void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }

    Node* tempNode = stack->top;
    while (tempNode!= NULL) {
        printf("%d ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("\n");
}

// Main function to test the stack implementation
int main() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printStack(&stack);

    int poppedData = pop(&stack);
    printf("Popped data: %d\n", poppedData);

    printStack(&stack);

    push(&stack, 40);
    push(&stack, 50);

    printf("Stack is full\n");

    return 0;
}