//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    int is_end_of_word;
} TrieNode;

TrieNode *root = NULL;

void add_word(TrieNode *node, const char *word) {
    TrieNode *current = node;
    for (int i = 0; word[i]; i++) {
        int index = tolower(word[i]) - 'a';
        if (!current->children[index]) {
            current->children[index] = calloc(1, sizeof(TrieNode));
        }
        current = current->children[index];
    }
    current->is_end_of_word = 1;
}

int search_word(TrieNode *node, const char *word) {
    TrieNode *current = node;
    for (int i = 0; word[i]; i++) {
        int index = tolower(word[i]) - 'a';
        if (!current->children[index]) {
            return 0;
        }
        current = current->children[index];
    }
    return current->is_end_of_word;
}

int main() {
    root = calloc(1, sizeof(TrieNode));

    const char *words[] = {"apple", "banana", "orange", "grape", "appl", "app", "ban", "applen", "orang", "grapes", "apples"};

    for (int i = 0; i < sizeof(words) / sizeof(words[0]); i++) {
        add_word(root, words[i]);
    }

    while (1) {
        printf("Enter a word to check its spelling: ");
        char input[100];
        scanf("%s", input);

        int is_valid = search_word(root, input);
        if (is_valid) {
            printf("The word '%s' is spelled correctly.\n", input);
        } else {
            printf("The word '%s' is not in the dictionary.\n", input);
        }
    }

    return 0;
}