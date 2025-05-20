//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Node structure for linked list
typedef struct node {
    char data[MAX_SIZE];
    struct node* next;
} Node;

// Stack structure using linked list
typedef struct stack {
    Node* top;
} Stack;

// Function to create a new node with given data
Node* createNode(char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
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
    if (stack->top == NULL) {
        return NULL;
    }
    Node* tempNode = stack->top;
    stack->top = stack->top->next;
    free(tempNode);
    return tempNode;
}

// Function to display the stack
void display(Stack* stack) {
    Node* tempNode = stack->top;
    while (tempNode!= NULL) {
        printf("%s ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("\n");
}

int main() {
    Stack stack;
    stack.top = NULL;

    push(&stack, "Hello");
    push(&stack, "World");
    push(&stack, "C");
    push(&stack, "Programming");

    display(&stack);

    Node* poppedNode = pop(&stack);
    printf("Popped node: %s\n", poppedNode->data);

    display(&stack);

    return 0;
}