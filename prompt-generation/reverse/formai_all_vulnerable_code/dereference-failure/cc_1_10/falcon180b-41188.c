//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100

// Node structure for trie
struct TrieNode {
    int freq;
    struct TrieNode* children[26];
};

// Function to create a new trie node
struct TrieNode* newNode() {
    struct TrieNode* node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    node->freq = 0;
    for (int i = 0; i < 26; i++)
        node->children[i] = NULL;
    return node;
}

// Function to insert a word into the trie
void insert(struct TrieNode* root, char* word) {
    struct TrieNode* node = root;
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        int ch = tolower(word[i]);
        if (node->children[ch] == NULL)
            node->children[ch] = newNode();
        node = node->children[ch];
    }
    node->freq++;
}

// Function to traverse the trie and print words with their frequencies
void traverse(struct TrieNode* root, char prefix[]) {
    struct TrieNode* node = root;
    for (int i = 0; i < strlen(prefix); i++) {
        int ch = tolower(prefix[i]);
        if (node->children[ch] == NULL)
            return;
        node = node->children[ch];
    }
    if (node->freq > 0)
        printf("%s %d\n", prefix, node->freq);
    for (int i = 0; i < 26; i++) {
        if (node->children[i]!= NULL)
            traverse(node->children[i], prefix);
    }
}

// Function to read words from a file and insert them into the trie
void readWords(char* filename, struct TrieNode* root) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    char word[MAX_WORD_LEN];
    while (fscanf(fp, "%s", word)!= EOF) {
        insert(root, word);
    }
    fclose(fp);
}

int main() {
    char filename[100];
    printf("Enter the name of the text file: ");
    scanf("%s", filename);
    struct TrieNode* root = newNode();
    readWords(filename, root);
    printf("Enter the prefix to search for: ");
    char prefix[100];
    scanf("%s", prefix);
    traverse(root, prefix);
    return 0;
}