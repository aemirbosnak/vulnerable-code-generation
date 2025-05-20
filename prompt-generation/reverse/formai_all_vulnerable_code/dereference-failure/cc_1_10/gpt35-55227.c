//FormAI DATASET v1.0 Category: Binary search trees ; Style: careful
#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left, *right;
};

// Create a new node
struct node* newNode(int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert a new node
struct node* insertNode(struct node* node, int key) {
    if (node == NULL) return newNode(key);
    if (key < node->key)
        node->left = insertNode(node->left, key);
    else if (key > node->key)
        node->right = insertNode(node->right, key);
    return node;
}

// Inorder traversal
void inorderTraversal(struct node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

// Search for a node
struct node* searchNode(struct node* root, int key) {
    if (root == NULL || root->key == key) return root;
    if (root->key < key) return searchNode(root->right, key);
    return searchNode(root->left, key);
}

// Find the minimum value node
struct node* minValNode(struct node* node) {
    struct node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// Delete a node
struct node* deleteNode(struct node* root, int key) {
    if (root == NULL) return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

int main() {
    struct node* root = NULL;
    
    // Insert some nodes
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);
    
    printf("Inorder traversal of the BST: ");
    inorderTraversal(root);
    
    printf("\n\nDelete 20 from the BST\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified BST: ");
    inorderTraversal(root);

    printf("\n\nDelete 30 from the BST\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal of the modified BST: ");
    inorderTraversal(root);

    printf("\n\nDelete 50 from the BST\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal of the modified BST: ");
    inorderTraversal(root);

    return 0;
}