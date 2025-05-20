//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: excited
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Create a node for the trie
struct TrieNode {
    struct TrieNode *children[26];
    int isEndOfWord;
};

// Create a new trie node
struct TrieNode *getNode() {
    struct TrieNode *pNode = NULL;

    pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));

    if (pNode) {
        int i;

        pNode->isEndOfWord = 0;

        for (i = 0; i < 26; i++) {
            pNode->children[i] = NULL;
        }
    }

    return pNode;
}

// Insert a word into the trie
void insert(struct TrieNode *root, char *key) {
    int level;
    int length = strlen(key);
    int index;

    struct TrieNode *pCrawl = root;

    for (level = 0; level < length; level++) {
        index = key[level] - 'a';

        if (!pCrawl->children[index]) {
            pCrawl->children[index] = getNode();
        }

        pCrawl = pCrawl->children[index];
    }

    // mark last node as leaf
    pCrawl->isEndOfWord = 1;
}

// Check if a word is present in the trie
int search(struct TrieNode *root, char *key) {
    int level;
    int length = strlen(key);
    int index;

    struct TrieNode *pCrawl = root;

    for (level = 0; level < length; level++) {
        index = key[level] - 'a';

        if (!pCrawl->children[index]) {
            return 0;
        }

        pCrawl = pCrawl->children[index];
    }

    return (pCrawl->isEndOfWord);
}

// Utility function to check if a word is a valid word
int isWord(char *word) {
    int length = strlen(word);
    int i;

    for (i = 0; i < length; i++) {
        if (word[i] < 'a' || word[i] > 'z') {
            return 0;
        }
    }

    return 1;
}

// Main function
int main() {
    // Create a trie
    struct TrieNode *root = getNode();

    // Insert words into the trie
    insert(root, "the");
    insert(root, "a");
    insert(root, "there");
    insert(root, "answer");
    insert(root, "any");
    insert(root, "by");
    insert(root, "bye");
    insert(root, "their");

    // Get the input word
    char word[100];

    printf("Enter a word: ");
    scanf("%s", word);

    // Check if the word is a valid word
    if (!isWord(word)) {
        printf("Invalid word\n");
        return 0;
    }

    // Check if the word is present in the trie
    if (search(root, word)) {
        printf("The word is present in the dictionary\n");
    } else {
        printf("The word is not present in the dictionary\n");
    }

    return 0;
}