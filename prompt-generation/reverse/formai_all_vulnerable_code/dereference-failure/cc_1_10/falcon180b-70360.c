//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum size of the stack
#define MAX_STACK_SIZE 100

// Define the structure of a stack node
typedef struct {
    int data;
    struct stack_node* next;
} stack_node;

// Define the structure of a stack
typedef struct {
    stack_node* top;
    int size;
} stack;

// Initialize an empty stack
void init_stack(stack* st) {
    st->top = NULL;
    st->size = 0;
}

// Push an element onto the stack
void push_stack(stack* st, int data) {
    stack_node* new_node = (stack_node*) malloc(sizeof(stack_node));
    new_node->data = data;
    new_node->next = st->top;
    st->top = new_node;
    st->size++;
}

// Pop an element from the stack
int pop_stack(stack* st) {
    if (st->top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    stack_node* temp_node = st->top;
    int popped_data = temp_node->data;
    st->top = st->top->next;
    st->size--;
    free(temp_node);
    return popped_data;
}

// Display the elements of the stack
void display_stack(stack* st) {
    if (st->top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    stack_node* curr_node = st->top;
    while (curr_node!= NULL) {
        printf("%d ", curr_node->data);
        curr_node = curr_node->next;
    }
    printf("\n");
}

// Main function
int main() {
    stack st;
    init_stack(&st);

    push_stack(&st, 1);
    push_stack(&st, 2);
    push_stack(&st, 3);
    push_stack(&st, 4);
    push_stack(&st, 5);

    printf("Stack after pushing elements:\n");
    display_stack(&st);

    int popped_data = pop_stack(&st);
    printf("Popped element: %d\n", popped_data);

    printf("Stack after popping an element:\n");
    display_stack(&st);

    return 0;
}