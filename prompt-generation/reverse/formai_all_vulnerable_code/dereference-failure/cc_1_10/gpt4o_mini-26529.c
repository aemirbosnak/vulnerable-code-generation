//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_SIZE 10000
#define MAX_LINE_LENGTH 1024

typedef struct TrieNode {
    struct TrieNode *children[26];
    int isEndOfWord;
} TrieNode;

TrieNode *createNode() {
    TrieNode *node = (TrieNode *)malloc(sizeof(TrieNode));
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    node->isEndOfWord = 0;
    return node;
}

TrieNode *root;

void insertWord(const char *word) {
    TrieNode *current = root;
    while (*word) {
        int index = tolower(*word) - 'a';
        if (index < 0 || index >= 26) {
            word++;
            continue;
        }
        if (current->children[index] == NULL) {
            current->children[index] = createNode();
        }
        current = current->children[index];
        word++;
    }
    current->isEndOfWord = 1;
}

int searchWord(const char *word) {
    TrieNode *current = root;
    while (*word) {
        int index = tolower(*word) - 'a';
        if (index < 0 || index >= 26 || current->children[index] == NULL) {
            return 0;
        }
        current = current->children[index];
        word++;
    }
    return current->isEndOfWord;
}

void freeTrie(TrieNode *node) {
    for (int i = 0; i < 26; i++) {
        if (node->children[i] != NULL) {
            freeTrie(node->children[i]);
        }
    }
    free(node);
}

void loadDictionary(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open the dictionary file\n");
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LENGTH];
    while (fgets(word, sizeof(word), file)) {
        word[strcspn(word, "\n")] = 0; // Remove newline character
        insertWord(word);
    }

    fclose(file);
}

void checkSpelling(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open the file to check spelling\n");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        char *word = strtok(line, " \t\n");
        while (word != NULL) {
            if (!searchWord(word)) {
                printf("Misspelled word: %s\n", word);
            }
            word = strtok(NULL, " \t\n");
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    root = createNode();
    loadDictionary(argv[1]);
    checkSpelling(argv[2]);
    freeTrie(root);

    return 0;
}