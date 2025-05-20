//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Node structure for linked list
struct node {
    int data;
    struct node* next;
};

// Stack structure using linked list
struct stack {
    struct node* top;
};

// Function to create a new node with given data
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty stack
struct stack* createStack() {
    struct stack* newStack = (struct stack*)malloc(sizeof(struct stack));
    if (newStack == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newStack->top = NULL;
    return newStack;
}

// Function to push an element onto the stack
void push(struct stack* stack, int data) {
    struct node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
int pop(struct stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        exit(0);
    }
    struct node* tempNode = stack->top;
    int data = tempNode->data;
    stack->top = tempNode->next;
    free(tempNode);
    return data;
}

// Function to check if the stack is empty
int isEmpty(struct stack* stack) {
    if (stack->top == NULL)
        return 1;
    else
        return 0;
}

// Function to print the stack
void printStack(struct stack* stack) {
    struct node* tempNode = stack->top;
    if (tempNode == NULL) {
        printf("Stack is empty\n");
        return;
    }
    while (tempNode!= NULL) {
        printf("%d ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("\n");
}

int main() {
    struct stack* stack = createStack();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    printStack(stack);
    printf("Popped element: %d\n", pop(stack));
    printStack(stack);
    printf("Popped element: %d\n", pop(stack));
    printStack(stack);
    printf("Popped element: %d\n", pop(stack));
    printStack(stack);
    printf("Popped element: %d\n", pop(stack));
    printStack(stack);
    return 0;
}