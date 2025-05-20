//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Node structure to represent a binary search tree
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node with a given value
struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node into the tree
void insert(struct Node** root, int data) {
    if (*root == NULL) {
        *root = newNode(data);
    } else {
        if (data < (*root)->data) {
            insert(&(*root)->left, data);
        } else {
            insert(&(*root)->right, data);
        }
    }
}

// Function to search for a node in the tree
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

// Function to delete a node from the tree
void delete(struct Node** root, int data) {
    if (*root == NULL) {
        return;
    }
    if ((*root)->data == data) {
        if ((*root)->left == NULL && (*root)->right == NULL) {
            free(*root);
            *root = NULL;
        } else if ((*root)->left == NULL) {
            (*root)->right = NULL;
        } else if ((*root)->right == NULL) {
            (*root)->left = NULL;
        } else {
            struct Node* temp = search((*root)->left, (*root)->data);
            if (temp != NULL) {
                temp->left = (*root)->right;
                temp->right = NULL;
            } else {
                temp = search((*root)->right, (*root)->data);
                if (temp != NULL) {
                    temp->left = (*root)->left;
                    temp->right = NULL;
                }
            }
            free(*root);
            *root = temp;
        }
    } else {
        delete(&(*root)->left, data);
    }
}

int main() {
    struct Node* root = NULL;
    insert(&root, 5);
    insert(&root, 3);
    insert(&root, 7);
    insert(&root, 2);
    insert(&root, 4);
    insert(&root, 1);
    insert(&root, 6);

    struct Node* node = search(root, 4);
    if (node != NULL) {
        printf("Found %d\n", node->data);
    } else {
        printf("Not found\n");
    }

    delete(&root, 5);

    struct Node* node2 = search(root, 7);
    if (node2 != NULL) {
        printf("Found %d\n", node2->data);
    } else {
        printf("Not found\n");
    }

    return 0;
}