//Falcon-180B DATASET v1.0 Category: Memory management ; Style: genious
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
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to push a node onto the stack
void push(Stack* stack, int data) {
    Node* new_node = create_node(data);
    new_node->next = stack->top;
    stack->top = new_node;
}

// Function to pop a node from the stack
int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    Node* temp_node = stack->top;
    int data = temp_node->data;
    stack->top = temp_node->next;
    free(temp_node);
    return data;
}

// Function to display the stack
void display(Stack* stack) {
    Node* temp_node = stack->top;
    while (temp_node!= NULL) {
        printf("%d ", temp_node->data);
        temp_node = temp_node->next;
    }
    printf("\n");
}

int main() {
    Stack stack;
    stack.top = NULL;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    display(&stack);

    int popped_data = pop(&stack);
    printf("Popped data: %d\n", popped_data);
    display(&stack);

    popped_data = pop(&stack);
    printf("Popped data: %d\n", popped_data);
    display(&stack);

    popped_data = pop(&stack);
    printf("Popped data: %d\n", popped_data);
    display(&stack);

    popped_data = pop(&stack);
    printf("Popped data: %d\n", popped_data);

    return 0;
}