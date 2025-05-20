//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary search tree
struct Node {
    int key;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node with a given key
struct Node* newNode(int key) {
    struct Node* node = malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node into the binary search tree
void insert(struct Node** root, int key) {
    if (*root == NULL) {
        *root = newNode(key);
    } else if (key < (*root)->key) {
        insert(&(*root)->left, key);
    } else {
        insert(&(*root)->right, key);
    }
}

// Function to search for a node in the binary search tree
struct Node* search(struct Node* root, int key) {
    if (root == NULL) {
        return NULL;
    } else if (key < root->key) {
        return search(root->left, key);
    } else if (key > root->key) {
        return search(root->right, key);
    } else {
        return root;
    }
}

// Function to delete a node from the binary search tree
void delete(struct Node** root, int key) {
    if (*root == NULL) {
        return;
    } else if (key < (*root)->key) {
        delete(&(*root)->left, key);
    } else if (key > (*root)->key) {
        delete(&(*root)->right, key);
    } else {
        // If the node to be deleted has no children, simply free it
        if ((*root)->left == NULL && (*root)->right == NULL) {
            free(*root);
            *root = NULL;
        } else {
            // Find the node's replacement in the tree
            struct Node* replacement = NULL;
            if ((*root)->left == NULL) {
                replacement = (*root)->right;
            } else if ((*root)->right == NULL) {
                replacement = (*root)->left;
            } else {
                // Find the smallest node in the right subtree of the node to be deleted
                replacement = search((*root)->right, (*root)->key);
            }

            // Update the links of the node to be deleted
            if ((*root)->left != NULL) {
                (*root)->left->right = NULL;
            } else {
                (*root)->right->left = NULL;
            }

            // Replace the node to be deleted with the replacement node
            *root = replacement;

            // Free the node to be deleted
            free(*root);
        }
    }
}

int main() {
    struct Node* root = NULL;

    // Insert some nodes into the tree
    insert(&root, 5);
    insert(&root, 3);
    insert(&root, 7);
    insert(&root, 2);
    insert(&root, 4);

    // Search for some nodes in the tree
    struct Node* node = search(root, 5);
    printf("Node with key 5: %p\n", node);

    node = search(root, 3);
    printf("Node with key 3: %p\n", node);

    // Delete some nodes from the tree
    delete(&root, 7);
    delete(&root, 4);

    // Print the remaining nodes in the tree
    struct Node* current = root;
    while (current != NULL) {
        printf("Node with key %d: %p\n", current->key, current);
        current = current->right;
    }

    return 0;
}