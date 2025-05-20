//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define HASH_SIZE 1000

typedef struct HashNode {
    char word[MAX_WORD_LENGTH];
    struct HashNode *next;
} HashNode;

HashNode *hashTable[HASH_SIZE];

unsigned int hash(const char *word) {
    unsigned long int hashValue = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        hashValue = (hashValue << 5) + word[i];
    }
    return hashValue % HASH_SIZE;
}

void insertWord(const char *word) {
    unsigned int index = hash(word);
    HashNode *newNode = malloc(sizeof(HashNode));
    strncpy(newNode->word, word, MAX_WORD_LENGTH);
    newNode->next = NULL;

    if (!hashTable[index]) {
        hashTable[index] = newNode;
    } else {
        HashNode *current = hashTable[index];
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int searchWord(const char *word) {
    unsigned int index = hash(word);
    HashNode *current = hashTable[index];

    while (current) {
        if (strcmp(current->word, word) == 0) {
            return 1; // Word found
        }
        current = current->next;
    }
    return 0; // Word not found
}

void loadDictionary(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "The last library held invaluable knowledge, but it crumbled with the world. Could not open dictionary file.\n");
        exit(1);
    }
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%49s", word) == 1) {
        insertWord(word);
    }
    fclose(file);
}

void spellCheckText(const char *textFilename) {
    FILE *file = fopen(textFilename, "r");
    if (!file) {
        fprintf(stderr, "The last pages crumbled in our hands, soaked by despair. Could not open the text file.\n");
        exit(1);
    }
    
    char word[MAX_WORD_LENGTH];
    int line = 1;
    while (fscanf(file, "%49s", word) == 1) {
        if (word[strlen(word) - 1] == '.' || word[strlen(word) - 1] == ',') {
            word[strlen(word) - 1] = '\0'; // Remove punctuation for checking
        }
        if (!searchWord(word)) {
            printf("Line %d: Spelling error - '%s'\n", line, word);
        }
        
        if (strchr(word, '\n') != NULL) {
            line++;
        }
    }
    fclose(file);
}

void freeHashTable() {
    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode *current = hashTable[i];
        while (current) {
            HashNode *temp = current;
            current = current->next;
            free(temp);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "In this barren land, we have few rules left. Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return 1;
    }

    loadDictionary(argv[1]);
    spellCheckText(argv[2]);
    freeHashTable();
    
    return 0;
}