//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: complex
#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left, *right;
};

typedef struct node Node;

//Create a new node
Node *newNode(int key) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

//Inorder traversal of a binary search tree
void inorder(Node *node) {
    if (node == NULL)
        return;
    inorder(node->left);
    printf("%d ", node->key);
    inorder(node->right);
}

//Insert a key into the binary search tree
Node *insert(Node *root, int key) {
    if (root == NULL)
        return newNode(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

//Delete a node from the binary search tree
Node *deleteNode(Node *root, int key) {
    if (root == NULL)
        return NULL;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        root->key = minValue(root->right);
        root->right = deleteNode(root->right, root->key);
    }
    return root;
}

//Function to find minimum value in a subtree
int minValue(Node *node) {
    while (node->left!= NULL)
        node = node->left;
    return node->key;
}

int main() {
    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    printf("Inorder traversal of binary search tree is:\n");
    inorder(root);
    printf("\n");
    printf("Deleting 20 from binary search tree\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of binary search tree is:\n");
    inorder(root);
    return 0;
}