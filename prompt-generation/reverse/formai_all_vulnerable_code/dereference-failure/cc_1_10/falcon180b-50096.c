//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum size of the stack
#define MAX_STACK_SIZE 100

// Define the structure of a stack node
typedef struct StackNode {
    int data;
    struct StackNode *next;
} StackNode;

// Define the structure of a stack
typedef struct Stack {
    StackNode *top;
    int size;
} Stack;

// Initialize the stack
void init_stack(Stack *s) {
    s->top = NULL;
    s->size = 0;
}

// Push an integer onto the stack
void push_stack(Stack *s, int data) {
    StackNode *node = (StackNode *)malloc(sizeof(StackNode));
    if (node == NULL) {
        printf("Stack overflow\n");
        exit(1);
    }
    node->data = data;
    node->next = s->top;
    s->top = node;
    s->size++;
}

// Pop an integer from the stack
int pop_stack(Stack *s) {
    if (s->top == NULL) {
        printf("Stack underflow\n");
        exit(1);
    }
    StackNode *node = s->top;
    int data = node->data;
    s->top = node->next;
    free(node);
    s->size--;
    return data;
}

// Display the contents of the stack
void display_stack(Stack *s) {
    if (s->top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    StackNode *node = s->top;
    printf("Stack: ");
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

    push_stack(&s, 10);
    push_stack(&s, 20);
    push_stack(&s, 30);
    display_stack(&s);

    int data = pop_stack(&s);
    printf("Popped element: %d\n", data);
    display_stack(&s);

    push_stack(&s, 40);
    push_stack(&s, 50);
    display_stack(&s);

    return 0;
}