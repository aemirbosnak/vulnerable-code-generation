//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the search tree
typedef struct {
    char *word;
    struct node *next;
} node_t;

// Function to perform a recursive search
node_t *search(node_t *root, char *word) {
    // Base case: if the root is null, return null
    if (root == NULL) {
        return NULL;
    }

    // Recursive case: if the word is found, return the node
    if (strcmp(root->word, word) == 0) {
        return root;
    }

    // Recursive case: search the next node
    node_t *next = search(root->next, word);

    // If the word is not found, return null
    if (next == NULL) {
        return NULL;
    }

    // If the word is found, return the current node
    return root;
}

int main() {
    // Create a list of strings
    node_t *root = NULL;
    root = (node_t *)malloc(sizeof(node_t));
    root->word = "apple";
    root->next = NULL;

    node_t *node1 = (node_t *)malloc(sizeof(node_t));
    node1->word = "banana";
    node1->next = NULL;
    root->next = node1;

    node_t *node2 = (node_t *)malloc(sizeof(node_t));
    node2->word = "cherry";
    node2->next = NULL;
    node1->next = node2;

    // Search for the word "hello" in the list
    node_t *result = search(root, "hello");

    // Print the result
    if (result != NULL) {
        printf("Found %s\n", result->word);
    } else {
        printf("Not found\n");
    }

    // Free the memory
    free(root);

    return 0;
}