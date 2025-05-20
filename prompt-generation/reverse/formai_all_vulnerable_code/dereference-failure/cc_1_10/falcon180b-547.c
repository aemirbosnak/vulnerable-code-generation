//Falcon-180B DATASET v1.0 Category: Educational ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Node structure definition
typedef struct node {
    char data[MAX_SIZE];
    struct node *next;
} Node;

// Stack structure definition
typedef struct {
    Node *top;
} Stack;

// Function to create a new node with given data
Node* create_node(char data[MAX_SIZE]) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    strcpy(new_node->data, data);
    new_node->next = NULL;
    return new_node;
}

// Function to push a node onto the stack
void push(Stack *stack, char data[MAX_SIZE]) {
    Node *new_node = create_node(data);
    new_node->next = stack->top;
    stack->top = new_node;
}

// Function to pop a node from the stack
Node* pop(Stack *stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return NULL;
    }
    Node *temp_node = stack->top;
    stack->top = stack->top->next;
    return temp_node;
}

// Function to display the stack
void display(Stack stack) {
    Node *temp_node = stack.top;
    if (temp_node == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    while (temp_node!= NULL) {
        printf("%s\n", temp_node->data);
        temp_node = temp_node->next;
    }
}

int main() {
    Stack stack;
    stack.top = NULL;

    // Pushing elements onto the stack
    push(&stack, "Hello");
    push(&stack, "World");

    // Displaying the stack
    display(stack);

    // Popping elements from the stack
    Node *popped_node = pop(&stack);
    if (popped_node!= NULL) {
        printf("Popped element is: %s\n", popped_node->data);
        free(popped_node);
    }

    // Displaying the stack again
    display(stack);

    return 0;
}