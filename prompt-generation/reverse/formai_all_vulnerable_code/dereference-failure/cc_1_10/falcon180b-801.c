//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to create an empty stack
Stack* create_stack() {
    Stack* new_stack = (Stack*)malloc(sizeof(Stack));
    if (new_stack == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    new_stack->top = NULL;
    return new_stack;
}

// Function to check if the stack is empty
int is_empty(Stack* stack) {
    return (stack->top == NULL);
}

// Function to push an element onto the stack
void push(Stack* stack, int data) {
    Node* new_node = create_node(data);
    new_node->next = stack->top;
    stack->top = new_node;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (is_empty(stack)) {
        printf("Stack underflow\n");
        exit(0);
    }
    Node* temp_node = stack->top;
    int data = temp_node->data;
    stack->top = temp_node->next;
    free(temp_node);
    return data;
}

// Function to display the elements in the stack
void display(Stack* stack) {
    if (is_empty(stack)) {
        printf("Stack is empty\n");
    } else {
        printf("Elements in the stack are: ");
        Node* temp_node = stack->top;
        while (temp_node!= NULL) {
            printf("%d ", temp_node->data);
            temp_node = temp_node->next;
        }
        printf("\n");
    }
}

int main() {
    Stack* stack = create_stack();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    display(stack);
    printf("Popped element: %d\n", pop(stack));
    display(stack);
    printf("Popped element: %d\n", pop(stack));
    display(stack);
    printf("Popped element: %d\n", pop(stack));
    display(stack);
    printf("Popped element: %d\n", pop(stack));
    display(stack);
    return 0;
}