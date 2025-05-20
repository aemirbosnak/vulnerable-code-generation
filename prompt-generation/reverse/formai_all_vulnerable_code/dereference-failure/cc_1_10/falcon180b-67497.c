//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a node structure for a linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define a stack structure
typedef struct {
    Node* top;
} Stack;

// Create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Create a new empty stack
Stack* createStack() {
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    newStack->top = NULL;
    return newStack;
}

// Push a node onto the stack
void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Pop a node off the stack
Node* pop(Stack* stack) {
    Node* temp = stack->top;
    stack->top = stack->top->next;
    return temp;
}

// Print the stack
void printStack(Stack* stack) {
    Node* current = stack->top;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Stack* myStack = createStack();

    // Push some nodes onto the stack
    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);

    // Print the stack
    printStack(myStack);

    // Pop a node off the stack
    Node* poppedNode = pop(myStack);
    printf("Popped node: %d\n", poppedNode->data);

    // Print the stack again
    printStack(myStack);

    return 0;
}