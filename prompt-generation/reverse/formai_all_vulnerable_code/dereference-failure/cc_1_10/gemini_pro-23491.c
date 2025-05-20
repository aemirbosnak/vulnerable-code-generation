//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a node for the trie
struct TrieNode {
    char* word;
    struct TrieNode* children[26];
    int isEndOfWord;
};

// Create a new trie node
struct TrieNode* createTrieNode() {
    struct TrieNode* node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    node->word = NULL;
    node->isEndOfWord = 0;
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    return node;
}

// Insert a word into the trie
void insertIntoTrie(struct TrieNode* root, char* word) {
    struct TrieNode* current = root;
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = createTrieNode();
        }
        current = current->children[index];
    }
    current->isEndOfWord = 1;
    current->word = word;
}

// Search for a word in the trie
int searchInTrie(struct TrieNode* root, char* word) {
    struct TrieNode* current = root;
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (current->children[index] == NULL) {
            return 0;
        }
        current = current->children[index];
    }
    return current->isEndOfWord;
}

// Print all the words in the trie
void printTrieWords(struct TrieNode* root) {
    if (root->isEndOfWord) {
        printf("%s\n", root->word);
    }
    for (int i = 0; i < 26; i++) {
        if (root->children[i] != NULL) {
            printTrieWords(root->children[i]);
        }
    }
}

// Free the trie
void freeTrie(struct TrieNode* root) {
    for (int i = 0; i < 26; i++) {
        if (root->children[i] != NULL) {
            freeTrie(root->children[i]);
        }
    }
    free(root);
}

// Driver code
int main() {
    // Create a trie
    struct TrieNode* root = createTrieNode();

    // Insert words into the trie
    insertIntoTrie(root, "hello");
    insertIntoTrie(root, "world");
    insertIntoTrie(root, "trie");
    insertIntoTrie(root, "data");
    insertIntoTrie(root, "structure");

    // Print all the words in the trie
    printTrieWords(root);

    // Search for a word in the trie
    printf("Is \"hello\" in the trie? %d\n", searchInTrie(root, "hello"));
    printf("Is \"structures\" in the trie? %d\n", searchInTrie(root, "structures"));

    // Free the trie
    freeTrie(root);

    return 0;
}