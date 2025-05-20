//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

struct TrieNode {
    bool isWord;
    struct TrieNode *children[26];
};

struct TrieNode *createTrieNode() {
    struct TrieNode *node = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    node->isWord = false;
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void insertWord(struct TrieNode *root, char *word) {
    struct TrieNode *current = root;
    int index;
    for (int i = 0; i < strlen(word); i++) {
        index = tolower(word[i]) - 'a';
        if (!current->children[index]) {
            current->children[index] = createTrieNode();
        }
        current = current->children[index];
    }
    current->isWord = true;
}

bool searchWord(struct TrieNode *root, char *word) {
    struct TrieNode *current = root;
    int index;
    for (int i = 0; i < strlen(word); i++) {
        index = tolower(word[i]) - 'a';
        if (!current->children[index]) {
            return false;
        }
        current = current->children[index];
    }
    return current->isWord;
}

struct TrieNode *buildTrie(char **words, int numWords) {
    struct TrieNode *root = createTrieNode();
    for (int i = 0; i < numWords; i++) {
        insertWord(root, words[i]);
    }
    return root;
}

void spellCheck(struct TrieNode *root, char **words, int numWords) {
    for (int i = 0; i < numWords; i++) {
        if (!searchWord(root, words[i])) {
            printf("Oops! \"%s\" is not in the dictionary.\n", words[i]);
        }
    }
}

int main() {
    char *words[] = {"hello", "world", "computer", "science", "programming", "dictionary", "spell", "check", "error", "correct"};

    int numWords = sizeof(words) / sizeof(char *);

    struct TrieNode *root = buildTrie(words, numWords);

    char *testWords[] = {"hello", "world", "computer", "scienc", "programing", "dictionari", "spel", "chek", "eror", "corect"};

    int numTestWords = sizeof(testWords) / sizeof(char *);

    spellCheck(root, testWords, numTestWords);

    return 0;
}