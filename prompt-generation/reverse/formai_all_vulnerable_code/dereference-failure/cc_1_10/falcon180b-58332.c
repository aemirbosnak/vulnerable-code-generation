//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum size of the stack
#define MAX_SIZE 100

// Node structure for linked list implementation of stack
typedef struct node {
    int data;
    struct node* next;
} Node;

// Stack structure
typedef struct {
    Node* top;
    int size;
} Stack;

// Initialize an empty stack
void init(Stack* stack) {
    stack->top = NULL;
    stack->size = 0;
}

// Check if the stack is empty
bool is_empty(Stack* stack) {
    return stack->top == NULL;
}

// Get the size of the stack
int get_size(Stack* stack) {
    return stack->size;
}

// Push an element onto the stack
void push(Stack* stack, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}

// Pop an element from the stack
int pop(Stack* stack) {
    if (is_empty(stack)) {
        printf("Error: Stack is empty\n");
        exit(1);
    }
    Node* temp_node = stack->top;
    int data = temp_node->data;
    stack->top = temp_node->next;
    free(temp_node);
    stack->size--;
    return data;
}

// Display the elements in the stack
void display(Stack* stack) {
    if (is_empty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    Node* temp_node = stack->top;
    while (temp_node!= NULL) {
        printf("%d ", temp_node->data);
        temp_node = temp_node->next;
    }
    printf("\n");
}

int main() {
    Stack stack;
    init(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);

    printf("Stack after pushing 5 elements:\n");
    display(&stack);

    int popped_element = pop(&stack);
    printf("Popped element: %d\n", popped_element);

    printf("Stack after popping an element:\n");
    display(&stack);

    popped_element = pop(&stack);
    printf("Popped element: %d\n", popped_element);

    printf("Stack after popping another element:\n");
    display(&stack);

    return 0;
}