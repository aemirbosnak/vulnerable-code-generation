//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Node structure for linked list
typedef struct node {
    char data[MAX_SIZE];
    struct node* next;
} Node;

// Stack structure using linked list
typedef struct stack {
    Node* top;
} Stack;

// Function to push an element onto the stack
void push(Stack* stack, char* element) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory could not be allocated.\n");
        exit(1);
    }
    strcpy(newNode->data, element);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
char* pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Error: Stack is empty.\n");
        exit(1);
    }
    char* element = stack->top->data;
    Node* tempNode = stack->top;
    stack->top = stack->top->next;
    free(tempNode);
    return element;
}

// Main function
int main() {
    Stack stack;
    stack.top = NULL;

    // Test pushing elements onto the stack
    push(&stack, "Hello");
    push(&stack, "World");

    // Test popping elements from the stack
    char* element1 = pop(&stack);
    printf("%s\n", element1); // Output: Hello
    char* element2 = pop(&stack);
    printf("%s\n", element2); // Output: World

    // Test error handling for memory allocation failure
    push(&stack, "Error"); // This should print an error message and exit the program

    return 0;
}