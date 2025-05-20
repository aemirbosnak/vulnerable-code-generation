//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define HASH_TABLE_SIZE 1000

typedef struct Node {
    char word[MAX_WORD_LENGTH];
    struct Node* next;
} Node;

Node* hashTable[HASH_TABLE_SIZE];

unsigned int hash(const char* word) {
    unsigned int hashValue = 0;
    while (*word) {
        hashValue = (hashValue << 5) + *word++;
    }
    return hashValue % HASH_TABLE_SIZE;
}

void insertWord(const char* word) {
    unsigned int index = hash(word);
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

int checkWord(const char* word) {
    unsigned int index = hash(word);
    Node* current = hashTable[index];
    while (current) {
        if (strcmp(current->word, word) == 0) {
            return 1; // Found
        }
        current = current->next;
    }
    return 0; // Not found
}

void loadDictionary(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open dictionary file.\n");
        exit(EXIT_FAILURE);
    }
    
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) == 1) {
        insertWord(word);
    }
    
    fclose(file);
}

void freeDictionary() {
    for (int i = 0; i < HASH_TABLE_SIZE; ++i) {
        Node* current = hashTable[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
}

void toLowerCase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void spellCheck(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open text file for checking.\n");
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LENGTH];
    int lineNum = 1;

    while (fscanf(file, "%s", word) == 1) {
        toLowerCase(word);
        if (!checkWord(word)) {
            printf("Misspelled word on line %d: %s\n", lineNum, word);
        }
        if (strchr(word, '\n')) {
            lineNum++;
        }
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    loadDictionary(argv[1]);
    spellCheck(argv[2]);
    freeDictionary();
    
    return EXIT_SUCCESS;
}