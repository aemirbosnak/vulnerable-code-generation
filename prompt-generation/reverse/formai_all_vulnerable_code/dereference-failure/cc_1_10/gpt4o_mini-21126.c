//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define INITIAL_WORD_CAPACITY 10

typedef struct {
    char **words;
    int *counts;
    int size;
    int capacity;
} WordFrequency;

void initWordFrequency(WordFrequency *wf) {
    wf->size = 0;
    wf->capacity = INITIAL_WORD_CAPACITY;
    wf->words = malloc(wf->capacity * sizeof(char *));
    wf->counts = malloc(wf->capacity * sizeof(int));
    if (!wf->words || !wf->counts) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
}

void freeWordFrequency(WordFrequency *wf) {
    for (int i = 0; i < wf->size; i++) {
        free(wf->words[i]);
    }
    free(wf->words);
    free(wf->counts);
}

void addWord(WordFrequency *wf, const char *word) {
    for (int i = 0; i < wf->size; i++) {
        if (strcmp(wf->words[i], word) == 0) {
            wf->counts[i]++;
            return;
        }
    }

    if (wf->size >= wf->capacity) {
        wf->capacity *= 2;
        wf->words = realloc(wf->words, wf->capacity * sizeof(char *));
        wf->counts = realloc(wf->counts, wf->capacity * sizeof(int));
        if (!wf->words || !wf->counts) {
            perror("Failed to allocate memory");
            exit(EXIT_FAILURE);
        }
    }

    wf->words[wf->size] = strdup(word);
    wf->counts[wf->size] = 1;
    wf->size++;
}

void processLine(char *line, WordFrequency *wf) {
    char *token = strtok(line, " \t\n");
    while (token != NULL) {
        // To store the word in lowercase
        char lowerWord[MAX_LINE_LENGTH];
        for (int i = 0; token[i]; i++) {
            lowerWord[i] = tolower(token[i]);
        }
        lowerWord[strlen(token)] = '\0'; // Null terminate
        
        addWord(wf, lowerWord);
        token = strtok(NULL, " \t\n");
    }
}

void printWordFrequency(const WordFrequency *wf) {
    printf("\nWord Frequency:\n");
    for (int i = 0; i < wf->size; i++) {
        printf("%s: %d\n", wf->words[i], wf->counts[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Could not open file");
        return EXIT_FAILURE;
    }
    
    WordFrequency wf;
    initWordFrequency(&wf);
    
    char line[MAX_LINE_LENGTH];
    int lineCount = 0;
    int charCount = 0;
    
    while (fgets(line, sizeof(line), file)) {
        lineCount++;
        charCount += strlen(line);
        processLine(line, &wf);
    }
    
    fclose(file);
    
    printf("Lines: %d\n", lineCount);
    printf("Characters: %d\n", charCount);
    printWordFrequency(&wf);

    freeWordFrequency(&wf);
    return EXIT_SUCCESS;
}