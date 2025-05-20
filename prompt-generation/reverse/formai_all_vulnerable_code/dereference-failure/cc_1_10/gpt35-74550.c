//FormAI DATASET v1.0 Category: Syntax parsing ; Style: creative
/* This program parses a mathematical expression string into an syntax tree and evaluates it*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define the node structure for the syntax tree
struct node {
    int type;
    int val;
    struct node *left;
    struct node *right;
};

// Define the token types
enum {
    T_NUMBER,
    T_PLUS,
    T_MINUS,
    T_MULTIPLY,
    T_DIVIDE,
    T_LPAREN,
    T_RPAREN
};

// Define some utility functions
void error(char *msg);
void skip_whitespace(char **ptr);
struct node *new_node(int type);
struct node *new_number_node(int val);
void free_tree(struct node *n);

// Parse an expression string into a syntax tree
struct node *parse_expr(char **ptr) {
    struct node *left, *right, *n;

    skip_whitespace(ptr);

    if (**ptr == '(') {
        ++(*ptr);
        left = parse_expr(ptr);
        skip_whitespace(ptr);

        switch (**ptr) {
            case '+':
                ++(*ptr);
                skip_whitespace(ptr);
                right = parse_expr(ptr);
                skip_whitespace(ptr);

                if (**ptr != ')') {
                    error("Expected )");
                }

                ++(*ptr);
                skip_whitespace(ptr);
                n = new_node(T_PLUS);
                break;

            case '-':
                ++(*ptr);
                skip_whitespace(ptr);
                right = parse_expr(ptr);
                skip_whitespace(ptr);

                if (**ptr != ')') {
                    error("Expected )");
                }

                ++(*ptr);
                skip_whitespace(ptr);
                n = new_node(T_MINUS);
                break;

            case '*':
                ++(*ptr);
                skip_whitespace(ptr);
                right = parse_expr(ptr);
                skip_whitespace(ptr);

                if (**ptr != ')') {
                    error("Expected )");
                }

                ++(*ptr);
                skip_whitespace(ptr);
                n = new_node(T_MULTIPLY);
                break;

            case '/':
                ++(*ptr);
                skip_whitespace(ptr);
                right = parse_expr(ptr);
                skip_whitespace(ptr);

                if (**ptr != ')') {
                    error("Expected )");
                }

                ++(*ptr);
                skip_whitespace(ptr);
                n = new_node(T_DIVIDE);
                break;

            default:
                error("Expected operator");
        }
    } else if (isdigit(**ptr)) {
        int val = 0;

        while (isdigit(**ptr)) {
            val *= 10;
            val += **ptr - '0';
            ++(*ptr);
        }

        left = new_number_node(val);
        right = NULL;
        n = left;
    } else {
        error("Expected number or (");
    }

    n->left = left;
    n->right = right;
    return n;
}

// Evaluate a syntax tree
int evaluate_expr(struct node *n) {
    switch (n->type) {
        case T_NUMBER:
            return n->val;

        case T_PLUS:
            return evaluate_expr(n->left) + evaluate_expr(n->right);

        case T_MINUS:
            return evaluate_expr(n->left) - evaluate_expr(n->right);

        case T_MULTIPLY:
            return evaluate_expr(n->left) * evaluate_expr(n->right);

        case T_DIVIDE:
            return evaluate_expr(n->left) / evaluate_expr(n->right);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <expression>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *ptr = argv[1];
    struct node *expr = parse_expr(&ptr);
    int result = evaluate_expr(expr);

    printf("Result: %d\n", result);
    free_tree(expr);
    return EXIT_SUCCESS;
}

// Define utility functions
void error(char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(EXIT_FAILURE);
}

void skip_whitespace(char **ptr) {
    while (**ptr && isspace(**ptr)) {
        ++(*ptr);
    }
}

struct node *new_node(int type) {
    struct node *n = malloc(sizeof(*n));

    if (!n) {
        error("Out of memory");
    }

    n->type = type;
    n->val = 0;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct node *new_number_node(int val) {
    struct node *n = new_node(T_NUMBER);
    n->val = val;
    return n;
}

void free_tree(struct node *n) {
    if (n->left) {
        free_tree(n->left);
    }

    if (n->right) {
        free_tree(n->right);
    }

    free(n);
}