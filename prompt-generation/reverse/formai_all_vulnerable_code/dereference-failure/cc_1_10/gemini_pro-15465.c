//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a node in the parse tree.
typedef struct node {
    char *type;
    struct node *left;
    struct node *right;
} node;

// A function to create a new node in the parse tree.
node *new_node(char *type) {
    node *n = malloc(sizeof(node));
    n->type = type;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// A function to parse an expression.
node *parse_expression(char *expr) {
    // Check if the expression is empty.
    if (*expr == '\0') {
        return NULL;
    }

    // Check if the expression is a number.
    if (isdigit(*expr)) {
        // Create a new node for the number.
        node *n = new_node("number");
        n->type = expr;
        return n;
    }

    // Check if the expression is a variable.
    if (isalpha(*expr)) {
        // Create a new node for the variable.
        node *n = new_node("variable");
        n->type = expr;
        return n;
    }

    // Check if the expression is a parenthesis.
    if (*expr == '(') {
        // Parse the expression inside the parenthesis.
        node *n = parse_expression(expr + 1);
        if (n == NULL) {
            return NULL;
        }

        // Check if the parenthesis is closed.
        if (*expr != ')') {
            return NULL;
        }

        return n;
    }

    // Check if the expression is an operator.
    if (*expr == '+' || *expr == '-' || *expr == '*' || *expr == '/') {
        // Create a new node for the operator.
        node *n = new_node("operator");
        n->type = expr;

        // Parse the left and right expressions.
        n->left = parse_expression(expr + 1);
        if (n->left == NULL) {
            return NULL;
        }
        n->right = parse_expression(expr + 2);
        if (n->right == NULL) {
            return NULL;
        }

        return n;
    }

    // If the expression is not valid, return NULL.
    return NULL;
}

// A function to print the parse tree.
void print_tree(node *tree) {
    if (tree == NULL) {
        return;
    }

    printf("%s ", tree->type);
    print_tree(tree->left);
    print_tree(tree->right);
}

int main() {
    // Parse the expression.
    node *tree = parse_expression("1 + 2 * 3");

    // Print the parse tree.
    print_tree(tree);

    return 0;
}