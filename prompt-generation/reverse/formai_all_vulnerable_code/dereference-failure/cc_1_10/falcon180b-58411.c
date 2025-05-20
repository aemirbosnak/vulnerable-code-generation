//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define stack structure
typedef struct stack {
    Node* top;
    int size;
} Stack;

// Create a new node with given data
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Memory could not be allocated.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Create a new empty stack
Stack* create_stack() {
    Stack* new_stack = (Stack*)malloc(sizeof(Stack));
    if (new_stack == NULL) {
        printf("Error: Memory could not be allocated.\n");
        exit(1);
    }
    new_stack->top = NULL;
    new_stack->size = 0;
    return new_stack;
}

// Check if the stack is empty
bool is_empty(Stack* stack) {
    return stack->top == NULL;
}

// Get the size of the stack
int get_size(Stack* stack) {
    return stack->size;
}

// Push a node onto the stack
void push(Stack* stack, int data) {
    Node* new_node = create_node(data);
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}

// Pop a node from the stack
int pop(Stack* stack) {
    if (is_empty(stack)) {
        printf("Error: Stack is empty.\n");
        exit(1);
    }
    Node* temp_node = stack->top;
    int popped_data = temp_node->data;
    stack->top = temp_node->next;
    free(temp_node);
    stack->size--;
    return popped_data;
}

// Print the stack
void print_stack(Stack* stack) {
    if (is_empty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    Node* current_node = stack->top;
    while (current_node!= NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Main function demonstrating usage of stack operations
int main() {
    Stack* my_stack = create_stack();

    push(my_stack, 10);
    push(my_stack, 20);
    push(my_stack, 30);

    print_stack(my_stack);

    int popped_data = pop(my_stack);
    printf("Popped data: %d\n", popped_data);

    print_stack(my_stack);

    popped_data = pop(my_stack);
    printf("Popped data: %d\n", popped_data);

    print_stack(my_stack);

    popped_data = pop(my_stack);
    printf("Popped data: %d\n", popped_data);

    print_stack(my_stack);

    return 0;
}