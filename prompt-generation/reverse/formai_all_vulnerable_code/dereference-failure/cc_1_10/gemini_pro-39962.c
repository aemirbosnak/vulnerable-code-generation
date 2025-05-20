//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 50

// Create a node for the trie
typedef struct trie_node {
    struct trie_node *children[26]; // Array of child nodes
    int is_word; // Flag to indicate if this node represents the end of a word
} trie_node;

// Create a new trie node
trie_node *create_trie_node() {
    trie_node *node = (trie_node *)malloc(sizeof(trie_node));
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    node->is_word = 0;
    return node;
}

// Insert a word into the trie
void insert_word(trie_node *root, char *word) {
    trie_node *current = root;
    int index;
    for (int i = 0; word[i] != '\0'; i++) {
        index = tolower(word[i]) - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = create_trie_node();
        }
        current = current->children[index];
    }
    current->is_word = 1;
}

// Check if a word is in the trie
int find_word(trie_node *root, char *word) {
    trie_node *current = root;
    int index;
    for (int i = 0; word[i] != '\0'; i++) {
        index = tolower(word[i]) - 'a';
        if (current->children[index] == NULL) {
            return 0;
        }
        current = current->children[index];
    }
    return current->is_word;
}

// Load the dictionary into the trie
void load_dictionary(trie_node *root, char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening dictionary file");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word) != EOF) {
        insert_word(root, word);
    }

    fclose(fp);
}

// Check the spelling of a word
int check_spelling(trie_node *root, char *word) {
    return find_word(root, word);
}

// Main function
int main() {
    // Create the root of the trie
    trie_node *root = create_trie_node();

    // Load the dictionary into the trie
    load_dictionary(root, "dictionary.txt");

    // Get the word to be checked from the user
    char word[MAX_WORD_LENGTH];
    printf("Enter a word to check: ");
    scanf("%s", word);

    // Check the spelling of the word
    int is_correct = check_spelling(root, word);

    // Print the result
    if (is_correct) {
        printf("The word is spelled correctly.\n");
    } else {
        printf("The word is spelled incorrectly.\n");
    }

    return 0;
}