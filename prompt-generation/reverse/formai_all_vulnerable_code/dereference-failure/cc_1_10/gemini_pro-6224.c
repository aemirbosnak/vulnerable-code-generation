//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A node in the binary search tree
struct node {
    char *word;
    int count;
    struct node *left;
    struct node *right;
};

// Create a new node
struct node *create_node(char *word) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->word = strdup(word);
    new_node->count = 1;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a word into the binary search tree
void insert_word(struct node **root, char *word) {
    if (*root == NULL) {
        *root = create_node(word);
    } else {
        int comparison = strcmp(word, (*root)->word);
        if (comparison < 0) {
            insert_word(&(*root)->left, word);
        } else if (comparison > 0) {
            insert_word(&(*root)->right, word);
        } else {
            (*root)->count++;
        }
    }
}

// Print the words in the binary search tree in order of increasing count
void print_words(struct node *root) {
    if (root == NULL) {
        return;
    }
    print_words(root->left);
    printf("%s: %d\n", root->word, root->count);
    print_words(root->right);
}

// Free the memory allocated for the binary search tree
void free_tree(struct node *root) {
    if (root == NULL) {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root->word);
    free(root);
}

int main() {
    // Create a binary search tree
    struct node *root = NULL;

    // Insert some words into the binary search tree
    char *words[] = {"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
    for (int i = 0; i < sizeof(words) / sizeof(char *); i++) {
        insert_word(&root, words[i]);
    }

    // Print the words in the binary search tree in order of increasing count
    print_words(root);

    // Free the memory allocated for the binary search tree
    free_tree(root);

    return 0;
}