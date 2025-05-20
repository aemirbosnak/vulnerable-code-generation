//FormAI DATASET v1.0 Category: Binary search trees ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>

// Define a structure for the node
struct node {
    int key;
    struct node *left, *right;
};

// Function to create a new node
struct node* newNode(int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert function to insert a node to the tree
struct node* insert(struct node* node, int key) {
    if (node == NULL) return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

// Function to search for a node
struct node* search(struct node* root, int key) {
    if (root == NULL || root->key == key)
        return root;

    if (root->key < key)
        return search(root->right, key);
    
    return search(root->left, key);
}

// Function to delete a node 
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
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = newNode(root->right->key);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Function to print inorder traversal of the tree
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Main function
int main() {
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal: ");
    inorder(root);

    printf("\nFinding 70 in the tree\n");
    struct node* result = search(root, 70);
    if (result == NULL) printf("Not found");
    else printf("Found: %d", result->key);

    printf("\nDeleting 30 from the tree\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal after deletion: ");
    inorder(root);

    return 0;
}