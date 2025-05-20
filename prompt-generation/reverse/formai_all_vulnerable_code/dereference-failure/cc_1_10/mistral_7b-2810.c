//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define NUM_BUCKETS 256

typedef struct TrieNode {
    int isEndOfWord;
    struct TrieNode *children[NUM_BUCKETS];
} TrieNode;

TrieNode *createNode() {
    TrieNode *node = (TrieNode *)malloc(sizeof(TrieNode));
    node->isEndOfWord = 0;
    for (int i = 0; i < NUM_BUCKETS; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void insert(TrieNode *root, char *word) {
    int length = strlen(word);
    TrieNode *currentNode = root;

    for (int i = 0; i < length; i++) {
        int index = tolower(word[i]) - 'a';
        if (!currentNode->children[index]) {
            currentNode->children[index] = createNode();
        }
        currentNode = currentNode->children[index];
    }

    currentNode->isEndOfWord = 1;
}

int search(TrieNode *root, char *word) {
    int length = strlen(word);
    TrieNode *currentNode = root;

    for (int i = 0; i < length; i++) {
        int index = tolower(word[i]) - 'a';
        if (!currentNode->children[index]) {
            return 0;
        }
        currentNode = currentNode->children[index];
    }

    return currentNode->isEndOfWord;
}

void loadDictionary(TrieNode *root, char *filename) {
    FILE *file = fopen(filename, "r");

    if (file) {
        char word[MAX_WORD_LENGTH];
        while (fscanf(file, "%s", word) != EOF) {
            insert(root, word);
        }
        fclose(file);
    }
}

int main() {
    TrieNode *root = createNode();

    char filename[50];
    printf("Enter the dictionary file name: ");
    scanf("%s", filename);

    loadDictionary(root, filename);

    char word[MAX_WORD_LENGTH];
    int isSpelledCorrectly = 1;

    printf("Enter a word to check its spelling: ");
    scanf("%s", word);

    if (search(root, word)) {
        printf("The word '%s' is spelled correctly!\n", word);
    } else {
        printf("The word '%s' is not in the dictionary.\n", word);
        isSpelledCorrectly = 0;
    }

    if (isSpelledCorrectly) {
        printf("I am grateful that your word is spelled correctly!\n");
    } else {
        printf("I'm sorry, but I cannot find your word in the dictionary.\n");
        printf("Perhaps you meant to say '%s' instead?\n", word);
    }

    return 0;
}