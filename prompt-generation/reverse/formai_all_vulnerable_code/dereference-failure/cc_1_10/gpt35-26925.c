//FormAI DATASET v1.0 Category: Spell checking ; Style: lively
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/**
 * This program checks the spelling of a word using a hash table
 */

#define HASH_TABLE_SIZE 50000

typedef struct Node {
    char word[100];
    struct Node* next;
} Node;

Node* hashTable[HASH_TABLE_SIZE];

// calculate the hash value of a string
unsigned long hash(const char* word) {
    unsigned long hashValue = 0;

    for(int i = 0; i < strlen(word); i++) {
        hashValue = hashValue * 31 + word[i];
    }

    return hashValue % HASH_TABLE_SIZE;
}

// add a word to the hash table
void addWord(const char* word) {
    unsigned long hashValue = hash(word);

    Node* node = hashTable[hashValue];

    // check if the hash table already contains the word
    while(node != NULL) {
        if(strcmp(node->word, word) == 0) {
            return;
        }
        node = node->next;
    }

    // add the word to the hash table
    node = (Node*) malloc(sizeof(Node));
    strncpy(node->word, word, strlen(word));
    node->next = hashTable[hashValue];
    hashTable[hashValue] = node;
}

// check if a word is spelled correctly
int checkSpelling(const char* word) {
    unsigned long hashValue = hash(word);

    Node* node = hashTable[hashValue];

    // check if the hash table contains the word
    while(node != NULL) {
        if(strcmp(node->word, word) == 0) {
            return 1;
        }
        node = node->next;
    }

    return 0;
}

int main() {
    // add some words to the hash table
    addWord("apple");
    addWord("banana");
    addWord("cherry");
    addWord("orange");

    // prompt the user for input and check if each word is spelled correctly
    char input[100];
    printf("Enter some text for spell checking (press enter to quit):\n");

    while(fgets(input, 100, stdin) != NULL) {
        char* token = strtok(input, " \n");

        while(token != NULL) {
            // remove any punctuation from the word
            int i = 0;
            while(token[i]) {
                if(ispunct(token[i])) {
                    memmove(&token[i], &token[i + 1], strlen(token) - i);
                } else {
                    i++;
                }
            }

            // convert the word to lowercase
            for(i = 0; i < strlen(token); i++) {
                token[i] = tolower(token[i]);
            }

            // check if the word is spelled correctly
            if(!checkSpelling(token)) {
                printf("*** Error: %s is misspelled.\n", token);
            }

            token = strtok(NULL, " \n");
        }

        printf("\nEnter some text for spell checking (press enter to quit):\n");
    }

    return 0;
}