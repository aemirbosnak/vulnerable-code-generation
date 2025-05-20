//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

//Define node struct
struct node {
    int key;
    struct node* left;
    struct node* right;
};

//Binary search tree function
struct node* insert(struct node* node, int key) {
    //If node is empty, return a new node with the key
    if (node == NULL) {
        struct node* newNode = (struct node*) malloc(sizeof(struct node));
        newNode->key = key;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    //Otherwise, traverse the tree until you find the correct position
    else if (key < node->key) {
        node->left = insert(node->left, key);
    }
    else if (key > node->key) {
        node->right = insert(node->right, key);
    }
    return node;
}

//Inorder traversal function
void inorder(struct node* node) {
    if (node!= NULL) {
        inorder(node->left);
        printf("%d ", node->key);
        inorder(node->right);
    }
}

int main() {
    //Create root node
    struct node* root = NULL;
    //Insert some nodes
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    //Print inorder traversal
    inorder(root);
    return 0;
}