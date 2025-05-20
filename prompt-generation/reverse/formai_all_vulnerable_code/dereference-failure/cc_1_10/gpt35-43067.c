//FormAI DATASET v1.0 Category: Spell checking ; Style: single-threaded
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_WORD_LENGTH 100 // Maximum word length that program can detect

// Trie node for storing words
struct TrieNode {
    struct TrieNode* children[26];
    bool isEndOfWord;
};

// Creates a new trie node and returns its pointer
struct TrieNode* createNode() {
    struct TrieNode* newNode = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    newNode->isEndOfWord = false;
    for(int i = 0; i < 26; i++)
        newNode->children[i] = NULL;
    return newNode;
}

// Insert the word into the Trie
void insertWord(struct TrieNode* root, char* word) {
    int length = strlen(word);
    struct TrieNode* currentNode = root;

    for(int i = 0; i < length; i++) {
        int index = word[i] - 'a';
        if(currentNode->children[index] == NULL)
            currentNode->children[index] = createNode();
        currentNode = currentNode->children[index];
    }

    currentNode->isEndOfWord = true;
}

// Checks whether the word is present in the Trie
bool searchWord(struct TrieNode* root, char* word) {
    int length = strlen(word);
    struct TrieNode* currentNode = root;

    for(int i = 0; i < length; i++) {
        int index = word[i] - 'a';
        if(currentNode->children[index] == NULL)
            return false;
        currentNode = currentNode->children[index];
    }

    return (currentNode != NULL && currentNode->isEndOfWord);
}

// Spell check function that uses Trie data structure
void spellCheck(char* sentence, struct TrieNode* root) {
    char* word = strtok(sentence, " ");
    int lineNumber = 1;

    while(word) {
        if(strlen(word) > MAX_WORD_LENGTH) {
            printf("Line %d: %s is not a valid word.\n", lineNumber, word);
        }
        else if(!searchWord(root, word)) {
            printf("Line %d: Did you mean?", lineNumber);
            for(int i = 0; i < strlen(word); i++) {
                char originalChar = word[i]; // Store the original character

                // Iterate through all possible permutations of a character
                for(int j = 0; j < 26; j++) {
                    word[i] = 'a' + j; // Change the character
                    if(searchWord(root, word)) {
                        printf(" %s", word);
                    }
                }

                word[i] = originalChar; // Revert back the original character
            }
            printf("\n");
        }

        word = strtok(NULL, " ");
        lineNumber++;
    }
}

int main() {
    // Initialize the dictionary
    struct TrieNode* root = createNode();
    insertWord(root, "the");
    insertWord(root, "quick");
    insertWord(root, "brown");
    insertWord(root, "fox");
    insertWord(root, "jumps");
    insertWord(root, "over");
    insertWord(root, "lazy");
    insertWord(root, "dog");

    // Get the input sentence from user
    char sentence[1000];
    printf("Enter the sentence to spell check:\n");
    fgets(sentence, 1000, stdin);

    // Spell check the input sentence
    printf("\n");
    spellCheck(sentence, root);

    return 0;
}