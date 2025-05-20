//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the node structure for the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the stack structure
typedef struct Stack {
    Node* top;
} Stack;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push a node onto the stack
void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop a node from the stack
int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty!\n");
        exit(1);
    }
    Node* tempNode = stack->top;
    int poppedData = tempNode->data;
    stack->top = tempNode->next;
    free(tempNode);
    return poppedData;
}

// Function to print the stack
void printStack(Stack* stack) {
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
    stack.top = NULL;

    // Push some nodes onto the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // Print the stack
    printf("Stack after pushing 10, 20, 30:\n");
    printStack(&stack);

    // Pop a node from the stack
    int poppedData = pop(&stack);
    printf("Popped data: %d\n", poppedData);

    // Print the stack again
    printf("Stack after popping a node:\n");
    printStack(&stack);

    // Push some more nodes onto the stack
    push(&stack, 40);
    push(&stack, 50);

    // Print the stack again
    printf("Stack after pushing 40 and 50:\n");
    printStack(&stack);

    // Pop all the nodes from the stack
    while (stack.top!= NULL) {
        int poppedData = pop(&stack);
        printf("Popped data: %d\n", poppedData);
    }

    // Print the stack again (should be empty)
    printf("Stack after popping all nodes:\n");
    printStack(&stack);

    return 0;
}