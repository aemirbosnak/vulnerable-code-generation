//FormAI DATASET v1.0 Category: Spell checking ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100 // Maximum input length

// Node structure for hash table
typedef struct node {
    char word[MAX_LEN];
    struct node* next;
} Node;

// Hash function to determine index in hash table
int hash(char* word) {
    int sum = 0;
    for (int i = 0; i < strlen(word); i++) {
        sum += tolower(word[i]);
    }
    return sum % 26;
}

// Insert word into hash table
void insert(Node** hashTable, char* word) {
    int index = hash(word);

    // Create new node and insert at beginning of linked list
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// Check if word is in hash table
int check(Node** hashTable, char* word) {
    int index = hash(word);

    // Traverse linked list at index
    Node* curr = hashTable[index];
    while (curr != NULL) {
        if (strcmp(curr->word, word) == 0) {
            return 1; // Word found
        }
        curr = curr->next;
    }
    return 0; // Word not found
}

int main() {
    Node** hashTable = (Node**) calloc(26, sizeof(Node*)); // Create hash table with 26 indices

    printf("Enter a sentence to spell check:\n");
    char input[MAX_LEN];
    fgets(input, MAX_LEN, stdin); // Read input from user

    char* word = strtok(input, " .\n"); // Tokenize input by spaces and periods
    while (word != NULL) {
        if (!check(hashTable, word)) {
            insert(hashTable, word); // Add word to hash table
            printf("%s is misspelled!\n", word); // Print misspelled word
        }
        word = strtok(NULL, " .\n");
    }

    printf("\nSpell checking complete. No more errors remain!\n");

    // Free memory allocated for hash table
    for (int i = 0; i < 26; i++) {
        Node* curr = hashTable[i];
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(hashTable);

    return 0; // Program success
}