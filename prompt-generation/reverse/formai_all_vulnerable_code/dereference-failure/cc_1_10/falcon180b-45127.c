//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the stack
#define MAX_SIZE 100

// Define the structure of a node
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the structure of a stack
typedef struct stack {
    Node* top;
    int size;
} Stack;

// Function to create a new stack
void create_stack(Stack* stack) {
    stack->top = NULL;
    stack->size = 0;
}

// Function to check if the stack is empty
int is_empty(Stack* stack) {
    return stack->top == NULL;
}

// Function to push an element onto the stack
void push(Stack* stack, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (is_empty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    stack->size--;
    return data;
}

// Function to print the stack
void print_stack(Stack* stack) {
    if (is_empty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    Node* temp = stack->top;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    Stack stack;
    create_stack(&stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    print_stack(&stack);
    pop(&stack);
    print_stack(&stack);
    pop(&stack);
    print_stack(&stack);
    pop(&stack);
    print_stack(&stack);
    pop(&stack);
    print_stack(&stack);
    return 0;
}