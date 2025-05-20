//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: protected
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 1000

// Node structure for the trie
typedef struct node {
    char word[MAX_WORD_LENGTH];
    int count;
    struct node *children[26];
} TrieNode;

// Trie structure
TrieNode *trie = NULL;

// Function to initialize the trie
void initTrie() {
    trie = (TrieNode *)malloc(sizeof(TrieNode));
    memset(trie, 0, sizeof(TrieNode));
}

// Function to insert a word into the trie
void insertWord(char *word) {
    TrieNode *current = trie;
    int length = strlen(word);

    for (int i = 0; i < length; i++) {
        int index = tolower(word[i]) - 'a';

        if (current->children[index] == NULL) {
            current->children[index] = (TrieNode *)malloc(sizeof(TrieNode));
            memset(current->children[index], 0, sizeof(TrieNode));
        }

        current = current->children[index];
    }

    current->count++;
}

// Function to check if a word is in the trie
int checkWord(char *word) {
    TrieNode *current = trie;
    int length = strlen(word);

    for (int i = 0; i < length; i++) {
        int index = tolower(word[i]) - 'a';

        if (current->children[index] == NULL) {
            return 0;
        }

        current = current->children[index];
    }

    return current->count;
}

// Function to load words from a dictionary file
void loadDictionary(char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error loading dictionary file\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];

    while (fscanf(file, "%s", word)!= EOF) {
        insertWord(word);
    }

    fclose(file);
}

// Function to check a sentence for spelling errors
void checkSentence(char *sentence) {
    char word[MAX_WORD_LENGTH];
    char *token = strtok(sentence, " ");

    while (token!= NULL) {
        strcpy(word, token);
        int count = checkWord(word);

        if (count == 0) {
            printf("%s is not in the dictionary\n", word);
        }

        token = strtok(NULL, " ");
    }
}

// Main function
int main() {
    initTrie();
    loadDictionary("dictionary.txt");

    char sentence[1000];

    printf("Enter a sentence to check for spelling errors: ");
    fgets(sentence, sizeof(sentence), stdin);

    checkSentence(sentence);

    return 0;
}