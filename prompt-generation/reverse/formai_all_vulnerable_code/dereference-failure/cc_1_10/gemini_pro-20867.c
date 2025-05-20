//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 100

struct TrieNode {
    struct TrieNode *children[26];
    int is_word;
};

struct Trie {
    struct TrieNode *root;
};

struct TrieNode *create_trie_node() {
    struct TrieNode *node = malloc(sizeof(struct TrieNode));
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    node->is_word = 0;
    return node;
}

struct Trie *create_trie() {
    struct Trie *trie = malloc(sizeof(struct Trie));
    trie->root = create_trie_node();
    return trie;
}

void insert_word_into_trie(struct Trie *trie, char *word) {
    struct TrieNode *current = trie->root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = create_trie_node();
        }
        current = current->children[index];
    }
    current->is_word = 1;
}

int search_word_in_trie(struct Trie *trie, char *word) {
    struct TrieNode *current = trie->root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (current->children[index] == NULL) {
            return 0;
        }
        current = current->children[index];
    }
    return current->is_word;
}

int main() {
    struct Trie *trie = create_trie();
    char *words[] = {"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
    int num_words = sizeof(words) / sizeof(words[0]);
    for (int i = 0; i < num_words; i++) {
        insert_word_into_trie(trie, words[i]);
    }
    char *misspelled_words[] = {"teh", "qwick", "braun", "foks", "jmps", "ovr", "teh", "lazzy", "dok"};
    int num_misspelled_words = sizeof(misspelled_words) / sizeof(misspelled_words[0]);
    for (int i = 0; i < num_misspelled_words; i++) {
        if (!search_word_in_trie(trie, misspelled_words[i])) {
            printf("%s is misspelled.\n", misspelled_words[i]);
        }
    }
    return 0;
}