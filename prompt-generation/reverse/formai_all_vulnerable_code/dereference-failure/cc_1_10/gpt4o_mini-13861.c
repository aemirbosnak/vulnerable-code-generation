//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256
#define MAX_WORDS 1000

typedef struct {
    char **words;
    int count;
} WordList;

void initializeWordList(WordList *wl) {
    wl->words = malloc(MAX_WORDS * sizeof(char *));
    for (int i = 0; i < MAX_WORDS; i++) {
        wl->words[i] = malloc(MAX_LINE_LENGTH * sizeof(char));
    }
    wl->count = 0;
}

void freeWordList(WordList *wl) {
    for (int i = 0; i < wl->count; i++) {
        free(wl->words[i]);
    }
    free(wl->words);
}

void processLine(const char *line, WordList *wl) {
    char *token;
    char *lineCopy = strdup(line); // Create a modifiable copy of the line
    token = strtok(lineCopy, " \n");
    
    while (token != NULL && wl->count < MAX_WORDS) {
        strcpy(wl->words[wl->count++], token);
        token = strtok(NULL, " \n");
    }
    free(lineCopy);
}

void printWordList(const WordList *wl) {
    printf("Found %d words:\n", wl->count);
    for (int i = 0; i < wl->count; i++) {
        printf("%s\n", wl->words[i]);
    }
}

void convertToUppercase(WordList *wl) {
    for (int i = 0; i < wl->count; i++) {
        for (char *p = wl->words[i]; *p; p++) {
            *p = toupper(*p);
        }
    }
}

void saveWordsToFile(const WordList *wl, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file) {
        for (int i = 0; i < wl->count; i++) {
            fprintf(file, "%s\n", wl->words[i]);
        }
        fclose(file);
        printf("Words saved to %s\n", filename);
    } else {
        fprintf(stderr, "Error opening file for writing: %s\n", filename);
    }
}

void readFromFile(const char *filename, WordList *wl) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file for reading: %s\n", filename);
        return;
    }
    
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file) && wl->count < MAX_WORDS) {
        processLine(line, wl);
    }
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
        return 1;
    }

    WordList wl;
    initializeWordList(&wl);
    
    readFromFile(argv[1], &wl);
    printWordList(&wl);
  
    printf("\nConverting words to uppercase...\n");
    convertToUppercase(&wl);
    printWordList(&wl);
    
    saveWordsToFile(&wl, "output.txt");
    
    freeWordList(&wl);
    return 0;
}