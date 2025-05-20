//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Node structure for binary search tree
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node with given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node into the tree
void insert(struct Node** root, int data) {
    if (*root == NULL) {
        *root = newNode(data);
    } else if (data <= (*root)->data) {
        insert(&(*root)->left, data);
    } else {
        insert(&(*root)->right, data);
    }
}

// Function to search for a node in the tree
struct Node* search(struct Node* root, int data) {
    if (root == NULL) {
        return NULL;
    }
    if (data == root->data) {
        return root;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
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
            struct Node* temp = (*root)->right;
            while (temp->left != NULL) {
                (*root)->right = temp->left;
                temp = temp->left;
            }
            (*root)->right = temp;
        }
    } else if (data < (*root)->data) {
        delete(&(*root)->left, data);
    } else {
        delete(&(*root)->right, data);
    }
}

int main() {
    struct Node* root = NULL;
    insert(&root, 5);
    insert(&root, 2);
    insert(&root, 8);
    insert(&root, 3);
    insert(&root, 6);
    insert(&root, 1);
    insert(&root, 4);
    insert(&root, 9);

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