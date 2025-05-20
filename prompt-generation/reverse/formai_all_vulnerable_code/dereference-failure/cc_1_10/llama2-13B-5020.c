//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LENGTH 100
#define MAX_DEPTH 5

// Structure to hold the search tree
typedef struct node {
    char *word;
    int frequency;
    struct node *left, *right;
} node_t;

// Function to create a new node
node_t *new_node(char *word, int frequency) {
    node_t *node = (node_t *) malloc(sizeof(node_t));
    node->word = word;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to search the tree
node_t *search(node_t *root, char *word) {
    // If the word is null, return null
    if (word == NULL) {
        return NULL;
    }

    // If the word is empty, return null
    if (*word == '\0') {
        return NULL;
    }

    // If the current node is null, create a new one
    if (root == NULL) {
        root = new_node(word, 1);
    }

    // Compare the word with the current node's word
    if (strcmp(root->word, word) == 0) {
        // If the word is found, return the node
        return root;
    }

    // Recursively search the left and right subtrees
    node_t *left_node = search(root->left, word);
    node_t *right_node = search(root->right, word);

    // If the word is found in the left subtree, return the left node
    if (left_node != NULL) {
        return left_node;
    }

    // If the word is found in the right subtree, return the right node
    if (right_node != NULL) {
        return right_node;
    }

    // If the word is not found, return null
    return NULL;
}

// Function to print the search tree
void print_tree(node_t *root) {
    if (root == NULL) {
        return;
    }

    printf("%s (%d)\n", root->word, root->frequency);

    print_tree(root->left);
    print_tree(root->right);
}

int main() {
    // Create a new tree
    node_t *root = NULL;

    // Add some words to the tree
    root = new_node("hello", 2);
    root->left = new_node("ell", 1);
    root->right = new_node("o", 1);

    root = new_node("world", 2);
    root->left = new_node("orl", 1);
    root->right = new_node("d", 1);

    // Search the tree
    node_t *node = search(root, "hello");

    // Print the search tree
    print_tree(root);

    return 0;
}