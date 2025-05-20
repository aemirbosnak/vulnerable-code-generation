//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 512
#define INITIAL_WORD_COUNT 10

typedef struct {
    char **words;
    int count;
    int capacity;
} WordArray;

void initializeWordArray(WordArray *wa) {
    wa->count = 0;
    wa->capacity = INITIAL_WORD_COUNT;
    wa->words = (char **)malloc(wa->capacity * sizeof(char *));
    if(wa->words == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
}

void freeWordArray(WordArray *wa) {
    for (int i = 0; i < wa->count; i++) {
        free(wa->words[i]);
    }
    free(wa->words);
}

void addWord(WordArray *wa, const char *word) {
    if (wa->count >= wa->capacity) {
        wa->capacity *= 2;
        wa->words = (char **)realloc(wa->words, wa->capacity * sizeof(char *));
        if(wa->words == NULL) {
            fprintf(stderr, "Memory reallocation failed.\n");
            exit(EXIT_FAILURE);
        }
    }
    wa->words[wa->count] = strdup(word);
    if(wa->words[wa->count] == NULL) {
        fprintf(stderr, "Memory allocation for word failed.\n");
        exit(EXIT_FAILURE);
    }
    wa->count++;
}

int isWordCharacter(char c) {
    return isalpha(c) || c == '\'' || c == '-';
}

void processLine(char *line, WordArray *wa) {
    char word[MAX_WORD_LENGTH];
    int index = 0;

    for (int i = 0; i <= strlen(line); i++) {
        if (isWordCharacter(line[i])) {
            word[index++] = line[i];
        } else {
            if (index > 0) {
                word[index] = '\0';
                addWord(wa, word);
                index = 0;
            }
        }
    }
}

void displayWordCount(WordArray *wa) {
    printf("Unique words count: %d\n", wa->count);
    printf("Words:\n");
    for (int i = 0; i < wa->count; i++) {
        printf("%s\n", wa->words[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s.\n", argv[1]);
        return EXIT_FAILURE;
    }

    WordArray wa;
    initializeWordArray(&wa);

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        processLine(line, &wa);
    }

    fclose(file);
    displayWordCount(&wa);
    freeWordArray(&wa);

    return EXIT_SUCCESS;
}