//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the stack
#define MAX_STACK_SIZE 100

// Define the node structure for the stack
typedef struct {
    int data;
    struct node *next;
} StackNode;

// Define the stack structure
typedef struct {
    StackNode *top;
} Stack;

// Initialize the stack
void init_stack(Stack *s) {
    s->top = NULL;
}

// Push an element onto the stack
void push(Stack *s, int data) {
    StackNode *node = (StackNode *)malloc(sizeof(StackNode));
    if (node == NULL) {
        printf("Stack overflow\n");
        exit(1);
    }
    node->data = data;
    node->next = s->top;
    s->top = node;
}

// Pop an element from the stack
int pop(Stack *s) {
    StackNode *node = s->top;
    int data = node->data;
    s->top = node->next;
    free(node);
    return data;
}

// Display the elements in the stack
void display(Stack *s) {
    if (s->top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements:\n");
    StackNode *node = s->top;
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Main function to demonstrate the stack operations
int main() {
    Stack s;
    init_stack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);

    display(&s);

    int popped_data = pop(&s);
    printf("Popped element: %d\n", popped_data);

    display(&s);

    popped_data = pop(&s);
    printf("Popped element: %d\n", popped_data);

    display(&s);

    popped_data = pop(&s);
    printf("Popped element: %d\n", popped_data);

    display(&s);

    popped_data = pop(&s);
    printf("Popped element: %d\n", popped_data);

    display(&s);

    return 0;
}