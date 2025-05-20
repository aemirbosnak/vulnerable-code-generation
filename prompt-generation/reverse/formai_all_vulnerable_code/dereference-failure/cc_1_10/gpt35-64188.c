//FormAI DATASET v1.0 Category: Spell checking ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//suggested struct to hold dictionary words
typedef struct node {
    char *word;
    struct node *next;
} node;

//function prototypes
node* buildDictionary();
int checkWord(char *word, node *hashTable[]);
void addWord(char *word, node *hashTable[]);
void freeMemory(node *hashTable[]);

int main() {

    //initialize hash table with dictionary words
    node *hashTable[26];
    for (int i = 0; i < 26; i++) {
        hashTable[i] = buildDictionary();
    }

    char input[100];
    printf("Enter text to spell check: ");
    fgets(input, 100, stdin);

    //go through each word in input and check if it's spelled correctly
    char *token = strtok(input, " ,.!?\n");
    while(token != NULL) {
        //convert word to lowercase for easier comparison
        for (int i = 0; i < strlen(token); i++) {
            token[i] = tolower(token[i]);
        }
        //check if word is in hash table
        if (checkWord(token, hashTable)) {
            printf("%s ", token);
        } else {
            printf("*%s* ", token);
        }
        token = strtok(NULL, " ,.!?\n");
    }

    //free memory allocated for hash table and dictionary words
    freeMemory(hashTable);

    return 0;
}

//function to build dictionary hash table from text file
node* buildDictionary() {
    node *hashTable = NULL;
    char buffer[100];
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error opening dictionary file.\n");
        exit(1);
    }
    //read in each dictionary word and add to hash table
    while (fgets(buffer, 100, fp) != NULL) {
        //strip new line character
        strtok(buffer, "\n");
        //add new word to hash table
        addWord(buffer, &hashTable);
    }
    fclose(fp);
    return hashTable;
}

//function to check if word is in dictionary hash table
int checkWord(char *word, node *hashTable[]) {
    int index = word[0] - 'a';
    node *current = hashTable[index];
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

//function to add new word to dictionary hash table
void addWord(char *word, node *hashTable[]) {
    int index = word[0] - 'a';
    node *newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation error.\n");
        exit(1);
    }
    newNode->word = (char*)malloc(sizeof(char) * strlen(word) + 1);
    if (newNode->word == NULL) {
        printf("Memory allocation error.\n");
        exit(1);
    }
    strcpy(newNode->word, word);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

//function to free memory allocated for hash table and dictionary words
void freeMemory(node *hashTable[]) {
    node *current;
    for (int i = 0; i < 26; i++) {
        current = hashTable[i];
        while (current != NULL) {
            node *temp = current;
            current = current->next;
            free(temp->word);
            free(temp);
        }
    }
}