//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left;
    struct node *right;
};

struct node* new_node(int key) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* root, int key) {
    if (root == NULL) {
        root = new_node(key);
    } else if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

void inorder(struct node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

int main() {
    struct node* root = NULL;
    insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 5);
    insert(root, 15);
    insert(root, 25);
    insert(root, 35);
    insert(root, 40);
    insert(root, 50);
    printf("Inorder traversal of BST:\n");
    inorder(root);
    return 0;
}