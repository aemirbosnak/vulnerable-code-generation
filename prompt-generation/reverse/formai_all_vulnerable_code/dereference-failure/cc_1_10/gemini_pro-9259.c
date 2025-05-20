//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom data structure to represent a node in the binary search tree
typedef struct BSTNode {
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

// Function to create a new node with the given data
BSTNode *create_node(int data) {
    BSTNode *new_node = (BSTNode *)malloc(sizeof(BSTNode));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a new node into the binary search tree
void insert_node(BSTNode **root, int data) {
    if (*root == NULL) {
        *root = create_node(data);
    } else if (data < (*root)->data) {
        insert_node(&(*root)->left, data);
    } else {
        insert_node(&(*root)->right, data);
    }
}

// Function to search for a node with the given data in the binary search tree
BSTNode *search_node(BSTNode *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (root->data == data) {
        return root;
    } else if (data < root->data) {
        return search_node(root->left, data);
    } else {
        return search_node(root->right, data);
    }
}

// Function to find the minimum node in the binary search tree
BSTNode *find_min_node(BSTNode *root) {
    if (root == NULL) {
        return NULL;
    } else if (root->left == NULL) {
        return root;
    } else {
        return find_min_node(root->left);
    }
}

// Function to find the maximum node in the binary search tree
BSTNode *find_max_node(BSTNode *root) {
    if (root == NULL) {
        return NULL;
    } else if (root->right == NULL) {
        return root;
    } else {
        return find_max_node(root->right);
    }
}

// Function to delete a node with the given data from the binary search tree
void delete_node(BSTNode **root, int data) {
    if (*root == NULL) {
        return;
    } else if (data < (*root)->data) {
        delete_node(&(*root)->left, data);
    } else if (data > (*root)->data) {
        delete_node(&(*root)->right, data);
    } else {
        if ((*root)->left == NULL) {
            BSTNode *temp = *root;
            *root = (*root)->right;
            free(temp);
        } else if ((*root)->right == NULL) {
            BSTNode *temp = *root;
            *root = (*root)->left;
            free(temp);
        } else {
            BSTNode *temp = find_min_node((*root)->right);
            (*root)->data = temp->data;
            delete_node(&(*root)->right, temp->data);
        }
    }
}

// Function to print the binary search tree in preorder traversal
void preorder_traversal(BSTNode *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

// Function to print the binary search tree in inorder traversal
void inorder_traversal(BSTNode *root) {
    if (root == NULL) {
        return;
    }
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}

// Function to print the binary search tree in postorder traversal
void postorder_traversal(BSTNode *root) {
    if (root == NULL) {
        return;
    }
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d ", root->data);
}

int main() {
    // Create a binary search tree
    BSTNode *root = NULL;
    insert_node(&root, 50);
    insert_node(&root, 30);
    insert_node(&root, 70);
    insert_node(&root, 20);
    insert_node(&root, 40);
    insert_node(&root, 60);
    insert_node(&root, 80);

    // Search for a node with the given data in the binary search tree
    BSTNode *found_node = search_node(root, 40);
    if (found_node != NULL) {
        printf("Node with data %d found!\n", found_node->data);
    } else {
        printf("Node with data 40 not found!\n");
    }

    // Find the minimum node in the binary search tree
    BSTNode *min_node = find_min_node(root);
    printf("Minimum node: %d\n", min_node->data);

    // Find the maximum node in the binary search tree
    BSTNode *max_node = find_max_node(root);
    printf("Maximum node: %d\n", max_node->data);

    // Delete a node with the given data from the binary search tree
    delete_node(&root, 40);

    // Print the binary search tree in preorder traversal
    printf("Preorder traversal: ");
    preorder_traversal(root);
    printf("\n");

    // Print the binary search tree in inorder traversal
    printf("Inorder traversal: ");
    inorder_traversal(root);
    printf("\n");

    // Print the binary search tree in postorder traversal
    printf("Postorder traversal: ");
    postorder_traversal(root);
    printf("\n");

    return 0;
}