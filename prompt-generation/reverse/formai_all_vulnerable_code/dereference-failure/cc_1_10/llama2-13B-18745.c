//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: safe
#include <stdbool.h>
#include <stdlib.h>

// Node representing a binary search tree
struct BSTNode {
    int key;
    struct BSTNode *left, *right;
};

// Function to create a new node with the given key
struct BSTNode* newNode(int key) {
    struct BSTNode* node = malloc(sizeof(struct BSTNode));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a key into the binary search tree
void insert(struct BSTNode** root, int key) {
    if (!*root) {
        *root = newNode(key);
        return;
    }

    if (key < (*root)->key) {
        insert(&(*root)->left, key);
    } else {
        insert(&(*root)->right, key);
    }
}

// Function to search for a key in the binary search tree
struct BSTNode* search(struct BSTNode* root, int key) {
    if (!root) {
        return NULL;
    }

    if (key < root->key) {
        return search(root->left, key);
    } else if (key > root->key) {
        return search(root->right, key);
    } else {
        return root;
    }
}

// Function to delete a key from the binary search tree
void delete(struct BSTNode** root, int key) {
    if (!*root) {
        return;
    }

    if (key < (*root)->key) {
        delete(&(*root)->left, key);
    } else if (key > (*root)->key) {
        delete(&(*root)->right, key);
    } else {
        // Key to be deleted is the current node's key
        struct BSTNode* temp = *root;
        *root = (temp->left == NULL ? temp->right : temp->left);
        free(temp);
    }
}

int main() {
    struct BSTNode* root = NULL;

    insert(&root, 5);
    insert(&root, 3);
    insert(&root, 7);
    insert(&root, 2);
    insert(&root, 4);

    // Search for the key 7
    struct BSTNode* node = search(root, 7);
    if (node != NULL) {
        printf("Found key 7 in the tree\n");
    } else {
        printf("Key 7 not found in the tree\n");
    }

    // Delete the key 5
    delete(&root, 5);

    // Search for the key 5 again
    node = search(root, 5);
    if (node != NULL) {
        printf("Found key 5 in the tree after deletion\n");
    } else {
        printf("Key 5 not found in the tree after deletion\n");
    }

    return 0;
}