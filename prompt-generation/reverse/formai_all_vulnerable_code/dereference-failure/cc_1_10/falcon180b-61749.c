//Falcon-180B DATASET v1.0 Category: Memory management ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

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
    if (newNode == NULL) {
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
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    Node* tempNode = stack->top;
    int data = tempNode->data;
    stack->top = tempNode->next;
    free(tempNode);
    return data;
}

// Function to display the elements in the stack
void display(Stack* stack) {
    Node* tempNode = stack->top;
    while (tempNode!= NULL) {
        printf("%d ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("\n");
}

int main() {
    Stack stack;
    stack.top = NULL;

    // Test push function
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    display(&stack);

    // Test pop function
    int poppedElement = pop(&stack);
    printf("Popped element: %d\n", poppedElement);
    display(&stack);

    // Test memory management
    push(&stack, 40);
    push(&stack, 50);
    push(&stack, 60);
    push(&stack, 70);
    push(&stack, 80);
    push(&stack, 90);
    push(&stack, 100);
    printf("Stack size: %d\n", 7);

    return 0;
}