//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A node in the summary tree
struct node {
    char *word;
    int count;
    struct node *left;
    struct node *right;
};

// A summary tree
struct tree {
    struct node *root;
};

// Create a new node
struct node *new_node(char *word) {
    struct node *node = malloc(sizeof(struct node));
    node->word = strdup(word);
    node->count = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insert a word into the summary tree
void insert(struct tree *tree, char *word) {
    struct node *node = tree->root;
    if (node == NULL) {
        tree->root = new_node(word);
        return;
    }
    while (1) {
        int cmp = strcmp(word, node->word);
        if (cmp == 0) {
            node->count++;
            return;
        } else if (cmp < 0) {
            if (node->left == NULL) {
                node->left = new_node(word);
                return;
            } else {
                node = node->left;
            }
        } else {
            if (node->right == NULL) {
                node->right = new_node(word);
                return;
            } else {
                node = node->right;
            }
        }
    }
}

// Print the summary tree in order
void print_tree(struct tree *tree, int level) {
    if (tree->root == NULL) {
        return;
    }
    print_tree(tree->root->left, level + 1);
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printf("%s (%d)\n", tree->root->word, tree->root->count);
    print_tree(tree->root->right, level + 1);
}

// Free the summary tree
void free_tree(struct tree *tree) {
    if (tree->root == NULL) {
        return;
    }
    free_tree(tree->root->left);
    free_tree(tree->root->right);
    free(tree->root->word);
    free(tree->root);
}

// Summarize a text file
void summarize(char *filename) {
    // Open the text file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // Create a summary tree
    struct tree *tree = malloc(sizeof(struct tree));
    tree->root = NULL;

    // Read the text file line by line
    char line[1024];
    while (fgets(line, sizeof(line), file) != NULL) {
        // Tokenize the line
        char *tokens[1024];
        int num_tokens = 0;
        char *token = strtok(line, " ");
        while (token != NULL) {
            tokens[num_tokens++] = token;
            token = strtok(NULL, " ");
        }

        // Insert each token into the summary tree
        for (int i = 0; i < num_tokens; i++) {
            insert(tree, tokens[i]);
        }
    }

    // Close the text file
    fclose(file);

    // Print the summary tree
    print_tree(tree, 0);

    // Free the summary tree
    free_tree(tree);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    summarize(argv[1]);

    return 0;
}