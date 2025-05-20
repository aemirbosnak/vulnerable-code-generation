//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Create a node for the trie
typedef struct trie_node {
    bool is_word;
    struct trie_node *children[26];
} trie_node;

// Create a new trie node
trie_node *new_trie_node() {
    trie_node *node = malloc(sizeof(trie_node));
    node->is_word = false;
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    return node;
}

// Insert a word into the trie
void insert_word(trie_node *root, char *word) {
    trie_node *current = root;
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = new_trie_node();
        }
        current = current->children[index];
    }
    current->is_word = true;
}

// Check if a word is in the trie
bool is_word_in_trie(trie_node *root, char *word) {
    trie_node *current = root;
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (current->children[index] == NULL) {
            return false;
        }
        current = current->children[index];
    }
    return current->is_word;
}

// Free the trie
void free_trie(trie_node *root) {
    for (int i = 0; i < 26; i++) {
        if (root->children[i] != NULL) {
            free_trie(root->children[i]);
        }
    }
    free(root);
}

// Load the dictionary into the trie
trie_node *load_dictionary(char *filename) {
    trie_node *root = new_trie_node();
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }
    char word[100];
    while (fscanf(file, "%s", word) != EOF) {
        insert_word(root, word);
    }
    fclose(file);
    return root;
}

// Check the spelling of a word
bool check_spelling(trie_node *root, char *word) {
    return is_word_in_trie(root, word);
}

// Suggest corrections for a misspelled word
void suggest_corrections(trie_node *root, char *word) {
    // Check if the word is in the trie
    if (is_word_in_trie(root, word)) {
        printf("%s is spelled correctly.\n", word);
        return;
    }

    // Create a queue to store possible corrections
    trie_node *queue[100];
    int head = 0;
    int tail = 0;
    queue[tail++] = root;

    // Search the trie for possible corrections
    while (head != tail) {
        trie_node *current = queue[head++];

        // Check if the current node is a word in the trie
        if (current->is_word) {
            printf("Suggested correction: %s\n", word);
        }

        // Check if the current node has any children
        for (int i = 0; i < 26; i++) {
            if (current->children[i] != NULL) {
                // Add the child to the queue
                queue[tail++] = current->children[i];

                // Update the misspelled word to include the new character
                word[strlen(word)] = 'a' + i;

                // Check if the updated word is in the trie
                if (is_word_in_trie(root, word)) {
                    printf("Suggested correction: %s\n", word);
                }

                // Remove the new character from the misspelled word
                word[strlen(word) - 1] = '\0';
            }
        }
    }
}

// Get a word from the user
char *get_word() {
    char *word = malloc(100);
    printf("Enter a word: ");
    scanf("%s", word);
    return word;
}

// Main function
int main() {
    // Load the dictionary into the trie
    trie_node *root = load_dictionary("dictionary.txt");

    // Get a word from the user
    char *word = get_word();

    // Check the spelling of the word
    if (check_spelling(root, word)) {
        printf("%s is spelled correctly.\n", word);
    } else {
        printf("%s is misspelled.\n", word);
        suggest_corrections(root, word);
    }

    // Free the trie
    free_trie(root);
    free(word);
    return 0;
}