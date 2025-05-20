//Falcon-180B DATASET v1.0 Category: Memory management ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// node structure for linked list
typedef struct node {
    char *data;
    struct node *next;
} Node;

// stack structure using linked list
typedef struct stack {
    Node *top;
} Stack;

// function to push an element onto the stack
void push(Stack *stack, char *data) {
    Node *node = (Node *) malloc(sizeof(Node));
    if (node == NULL) {
        printf("Memory error: could not allocate node\n");
        exit(1);
    }
    node->data = data;
    node->next = stack->top;
    stack->top = node;
}

// function to pop an element off the stack
char *pop(Stack *stack) {
    Node *node = stack->top;
    char *data = node->data;
    stack->top = node->next;
    free(node);
    return data;
}

// main function
int main() {
    Stack stack;
    stack.top = NULL;

    // push some elements onto the stack
    push(&stack, "hello");
    push(&stack, "world");
    push(&stack, "how");
    push(&stack, "are");
    push(&stack, "you");

    // print the elements in reverse order
    printf("Original stack:\n");
    while (stack.top!= NULL) {
        printf("%s ", pop(&stack));
    }
    printf("\n");

    // free the memory used by the stack
    while (stack.top!= NULL) {
        pop(&stack);
    }

    return 0;
}