//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

// Define a node structure for linked lists
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define a stack structure using linked lists
typedef struct stack {
    Node* top;
} Stack;

// Initialize an empty stack
void init(Stack* s) {
    s->top = NULL;
}

// Push an integer onto the stack
void push(Stack* s, int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = s->top;
    s->top = newNode;
}

// Pop an integer from the stack
int pop(Stack* s) {
    if (s->top == NULL) {
        printf("Stack underflow\n");
        exit(0);
    }
    Node* tempNode = s->top;
    int x = s->top->data;
    s->top = s->top->next;
    free(tempNode);
    return x;
}

// Peek at the top element of the stack
int peek(Stack* s) {
    if (s->top == NULL) {
        printf("Stack is empty\n");
        exit(0);
    }
    return s->top->data;
}

// Check if the stack is empty
bool isEmpty(Stack* s) {
    return s->top == NULL;
}

int main() {
    Stack stack;
    init(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    printf("Top element: %d\n", peek(&stack));

    pop(&stack);

    printf("Top element after pop: %d\n", peek(&stack));

    printf("Is stack empty? %s\n", isEmpty(&stack)? "Yes" : "No");

    return 0;
}