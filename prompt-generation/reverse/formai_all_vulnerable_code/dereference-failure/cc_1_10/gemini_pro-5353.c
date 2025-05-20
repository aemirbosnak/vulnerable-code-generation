//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom data type for a linked list node
typedef struct node {
    char data;
    struct node *next;
} node_t;

// Custom data type for a stack
typedef struct stack {
    node_t *top;
} stack_t;

// Function to create a new node
node_t *create_node(char data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to push a node onto the stack
void push(stack_t *stack, node_t *new_node) {
    new_node->next = stack->top;
    stack->top = new_node;
}

// Function to pop a node from the stack
node_t *pop(stack_t *stack) {
    if (stack->top == NULL) {
        printf("Error: Stack is empty\n");
        exit(1);
    }
    node_t *temp = stack->top;
    stack->top = stack->top->next;
    return temp;
}

// Function to check if a string is a palindrome
int is_palindrome(char *str) {
    int len = strlen(str);
    stack_t stack;
    stack.top = NULL;
    for (int i = 0; i < len / 2; i++) {
        node_t *new_node = create_node(str[i]);
        push(&stack, new_node);
    }
    int mid = len % 2;
    if (mid) {
        pop(&stack);
    }
    for (int i = len / 2 + mid; i < len; i++) {
        node_t *temp = pop(&stack);
        if (temp->data != str[i]) {
            return 0;
        }
    }
    return 1;
}

// Main function
int main() {
    char str[] = "racecar";
    if (is_palindrome(str)) {
        printf("%s is a palindrome\n", str);
    } else {
        printf("%s is not a palindrome\n", str);
    }
    return 0;
}