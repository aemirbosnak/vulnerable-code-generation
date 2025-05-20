//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: rigorous
#include <stdio.h>

// Node structure definition for singly linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Stack structure definition using linked list
typedef struct Stack {
    Node* top;
} Stack;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push a node onto the stack
void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    if (newNode == NULL)
        return;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop a node from the stack
int pop(Stack* stack) {
    if (stack->top == NULL)
        return -1;
    int data = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

// Function to print the stack
void printStack(Stack stack) {
    Node* temp = stack.top;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    Stack stack;
    stack.top = NULL;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Stack: ");
    printStack(stack);

    int poppedData = pop(&stack);
    printf("\nPopped element: %d\n", poppedData);

    printf("Stack after popping: ");
    printStack(stack);

    return 0;
}