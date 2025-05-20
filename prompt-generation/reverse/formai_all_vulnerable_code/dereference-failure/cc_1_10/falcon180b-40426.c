//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

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
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->data, element);
    new_node->next = NULL;

    if (stack->top == NULL) {
        stack->top = new_node;
    } else {
        new_node->next = stack->top;
        stack->top = new_node;
    }
}

// Function to pop an element from the stack
char* pop(Stack* stack) {
    char* result = NULL;

    if (stack->top!= NULL) {
        result = stack->top->data;
        Node* temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }

    return result;
}

// Function to check if the stack is empty
int is_empty(Stack* stack) {
    return (stack->top == NULL);
}

// Function to print the stack
void print_stack(Stack* stack) {
    Node* temp = stack->top;

    while (temp!= NULL) {
        printf("%s ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    Stack stack;
    stack.top = NULL;

    push(&stack, "apple");
    push(&stack, "banana");
    push(&stack, "cherry");

    print_stack(&stack);

    char* popped_element = pop(&stack);
    printf("Popped element: %s\n", popped_element);

    print_stack(&stack);

    return 0;
}