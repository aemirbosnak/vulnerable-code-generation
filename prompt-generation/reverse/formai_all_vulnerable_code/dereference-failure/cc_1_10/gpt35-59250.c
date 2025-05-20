//FormAI DATASET v1.0 Category: Binary search trees ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node* left;
    struct node* right;
};

struct node* createNode(int key) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, int key) {
    if (root == NULL){
        printf("\nA new knight with strength %d has entered the kingdom!\n", key);
        return createNode(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    } else {
        printf("\nThis knight is already in the kingdom!\n");
        return root;
    }

    return root;
}

struct node* search(struct node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }

    if (root->key < key) {
        return search(root->right, key);
    }

    return search(root->left, key);
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main() {
    struct node* root = NULL;

    root = insert(root, 40);
    root = insert(root, 20);
    root = insert(root, 60);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 50);
    root = insert(root, 70);

    printf("\nThe knights in the kingdom are: ");
    inorder(root);

    struct node* searchNode = search(root, 20);
    if (searchNode == NULL) {
        printf("\nThe knight with strength 20 is not in the kingdom.\n");
    } else {
        printf("\nThe knight with strength 20 is in the kingdom!\n");
    }
    
    return 0;
}