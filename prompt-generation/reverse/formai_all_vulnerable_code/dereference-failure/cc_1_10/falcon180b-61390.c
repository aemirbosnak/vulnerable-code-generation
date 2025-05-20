//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the stack
#define MAX_SIZE 100

// Define the structure of a stack node
typedef struct {
    int data;
    struct stack_node* next;
} StackNode;

// Define the structure of a stack
typedef struct {
    StackNode* top;
    int size;
} Stack;

// Initialize an empty stack
void init_stack(Stack* stack) {
    stack->top = NULL;
    stack->size = 0;
}

// Push an element onto the stack
void push_stack(Stack* stack, int data) {
    StackNode* new_node = (StackNode*)malloc(sizeof(StackNode));
    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}

// Pop an element off the stack
int pop_stack(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    StackNode* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    stack->size--;
    return data;
}

// Print the elements of the stack
void print_stack(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    StackNode* temp = stack->top;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the stack operations
int main() {
    Stack stack;
    init_stack(&stack);
    push_stack(&stack, 10);
    push_stack(&stack, 20);
    push_stack(&stack, 30);
    push_stack(&stack, 40);
    push_stack(&stack, 50);
    print_stack(&stack);
    pop_stack(&stack);
    pop_stack(&stack);
    print_stack(&stack);
    return 0;
}