//FormAI DATASET v1.0 Category: Data structures visualization ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// Node for the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Stack data structure
typedef struct stack {
    Node* top;
} Stack;

// Initialize an empty stack
Stack* createStack() {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

// Check if stack is empty
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Push element onto stack
void push(Stack* stack, int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = stack->top;
    stack->top = node;
}

// Pop element from stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack is empty!\n");
        return -1;
    }

    Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

// Display stack contents
void display(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return;
    }

    Node* temp = stack->top;

    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // Initialize random seed

    Stack* stack = createStack(); // Create stack

    // Push random elements onto stack
    for (int i = 0; i < SIZE; i++) {
        int data = rand() % 100; // Generate random number between 0 and 99
        push(stack, data);
    }

    display(stack); // Display stack contents

    pop(stack); // Pop one element from stack

    display(stack); // Display stack contents

    return 0;
}