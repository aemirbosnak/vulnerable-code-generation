//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 256

// Create a node for the trie
struct TrieNode {
    char letter;
    struct TrieNode *children[26];
    int is_word;
};

// Create a new trie node
struct TrieNode *create_trie_node(char letter) {
    struct TrieNode *node = malloc(sizeof(struct TrieNode));
    node->letter = letter;
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    node->is_word = 0;
    return node;
}

// Insert a word into the trie
void insert_word(struct TrieNode *root, char *word) {
    struct TrieNode *current = root;
    for (int i = 0; i < strlen(word); i++) {
        int index = tolower(word[i]) - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = create_trie_node(word[i]);
        }
        current = current->children[index];
    }
    current->is_word = 1;
}

// Check if a word is in the trie
int is_word_in_trie(struct TrieNode *root, char *word) {
    struct TrieNode *current = root;
    for (int i = 0; i < strlen(word); i++) {
        int index = tolower(word[i]) - 'a';
        if (current->children[index] == NULL) {
            return 0;
        }
        current = current->children[index];
    }
    return current->is_word;
}

// Free the trie
void free_trie(struct TrieNode *root) {
    for (int i = 0; i < 26; i++) {
        if (root->children[i] != NULL) {
            free_trie(root->children[i]);
        }
    }
    free(root);
}

// Load the dictionary into the trie
void load_dictionary(struct TrieNode *root, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening dictionary file");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        insert_word(root, word);
    }

    fclose(file);
}

// Check the spelling of a word
int check_spelling(struct TrieNode *root, char *word) {
    return is_word_in_trie(root, word);
}

// Print the suggestions for a misspelled word
void print_suggestions(struct TrieNode *root, char *word) {
    struct TrieNode *current = root;
    for (int i = 0; i < strlen(word); i++) {
        int index = tolower(word[i]) - 'a';
        if (current->children[index] == NULL) {
            return;
        }
        current = current->children[index];
    }

    // Print the suggestions
    printf("Suggestions:\n");
    for (int i = 0; i < 26; i++) {
        if (current->children[i] != NULL) {
            printf("%s\n", current->children[i]->letter);
        }
    }
}

// Main function
int main() {
    // Create the root of the trie
    struct TrieNode *root = create_trie_node('*');

    // Load the dictionary into the trie
    load_dictionary(root, "dictionary.txt");

    // Get the word to check from the user
    char word[MAX_WORD_LENGTH];
    printf("Enter a word to check: ");
    scanf("%s", word);

    // Check the spelling of the word
    if (check_spelling(root, word)) {
        printf("The word is spelled correctly.\n");
    } else {
        printf("The word is misspelled.\n");
        print_suggestions(root, word);
    }

    // Free the trie
    free_trie(root);

    return 0;
}