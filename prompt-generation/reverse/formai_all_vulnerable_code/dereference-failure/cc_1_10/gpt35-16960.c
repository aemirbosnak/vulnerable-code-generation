//FormAI DATASET v1.0 Category: Data structures visualization ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// define a struct for binary tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// insert a new node to the binary tree
void insert(Node** root, int data) {
    if (*root == NULL) {
        *root = (Node*) malloc(sizeof(Node));
        (*root)->data = data;
        (*root)->left = NULL;
        (*root)->right = NULL;
    } else if (data <= (*root)->data) {
        insert(&((*root)->left), data);
    } else {
        insert(&((*root)->right), data);
    }
}

// print the binary tree from left to right using Inorder traversal
void printInorder(Node* root, int space) {
    if (root != NULL) {
        printInorder(root->right, space + 4);
        printf("%*d\n", space, root->data);
        printInorder(root->left, space + 4);
    }
}

// main function to execute the program
int main() {
    Node* root = NULL;
    int n, data;

    // prompt user to input number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // prompt user to input node values
    printf("Enter the values of the nodes:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insert(&root, data);
    }

    // print the binary tree using Inorder traversal
    printf("Binary Tree Visualization:\n");
    printInorder(root, 0);

    return 0;
}