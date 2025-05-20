//FormAI DATASET v1.0 Category: Math exercise ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Structure to hold an expression tree */
struct expressionTree {
    char data;
    struct expressionTree *left;
    struct expressionTree *right;
};

/* Function to create a new node for the expression tree */
struct expressionTree *newNode(char x) {
    struct expressionTree *temp = (struct expressionTree*)malloc(sizeof(struct expressionTree));
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}

/* Function to evaluate the expression tree */
int evaluateExpressionTree(struct expressionTree *root) {
    /* If root is a leaf node, return its data */
    if (root->left == NULL && root->right == NULL) {
        return root->data - '0'; // Converting character to integer
    }
    else {
        int leftOperand = evaluateExpressionTree(root->left);
        int rightOperand = evaluateExpressionTree(root->right);
        switch (root->data) {
            case '+':
                return leftOperand + rightOperand;
            case '-':
                return leftOperand - rightOperand;
            case '*':
                return leftOperand * rightOperand;
            case '/':
                return leftOperand / rightOperand;
            case '^':
                return pow(leftOperand, rightOperand);
            default:
                printf("Invalid operator\n");
                return 0;
        }
    }
}

/* Function to build an expression tree from given postfix expression */
struct expressionTree *buildExpressionTree(char *postfix) {
    struct expressionTree *stack[50]; // Stack to hold the nodes of the expression tree
    int top = -1; // Top of the stack
    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            // If the character is a digit, create a new node for it and push onto the stack
            stack[++top] = newNode(postfix[i]);
        }
        else {
            // If the character is an operator, pop two nodes from the stack, create a new node with the operator as its data,
            // and make the popped nodes as the children of the new node. Finally, push the new node onto the stack.
            struct expressionTree *temp = newNode(postfix[i]);
            temp->right = stack[top--];
            temp->left = stack[top--];
            stack[++top] = temp;
        }
    }
    // The last node remaining on the stack is the root of the expression tree
    return stack[top];
}

int main() {
    char postfix[50];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);
    struct expressionTree *root = buildExpressionTree(postfix);
    printf("Result = %d\n", evaluateExpressionTree(root));
    return 0;
}