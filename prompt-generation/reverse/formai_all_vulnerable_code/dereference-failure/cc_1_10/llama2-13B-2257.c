//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 100
#define MAX_DEPTH 5

// Define a struct to represent a tree node
typedef struct node {
    char word[MAX_LENGTH];
    int depth;
    struct node *left, *right;
} node;

// Function to create a new node
node *new_node(char *word, int depth) {
    node *n = (node *)malloc(sizeof(node));
    strcpy(n->word, word);
    n->depth = depth;
    n->left = n->right = NULL;
    return n;
}

// Function to insert a word into the tree
void insert(node **root, char *word) {
    node *n = *root;
    int i;

    // Check if the word is already in the tree
    for (i = 0; i < MAX_DEPTH; i++) {
        if (strcmp(n->word, word) == 0) {
            break;
        }

        // If not found, continue traversing the tree
        if (n->left == NULL) {
            n->left = new_node(word, n->depth + 1);
        } else {
            n->right = new_node(word, n->depth + 1);
        }

        // Update the depth of the new node
        n->depth++;

        // Break out of the loop if the word is found
        if (i == MAX_DEPTH) {
            break;
        }
    }

    // Update the root node
    *root = n;
}

// Function to print the tree
void print_tree(node *root) {
    int i;

    // Print the root node
    printf("%s\n", root->word);

    // Recursively print the left and right subtrees
    if (root->left != NULL) {
        print_tree(root->left);
    }

    if (root->right != NULL) {
        print_tree(root->right);
    }
}

int main() {
    // Create the root node
    node *root = new_node("peace", 1);

    // Insert words into the tree
    insert(&root, "love");
    insert(&root, "harmony");
    insert(&root, "unity");
    insert(&root, "understanding");

    // Print the tree
    print_tree(root);

    return 0;
}