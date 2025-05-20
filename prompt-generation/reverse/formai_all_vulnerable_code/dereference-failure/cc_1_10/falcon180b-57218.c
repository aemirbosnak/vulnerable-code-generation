//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for linked list
typedef struct node {
    char data;
    struct node* next;
} Node;

// Stack structure using linked list
typedef struct stack {
    Node* top;
} Stack;

// Function to push an element onto the stack
void push(Stack* stack, char element) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = element;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
char pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        exit(0);
    }
    char poppedElement = stack->top->data;
    Node* tempNode = stack->top;
    stack->top = stack->top->next;
    free(tempNode);
    return poppedElement;
}

// Function to display the elements in the stack
void display(Stack* stack) {
    Node* tempNode = stack->top;
    while (tempNode!= NULL) {
        printf("%c ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("\n");
}

int main() {
    Stack stack;
    stack.top = NULL;

    // Pushing elements onto the stack
    push(&stack, 'R');
    push(&stack, 'o');
    push(&stack,'m');
    push(&stack, 'e');
    push(&stack, 'o');

    // Displaying the elements in the stack
    printf("Elements in the stack:\n");
    display(&stack);

    // Popping elements from the stack
    char poppedElement = pop(&stack);
    printf("Popped element: %c\n", poppedElement);

    // Displaying the elements in the stack after popping
    printf("Elements in the stack after popping:\n");
    display(&stack);

    return 0;
}