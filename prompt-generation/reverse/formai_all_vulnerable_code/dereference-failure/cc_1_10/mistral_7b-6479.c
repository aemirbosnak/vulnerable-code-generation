//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TRIE_SIZE 26

typedef struct TrieNode {
    int is_end_of_word;
    struct TrieNode *children[TRIE_SIZE];
} TrieNode;

TrieNode *root = NULL;

void add_word(TrieNode *root, const char *word) {
    TrieNode *current = root;
    int level;

    for (level = 0; word[level]; level++) {
        int index = tolower(word[level]) - 'a';
        if (!current->children[index])
            current->children[index] = calloc(1, sizeof(TrieNode));

        current = current->children[index];
    }

    current->is_end_of_word = 1;
}

int search_word(const char *word) {
    TrieNode *current = root;
    int level;

    for (level = 0; word[level]; level++) {
        int index = tolower(word[level]) - 'a';
        if (!current->children[index])
            return 0;

        current = current->children[index];
    }

    return current->is_end_of_word;
}

void free_trie(TrieNode *node) {
    int i;

    if (!node)
        return;

    for (i = 0; i < TRIE_SIZE; i++) {
        if (node->children[i])
            free_trie(node->children[i]);
    }

    free(node);
}

int main(void) {
    int i, words_count;
    const char *words[] = {
        "apple",
        "banana",
        "orange",
        "grape",
        "mango",
        "kiwi",
        "pear",
        "peach",
        "apricot",
        "plum"
    };

    root = calloc(1, sizeof(TrieNode));

    for (words_count = 0; words[words_count]; words_count++)
        add_word(root, words[words_count]);

    for (i = 0; words[i]; i++) {
        printf("Checking word: %s\n", words[i]);
        if (search_word(words[i]))
            printf("Correct spelling!\n");
        else
            printf("Incorrect spelling!\n");
    }

    free_trie(root);

    return 0;
}