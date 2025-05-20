//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    int count;
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
} TrieNode;

void initTrieNode(TrieNode *node) {
    memset(node->children, 0, ALPHABET_SIZE * sizeof(TrieNode *));
    node->count = 0;
    node->isEndOfWord = false;
}

TrieNode *createTrieNode() {
    TrieNode *node = malloc(sizeof(TrieNode));
    initTrieNode(node);
    return node;
}

void insert(TrieNode *root, const char *word) {
    TrieNode *current = root;
    for (int level = 0; word[level]; ++level) {
        int index = tolower(word[level]) - 'a';
        if (!current->children[index]) {
            current->children[index] = createTrieNode();
        }
        current = current->children[index];
    }
    current->isEndOfWord = true;
    ++current->count;
}

void freeTrieNode(TrieNode *node) {
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if (node->children[i]) {
            freeTrieNode(node->children[i]);
        }
    }
    free(node);
}

void destroyTrie(TrieNode *root) {
    freeTrieNode(root);
}

bool search(const TrieNode *root, const char *word) {
    TrieNode *current = root;
    for (int level = 0; word[level]; ++level) {
        int index = tolower(word[level]) - 'a';
        if (!current->children[index]) {
            return false;
        }
        current = current->children[index];
    }
    return current && current->isEndOfWord;
}

unsigned int countWordsInFile(const char *filename, TrieNode *root) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return 0;
    }

    char word[1024];
    unsigned int count = 0;
    while (fscanf(file, "%s%*c", word) != EOF) {
        if (strlen(word) > 0) {
            ++count;
            insert(root, word);
        }
    }

    fclose(file);
    return count;
}

int main() {
    TrieNode *root = createTrieNode();

    const char *filename = "sample.txt";
    unsigned int numWords = countWordsInFile(filename, root);

    printf("Number of unique words in file \"%s\": %u\n", filename, numWords);

    destroyTrie(root);

    return EXIT_SUCCESS;
}