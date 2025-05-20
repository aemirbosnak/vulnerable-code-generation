//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

// A node in the trie
typedef struct TrieNode {
    struct TrieNode* children[26];
    int isEndOfWord;
} TrieNode;

// Function to create a new Trie node
TrieNode* createNode() {
    TrieNode* newNode = (TrieNode*)malloc(sizeof(TrieNode));
    newNode->isEndOfWord = 0;
    for (int i = 0; i < 26; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

// A trie to store the dictionary words
TrieNode* root;

// Function to convert a character to an index
int charToIndex(char ch) {
    return tolower(ch) - 'a';
}

// Function to insert a word into the trie
void insert(TrieNode* root, const char* word) {
    TrieNode* pCrawl = root;
    for (int level = 0; word[level]; level++) {
        int index = charToIndex(word[level]);
        if (!pCrawl->children[index]) {
            pCrawl->children[index] = createNode();
        }
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = 1;
}

// Function to search for a word in the trie
int search(TrieNode* root, const char* word) {
    TrieNode* pCrawl = root;
    for (int level = 0; word[level]; level++) {
        int index = charToIndex(word[level]);
        if (!pCrawl->children[index]) {
            return 0;  // Word not found
        }
        pCrawl = pCrawl->children[index];
    }
    return (pCrawl != NULL && pCrawl->isEndOfWord);
}

// Function to load a dictionary into the trie
void loadDictionary(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open dictionary file");
        exit(EXIT_FAILURE);
    }
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%49s", word) != EOF) {
        insert(root, word);
    }
    fclose(file);
}

// Function to check spelling of words in a sentence
void checkSpelling(const char* sentence) {
    char word[MAX_WORD_LENGTH];
    int index = 0;
    for (int i = 0; sentence[i] != '\0'; i++) {
        if (isalpha(sentence[i])) {
            word[index++] = sentence[i];
        } else {
            if (index > 0) {  // Word boundary
                word[index] = '\0';  // Null-terminate the word
                if (!search(root, word)) {
                    printf("Misspelled word: %s\n", word);
                }
                index = 0;  // Reset index for the next word
            }
        }
    }
    // Check last word if any
    if (index > 0) {
        word[index] = '\0';
        if (!search(root, word)) {
            printf("Misspelled word: %s\n", word);
        }
    }
}

int main() {
    root = createNode();
    loadDictionary("dictionary.txt");  // Replace with your dictionary file path
    printf("Spell Checker\n");
    printf("Enter a sentence (type 'exit' to quit):\n");

    char sentence[256];
    while (1) {
        printf("> ");
        fgets(sentence, sizeof(sentence), stdin);
        sentence[strcspn(sentence, "\n")] = 0;  // Remove trailing newline

        if (strcmp(sentence, "exit") == 0) {
            break;
        }

        checkSpelling(sentence);
    }

    return 0;
}