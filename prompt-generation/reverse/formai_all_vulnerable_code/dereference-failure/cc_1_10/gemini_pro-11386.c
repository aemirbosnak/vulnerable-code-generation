//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 20

// Create a node for the trie
typedef struct TrieNode {
    char letter;
    struct TrieNode *children[26];
    int is_word;
} TrieNode;

// Create a new trie node
TrieNode *newTrieNode(char letter) {
    TrieNode *node = malloc(sizeof(TrieNode));
    node->letter = letter;
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    node->is_word = 0;
    return node;
}

// Insert a word into the trie
void insertWord(TrieNode *root, char *word) {
    TrieNode *current = root;
    int index;
    for (int i = 0; i < strlen(word); i++) {
        index = word[i] - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = newTrieNode(word[i]);
        }
        current = current->children[index];
    }
    current->is_word = 1;
}

// Check if a word is in the trie
int isWord(TrieNode *root, char *word) {
    TrieNode *current = root;
    int index;
    for (int i = 0; i < strlen(word); i++) {
        index = word[i] - 'a';
        if (current->children[index] == NULL) {
            return 0;
        }
        current = current->children[index];
    }
    return current->is_word;
}

// Load the dictionary into the trie
void loadDictionary(TrieNode *root, char *filename) {
    FILE *file = fopen(filename, "r");
    char word[MAX_WORD_LEN];
    while (fscanf(file, "%s", word) != EOF) {
        insertWord(root, word);
    }
    fclose(file);
}

// Check the spelling of a word
int checkSpelling(TrieNode *root, char *word) {
    return isWord(root, word);
}

// Print the suggestions for a misspelled word
void printSuggestions(TrieNode *root, char *word) {
    TrieNode *current = root;
    int index;
    for (int i = 0; i < strlen(word); i++) {
        index = word[i] - 'a';
        if (current->children[index] == NULL) {
            printf("No suggestions found.\n");
            return;
        }
        current = current->children[index];
    }
    printf("Suggestions:\n");
    for (int i = 0; i < 26; i++) {
        if (current->children[i] != NULL) {
            printf("%s\n", current->children[i]->letter);
        }
    }
}

// Free the trie
void freeTrie(TrieNode *root) {
    for (int i = 0; i < 26; i++) {
        if (root->children[i] != NULL) {
            freeTrie(root->children[i]);
        }
    }
    free(root);
}

int main() {
    // Create the trie
    TrieNode *root = newTrieNode(' ');

    // Load the dictionary into the trie
    loadDictionary(root, "dictionary.txt");

    // Check the spelling of a word
    char word[MAX_WORD_LEN];
    printf("Enter a word to check the spelling: ");
    scanf("%s", word);

    if (checkSpelling(root, word)) {
        printf("The word is spelled correctly.\n");
    } else {
        printf("The word is misspelled.\n");
        printSuggestions(root, word);
    }

    // Free the trie
    freeTrie(root);

    return 0;
}