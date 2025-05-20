//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char *data;
    struct node *next;
};

struct stack {
    struct node *top;
};

void push(struct stack *s, char *data) {
    struct node *n = malloc(sizeof(struct node));
    n->data = data;
    n->next = s->top;
    s->top = n;
}

char *pop(struct stack *s) {
    if (s->top == NULL) {
        return NULL;
    }
    char *data = s->top->data;
    struct node *n = s->top;
    s->top = s->top->next;
    free(n);
    return data;
}

int peek(struct stack *s) {
    if (s->top == NULL) {
        return -1;
    }
    return s->top->data;
}

int is_empty(struct stack *s) {
    return s->top == NULL;
}

struct tree {
    char *data;
    struct tree *left;
    struct tree *right;
};

struct tree *create_tree(char *data) {
    struct tree *t = malloc(sizeof(struct tree));
    t->data = data;
    t->left = NULL;
    t->right = NULL;
    return t;
}

void insert_left(struct tree *t, struct tree *left) {
    t->left = left;
}

void insert_right(struct tree *t, struct tree *right) {
    t->right = right;
}

void print_tree(struct tree *t) {
    if (t == NULL) {
        return;
    }
    printf("%s\n", t->data);
    print_tree(t->left);
    print_tree(t->right);
}

int main() {
    char *input = "(* (+ 1 2) (- 3 4))";
    struct stack s;
    s.top = NULL;
    char *token = strtok(input, " ");
    while (token != NULL) {
        if (strcmp(token, "(") == 0) {
            push(&s, token);
        } else if (strcmp(token, ")") == 0) {
            char *op = pop(&s);
            char *right = pop(&s);
            char *left = pop(&s);
            struct tree *t = create_tree(op);
            insert_left(t, create_tree(left));
            insert_right(t, create_tree(right));
            push(&s, t);
        } else {
            push(&s, token);
        }
        token = strtok(NULL, " ");
    }
    struct tree *t = pop(&s);
    print_tree(t);
    return 0;
}