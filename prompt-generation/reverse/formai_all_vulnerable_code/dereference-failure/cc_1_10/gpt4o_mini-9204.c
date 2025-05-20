//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100
#define HASH_TABLE_SIZE 2003 // A prime number for better distribution

typedef struct WordCount {
    char word[MAX_WORD_LENGTH];
    int count;
    struct WordCount *next; // To handle collisions with chaining
} WordCount;

WordCount *hashTable[HASH_TABLE_SIZE];

// Function to create a new WordCount node
WordCount *createNode(const char *word) {
    WordCount *newNode = (WordCount *)malloc(sizeof(WordCount));
    if (newNode == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->word, word);
    newNode->count = 1;
    newNode->next = NULL;
    return newNode;
}

// Hash function for the words
unsigned int hash(const char *word) {
    unsigned int hashValue = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        hashValue = (hashValue * 31 + word[i]) % HASH_TABLE_SIZE;
    }
    return hashValue;
}

// Function to insert or update the word count in the hash table
void insert(const char *word) {
    unsigned int index = hash(word);
    WordCount *current = hashTable[index];

    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            current->count++;
            return;
        }
        current = current->next;
    }

    // If word was not found, create a new node
    WordCount *newNode = createNode(word);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// Function to free the hash table memory
void freeHashTable() {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        WordCount *current = hashTable[i];
        while (current != NULL) {
            WordCount *toDelete = current;
            current = current->next;
            free(toDelete);
        }
    }
}

// Function to print the word counts in descending order
int compare(const void *a, const void *b) {
    return (*(WordCount **)b)->count - (*(WordCount **)a)->count;
}

void printWordCounts() {
    WordCount *wordList[MAX_WORDS];
    int count = 0;

    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        WordCount *current = hashTable[i];
        while (current != NULL) {
            if (count < MAX_WORDS) {
                wordList[count++] = current;
            }
            current = current->next;
        }
    }

    qsort(wordList, count, sizeof(WordCount *), compare);

    printf("\nWord Frequency Count:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", wordList[i]->word, wordList[i]->count);
    }
}

// Function to read the file and count words
void countWordsInFile(const char *fileName) {
    FILE *file = fopen(fileName, "r");
    
    if (file == NULL) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        // Normalize the word to lowercase
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }
        // Insert the word into the hash table
        insert(word);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    countWordsInFile(argv[1]);
    printWordCounts();
    freeHashTable();

    return EXIT_SUCCESS;
}