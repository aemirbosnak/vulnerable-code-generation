//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LEN 256

typedef struct node {
    char *word;
    struct node *left;
    struct node *right;
} node_t;

node_t *root = NULL;

// Insert a word into the tree
void insert(char *word) {
    if (root == NULL) {
        root = (node_t *)malloc(sizeof(node_t));
        root->word = strdup(word);
        root->left = NULL;
        root->right = NULL;
        return;
    }

    node_t *current = root;
    while (true) {
        int cmp = strcmp(word, current->word);
        if (cmp == 0) {
            // Word already exists in the tree
            return;
        } else if (cmp < 0) {
            if (current->left == NULL) {
                // Insert the word as the left child of the current node
                current->left = (node_t *)malloc(sizeof(node_t));
                current->left->word = strdup(word);
                current->left->left = NULL;
                current->left->right = NULL;
                return;
            } else {
                // Recursively insert the word into the left subtree
                current = current->left;
            }
        } else {
            if (current->right == NULL) {
                // Insert the word as the right child of the current node
                current->right = (node_t *)malloc(sizeof(node_t));
                current->right->word = strdup(word);
                current->right->left = NULL;
                current->right->right = NULL;
                return;
            } else {
                // Recursively insert the word into the right subtree
                current = current->right;
            }
        }
    }
}

// Search for a word in the tree
bool search(char *word) {
    if (root == NULL) {
        return false;
    }

    node_t *current = root;
    while (true) {
        int cmp = strcmp(word, current->word);
        if (cmp == 0) {
            // Word found in the tree
            return true;
        } else if (cmp < 0) {
            if (current->left == NULL) {
                // Word not found in the tree
                return false;
            } else {
                // Recursively search for the word in the left subtree
                current = current->left;
            }
        } else {
            if (current->right == NULL) {
                // Word not found in the tree
                return false;
            } else {
                // Recursively search for the word in the right subtree
                current = current->right;
            }
        }
    }
}

// Free the memory allocated for the tree
void free_tree(node_t *node) {
    if (node == NULL) {
        return;
    }

    free_tree(node->left);
    free_tree(node->right);
    free(node->word);
    free(node);
}

// Load words from a file into the tree
void load_words(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LEN];
    while (fscanf(file, "%s", word) != EOF) {
        insert(word);
    }

    fclose(file);
}

// Spell check a word
bool spell_check(char *word) {
    return search(word);
}

// Get a word from the user
char *get_word() {
    char *word = (char *)malloc(MAX_WORD_LEN);
    printf("Enter a word: ");
    scanf("%s", word);
    return word;
}

// Main function
int main() {
    // Load words from the dictionary into the tree
    load_words("dictionary.txt");

    // Get a word from the user
    char *word = get_word();

    // Spell check the word
    bool correct = spell_check(word);

    // Print the result
    if (correct) {
        printf("The word is spelled correctly.\n");
    } else {
        printf("The word is spelled incorrectly.\n");
    }

    // Free the memory allocated for the word
    free(word);

    // Free the memory allocated for the tree
    free_tree(root);

    return 0;
}