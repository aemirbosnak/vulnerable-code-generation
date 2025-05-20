//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum size of the stack
#define MAX_SIZE 100

// Define the structure for a node in the stack
typedef struct node {
    int data;
    struct node *next;
} Node;

// Define the structure for the stack
typedef struct {
    Node *top;
    int size;
} Stack;

// Initialize the stack
void init(Stack *stack) {
    stack->top = NULL;
    stack->size = 0;
}

// Check if the stack is empty
bool is_empty(Stack *stack) {
    return stack->top == NULL;
}

// Push an element onto the stack
void push(Stack *stack, int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}

// Pop an element from the stack
int pop(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is empty! ");
        exit(1);
    }
    Node *temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    stack->size--;
    return data;
}

// Display the elements in the stack
void display(Stack *stack) {
    printf("Stack: ");
    Node *temp = stack->top;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    Stack stack;
    init(&stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    display(&stack);
    pop(&stack);
    display(&stack);
    pop(&stack);
    display(&stack);
    pop(&stack);
    display(&stack);
    return 0;
}