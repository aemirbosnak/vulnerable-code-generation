//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char type; // 'n' for number, 'o' for operator
    union {
        double number;
        char operator;
    };
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(char type) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->type = type;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void freeNode(Node* node) {
    if (node) {
        freeNode(node->left);
        freeNode(node->right);
        free(node);
    }
}

double evaluate(Node* root) {
    if (!root) return 0;
    if (root->type == 'n') return root->number;
    
    double leftValue = evaluate(root->left);
    double rightValue = evaluate(root->right);
    
    switch (root->operator) {
        case '+': return leftValue + rightValue;
        case '-': return leftValue - rightValue;
        case '*': return leftValue * rightValue;
        case '/': return leftValue / rightValue;
    }
    return 0;
}

void printAST(Node* root, int level) {
    if (root == NULL) return;
    printAST(root->right, level + 1);
    for (int i = 0; i < level; i++) printf("    ");
    if (root->type == 'o') {
        printf("%c\n", root->operator);
    } else {
        printf("%lf\n", root->number);
    }
    printAST(root->left, level + 1);
}

Node* parseExpression(const char **expr);
Node* parseTerm(const char **expr);
Node* parseFactor(const char **expr);

Node* parseNumber(const char **expr) {
    while (isspace(**expr)) (*expr)++;
    
    double value = 0;
    int decimalPlace = -1;

    while (isdigit(**expr) || **expr == '.') {
        if (**expr == '.') {
            decimalPlace = 0; // mark decimal point
        } else {
            value = value * 10 + (**expr - '0');
            if (decimalPlace >= 0) decimalPlace++;
        }
        (*expr)++;
    }

    if (decimalPlace > 0) {
        value /= pow(10, decimalPlace);
    }
    
    Node* node = createNode('n');
    node->number = value;
    return node;
}

Node* parseFactor(const char **expr) {
    while (isspace(**expr)) (*expr)++;
    
    if (**expr == '(') {
        (*expr)++;
        Node* node = parseExpression(expr);
        if (**expr == ')') {
            (*expr)++;
            return node;
        } else {
            fprintf(stderr, "Error: Mismatched parentheses.\n");
            exit(EXIT_FAILURE);
        }
    }
    return parseNumber(expr);
}

Node* parseTerm(const char **expr) {
    Node* left = parseFactor(expr);

    while (1) {
        while (isspace(**expr)) (*expr)++;
        if (**expr == '*') {
            Node* opNode = createNode('o');
            opNode->operator = '*';
            (*expr)++;
            opNode->left = left;
            opNode->right = parseFactor(expr);
            left = opNode;
        } else if (**expr == '/') {
            Node* opNode = createNode('o');
            opNode->operator = '/';
            (*expr)++;
            opNode->left = left;
            opNode->right = parseFactor(expr);
            left = opNode;
        } else {
            break;
        }
    }
    return left;
}

Node* parseExpression(const char **expr) {
    Node* left = parseTerm(expr);

    while (1) {
        while (isspace(**expr)) (*expr)++;
        if (**expr == '+') {
            Node* opNode = createNode('o');
            opNode->operator = '+';
            (*expr)++;
            opNode->left = left;
            opNode->right = parseTerm(expr);
            left = opNode;
        } else if (**expr == '-') {
            Node* opNode = createNode('o');
            opNode->operator = '-';
            (*expr)++;
            opNode->left = left;
            opNode->right = parseTerm(expr);
            left = opNode;
        } else {
            break;
        }
    }
    return left;
}

int main() {
    char input[256];
    printf("Enter a mathematical expression: ");
    fgets(input, sizeof(input), stdin);
    const char *expr = input;

    Node* root = parseExpression(&expr);
    
    printf("Abstract Syntax Tree (AST):\n");
    printAST(root, 0);

    double result = evaluate(root);
    printf("Result of the expression: %lf\n", result);

    freeNode(root);
    return 0;
}