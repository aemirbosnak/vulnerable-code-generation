//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a node in the syntax tree
typedef struct node {
    char* type;
    struct node* left;
    struct node* right;
} node;

// Function to create a new node
node* createNode(char* type) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->type = type;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to parse an expression
node* parseExpression(char* expression) {
    // Check if the expression is empty
    if (strlen(expression) == 0) {
        return NULL;
    }

    // Get the first character of the expression
    char firstChar = expression[0];

    // If the first character is an operand, create a new node with that operand
    if (firstChar >= 'a' && firstChar <= 'z') {
        node* newNode = createNode("operand");
        newNode->type = firstChar;
        return newNode;
    }

    // If the first character is an operator, create a new node with that operator
    else if (firstChar == '+' || firstChar == '-' || firstChar == '*' || firstChar == '/') {
        node* newNode = createNode("operator");
        newNode->type = firstChar;

        // Parse the left and right subexpressions
        newNode->left = parseExpression(expression + 1);
        newNode->right = parseExpression(expression + 2);

        return newNode;
    }

    // If the first character is not a valid operand or operator, return NULL
    else {
        return NULL;
    }
}

// Function to print the syntax tree
void printSyntaxTree(node* root) {
    // If the root is NULL, return
    if (root == NULL) {
        return;
    }

    // Print the root
    printf("%s\n", root->type);

    // Print the left and right subtrees
    printSyntaxTree(root->left);
    printSyntaxTree(root->right);
}

// Function to free the syntax tree
void freeSyntaxTree(node* root) {
    // If the root is NULL, return
    if (root == NULL) {
        return;
    }

    // Free the left and right subtrees
    freeSyntaxTree(root->left);
    freeSyntaxTree(root->right);

    // Free the root
    free(root);
}

// Main function
int main() {
    // Get the input expression
    char* expression = "a+b*c";

    // Parse the expression
    node* root = parseExpression(expression);

    // Print the syntax tree
    printSyntaxTree(root);

    // Free the syntax tree
    freeSyntaxTree(root);

    return 0;
}