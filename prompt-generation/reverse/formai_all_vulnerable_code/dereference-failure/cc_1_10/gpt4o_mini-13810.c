//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INITIAL_SIZE 64 // Initial size of the word list
#define MAX_WORD_LENGTH 100 // Max length of a word
#define DATABASE_TIMEOUT 300 // Timeout in seconds

typedef struct {
    char **words;
    int *count;
    int size;
    int capacity;
} WordCounter;

void initializeWordCounter(WordCounter *wc) {
    wc->size = 0;
    wc->capacity = INITIAL_SIZE;
    wc->words = (char **)malloc(sizeof(char *) * wc->capacity);
    wc->count = (int *)malloc(sizeof(int) * wc->capacity);
}

void freeWordCounter(WordCounter *wc) {
    for (int i = 0; i < wc->size; ++i) {
        free(wc->words[i]);
    }
    free(wc->words);
    free(wc->count);
}

void addWord(WordCounter *wc, const char *word) {
    for (int i = 0; i < wc->size; ++i) {
        if (strcmp(wc->words[i], word) == 0) {
            wc->count[i]++;
            return;
        }
    }
    
    if (wc->size == wc->capacity) {
        wc->capacity *= 2;
        wc->words = (char **)realloc(wc->words, sizeof(char *) * wc->capacity);
        wc->count = (int *)realloc(wc->count, sizeof(int) * wc->capacity);
    }
    
    wc->words[wc->size] = (char *)malloc(strlen(word) + 1);
    strcpy(wc->words[wc->size], word);
    wc->count[wc->size] = 1;
    wc->size++;
}

void printWordCount(const WordCounter *wc) {
    printf("---- Word Frequency Database ----\n");
    for (int i = 0; i < wc->size; ++i) {
        printf("%s: %d\n", wc->words[i], wc->count[i]);
    }
    printf("---------------------------------\n");
}

void processTextFile(const char *filename, WordCounter *wc) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return;
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%99s", word) == 1) {
        // Normalize word by converting to lower case and stripping punctuation
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
            if (ispunct(word[i])) {
                word[i] = '\0';
            }
        }
        addWord(wc, word);
    }
    fclose(file);
}

void commandLineInterface() {
    printf("Welcome to the Galactic Word Frequency Analyzer!\n");
    printf("Type 'exit' to terminate the program.\n");
    
    WordCounter wc;
    initializeWordCounter(&wc);
    
    char input[200];
    while (1) {
        printf("Enter the name of the text file to analyze (or 'exit'): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // Strip newline
        
        if (strcmp(input, "exit") == 0) {
            break;
        }
        
        processTextFile(input, &wc);
        printWordCount(&wc);
    }
    
    freeWordCounter(&wc);
    printf("Thanks for using the Galactic Word Frequency Analyzer!\n");
}

int main() {
    commandLineInterface();
    return 0;
}