//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

typedef struct {
    char *word;
    int count;
} WordCount;

typedef struct {
    WordCount *words;
    int size;
} WordList;

void initWordList(WordList *list) {
    list->words = malloc(MAX_WORDS * sizeof(WordCount));
    if (!list->words) {
        fprintf(stderr, "Failed to allocate memory for words.\n");
        exit(1);
    }
    list->size = 0;
}

void freeWordList(WordList *list) {
    for (int i = 0; i < list->size; i++) {
        free(list->words[i].word);
    }
    free(list->words);
}

void addWord(WordList *list, const char *word) {
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->words[i].word, word) == 0) {
            list->words[i].count++;
            return;
        }
    }
    
    if (list->size < MAX_WORDS) {
        list->words[list->size].word = strdup(word);
        list->words[list->size].count = 1;
        list->size++;
    } else {
        fprintf(stderr, "Word list maximum capacity reached.\n");
    }
}

void processTextFile(const char *filename, WordList *wordList) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Unable to open file: %s\n", filename);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, " \n\t\r\f");
        while (token) {
            addWord(wordList, token);
            token = strtok(NULL, " \n\t\r\f");
        }
    }

    fclose(file);
}

void printWordList(const WordList *list) {
    printf("\nSurvivor Text Analysis Report:\n");
    printf("---------------------------------\n");
    for (int i = 0; i < list->size; i++) {
        printf("Word: '%s' | Count: %d\n", list->words[i].word, list->words[i].count);
    }
    printf("---------------------------------\n");
}

void writeWordListToFile(const WordList *list, const char *outputFileName) {
    FILE *outputFile = fopen(outputFileName, "w");
    if (!outputFile) {
        fprintf(stderr, "Unable to open output file: %s\n", outputFileName);
        exit(1);
    }

    for (int i = 0; i < list->size; i++) {
        fprintf(outputFile, "%s: %d\n", list->words[i].word, list->words[i].count);
    }

    fclose(outputFile);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <inputFileName>\n", argv[0]);
        exit(1);
    }

    WordList wordList;
    initWordList(&wordList);

    processTextFile(argv[1], &wordList);
    printWordList(&wordList);
    writeWordListToFile(&wordList, "word_count_output.txt");

    freeWordList(&wordList);
    printf("Analysis complete. Output written to word_count_output.txt\n");
    
    return 0;
}