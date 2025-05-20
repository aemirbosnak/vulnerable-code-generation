//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

typedef struct {
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int count;
} WordList;

void initializeWordList(WordList *list) {
    list->count = 0;
}

void addWord(WordList *list, const char *word) {
    if (list->count < MAX_WORDS) {
        strncpy(list->words[list->count++], word, MAX_WORD_LENGTH - 1);
        list->words[list->count - 1][MAX_WORD_LENGTH - 1] = '\0'; // Ensure null-termination
    } else {
        printf("Warning: Word list is full. Cannot add '%s'\n", word);
    }
}

int compareWords(const void *a, const void *b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

void sortWords(WordList *list) {
    qsort(list->words, list->count, sizeof(list->words[0]), compareWords);
}

void printWordList(const WordList *list) {
    for (int i = 0; i < list->count; i++) {
        printf("%s\n", list->words[i]);
    }
}

void processLine(const char *line, WordList *list) {
    char *tempLine = strdup(line); // Duplicate the line for tokenization
    if (!tempLine) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    char *token = strtok(tempLine, " \t\n");
    while (token != NULL) {
        // Remove punctuation from the token
        char cleanWord[MAX_WORD_LENGTH];
        int j = 0;
        for (int i = 0; token[i] != '\0'; i++) {
            if (isalnum(token[i])) {
                cleanWord[j++] = tolower(token[i]); // Convert to lowercase
            }
        }
        cleanWord[j] = '\0'; // Terminate the cleaned word
        if (j > 0) {
            addWord(list, cleanWord);
        }
        
        token = strtok(NULL, " \t\n");
    }
    
    free(tempLine);
}

void writeUniqueWordsToFile(const WordList *list, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "Could not open file %s for writing.\n", filename);
        return;
    }

    for (int i = 0; i < list->count; i++) {
        fprintf(file, "%s\n", list->words[i]);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *inputFile = fopen(argv[1], "r");
    if (!inputFile) {
        fprintf(stderr, "Could not open file %s for reading.\n", argv[1]);
        return EXIT_FAILURE;
    }

    WordList wordList;
    initializeWordList(&wordList);

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), inputFile)) {
        processLine(line, &wordList);
    }
    
    fclose(inputFile);

    sortWords(&wordList); // Sort the words alphabetically

    writeUniqueWordsToFile(&wordList, argv[2]);

    printf("Unique words have been written to %s\n", argv[2]);

    return EXIT_SUCCESS;
}