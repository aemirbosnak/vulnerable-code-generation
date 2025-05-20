//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node for the Trie data structure
struct TrieNode {
    char letter;
    struct TrieNode* children[26]; // One child for each possible letter in the alphabet
    int isWord; // 1 if the node represents the end of a word, 0 otherwise
};

// Create a new Trie node with the given letter
struct TrieNode* createTrieNode(char letter) {
    struct TrieNode* node = malloc(sizeof(struct TrieNode));
    node->letter = letter;
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    node->isWord = 0;
    return node;
}

// Insert a word into the Trie
void insertWord(struct TrieNode* root, char* word) {
    struct TrieNode* current = root;
    int index;
    int wordLength = strlen(word);

    for (int i = 0; i < wordLength; i++) {
        index = word[i] - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = createTrieNode(word[i]);
        }
        current = current->children[index];
    }

    current->isWord = 1;
}

// Search for a word in the Trie
int searchWord(struct TrieNode* root, char* word) {
    struct TrieNode* current = root;
    int index;
    int wordLength = strlen(word);

    for (int i = 0; i < wordLength; i++) {
        index = word[i] - 'a';
        if (current->children[index] == NULL) {
            return 0;
        }
        current = current->children[index];
    }

    return current->isWord;
}

// Print all the words in the Trie
void printWords(struct TrieNode* root, char* prefix) {
    if (root->isWord) {
        printf("%s\n", prefix);
    }

    for (int i = 0; i < 26; i++) {
        if (root->children[i] != NULL) {
            char newPrefix[strlen(prefix) + 2];
            strcpy(newPrefix, prefix);
            newPrefix[strlen(prefix)] = root->children[i]->letter;
            newPrefix[strlen(prefix) + 1] = '\0';
            printWords(root->children[i], newPrefix);
        }
    }
}

// Free the memory allocated for the Trie
void freeTrie(struct TrieNode* root) {
    for (int i = 0; i < 26; i++) {
        if (root->children[i] != NULL) {
            freeTrie(root->children[i]);
        }
    }

    free(root);
}

// The main function
int main() {
    // Create the root node of the Trie
    struct TrieNode* root = createTrieNode('\0');

    // Insert some words into the Trie
    insertWord(root, "hello");
    insertWord(root, "world");
    insertWord(root, "dog");
    insertWord(root, "cat");
    insertWord(root, "fish");

    // Search for a word in the Trie
    if (searchWord(root, "dog")) {
        printf("The word dog is in the Trie\n");
    } else {
        printf("The word dog is not in the Trie\n");
    }

    // Print all the words in the Trie
    printf("The words in the Trie are:\n");
    printWords(root, "");

    // Free the memory allocated for the Trie
    freeTrie(root);

    return 0;
}