//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum word length
#define MAX_WORD_LENGTH 20

// Define the maximum number of words in the dictionary
#define MAX_DICTIONARY_SIZE 1000

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
    int index;
    for (int i = 0; i < strlen(word); i++) {
        index = word[i] - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = create_trie_node(word[i]);
        }
        current = current->children[index];
    }
    current->is_word = 1;
}

// Search for a word in the trie
int search_word(struct TrieNode *root, char *word) {
    struct TrieNode *current = root;
    int index;
    for (int i = 0; i < strlen(word); i++) {
        index = word[i] - 'a';
        if (current->children[index] == NULL) {
            return 0;
        }
        current = current->children[index];
    }
    return current->is_word;
}

// Load the dictionary into the trie
void load_dictionary(struct TrieNode *root, char *filename) {
    FILE *file = fopen(filename, "r");
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        insert_word(root, word);
    }
    fclose(file);
}

// Check if a word is spelled correctly
int check_spelling(struct TrieNode *root, char *word) {
    return search_word(root, word);
}

// Get suggestions for a misspelled word
void get_suggestions(struct TrieNode *root, char *word) {
    struct TrieNode *current = root;
    int index;
    for (int i = 0; i < strlen(word); i++) {
        index = word[i] - 'a';
        if (current->children[index] == NULL) {
            break;
        }
        current = current->children[index];
    }
    if (current->is_word) {
        printf("%s\n", word);
    } else {
        for (int i = 0; i < 26; i++) {
            if (current->children[i] != NULL) {
                char new_word[MAX_WORD_LENGTH];
                strcpy(new_word, word);
                new_word[i] = current->children[i]->letter;
                get_suggestions(root, new_word);
            }
        }
    }
}

// Print the trie
void print_trie(struct TrieNode *root) {
    if (root == NULL) {
        return;
    }
    if (root->is_word) {
        printf("%s\n", root->letter);
    }
    for (int i = 0; i < 26; i++) {
        if (root->children[i] != NULL) {
            printf("%c", root->letter);
            print_trie(root->children[i]);
        }
    }
}

// Free the trie
void free_trie(struct TrieNode *root) {
    if (root == NULL) {
        return;
    }
    for (int i = 0; i < 26; i++) {
        if (root->children[i] != NULL) {
            free_trie(root->children[i]);
        }
    }
    free(root);
}

// Main function
int main() {
    // Create the root node of the trie
    struct TrieNode *root = create_trie_node(' ');
    // Load the dictionary into the trie
    load_dictionary(root, "dict.txt");
    // Check the spelling of a word
    char word[MAX_WORD_LENGTH];
    printf("Enter a word: ");
    scanf("%s", word);
    if (check_spelling(root, word)) {
        printf("The word is spelled correctly.\n");
    } else {
        printf("The word is spelled incorrectly.\n");
        // Get suggestions for the misspelled word
        get_suggestions(root, word);
    }
    // Free the trie
    free_trie(root);
    return 0;
}