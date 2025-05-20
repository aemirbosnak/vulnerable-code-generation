//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    int is_end_of_word;
} TrieNode;

TrieNode *create_node() {
    TrieNode *new_node = (TrieNode *) malloc(sizeof(TrieNode));
    new_node->is_end_of_word = false;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        new_node->children[i] = NULL;
    }

    return new_node;
}

void insert(TrieNode *root, const char *word) {
    TrieNode *current = root;

    for (int level = 0; word[level]; level++) {
        int index = tolower(word[level]) - 'a';
        if (!current->children[index]) {
            current->children[index] = create_node();
        }
        current = current->children[index];
    }

    current->is_end_of_word = true;
}

int search(TrieNode *root, const char *word, int *frequency) {
    TrieNode *current = root;

    for (int level = 0; word[level]; level++) {
        int index = tolower(word[level]) - 'a';
        if (!current->children[index]) {
            return false;
        }
        current = current->children[index];
    }

    if (current->is_end_of_word) {
        (*frequency)++;
        return true;
    }

    return false;
}

void free_trie(TrieNode *node) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) {
            free_trie(node->children[i]);
        }
    }

    free(node);
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    TrieNode *root = create_node();

    char word[256];
    int frequency = 0;

    while (fscanf(file, "%s%*c", word) != EOF) {
        insert(root, word);
    }

    rewind(file);

    while (fscanf(file, "%s%*c", word) != EOF) {
        search(root, word, &frequency);
    }

    printf("Total frequency of all words: %d\n", frequency);

    free_trie(root);
    fclose(file);

    return 0;
}