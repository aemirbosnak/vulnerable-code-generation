//Falcon-180B DATASET v1.0 Category: Syntax parsing ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Define a struct for a node in the syntax tree
typedef struct {
    char *value;
    struct node *left;
    struct node *right;
} node;

// Define a function to create a new node
node *createNode(char *value) {
    node *newNode = (node *) malloc(sizeof(node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Define a function to print the syntax tree
void printTree(node *root) {
    if (root == NULL) {
        return;
    }
    printf("%s ", root->value);
    printTree(root->left);
    printTree(root->right);
}

// Define a function to parse the input string and build the syntax tree
node *parse(char *input) {
    char *token = strtok(input, " ");
    node *root = createNode(token);

    while ((token = strtok(NULL, " "))!= NULL) {
        if (strcmp(token, "+") == 0) {
            node *newNode = createNode("+");
            newNode->left = root;
            root = newNode;
        } else if (strcmp(token, "-") == 0) {
            node *newNode = createNode("-");
            newNode->left = root;
            root = newNode;
        } else if (strcmp(token, "*") == 0) {
            node *newNode = createNode("*");
            newNode->left = root;
            root = newNode;
        } else if (strcmp(token, "/") == 0) {
            node *newNode = createNode("/");
            newNode->left = root;
            root = newNode;
        } else if (strcmp(token, "(") == 0) {
            node *newNode = createNode("(");
            newNode->left = root;
            root = newNode;
        } else if (strcmp(token, ")") == 0) {
            node *newNode = createNode(")");
            newNode->left = root;
            root = newNode;
        } else {
            node *newNode = createNode(token);
            newNode->left = root;
            root = newNode;
        }
    }

    return root;
}

// Define the main function
int main(int argc, char *argv[]) {
    char *input = argv[1];
    node *root = parse(input);
    printTree(root);
    return 0;
}