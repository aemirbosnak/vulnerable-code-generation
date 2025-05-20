//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 256
#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char **words;
    int count;
} WordList;

void initWordList(WordList *wl) {
    wl->words = malloc(MAX_WORDS * sizeof(char *));
    for (int i = 0; i < MAX_WORDS; i++) {
        wl->words[i] = malloc(MAX_WORD_LENGTH * sizeof(char));
    }
    wl->count = 0;
}

void freeWordList(WordList *wl) {
    for (int i = 0; i < wl->count; i++) {
        free(wl->words[i]);
    }
    free(wl->words);
}

void addWord(WordList *wl, const char *word) {
    if (wl->count < MAX_WORDS) {
        strncpy(wl->words[wl->count], word, MAX_WORD_LENGTH);
        wl->words[wl->count][MAX_WORD_LENGTH - 1] = '\0'; // Ensure null termination
        wl->count++;
    } else {
        fprintf(stderr, "Warning: Maximum word limit reached. '%s' not added.\n", word);
    }
}

int isWordUnique(WordList *wl, const char *word) {
    for (int i = 0; i < wl->count; i++) {
        if (strcmp(wl->words[i], word) == 0) {
            return 0; // Word is not unique
        }
    }
    return 1; // Word is unique
}

void countWordsInFile(const char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", fileName);
        return;
    }

    WordList wl;
    initWordList(&wl);

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) == 1) {
        if (isWordUnique(&wl, word)) {
            addWord(&wl, word);
        }
    }

    fclose(file);

    printf("Unique words in file '%s': %d\n", fileName, wl.count);
    printf("Words:\n");

    for (int i = 0; i < wl.count; i++) {
        printf("%s\n", wl.words[i]);
    }

    freeWordList(&wl);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1> [<file2> ... <fileN>]\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        const char *fileName = argv[i];
        countWordsInFile(fileName);
    }

    return 0;
}