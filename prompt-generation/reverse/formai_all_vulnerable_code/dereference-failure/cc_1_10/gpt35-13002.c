//FormAI DATASET v1.0 Category: Syntax parsing ; Style: imaginative
#include<stdio.h>

/* This program parses a syntax tree */
/* It starts with a root node and branches into different nodes*/

/* Define the structure of the node */
struct Node {
    char value;
    struct Node* left;
    struct Node* right;  
};

/* Create a function to add node to the syntax tree */
struct Node* addNode(char value) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node -> value = value;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

/* Create a function to print the syntax tree */
void printTree(struct Node* root, int space) {
    if (root == NULL) {
        return;
    }

    /* Print the right node */
    printTree(root -> right, space + 5);

    /* Print the value of the root node with proper indentation */
    printf("\n");
    for (int i = 0; i < space; i++) {
        printf(" ");
    }
    printf("%c\n", root -> value);

    /* Print the left node */
    printTree(root -> left, space + 5);

}

int main() {

    /* Create the root node */
    struct Node* root = addNode('A');

    /* Create the left and right child nodes */
    root -> left = addNode('B');
    root -> right = addNode('C');

    /* Create more child nodes */
    root -> left -> left = addNode('D');
    root -> left -> right = addNode('E');
    root -> right -> left = addNode('F');
    root -> right -> right = addNode('G');

    /* Print the syntax tree */
    printf("\n\n Here's the syntax tree: \n\n");
    printTree(root, 0);

    return 0;
}