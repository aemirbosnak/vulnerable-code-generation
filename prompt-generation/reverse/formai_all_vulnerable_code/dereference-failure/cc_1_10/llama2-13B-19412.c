//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DEPTH 5
#define MAX_LEN 100

// Structure to represent a node in the tree
typedef struct node {
    char *label;
    int count;
    struct node *left;
    struct node *right;
} Node;

// Function to create a new node
Node *new_node(char *label, int count) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->label = label;
    node->count = count;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to traverse the tree and count the number of occurrences of each label
void count_labels(Node *root) {
    if (root == NULL) {
        return;
    }

    // Recursively traverse the tree
    count_labels(root->left);
    count_labels(root->right);

    // Increment the count of the current label
    int count = 0;
    for (int i = 0; i < strlen(root->label); i++) {
        count++;
    }
    root->count += count;
}

// Function to build the tree from a list of strings
Node *build_tree(char **labels) {
    Node *root = NULL;
    for (int i = 0; labels[i] != NULL; i++) {
        // Create a new node for each label
        Node *node = new_node(labels[i], 1);

        // Add the node to the tree
        if (i == 0) {
            root = node;
        } else if (labels[i - 1][strlen(labels[i - 1]) - 1] == ']') {
            // If the current label is the last label in the previous node,
            // add it as a child of the previous node
            Node *prev_node = root;
            while (prev_node->left != NULL && prev_node->left->label[0] != ']') {
                prev_node = prev_node->left;
            }
            prev_node->left = node;
        } else {
            // If the current label is not the last label in the previous node,
            // create a new node as the left child of the previous node
            Node *prev_node = root;
            while (prev_node->left != NULL && prev_node->left->label[0] != ']') {
                prev_node = prev_node->left;
            }
            prev_node->left = node;
        }
    }
    return root;
}

int main() {
    // Example list of strings
    char *labels[] = {"apple", "banana", "orange", "banana", "apple", "orange"};

    // Build the tree from the list of strings
    Node *root = build_tree(labels);

    // Count the number of occurrences of each label in the tree
    count_labels(root);

    // Print the results
    for (int i = 0; i < MAX_DEPTH; i++) {
        printf("%c%d", i == 0 ? ' ' : ' ', root->count);
        root = root->left;
    }
    printf("\n");

    return 0;
}