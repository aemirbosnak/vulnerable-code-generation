//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a string
#define MAX_LENGTH 100

// Define the node structure for the linked list
typedef struct node {
    char data[MAX_LENGTH];
    struct node* next;
} Node;

// Define the stack structure
typedef struct stack {
    Node* top;
} Stack;

// Function to create a new node with the given data
Node* createNode(char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

// Function to push a node onto the stack
void push(Stack* stack, char* data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop a node from the stack
Node* pop(Stack* stack) {
    Node* tempNode = stack->top;
    stack->top = tempNode->next;
    return tempNode;
}

// Function to print the stack
void printStack(Stack* stack) {
    Node* currentNode = stack->top;
    while (currentNode!= NULL) {
        printf("%s ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

int main() {
    // Create a new stack
    Stack myStack;
    myStack.top = NULL;

    // Push some nodes onto the stack
    push(&myStack, "Hello");
    push(&myStack, "World");
    push(&myStack, "How");
    push(&myStack, "are");
    push(&myStack, "you?");

    // Print the stack
    printStack(&myStack);

    // Pop a node from the stack
    Node* poppedNode = pop(&myStack);
    printf("Popped node: %s\n", poppedNode->data);

    // Print the stack again
    printStack(&myStack);

    return 0;
}