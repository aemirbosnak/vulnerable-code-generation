//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 256

struct TrieNode {
    struct TrieNode *children[26];
    int is_word;
};

struct TrieNode *create_trie_node() {
    struct TrieNode *node = malloc(sizeof(struct TrieNode));
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    node->is_word = 0;
    return node;
}

void insert_word_into_trie(struct TrieNode *root, const char *word) {
    if (word == NULL || *word == '\0') {
        return;
    }

    struct TrieNode *current = root;
    int index;
    while (*word != '\0') {
        index = *word - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = create_trie_node();
        }
        current = current->children[index];
        word++;
    }

    current->is_word = 1;
}

int search_word_in_trie(struct TrieNode *root, const char *word) {
    if (word == NULL || *word == '\0') {
        return 0;
    }

    struct TrieNode *current = root;
    int index;
    while (*word != '\0') {
        index = *word - 'a';
        if (current->children[index] == NULL) {
            return 0;
        }
        current = current->children[index];
        word++;
    }

    return current->is_word;
}

int main() {
    struct TrieNode *root = create_trie_node();
    char *words[] = {"hello", "world", "computer", "science", "mathematics"};
    int num_words = sizeof(words) / sizeof(char *);

    for (int i = 0; i < num_words; i++) {
        insert_word_into_trie(root, words[i]);
    }

    char *input_word = "computer";
    int result = search_word_in_trie(root, input_word);

    if (result == 1) {
        printf("The word '%s' is spelled correctly.\n", input_word);
    } else {
        printf("The word '%s' is misspelled.\n", input_word);
    }

    return 0;
}