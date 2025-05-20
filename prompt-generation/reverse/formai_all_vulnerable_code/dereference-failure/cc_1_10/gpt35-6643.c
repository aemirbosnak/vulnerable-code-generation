//FormAI DATASET v1.0 Category: Data structures visualization ; Style: random
#include <stdio.h>
#include <stdlib.h>

/* define a struct to represent a node in a binary tree */
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

/* function to create a new node */
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* function to insert a new node into the binary tree */
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else {
        if (data <= root->data) {
            root->left = insert(root->left, data);
        } else {
            root->right = insert(root->right, data);
        }
        return root;
    }
}

/* function to print the binary tree using an inorder traversal */
void printTree(Node* root, int depth) {
    if (root) {
        printTree(root->right, depth+1);
        for (int i = 0; i < depth; i++) {
            printf("\t");
        }
        printf("%d\n", root->data);
        printTree(root->left, depth+1);
    }
}

/* the main function */
int main() {
    Node* root = NULL;
    int data;

    /* get input from the user */
    printf("Enter a list of integers to insert into the binary tree (-1 to stop):\n");
    scanf("%d", &data);
    while (data != -1) {
        root = insert(root, data);
        scanf("%d", &data);
    }

    /* print the binary tree */
    printf("\nHere is the binary tree (depth increases from top to bottom):\n");
    printTree(root, 0);

    return 0;
}