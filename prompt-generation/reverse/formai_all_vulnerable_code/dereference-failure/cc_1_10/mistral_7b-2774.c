//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    bool is_end_of_word;
    struct TrieNode *children[ALPHABET_SIZE];
} TrieNode;

void load_dictionary(const char *filename, TrieNode **root) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening dictionary file\n");
        exit(EXIT_FAILURE);
    }

    *root = calloc(1, sizeof(TrieNode));
    TrieNode *current = *root;

    char word[50];
    while (fscanf(file, "%s", word) != EOF) {
        int length = strlen(word);
        for (int i = 0; i < length; ++i) {
            int index = tolower(word[i]) - 'a';
            if (!current->children[index]) {
                current->children[index] = calloc(1, sizeof(TrieNode));
            }
            current = current->children[index];
        }
        current->is_end_of_word = true;
    }

    fclose(file);
}

bool search(const TrieNode *root, const char *word, int depth) {
    if (depth > strlen(word)) {
        return root->is_end_of_word;
    }

    int index = tolower(word[depth]) - 'a';
    if (!root->children[index]) {
        return false;
    }

    return search(root->children[index], word, depth + 1);
}

int main() {
    TrieNode *root;
    load_dictionary("dictionary.txt", &root);

    char input[100];
    while (true) {
        printf("Enter a word to check: ");
        scanf("%s", input);

        int length = strlen(input);
        if (search(root, input, 0)) {
            printf("The word '%s' is spelled correctly.\n", input);
        } else {
            printf("The word '%s' is misspelled.\n", input);
        }
    }

    free(root);
    return 0;
}