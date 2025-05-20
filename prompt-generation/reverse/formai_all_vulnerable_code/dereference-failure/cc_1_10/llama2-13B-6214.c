//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: genius
#include <stdio.h>
#include <stdlib.h>

// Definition of the BST node
struct BSTNode {
    int key;
    struct BSTNode *left, *right;
};

// Function to create a new BST node with a given key
struct BSTNode *newBSTNode(int key) {
    struct BSTNode *node = (struct BSTNode *) malloc(sizeof(struct BSTNode));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a node into the BST
void insertBST(struct BSTNode **root, int key) {
    if (*root == NULL) {
        *root = newBSTNode(key);
    } else if (key < (*root)->key) {
        insertBST(&(*root)->left, key);
    } else {
        insertBST(&(*root)->right, key);
    }
}

// Function to search for a node in the BST
struct BSTNode *searchBST(struct BSTNode *root, int key) {
    if (root == NULL) {
        return NULL;
    } else if (root->key == key) {
        return root;
    } else {
        return searchBST(root->left, key) ?: searchBST(root->right, key);
    }
}

// Function to delete a node from the BST
void deleteBST(struct BSTNode **root, int key) {
    if (*root == NULL) {
        return;
    } else if ((*root)->key == key) {
        if ((*root)->left == NULL && (*root)->right == NULL) {
            free(*root);
            *root = NULL;
        } else if ((*root)->left == NULL) {
            (*root)->right = NULL;
        } else if ((*root)->right == NULL) {
            (*root)->left = NULL;
        } else {
            struct BSTNode *temp = (*root)->right;
            while (temp->left != NULL) {
                (*root)->right = temp->left;
                temp = temp->left;
            }
            free(temp);
        }
    } else {
        deleteBST(&(*root)->left, key);
    }
}

int main() {
    struct BSTNode *root = NULL;
    insertBST(&root, 5);
    insertBST(&root, 3);
    insertBST(&root, 7);
    insertBST(&root, 2);
    insertBST(&root, 4);

    struct BSTNode *node = searchBST(root, 7);
    if (node != NULL) {
        printf("Found %d\n", node->key);
    } else {
        printf("Not found\n");
    }

    deleteBST(&root, 4);

    node = searchBST(root, 4);
    if (node != NULL) {
        printf("Found %d\n", node->key);
    } else {
        printf("Not found\n");
    }

    return 0;
}