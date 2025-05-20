//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A node in the trie data structure
struct TrieNode {
    struct TrieNode *children[26]; // Child nodes for each letter of the alphabet
    int is_word; // Flag indicating if this node represents the end of a word
};

// Create a new trie node
struct TrieNode *create_trie_node() {
    struct TrieNode *node = malloc(sizeof(struct TrieNode));
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    node->is_word = 0;
    return node;
}

// Insert a word into the trie
void insert_word(struct TrieNode *root, char *word) {
    struct TrieNode *current = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = create_trie_node();
        }
        current = current->children[index];
    }
    current->is_word = 1;
}

// Count the number of words in the trie
int count_words(struct TrieNode *root) {
    int count = 0;
    for (int i = 0; i < 26; i++) {
        if (root->children[i] != NULL) {
            count += count_words(root->children[i]);
        }
    }
    return count + root->is_word;
}

// Main function
int main() {
    // Create the root of the trie
    struct TrieNode *root = create_trie_node();

    // Insert some words into the trie
    insert_word(root, "hello");
    insert_word(root, "world");
    insert_word(root, "computer");
    insert_word(root, "science");
    insert_word(root, "programming");

    // Count the number of words in the trie
    int word_count = count_words(root);

    // Print the word count
    printf("The trie contains %d words.\n", word_count);

    return 0;
}