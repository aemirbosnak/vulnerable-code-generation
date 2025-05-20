//FormAI DATASET v1.0 Category: Spell checking ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define HASH_TABLE_SIZE 1000

typedef struct Node {
    char *word;
    struct Node *next;
} Node;

Node *hashTable[HASH_TABLE_SIZE];

// Hash function
unsigned int hash(char *word){
    unsigned int hash = 0;
    for (int i = 0; i < strlen(word); i++) {
        hash = hash * 31 + tolower(word[i]);
    }
    return hash % HASH_TABLE_SIZE;
}

// Add a word to the hash table
void addWord(char *word) {
    unsigned int hashValue = hash(word);
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->word = (char*) malloc(strlen(word) + 1);
    strcpy(newNode->word, word);
    newNode->next = NULL;

    if (hashTable[hashValue] == NULL) {
        hashTable[hashValue] = newNode;
    } else {
        Node *ptr = hashTable[hashValue];
        while (ptr->next != NULL) {
            ptr = ptr->next;    
        }
        ptr->next = newNode;
    }
}

// Check if a word is correctly spelled
int checkWord(char *word) {
    unsigned int hashValue = hash(word);

    if (hashTable[hashValue] != NULL) {
        Node *ptr = hashTable[hashValue];
        while (ptr != NULL) {
            if (strcmp(ptr->word, word) == 0) {
                return 1;
            }
            ptr = ptr->next;
        }
    }

    return 0;
}

int main() {
    // Add some words to the hash table
    addWord("apple");
    addWord("banana");
    addWord("cherry");
    addWord("date");
    addWord("elderberry");

    // Get input from user
    char input[1000];
    printf("Enter a sentence: ");
    fgets(input, 1000, stdin);

    // Check each word for spelling errors
    char *word = strtok(input, " \n");
    while (word != NULL) {
        if (!checkWord(word)) {
            printf("Spelling error: %s\n", word);
        }
        word = strtok(NULL, " \n");
    }

    return 0;
}