//FormAI DATASET v1.0 Category: Binary search trees ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// BST node structure
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node
struct node* create_node(int value) {
    struct node* new_node =
        (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a new node in the BST
struct node* insert_node(struct node* root, int value) {
    if (root == NULL)
        return create_node(value);
    if (value < root->data)
        root->left = insert_node(root->left, value);
    else if (value > root->data)
        root->right = insert_node(root->right, value);
    return root;
}

// Search for a node in the BST
struct node* search_node(struct node* root, int value) {
    if (root == NULL || root->data == value)
        return root;
    if (root->data < value)
        return search_node(root->right, value);
    return search_node(root->left, value);
}

// Function to find the minimum value in the BST
struct node* find_minimum(struct node* root) {
    struct node* current = root;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Deleting a node from BST
struct node* delete_node(struct node* root, int value) {
    if (root == NULL)
        return root;
    if (value < root->data)
        root->left = delete_node(root->left, value);
    else if (value > root->data)
        root->right = delete_node(root->right, value);
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
        struct node* temp = find_minimum(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }
    return root;
}

// Function to traverse the BST in inorder
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d -> ", root->data);
        inorder(root->right);
    }
}

// Main function
int main() {
    struct node* root = NULL;
    root = insert_node(root, 8);
    insert_node(root, 3);
    insert_node(root, 1);
    insert_node(root, 6);
    insert_node(root, 4);
    insert_node(root, 7);
    insert_node(root, 10);
    insert_node(root, 14);
    insert_node(root, 13);

    printf("BST: ");
    inorder(root);
    printf("\n");

    root = delete_node(root, 7);
    printf("BST after deleting node 7: ");
    inorder(root);
    printf("\n");

    struct node* search_result = search_node(root, 10);
    if (search_result != NULL)
        printf("Node with value 10 exists in the BST\n");
    else
        printf("Node with value 10 does not exist in the BST\n");

    return 0;
}