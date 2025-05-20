//FormAI DATASET v1.0 Category: Data structures visualization ; Style: secure
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

// Insert a new node into the tree
void insert(Node** root, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    if (*root == NULL) {
        *root = new_node;
        return;
    }

    Node* current = *root;
    while (1) {
        if (data < current->data) {
            if (current->left == NULL) {
                current->left = new_node;
                return;
            }
            current = current->left;
        }
        else {
            if (current->right == NULL) {
                current->right = new_node;
                return;
            }
            current = current->right;
        }
    }
}

// Print the tree in order
void print_in_order(Node* root) {
    if (root == NULL) {
        return;
    }

    print_in_order(root->left);
    printf("%d ", root->data);
    print_in_order(root->right);
}

int main() {
    Node* root = NULL;

    // Insert some nodes into the tree
    insert(&root, 4);
    insert(&root, 2);
    insert(&root, 6);
    insert(&root, 1);
    insert(&root, 3);
    insert(&root, 5);
    insert(&root, 7);

    // Print the tree in order
    print_in_order(root);

    return 0;
}