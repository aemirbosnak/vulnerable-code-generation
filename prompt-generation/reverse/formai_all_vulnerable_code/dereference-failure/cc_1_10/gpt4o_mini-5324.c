//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1024

typedef struct {
    char **words;
    int count;
    int capacity;
} WordList;

void initWordList(WordList *wl) {
    wl->count = 0;
    wl->capacity = 10;
    wl->words = malloc(wl->capacity * sizeof(char *));
}

void addWord(WordList *wl, const char *word) {
    if (wl->count >= wl->capacity) {
        wl->capacity *= 2;
        wl->words = realloc(wl->words, wl->capacity * sizeof(char *));
    }
    wl->words[wl->count] = malloc((strlen(word) + 1) * sizeof(char));
    strcpy(wl->words[wl->count], word);
    wl->count++;
}

void freeWordList(WordList *wl) {
    for (int i = 0; i < wl->count; i++) {
        free(wl->words[i]);
    }
    free(wl->words);
}

int isWordChar(char ch) {
    return isalnum(ch) || ch == '\'' || ch == '-';
}

void processLine(const char *line, WordList *wl) {
    char word[MAX_WORD_LENGTH];
    int index = 0;

    for (size_t i = 0; i < strlen(line); i++) {
        if (isWordChar(line[i])) {
            word[index++] = line[i];
        } else {
            if (index > 0) {
                word[index] = '\0';
                addWord(wl, word);
                index = 0;
            }
        }
    }

    if (index > 0) {
        word[index] = '\0';
        addWord(wl, word);
    }
}

void displayWordFrequency(const WordList *wl) {
    printf("Word Count: %d\n", wl->count);
    printf("Words:\n");
    for (int i = 0; i < wl->count; i++) {
        printf("%s\n", wl->words[i]);
    }
}

int compareWords(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

void sortWords(WordList *wl) {
    qsort(wl->words, wl->count, sizeof(char *), compareWords);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Unable to open file");
        return EXIT_FAILURE;
    }

    WordList wordList;
    initWordList(&wordList);

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        processLine(line, &wordList);
    }
    fclose(file);

    sortWords(&wordList);
    displayWordFrequency(&wordList);
    
    freeWordList(&wordList);

    return EXIT_SUCCESS;
}