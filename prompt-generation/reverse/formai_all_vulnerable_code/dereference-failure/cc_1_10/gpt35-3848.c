//FormAI DATASET v1.0 Category: Data structures visualization ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node* left_child;
    struct node* right_child;
} Node;

// Define the tree structure
typedef struct tree {
    Node* root;
} Tree;

// Function to create a new node
Node* create_node(int value) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = value;
    new_node->left_child = NULL;
    new_node->right_child = NULL;
    return new_node;
}

// Function to insert a node into the tree
void insert_node(Tree* tree, int value) {
    Node* new_node = create_node(value);
    if (tree->root == NULL) {
        tree->root = new_node;
        return;
    }

    Node* current_node = tree->root;
    while (1) {
        if (value < current_node->data) {
            if (current_node->left_child == NULL) {
                current_node->left_child = new_node;
                return;
            } else {
                current_node = current_node->left_child;
            }
        } else if (value > current_node->data) {
            if (current_node->right_child == NULL) {
                current_node->right_child = new_node;
                return;
            } else {
                current_node = current_node->right_child;
            }
        } else {
            // Node already exists in tree
            free(new_node);
            return;
        }
    }
}

// Function to traverse the tree in order
void traverse_in_order(Node* node) {
    if (node == NULL) {
        return;
    }
    traverse_in_order(node->left_child);
    printf("%d ", node->data);
    traverse_in_order(node->right_child);
}

int main() {
    Tree my_tree;
    my_tree.root = NULL;

    insert_node(&my_tree, 10);
    insert_node(&my_tree, 5);
    insert_node(&my_tree, 7);
    insert_node(&my_tree, 15);
    insert_node(&my_tree, 12);
    insert_node(&my_tree, 17);

    printf("In-order traversal: ");
    traverse_in_order(my_tree.root);
    printf("\n");

    return 0;
}