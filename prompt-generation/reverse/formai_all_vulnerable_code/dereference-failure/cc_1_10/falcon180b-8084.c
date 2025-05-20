//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

// Node structure for trie
struct TrieNode {
    int count; // Count of words ending at this node
    struct TrieNode* children[26]; // Array of child nodes
};

void createNode(struct TrieNode** node) {
    *node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    (*node)->count = 0;
    for (int i = 0; i < 26; i++) {
        (*node)->children[i] = NULL;
    }
}

void insertWord(struct TrieNode* node, char* word) {
    int length = strlen(word);
    struct TrieNode* current = node;
    for (int i = 0; i < length; i++) {
        int index = word[i] - 'a';
        if (current->children[index] == NULL) {
            createNode(&(current->children[index]));
        }
        current = current->children[index];
    }
    current->count++;
}

void printWords(struct TrieNode* node, char* prefix) {
    if (node == NULL) {
        return;
    }
    if (node->count > 0) {
        printf("%s\n", prefix);
    }
    for (int i = 0; i < 26; i++) {
        printWords(node->children[i], prefix + 1);
    }
}

int main() {
    char input[MAX_WORD_LENGTH];
    int length = 0;
    struct TrieNode* root = NULL;
    createNode(&root);
    while (scanf("%s", input) == 1) {
        insertWord(root, input);
        length++;
        if (length >= MAX_WORDS) {
            break;
        }
    }
    printWords(root, "");
    return 0;
}