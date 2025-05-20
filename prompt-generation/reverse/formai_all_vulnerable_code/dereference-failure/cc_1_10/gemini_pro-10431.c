//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1024
#define MAX_WORD_LEN 32

typedef struct TrieNode {
    struct TrieNode *children[26];
    int isEndOfWord;
} TrieNode;

TrieNode *createTrieNode() {
    TrieNode *node = (TrieNode *)malloc(sizeof(TrieNode));
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    node->isEndOfWord = 0;
    return node;
}

void insertIntoTrie(TrieNode *root, char *word) {
    TrieNode *curr = root;
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        int index = word[i] - 'a';
        if (curr->children[index] == NULL) {
            curr->children[index] = createTrieNode();
        }
        curr = curr->children[index];
    }
    curr->isEndOfWord = 1;
}

int searchInTrie(TrieNode *root, char *word) {
    TrieNode *curr = root;
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        int index = word[i] - 'a';
        if (curr->children[index] == NULL) {
            return 0;
        }
        curr = curr->children[index];
    }
    return curr->isEndOfWord;
}

void printTrie(TrieNode *root, char *prefix) {
    if (root->isEndOfWord) {
        printf("%s\n", prefix);
    }
    for (int i = 0; i < 26; i++) {
        if (root->children[i] != NULL) {
            char newPrefix[MAX_STR_LEN];
            strcpy(newPrefix, prefix);
            newPrefix[strlen(newPrefix)] = 'a' + i;
            printTrie(root->children[i], newPrefix);
        }
    }
}

int main() {
    char words[][MAX_WORD_LEN] = {
        "apple",
        "banana",
        "cherry",
        "dog",
        "elephant",
        "fish",
        "grape",
        "horse",
        "ice cream",
        "juice"
    };
    int numWords = sizeof(words) / sizeof(words[0]);

    TrieNode *root = createTrieNode();
    for (int i = 0; i < numWords; i++) {
        insertIntoTrie(root, words[i]);
    }

    char searchWords[][MAX_WORD_LEN] = {
        "apple",
        "dog",
        "elephant",
        "zebra"
    };
    int numSearchWords = sizeof(searchWords) / sizeof(searchWords[0]);

    for (int i = 0; i < numSearchWords; i++) {
        int found = searchInTrie(root, searchWords[i]);
        printf("%s: %s\n", searchWords[i], found ? "Found" : "Not found");
    }

    printf("\nAll words in the trie:\n");
    printTrie(root, "");

    return 0;
}