//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define ALPHABET_SIZE 26

typedef struct TrieNode {
    int isEndOfWord;
    struct TrieNode *children[ALPHABET_SIZE];
} TrieNode;

TrieNode *createNode() {
    TrieNode *newNode = (TrieNode *) malloc(sizeof(TrieNode));
    newNode->isEndOfWord = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

void addWord(TrieNode *root, char *word) {
    TrieNode *current = root;
    for (int level = 0; level < strlen(word); level++) {
        int index = tolower(word[level]) - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = createNode();
        }
        current = current->children[index];
    }
    current->isEndOfWord = 1;
}

int searchWord(TrieNode *root, char *word) {
    TrieNode *current = root;
    for (int level = 0; level < strlen(word); level++) {
        int index = tolower(word[level]) - 'a';
        if (current->children[index] == NULL) {
            return 0;
        }
        current = current->children[index];
    }
    return current != NULL && current->isEndOfWord;
}

void loadDictionary(TrieNode **root, char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", fileName);
        exit(1);
    }

    *root = createNode();
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        addWord(*root, word);
    }

    fclose(file);
}

int main() {
    TrieNode *root = NULL;
    char fileName[100];
    printf("Enter dictionary file name: ");
    scanf("%s", fileName);

    loadDictionary(&root, fileName);

    char word[MAX_WORD_LENGTH];
    while (1) {
        printf("Enter a word to check (or type 'quit' to exit): ");
        scanf("%s", word);

        if (strcmp(word, "quit") == 0) {
            break;
        }

        int result = searchWord(root, word);
        if (result) {
            printf("The word '%s' is in the dictionary.\n", word);
        } else {
            printf("The word '%s' is not in the dictionary.\n", word);
        }
    }

    free(root);

    return 0;
}