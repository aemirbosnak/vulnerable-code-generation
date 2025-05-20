//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node of the trie
typedef struct TrieNode {
    char *word;
    struct TrieNode *children[26];
    int isWord;
} TrieNode;

// Insert a word into the trie
void insertIntoTrie(TrieNode *root, char *word) {
    TrieNode *curr = root;
    int i;
    for (i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (curr->children[index] == NULL) {
            curr->children[index] = (TrieNode *)malloc(sizeof(TrieNode));
            curr->children[index]->word = NULL;
            curr->children[index]->isWord = 0;
            for (int j = 0; j < 26; j++) {
                curr->children[index]->children[j] = NULL;
            }
        }
        curr = curr->children[index];
    }
    curr->word = malloc(strlen(word) + 1);
    strcpy(curr->word, word);
    curr->isWord = 1;
}

// Search for a word in the trie
int searchInTrie(TrieNode *root, char *word) {
    TrieNode *curr = root;
    int i;
    for (i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (curr->children[index] == NULL) {
            return 0;
        }
        curr = curr->children[index];
    }
    return curr->isWord;
}

// Free the trie
void freeTrie(TrieNode *root) {
    for (int i = 0; i < 26; i++) {
        if (root->children[i] != NULL) {
            freeTrie(root->children[i]);
        }
    }
    free(root->word);
    free(root);
}

// Load the dictionary into the trie
void loadDictionary(TrieNode *root, char *filename) {
    FILE *fp = fopen(filename, "r");
    char word[100];
    while (fscanf(fp, "%s", word) != EOF) {
        insertIntoTrie(root, word);
    }
    fclose(fp);
}

// Spell check a document
void spellCheck(TrieNode *root, char *filename) {
    FILE *fp = fopen(filename, "r");
    char word[100];
    while (fscanf(fp, "%s", word) != EOF) {
        if (!searchInTrie(root, word)) {
            printf("%s is not in the dictionary\n", word);
        }
    }
    fclose(fp);
}

// Main function
int main() {
    // Create the trie
    TrieNode *root = (TrieNode *)malloc(sizeof(TrieNode));
    root->word = NULL;
    root->isWord = 0;
    for (int i = 0; i < 26; i++) {
        root->children[i] = NULL;
    }

    // Load the dictionary into the trie
    loadDictionary(root, "dictionary.txt");

    // Spell check a document
    spellCheck(root, "document.txt");

    // Free the trie
    freeTrie(root);

    return 0;
}