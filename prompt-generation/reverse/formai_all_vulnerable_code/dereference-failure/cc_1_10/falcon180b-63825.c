//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Define the structure of a node in the linked list
typedef struct {
    char data;
    struct node* next;
} node;

// Define the structure of a stack using linked list
typedef struct {
    node* top;
} stack;

// Function to create a new node with given data
node* createNode(char data) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
void push(stack* s, char data) {
    node* newNode = createNode(data);
    newNode->next = s->top;
    s->top = newNode;
}

// Function to pop an element from the stack
char pop(stack* s) {
    if (s->top == NULL) {
        printf("Stack is empty\n");
        exit(0);
    }
    char data = s->top->data;
    node* temp = s->top;
    s->top = s->top->next;
    free(temp);
    return data;
}

// Function to check if the stack is empty
int isEmpty(stack s) {
    return s.top == NULL;
}

// Function to print the stack
void printStack(stack s) {
    node* temp = s.top;
    while (temp!= NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
}

// Main function demonstrating the usage of the stack data structure
int main() {
    stack s;
    s.top = NULL;

    // Push elements onto the stack
    push(&s, 'R');
    push(&s, 'o');
    push(&s,'m');
    push(&s, 'e');
    push(&s, 'o');

    // Print the stack
    printf("Stack: ");
    printStack(s);

    // Pop elements from the stack
    printf("\nPopped element: %c\n", pop(&s));
    printf("Popped element: %c\n", pop(&s));

    // Print the stack again
    printf("Stack after popping 2 elements: ");
    printStack(s);

    return 0;
}