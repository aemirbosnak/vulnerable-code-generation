//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the stack
#define MAX_SIZE 100

// Node structure for the stack
typedef struct node {
    int data;
    struct node* next;
} Node;

// Stack structure
typedef struct {
    Node* top;
    int size;
} Stack;

// Function to create an empty stack
Stack* create_stack() {
    Stack* new_stack = (Stack*)malloc(sizeof(Stack));
    new_stack->top = NULL;
    new_stack->size = 0;
    return new_stack;
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
    if (stack->top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }
    Node* temp_node = stack->top;
    int popped_data = temp_node->data;
    stack->top = temp_node->next;
    free(temp_node);
    stack->size--;
    return popped_data;
}

// Function to display the elements in the stack
void display(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    Node* temp_node = stack->top;
    printf("Elements in the stack: ");
    while (temp_node!= NULL) {
        printf("%d ", temp_node->data);
        temp_node = temp_node->next;
    }
    printf("\n");
}

// Main function
int main() {
    Stack* my_stack = create_stack();
    push(my_stack, 10);
    push(my_stack, 20);
    push(my_stack, 30);
    display(my_stack);
    int popped_data = pop(my_stack);
    printf("Popped data: %d\n", popped_data);
    display(my_stack);
    popped_data = pop(my_stack);
    printf("Popped data: %d\n", popped_data);
    display(my_stack);
    popped_data = pop(my_stack);
    printf("Popped data: %d\n", popped_data);
    display(my_stack);
    popped_data = pop(my_stack);
    printf("Popped data: %d\n", popped_data);
    display(my_stack);
    free(my_stack);
    return 0;
}