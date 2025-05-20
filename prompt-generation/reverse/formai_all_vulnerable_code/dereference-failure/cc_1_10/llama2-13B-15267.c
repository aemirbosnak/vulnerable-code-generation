//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to represent a node in the tree
typedef struct node {
    int feature;    // Feature value
    int label;     // Label
    struct node* left;  // Left child node
    struct node* right; // Right child node
} node_t;

// Function to create a new node
node_t* new_node(int feature, int label) {
    node_t* node = (node_t*) malloc(sizeof(node_t));
    node->feature = feature;
    node->label = label;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node into the tree
void insert_node(node_t** root, int feature, int label) {
    if (*root == NULL) {
        *root = new_node(feature, label);
    } else {
        if (feature < (*root)->feature) {
            insert_node(&(*root)->left, feature, label);
        } else if (feature > (*root)->feature) {
            insert_node(&(*root)->right, feature, label);
        } else {
            // Label already exists, do nothing
            return;
        }
    }
}

// Function to traverse the tree and count the number of instances for each label
int count_instances(node_t* root) {
    int count = 0;
    if (root != NULL) {
        count += count_instances(root->left);
        count += count_instances(root->right);
        count += (root->label == count) ? 1 : 0; // Count the current label
    }
    return count;
}

// Function to print the tree
void print_tree(node_t* root) {
    if (root != NULL) {
        print_tree(root->left);
        printf("%d (%d) ", root->feature, root->label);
        print_tree(root->right);
    }
}

int main() {
    // Create some sample data
    node_t* root = NULL;
    insert_node(&root, 2, 1);
    insert_node(&root, 4, 1);
    insert_node(&root, 1, 1);
    insert_node(&root, 3, 0);
    insert_node(&root, 2, 0);

    // Count the number of instances for each label
    int instances[3] = {0};
    instances[0] = count_instances(root);

    // Print the tree
    print_tree(root);

    return 0;
}