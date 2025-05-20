//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 20

// Create a node for the trie
struct TrieNode {
    struct TrieNode *children[26];
    bool is_word;
};

// Create a new trie node
struct TrieNode *create_trie_node() {
    struct TrieNode *node = malloc(sizeof(struct TrieNode));
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    node->is_word = false;
    return node;
}

// Insert a word into the trie
void insert_word(struct TrieNode *root, const char *word) {
    struct TrieNode *current = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = tolower(word[i]) - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = create_trie_node();
        }
        current = current->children[index];
    }
    current->is_word = true;
}

// Check if a word is in the trie
bool is_word_in_trie(struct TrieNode *root, const char *word) {
    struct TrieNode *current = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = tolower(word[i]) - 'a';
        if (current->children[index] == NULL) {
            return false;
        }
        current = current->children[index];
    }
    return current->is_word;
}

// Load a dictionary into the trie
void load_dictionary(struct TrieNode *root, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening dictionary file");
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        insert_word(root, word);
    }

    fclose(file);
}

// Check the spelling of a word
bool check_spelling(struct TrieNode *root, const char *word) {
    return is_word_in_trie(root, word);
}

// Print suggestions for a misspelled word
void print_suggestions(struct TrieNode *root, const char *word) {
    struct TrieNode *current = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = tolower(word[i]) - 'a';
        if (current->children[index] == NULL) {
            break;
        }
        current = current->children[index];
    }

    if (current->is_word) {
        printf("Did you mean '%s'?\n", word);
    } else {
        printf("No suggestions found.\n");
    }

    for (int i = 0; i < 26; i++) {
        if (current->children[i] != NULL) {
            char suggestion[MAX_WORD_LENGTH];
            strcpy(suggestion, word);
            suggestion[i] = 'a' + i;
            if (is_word_in_trie(root, suggestion)) {
                printf("Did you mean '%s'?\n", suggestion);
            }
        }
    }
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

int main() {
    // Create the root of the trie
    struct TrieNode *root = create_trie_node();

    // Load the dictionary into the trie
    load_dictionary(root, "dictionary.txt");

    // Get the word to check from the user
    char word[MAX_WORD_LENGTH];
    printf("Enter a word to check: ");
    scanf("%s", word);

    // Check the spelling of the word
    if (check_spelling(root, word)) {
        printf("The word '%s' is spelled correctly.\n", word);
    } else {
        printf("The word '%s' is spelled incorrectly.\n", word);
        print_suggestions(root, word);
    }

    // Free the trie
    free_trie(root);

    return 0;
}