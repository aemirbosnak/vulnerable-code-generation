//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a node structure for linked list
struct Node {
    int data;
    struct Node* next;
};

// Define a stack structure using linked list
struct Stack {
    struct Node* top;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push a node onto the stack
void push(struct Stack* stack, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop a node from the stack
int pop(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        exit(0);
    }
    struct Node* tempNode = stack->top;
    int data = tempNode->data;
    stack->top = tempNode->next;
    free(tempNode);
    return data;
}

// Function to display the stack
void display(struct Stack* stack) {
    struct Node* tempNode = stack->top;
    while (tempNode!= NULL) {
        printf("%d ", tempNode->data);
        tempNode = tempNode->next;
    }
}

// Main function to test the stack implementation
int main() {
    struct Stack stack;
    stack.top = NULL;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Stack after pushing 10, 20 and 30:\n");
    display(&stack);

    int poppedData = pop(&stack);
    printf("Popped data: %d\n", poppedData);

    printf("Stack after popping:\n");
    display(&stack);

    return 0;
}