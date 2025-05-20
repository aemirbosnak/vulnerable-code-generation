//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the BST
struct Node {
    int key;
    struct Node *left, *right;
};

// Function to create a new node with a given key
struct Node* newNode(int key) {
    struct Node* node = malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a key into the BST
void insert(struct Node** root, int key) {
    if (*root == NULL) {
        *root = newNode(key);
    } else if (key < (*root)->key) {
        insert(&(*root)->left, key);
    } else {
        insert(&(*root)->right, key);
    }
}

// Function to search for a key in the BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL) {
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

// Function to delete a key from the BST
void delete(struct Node** root, int key) {
    if (*root == NULL) {
        return;
    }
    if (key < (*root)->key) {
        delete(&(*root)->left, key);
    } else if (key > (*root)->key) {
        delete(&(*root)->right, key);
    } else {
        if ((*root)->left == NULL && (*root)->right == NULL) {
            free(*root);
            *root = NULL;
        } else {
            struct Node* temp = (*root)->left == NULL ? (*root)->right : (*root)->left;
            (*root)->key = temp->key;
            (*root)->left = temp->left;
            (*root)->right = temp->right;
            free(temp);
        }
    }
}

int main() {
    struct Node* root = NULL;

    // Test cases
    insert(&root, 10);
    insert(&root, 5);
    insert(&root, 8);
    insert(&root, 2);
    insert(&root, 12);

    // Search for keys
    struct Node* node = search(root, 5);
    if (node != NULL) {
        printf("Key 5 found at %p\n", node);
    } else {
        printf("Key 5 not found\n");
    }

    node = search(root, 12);
    if (node != NULL) {
        printf("Key 12 found at %p\n", node);
    } else {
        printf("Key 12 not found\n");
    }

    // Delete keys
    delete(&root, 5);
    delete(&root, 12);

    // Print the remaining keys
    struct Node* current = root;
    while (current != NULL) {
        printf("%d ", current->key);
        current = current->left;
    }
    printf("\n");

    return 0;
}