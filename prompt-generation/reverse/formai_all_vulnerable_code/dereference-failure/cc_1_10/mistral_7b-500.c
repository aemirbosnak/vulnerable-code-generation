//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct TrieNode {
    bool is_end_of_word;
    struct TrieNode *children[27];
} TrieNode;

void trie_insert(TrieNode *root, const char *word) {
    TrieNode *current = root;
    for (int i = 0; word[i]; i++) {
        int index = word[i] - 'a';
        if (!current->children[index]) {
            current->children[index] = malloc(sizeof(TrieNode));
            memset(current->children[index], 0, sizeof(TrieNode));
        }
        current = current->children[index];
    }
    current->is_end_of_word = true;
}

bool trie_search(const TrieNode *root, const char *word, int length) {
    TrieNode *current = root;
    for (int i = 0; i < length; i++) {
        int index = word[i] - 'a';
        if (!current->children[index]) {
            return false;
        }
        current = current->children[index];
    }
    return current && current->is_end_of_word;
}

int main() {
    FILE *dictionary_file = fopen("dictionary.txt", "r");
    if (!dictionary_file) {
        perror("Error opening dictionary file");
        return 1;
    }

    TrieNode *root = calloc(1, sizeof(TrieNode));

    char word[100];
    while (fscanf(dictionary_file, "%s", word) != EOF) {
        int length = strlen(word);
        trie_insert(root, word);
    }

    fclose(dictionary_file);

    char input[100];
    while (true) {
        printf("Enter a word to check (type 'quit' to exit): ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        }

        int length = strlen(input);
        bool is_valid_word = trie_search(root, input, length);

        if (is_valid_word) {
            printf("Congratulations! '%s' is a valid word.\n", input);
        } else {
            printf("Warning! '%s' may not be a valid word.\n", input);
        }
    }

    free(root);

    return 0;
}