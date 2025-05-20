//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

// Node structure for the trie
typedef struct trieNode {
    int count;
    struct trieNode* children[26];
} TrieNode;

// Trie structure
TrieNode* root = NULL;

// Function to create a new trie node
TrieNode* createNode() {
    TrieNode* newNode = (TrieNode*)malloc(sizeof(TrieNode));
    newNode->count = 0;
    for (int i = 0; i < 26; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

// Function to insert a word into the trie
void insert(char* word) {
    TrieNode* current = root;
    int length = strlen(word);

    for (int i = 0; i < length; i++) {
        int index = tolower(word[i]) - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = createNode();
        }
        current = current->children[index];
    }

    current->count++;
}

// Function to traverse the trie and count the frequency of words
void traverse(TrieNode* node, char* prefix, int depth) {
    if (node == NULL) {
        return;
    }

    if (depth == strlen(prefix)) {
        printf("%s: %d\n", prefix, node->count);
    } else {
        for (int i = 0; i < 26; i++) {
            if (node->children[i]!= NULL) {
                char nextChar = 'a' + i;
                traverse(node->children[i], prefix, depth + 1);
            }
        }
    }
}

// Main function
int main() {
    root = createNode();

    char word[MAX_WORD_LENGTH];
    while (fscanf(stdin, "%s", word)!= EOF) {
        insert(word);
    }

    printf("Enter a prefix to search for:\n");
    scanf("%s", word);

    traverse(root, word, 0);

    return 0;
}