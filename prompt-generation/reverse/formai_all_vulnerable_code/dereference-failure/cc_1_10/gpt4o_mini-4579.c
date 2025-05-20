//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Define a structure for the nodes of the Expression Tree
typedef struct ExprTreeNode {
    char operation;             // Operation (e.g., '+', '-', '*', '/')
    double value;              // Value for number nodes
    struct ExprTreeNode* left; // Left child
    struct ExprTreeNode* right;// Right child
} ExprTreeNode;

// Function to create a new number node
ExprTreeNode* createNumberNode(double value) {
    ExprTreeNode* node = (ExprTreeNode*)malloc(sizeof(ExprTreeNode));
    node->operation = ' ';
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to create a new operation node
ExprTreeNode* createOperationNode(char operation, ExprTreeNode* left, ExprTreeNode* right) {
    ExprTreeNode* node = (ExprTreeNode*)malloc(sizeof(ExprTreeNode));
    node->operation = operation;
    node->value = 0; // Value set to 0 for operations
    node->left = left;
    node->right = right;
    return node;
}

// Function to evaluate the expression tree
double evaluateExprTree(ExprTreeNode* node) {
    if (node->operation == ' ') {
        return node->value; // Return the value if it's a number node
    }
    
    double leftValue = evaluateExprTree(node->left);
    double rightValue = evaluateExprTree(node->right);
    
    switch (node->operation) {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        case '/':
            if (rightValue != 0) {
                return leftValue / rightValue;
            } else {
                printf("Error: Division by zero\n");
                exit(EXIT_FAILURE);
            }
    }
    return 0; // Should never reach here
}

// Function for in-order traversal of the tree (to visualize the expression)
void inOrderTraversal(ExprTreeNode* node) {
    if (node == NULL) {
        return;
    }
    
    if (node->left != NULL) {
        inOrderTraversal(node->left);
    }
    
    if (node->operation == ' ') {
        printf("%.2f ", node->value); // Print the value if it's a number node
    } else {
        printf("%c ", node->operation); // Print the operation
    }
    
    if (node->right != NULL) {
        inOrderTraversal(node->right);
    }
}

// Function to free the expression tree
void freeExprTree(ExprTreeNode* node) {
    if (node == NULL) {
        return;
    }
    freeExprTree(node->left);
    freeExprTree(node->right);
    free(node);
}

// Main function to demonstrate the expression tree
int main() {
    // Creating a simple expression tree for: (3 + 4) * (5 - 2)
    ExprTreeNode* n1 = createNumberNode(3);
    ExprTreeNode* n2 = createNumberNode(4);
    ExprTreeNode* n3 = createNumberNode(5);
    ExprTreeNode* n4 = createNumberNode(2);
    
    ExprTreeNode* addNode = createOperationNode('+', n1, n2);
    ExprTreeNode* subNode = createOperationNode('-', n3, n4);
    ExprTreeNode* root = createOperationNode('*', addNode, subNode);
    
    // Display the expression in infix notation
    printf("Expression in infix notation: ");
    inOrderTraversal(root);
    printf("\n");
    
    // Evaluate the expression
    double result = evaluateExprTree(root);
    printf("Result of the expression: %.2f\n", result);
    
    // Free the memory allocated for the expression tree
    freeExprTree(root);
    
    return 0;
}