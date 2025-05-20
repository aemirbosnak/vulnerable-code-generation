//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = data;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a new node in the tree
void insert(struct Node** root, int key) {
    if (*root == NULL) {
        *root = newNode(key);
        return;
    }

    struct Node* current = *root;
    while (1) {
        if (key < current->key) {
            if (current->left == NULL) {
                current->left = newNode(key);
                return;
            }
            current = current->left;
        } else {
            if (current->right == NULL) {
                current->right = newNode(key);
                return;
            }
            current = current->right;
        }
    }
}

// Function to search for a key in the tree
int search(struct Node* root, int key) {
    struct Node* current = root;
    while (current!= NULL) {
        if (key == current->key) {
            return 1;
        }
        if (key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return 0;
}

// Function to print the binary search tree inorder
void printInorder(struct Node* root) {
    if (root!= NULL) {
        printInorder(root->left);
        printf("%d ", root->key);
        printInorder(root->right);
    }
}

// Function to delete a key from the tree
void delete(struct Node** root, int key) {
    if (*root == NULL) {
        return;
    }

    if (key < (*root)->key) {
        delete(&(*root)->left, key);
    } else if (key > (*root)->key) {
        delete(&(*root)->right, key);
    } else {
        // Node with only one child or no child
        if ((*root)->left == NULL) {
            struct Node* temp = (*root)->right;
            free((*root));
            *root = temp;
        } else if ((*root)->right == NULL) {
            struct Node* temp = (*root)->left;
            free((*root));
            *root = temp;
        } else {
            // Node with two children: get the inorder successor (smallest in the right subtree)
            struct Node* temp = (*root)->right;
            while (temp->left!= NULL) {
                temp = temp->left;
            }
            (*root)->key = temp->key;
            delete(&(*root)->right, temp->key);
        }
    }
}

int main() {
    struct Node* root = NULL;
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);

    printf("Inorder traversal of the binary search tree:\n");
    printInorder(root);

    printf("\nDeleting node with key 40...\n");
    delete(&root, 40);

    printf("\nInorder traversal of the binary search tree after deletion:\n");
    printInorder(root);

    return 0;
}