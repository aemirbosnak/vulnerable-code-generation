//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50
#define WORD_COUNT 4

typedef struct {
    char *word;
} Word;

void initializeWords(Word *words) {
    for(int i = 0; i < WORD_COUNT; i++) {
        words[i].word = (char *)malloc(MAX_LENGTH * sizeof(char));
        if (words[i].word == NULL) {
            fprintf(stderr, "Memory allocation failed for word %d\n", i);
            exit(EXIT_FAILURE);
        }
    }
}

void assignWords(Word *words) {
    const char *sampleWords[WORD_COUNT] = {"Cryptic", "Memory", "Management", "Example"};
    for(int i = 0; i < WORD_COUNT; i++) {
        strncpy(words[i].word, sampleWords[i], MAX_LENGTH);
        words[i].word[MAX_LENGTH - 1] = '\0'; // Ensure null-termination
    }
}

void printWords(Word *words) {
    printf("Words are:\n");
    for(int i = 0; i < WORD_COUNT; i++) {
        printf("%s\n", words[i].word);
    }
}

void freeWords(Word *words) {
    for(int i = 0; i < WORD_COUNT; i++) {
        free(words[i].word);
        words[i].word = NULL; // Prevent dangling pointer
    }
}

int main() {
    Word words[WORD_COUNT];
    
    initializeWords(words);
    assignWords(words);
    printWords(words);
    
    // Re-assigning to demonstrate memory management
    printf("\nRe-assigning words...\n");
    const char *newWords[WORD_COUNT] = {"Dynamic", "Allocation", "In", "C"};
    
    for(int i = 0; i < WORD_COUNT; i++) {
        strncpy(words[i].word, newWords[i], MAX_LENGTH);
        words[i].word[MAX_LENGTH - 1] = '\0'; // Ensure null-termination
    }
    printWords(words);
    
    // Free allocated memory
    freeWords(words);
    return EXIT_SUCCESS;
}