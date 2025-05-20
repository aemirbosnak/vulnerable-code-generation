//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary search tree
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a new node into the binary search tree
void insert(struct Node** root, int data) {
    if (*root == NULL) {
        *root = newNode(data);
    } else if (data < (*root)->data) {
        insert(&(*root)->left, data);
    } else {
        insert(&(*root)->right, data);
    }
}

// Function to search for a node in the binary search tree
struct Node* search(struct Node* root, int data) {
    if (root == NULL) {
        return NULL;
    }

    if (data < root->data) {
        return search(root->left, data);
    } else if (data > root->data) {
        return search(root->right, data);
    } else {
        return root;
    }
}

// Function to delete a node from the binary search tree
void delete(struct Node** root, int data) {
    if (*root == NULL) {
        return;
    }

    if (data < (*root)->data) {
        delete(&(*root)->left, data);
    } else if (data > (*root)->data) {
        delete(&(*root)->right, data);
    } else {
        if ((*root)->left == NULL && (*root)->right == NULL) {
            free(*root);
            *root = NULL;
        } else {
            struct Node* temp = (*root)->left == NULL ? (*root)->right : (*root)->left;
            temp->data = (*root)->data;
            delete(&temp->left, (*root)->left == NULL ? NULL : (*root)->left->data);
            delete(&temp->right, (*root)->right == NULL ? NULL : (*root)->right->data);
            free(*root);
            *root = temp;
        }
    }
}

int main() {
    struct Node* root = NULL;

    insert(&root, 5);
    insert(&root, 2);
    insert(&root, 8);
    insert(&root, 3);
    insert(&root, 1);
    insert(&root, 6);
    insert(&root, 4);

    struct Node* node = search(root, 5);
    if (node != NULL) {
        printf("Found %d\n", node->data);
    } else {
        printf("Not found\n");
    }

    delete(&root, 5);

    node = search(root, 5);
    if (node != NULL) {
        printf("Found %d\n", node->data);
    } else {
        printf("Not found\n");
    }

    return 0;
}