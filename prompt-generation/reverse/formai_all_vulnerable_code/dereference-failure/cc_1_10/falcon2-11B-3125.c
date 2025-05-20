//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Define a struct to hold elements of the stack
typedef struct {
    char *str;
    struct stack_node *next;
} stack_element;

// Define a struct to hold the stack itself
typedef struct {
    stack_element *top;
    int size;
} stack;

// Function to create a new stack
stack *create_stack(int size) {
    stack *new_stack = (stack *)malloc(sizeof(stack));
    new_stack->top = NULL;
    new_stack->size = size;
    return new_stack;
}

// Function to add an element to the top of the stack
void push(stack *stack, char *str) {
    stack_element *new_element = (stack_element *)malloc(sizeof(stack_element));
    new_element->str = str;
    new_element->next = NULL;
    if (stack->top == NULL) {
        stack->top = new_element;
    } else {
        stack_element *current = stack->top;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_element;
    }
    stack->size++;
}

// Function to remove the top element from the stack
char *pop(stack *stack) {
    stack_element *current = stack->top;
    if (current == NULL) {
        return NULL;
    }
    char *str = current->str;
    stack_element *temp = current->next;
    free(current);
    stack->size--;
    return str;
}

// Function to print the stack in reverse order
void print_stack(stack *stack) {
    stack_element *current = stack->top;
    while (current!= NULL) {
        printf("%s\n", current->str);
        current = current->next;
    }
}

int main() {
    stack *stack = create_stack(MAX_SIZE);

    push(stack, "Hello");
    push(stack, "World");
    push(stack, "Stack");

    printf("Stack contents:\n");
    print_stack(stack);

    printf("\nPopped: %s\n", pop(stack));

    printf("\nStack contents after pop:\n");
    print_stack(stack);

    return 0;
}