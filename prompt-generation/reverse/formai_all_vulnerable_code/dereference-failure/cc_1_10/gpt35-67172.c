//FormAI DATASET v1.0 Category: Binary search trees ; Style: complete
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} Node;

/* Function prototyping of all functions */
Node *createNode(int val);
void insert(Node **root, int val);
void inorder(Node *root);

int main() {
    Node *root = NULL;

    /* Inserting values into the binary search tree */
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);

    printf("Inorder traversal of binary search tree: ");
    inorder(root);
    printf("\n");

    return 0;
}

/* Function to create a new node */
Node *createNode(int val) {
    Node *newNode = malloc(sizeof(Node));
    newNode->value = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

/* Function to insert a value into BST */
void insert(Node **root, int val) {
    if (*root == NULL) {
        *root = createNode(val);
        return;
    }

    if (val < (*root)->value) {
        insert(&(*root)->left, val);
    } else if (val > (*root)->value) {
        insert(&(*root)->right, val);
    }
}

/* Function to traverse the BST in inorder */
void inorder(Node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->value);
    inorder(root->right);
}