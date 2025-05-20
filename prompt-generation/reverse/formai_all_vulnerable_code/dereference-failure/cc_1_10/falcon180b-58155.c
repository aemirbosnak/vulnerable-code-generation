//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Stack structure using linked list
typedef struct stack {
    Node* top;
} Stack;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (stack->top == NULL)
        return -1;
    Node* tempNode = stack->top;
    int poppedData = tempNode->data;
    stack->top = tempNode->next;
    free(tempNode);
    return poppedData;
}

// Function to print the stack
void printStack(Stack* stack) {
    Node* currNode = stack->top;
    while (currNode!= NULL) {
        printf("%d ", currNode->data);
        currNode = currNode->next;
    }
    printf("\n");
}

int main() {
    Stack* myStack = (Stack*)malloc(sizeof(Stack));
    myStack->top = NULL;

    // Test pushing elements onto the stack
    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);

    // Test popping elements from the stack
    printf("Popped element: %d\n", pop(myStack));
    printf("Popped element: %d\n", pop(myStack));

    // Test printing the stack
    printf("Stack elements:\n");
    printStack(myStack);

    return 0;
}