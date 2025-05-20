//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool is_end_of_word;
} TrieNode;

TrieNode *create_node() {
    TrieNode *node = (TrieNode *)calloc(1, sizeof(TrieNode));
    node->is_end_of_word = false;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void insert(TrieNode *root, const char *word) {
    TrieNode *current = root;
    for (int level = 0; word[level] != '\0'; level++) {
        int index = tolower(word[level]) - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = create_node();
        }
        current = current->children[index];
    }
    current->is_end_of_word = true;
}

bool search(TrieNode *root, const char *word) {
    TrieNode *current = root;
    for (int level = 0; word[level] != '\0'; level++) {
        int index = tolower(word[level]) - 'a';
        if (current->children[index] == NULL) {
            return false;
        }
        current = current->children[index];
    }
    return current != NULL && current->is_end_of_word;
}

bool check_spelling(const char *word) {
    TrieNode *root = create_node();
    bool result = search(root, word);
    free(root);
    return result;
}

int main() {
    char input[100];
    while (true) {
        printf("Enter a word to check its spelling (or type 'quit' to exit): ");
        scanf("%s", input);
        if (strcmp(input, "quit") == 0) {
            break;
        }
        bool is_valid = check_spelling(input);
        if (is_valid) {
            printf("%s is a valid word.\n", input);
        } else {
            printf("%s is not a valid word.\n", input);
        }
    }
    return 0;
}