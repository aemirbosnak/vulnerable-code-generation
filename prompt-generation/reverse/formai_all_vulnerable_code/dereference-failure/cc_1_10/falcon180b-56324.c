//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a node structure for the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define a stack structure using linked list
typedef struct Stack {
    Node* top;
} Stack;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Function to push an element onto the stack
void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(0);
    }
    Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

// Function to print the stack
void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    Node* temp = stack->top;
    printf("Stack elements are: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Stack stack;
    stack.top = NULL;

    // Testing push function
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    printStack(&stack);

    // Testing pop function
    int poppedElement = pop(&stack);
    printf("Popped element is: %d\n", poppedElement);
    printStack(&stack);

    // Testing isEmpty function
    if (isEmpty(&stack)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack is not empty\n");
    }

    return 0;
}