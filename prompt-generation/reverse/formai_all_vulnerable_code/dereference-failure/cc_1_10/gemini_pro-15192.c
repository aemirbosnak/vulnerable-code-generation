//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: unmistakable
// A whimsical C program that parses syntax with a dash of eccentricity

#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a syntax node
typedef struct SyntaxNode {
    char type; // The type of the node (e.g., 'E', 'T', 'F')
    struct SyntaxNode *left; // The left child node
    struct SyntaxNode *right; // The right child node
} SyntaxNode;

// Create a new syntax node
SyntaxNode *createNode(char type) {
    SyntaxNode *node = (SyntaxNode *)malloc(sizeof(SyntaxNode));
    node->type = type;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Parse an expression
SyntaxNode *parseExpression() {
    // Get the first token
    char token = getchar();

    // Create the root node
    SyntaxNode *root = createNode('E');

    // Parse the left subtree
    if (token == '(') {
        root->left = parseExpression();
        token = getchar(); // Consume the closing parenthesis
    } else {
        root->left = createNode('F');
        root->left->type = token;
    }

    // Parse the operator
    if (token == '+' || token == '-') {
        root->type = token;
        token = getchar(); // Consume the operator
    }

    // Parse the right subtree
    if (token == '(') {
        root->right = parseExpression();
        token = getchar(); // Consume the closing parenthesis
    } else {
        root->right = createNode('F');
        root->right->type = token;
    }

    // Return the root node
    return root;
}

// Print a syntax tree
void printSyntaxTree(SyntaxNode *root) {
    if (root == NULL) {
        return;
    }

    // Print the node's type
    printf("%c", root->type);

    // Print the left subtree
    printSyntaxTree(root->left);

    // Print the right subtree
    printSyntaxTree(root->right);
}

// Main function
int main() {
    // Parse the expression
    SyntaxNode *root = parseExpression();

    // Print the syntax tree
    printSyntaxTree(root);

    // Free the syntax tree
    free(root);

    return 0;
}