//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the binary search tree
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

// Define the structure for the binary search tree
typedef struct bst {
    Node* root;
} BST;

// Create a new node with the given data
Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Create a new binary search tree
BST* create_bst() {
    BST* new_bst = (BST*) malloc(sizeof(BST));
    new_bst->root = NULL;
    return new_bst;
}

// Insert a new node with the given data into the binary search tree
void insert_node(BST* bst, int data) {
    Node* new_node = create_node(data);
    Node* current_node = bst->root;

    if (bst->root == NULL) {
        bst->root = new_node;
        return;
    }

    while (1) {
        if (data < current_node->data) {
            if (current_node->left == NULL) {
                current_node->left = new_node;
                break;
            } else {
                current_node = current_node->left;
            }
        } else {
            if (current_node->right == NULL) {
                current_node->right = new_node;
                break;
            } else {
                current_node = current_node->right;
            }
        }
    }
}

// Print all the data in the binary search tree in sorted order
void print_bst(Node* root) {
    if (root == NULL) {
        return;
    }

    print_bst(root->left);
    printf("%d ", root->data);
    print_bst(root->right);
}

// Main function
int main() {
    BST* bst = create_bst();

    insert_node(bst, 5);
    insert_node(bst, 3);
    insert_node(bst, 7);
    insert_node(bst, 2);
    insert_node(bst, 4);
    insert_node(bst, 6);
    insert_node(bst, 8);

    printf("Sorted data in the binary search tree:\n");
    print_bst(bst->root);

    return 0;
}