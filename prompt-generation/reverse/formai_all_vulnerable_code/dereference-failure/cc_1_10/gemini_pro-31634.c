//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A simple linked list to represent a syntax tree node
typedef struct node {
    char *value;
    struct node *next;
} node;

// A stack to keep track of open parentheses and brackets
typedef struct stack {
    node *top;
} stack;

// Create a new node
node *new_node(char *value) {
    node *n = malloc(sizeof(node));
    n->value = strdup(value);
    n->next = NULL;
    return n;
}

// Push a node onto the stack
void push(stack *s, node *n) {
    n->next = s->top;
    s->top = n;
}

// Pop a node from the stack
node *pop(stack *s) {
    if (s->top == NULL) {
        return NULL;
    }
    node *n = s->top;
    s->top = s->top->next;
    return n;
}

// Check if the stack is empty
int is_empty(stack *s) {
    return s->top == NULL;
}

// Parse a C expression and return a syntax tree
node *parse_expression(char *expr) {
    stack s;
    s.top = NULL;
    char *token = strtok(expr, " ");
    while (token != NULL) {
        if (strcmp(token, "(") == 0) {
            push(&s, new_node("("));
        } else if (strcmp(token, ")") == 0) {
            node *n = pop(&s);
            if (n == NULL) {
                fprintf(stderr, "Error: Unbalanced parentheses\n");
                return NULL;
            }
            if (strcmp(n->value, "(") != 0) {
                fprintf(stderr, "Error: Mismatched parentheses\n");
                return NULL;
            }
        } else {
            push(&s, new_node(token));
        }
        token = strtok(NULL, " ");
    }
    if (!is_empty(&s)) {
        fprintf(stderr, "Error: Unbalanced parentheses\n");
        return NULL;
    }
    return s.top;
}

// Print a syntax tree
void print_tree(node *n) {
    if (n == NULL) {
        printf("NULL");
    } else {
        printf("%s ", n->value);
        print_tree(n->next);
    }
}

// Free the memory allocated for a syntax tree
void free_tree(node *n) {
    if (n == NULL) {
        return;
    }
    free_tree(n->next);
    free(n->value);
    free(n);
}

int main() {
    char *expr = "(5 + 3) * 2";
    node *tree = parse_expression(expr);
    if (tree == NULL) {
        return 1;
    }
    print_tree(tree);
    printf("\n");
    free_tree(tree);
    return 0;
}