//FormAI DATASET v1.0 Category: Spell checking ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DICTIONARY_SIZE 370099 // number of words in dictionary
#define MAX_WORD_LENGTH 45 // maximum word length

// structure for each node in the trie
typedef struct TrieNode {
    struct TrieNode *children[26];
    int isEnd;
} TrieNode;

// function prototypes
void insert(TrieNode *root, char *word);
int search(TrieNode *root, char *word);
void freeTrie(TrieNode *root);

int main() {
    // load dictionary into trie
    FILE *dictionary = fopen("dictionary.txt", "r"); // dictionary.txt contains one word per line
    if (dictionary == NULL) {
        printf("Error: Could not open dictionary.txt");
        return 1;
    }
    char word[MAX_WORD_LENGTH];
    TrieNode *root = (TrieNode *) malloc(sizeof(TrieNode));
    if (root == NULL) {
        printf("Error: Could not allocate memory");
        return 1;
    }
    root->isEnd = 0;
    for (int i = 0; i < 26; i++) {
        root->children[i] = NULL;
    }
    while (fscanf(dictionary, "%s", word) != EOF) {
        insert(root, word);
    }
    fclose(dictionary);

    // prompt user for text to spell-check
    printf("Enter text to spell-check:\n");
    char text[MAX_WORD_LENGTH * 1000]; // assume text is at most 1000 words, each with length <= MAX_WORD_LENGTH
    fgets(text, MAX_WORD_LENGTH * 1000, stdin);

    // tokenize text into words and check spelling
    char *token = strtok(text, " \n\t\r");
    while (token != NULL) {
        for (int i = 0; i < strlen(token); i++) {
            if (!isalpha(token[i])) {
                printf("Error: %s contains non-letter characters", token);
                freeTrie(root);
                return 1;
            }
            token[i] = tolower(token[i]);
        }
        if (!search(root, token)) {
            printf("Warning: %s is misspelled\n", token);
        }
        token = strtok(NULL, " \n\t\r");
    }

    // free allocated memory and exit
    freeTrie(root);
    return 0;
}

// inserts a word into the trie
void insert(TrieNode *root, char *word) {
    TrieNode *curr = root;
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (curr->children[index] == NULL) {
            curr->children[index] = (TrieNode *) malloc(sizeof(TrieNode));
            curr->children[index]->isEnd = 0;
            for (int j = 0; j < 26; j++) {
                curr->children[index]->children[j] = NULL;
            }
        }
        curr = curr->children[index];
    }
    curr->isEnd = 1; // mark end of word
}

// searches for a word in the trie
int search(TrieNode *root, char *word) {
    TrieNode *curr = root;
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (curr->children[index] == NULL) {
            return 0; // word not found
        }
        curr = curr->children[index];
    }
    return curr->isEnd; // word found if curr->isEnd == 1
}

// frees all memory allocated for the trie
void freeTrie(TrieNode *root) {
    if (root == NULL) {
        return;
    }
    for (int i = 0; i < 26; i++) {
        freeTrie(root->children[i]);
    }
    free(root);
}