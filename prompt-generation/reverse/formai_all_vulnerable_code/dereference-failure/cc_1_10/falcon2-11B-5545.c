//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node* create_node(int data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a new node in the BST
struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        root = create_node(data);
        return root;
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to search a node in the BST
struct node* search(struct node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Function to print the nodes in inorder traversal
void inorder(struct node* root) {
    if (root!= NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to print the nodes in preorder traversal
void preorder(struct node* root) {
    if (root!= NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function to print the nodes in postorder traversal
void postorder(struct node* root) {
    if (root!= NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    // Create root
    struct node* root = NULL;

    // Insert some nodes
    insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Search for a node
    struct node* search_node = search(root, 50);
    if (search_node!= NULL) {
        printf("Node found: %d\n", search_node->data);
    } else {
        printf("Node not found\n");
    }

    // Inorder traversal
    inorder(root);

    // Preorder traversal
    preorder(root);

    // Postorder traversal
    postorder(root);

    // Free memory
    while (root!= NULL) {
        struct node* temp = root;
        root = root->left;
        free(temp);
    }

    return 0;
}