//Falcon-180B DATASET v1.0 Category: Data mining ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

// Node structure for trie
typedef struct trieNode {
    int count;
    struct trieNode* children[26];
} trieNode;

// Trie structure
trieNode* root = NULL;

// Function to create a new trie node
trieNode* createNode() {
    trieNode* node = (trieNode*)malloc(sizeof(trieNode));
    node->count = 0;
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    return node;
}

// Function to insert a word into the trie
void insertWord(char* word) {
    int length = strlen(word);
    trieNode* current = root;
    for (int i = 0; i < length; i++) {
        int index = word[i] - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = createNode();
        }
        current = current->children[index];
    }
    current->count++;
}

// Function to traverse the trie and print all words
void traverseTrie(trieNode* node, char* prefix) {
    if (node == NULL) {
        return;
    }
    if (node->count > 0) {
        printf("%s (%d)\n", prefix, node->count);
    }
    for (int i = 0; i < 26; i++) {
        traverseTrie(node->children[i], prefix);
    }
}

// Function to read words from a file and insert them into the trie
void readWordsFromFile(FILE* file) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        insertWord(word);
    }
}

int main() {
    root = createNode();
    FILE* file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }
    readWordsFromFile(file);
    fclose(file);
    printf("Total words: %d\n", root->count);
    traverseTrie(root, "");
    return 0;
}