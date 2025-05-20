//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of words to store in the dictionary
#define MAX_WORDS 10000

// Create a node for the trie
typedef struct trie_node {
    char letter;
    int is_word;
    struct trie_node *children[26];
} trie_node;

// Create a new trie node
trie_node *new_trie_node(char letter) {
    trie_node *node = malloc(sizeof(trie_node));
    node->letter = letter;
    node->is_word = 0;
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    return node;
}

// Insert a word into the trie
void insert_word(trie_node *root, char *word) {
    trie_node *current = root;
    for (int i = 0; i < strlen(word); i++) {
        char letter = word[i];
        int index = letter - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = new_trie_node(letter);
        }
        current = current->children[index];
    }
    current->is_word = 1;
}

// Check if a word is in the trie
int is_word_in_trie(trie_node *root, char *word) {
    trie_node *current = root;
    for (int i = 0; i < strlen(word); i++) {
        char letter = word[i];
        int index = letter - 'a';
        if (current->children[index] == NULL) {
            return 0;
        }
        current = current->children[index];
    }
    return current->is_word;
}

// Load the dictionary into the trie
void load_dictionary(trie_node *root, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening dictionary file\n");
        exit(1);
    }
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        char *word = strtok(line, "\n");
        insert_word(root, word);
    }
    fclose(file);
}

// Check if a message contains any spam words
int is_spam(trie_node *root, char *message) {
    char *word = strtok(message, " ");
    while (word != NULL) {
        if (is_word_in_trie(root, word)) {
            return 1;
        }
        word = strtok(NULL, " ");
    }
    return 0;
}

// Main function
int main() {
    // Create the root of the trie
    trie_node *root = new_trie_node(' ');

    // Load the dictionary into the trie
    load_dictionary(root, "dictionary.txt");

    // Check if a message contains any spam words
    char *message = "This is a spam message";
    if (is_spam(root, message)) {
        printf("The message is spam\n");
    } else {
        printf("The message is not spam\n");
    }

    return 0;
}