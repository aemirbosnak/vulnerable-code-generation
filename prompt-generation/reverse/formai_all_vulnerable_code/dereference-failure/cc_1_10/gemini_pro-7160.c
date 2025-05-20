//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 10000
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
void insert_word(struct TrieNode *root, char *word) {
    struct TrieNode *current = root;
    while (*word) {
        int index = tolower(*word) - 'a';
        if (!current->children[index]) {
            current->children[index] = create_trie_node();
        }
        current = current->children[index];
        word++;
    }
    current->is_word = true;
}

// Check if a word is in the trie
bool is_word_in_trie(struct TrieNode *root, char *word) {
    struct TrieNode *current = root;
    while (*word) {
        int index = tolower(*word) - 'a';
        if (!current->children[index]) {
            return false;
        }
        current = current->children[index];
        word++;
    }
    return current->is_word;
}

// Load the dictionary into the trie
void load_dictionary(struct TrieNode *root, char *filename) {
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
bool check_spelling(struct TrieNode *root, char *word) {
    return is_word_in_trie(root, word);
}

// Suggest corrections for a misspelled word
void suggest_corrections(struct TrieNode *root, char *word, char **corrections) {
    int num_corrections = 0;

    // Check for insertions
    for (int i = 0; i <= strlen(word); i++) {
        for (int j = 0; j < 26; j++) {
            char new_word[MAX_WORD_LENGTH];
            strncpy(new_word, word, i);
            new_word[i] = 'a' + j;
            strncpy(new_word + i + 1, word + i, strlen(word) - i);
            if (is_word_in_trie(root, new_word)) {
                corrections[num_corrections++] = strdup(new_word);
            }
        }
    }

    // Check for deletions
    for (int i = 0; i < strlen(word); i++) {
        char new_word[MAX_WORD_LENGTH];
        strncpy(new_word, word, i);
        strncpy(new_word + i, word + i + 1, strlen(word) - i - 1);
        if (is_word_in_trie(root, new_word)) {
            corrections[num_corrections++] = strdup(new_word);
        }
    }

    // Check for substitutions
    for (int i = 0; i < strlen(word); i++) {
        for (int j = 0; j < 26; j++) {
            if (word[i] != 'a' + j) {
                char new_word[MAX_WORD_LENGTH];
                strncpy(new_word, word, i);
                new_word[i] = 'a' + j;
                strncpy(new_word + i + 1, word + i + 1, strlen(word) - i);
                if (is_word_in_trie(root, new_word)) {
                    corrections[num_corrections++] = strdup(new_word);
                }
            }
        }
    }

    // Check for transpositions
    for (int i = 0; i < strlen(word) - 1; i++) {
        char new_word[MAX_WORD_LENGTH];
        strncpy(new_word, word, i);
        new_word[i] = word[i + 1];
        new_word[i + 1] = word[i];
        strncpy(new_word + i + 2, word + i + 2, strlen(word) - i - 2);
        if (is_word_in_trie(root, new_word)) {
            corrections[num_corrections++] = strdup(new_word);
        }
    }
}

// Print the corrections for a misspelled word
void print_corrections(char **corrections, int num_corrections) {
    if (num_corrections == 0) {
        printf("No corrections found.\n");
    } else {
        printf("Corrections:\n");
        for (int i = 0; i < num_corrections; i++) {
            printf("%s\n", corrections[i]);
            free(corrections[i]);
        }
    }
}

// Free the trie
void free_trie(struct TrieNode *root) {
    for (int i = 0; i < 26; i++) {
        if (root->children[i]) {
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
    bool is_correct = check_spelling(root, word);

    // Print the result
    if (is_correct) {
        printf("%s is spelled correctly.\n", word);
    } else {
        printf("%s is spelled incorrectly.\n", word);

        // Suggest corrections
        char *corrections[MAX_WORDS];
        suggest_corrections(root, word, corrections);
        print_corrections(corrections, MAX_WORDS);
    }

    // Free the trie
    free_trie(root);

    return 0;
}