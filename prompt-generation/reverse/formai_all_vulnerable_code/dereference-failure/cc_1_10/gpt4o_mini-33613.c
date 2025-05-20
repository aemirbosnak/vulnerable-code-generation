//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char *word;
    int count;
} WordCount;

WordCount wordList[MAX_WORDS];
int wordCount = 0;

void addWord(const char *word) {
    for (int i = 0; i < wordCount; i++) {
        if (strcmp(wordList[i].word, word) == 0) {
            wordList[i].count++;
            return;
        }
    }

    if (wordCount < MAX_WORDS) {
        wordList[wordCount].word = malloc(strlen(word) + 1);
        if (wordList[wordCount].word == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
        strcpy(wordList[wordCount].word, word);
        wordList[wordCount].count = 1;
        wordCount++;
    } else {
        fprintf(stderr, "Word limit exceeded!\n");
    }
}

void processFile(FILE *file) {
    char word[MAX_WORD_LENGTH];
    int index = 0;
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        if (isalpha(ch) || ch == '\'') {
            // Collecting a word
            word[index++] = ch;
        } else if (index > 0) {
            // End of a word
            word[index] = '\0';
            addWord(word);
            index = 0; // Resetting for the next word
        }
    }

    // Check if last word is captured
    if (index > 0) {
        word[index] = '\0';
        addWord(word);
    }
}

void sortWords() {
    for (int i = 0; i < wordCount - 1; i++) {
        for (int j = i + 1; j < wordCount; j++) {
            if (wordList[i].count < wordList[j].count) {
                // Swap words
                WordCount temp = wordList[i];
                wordList[i] = wordList[j];
                wordList[j] = temp;
            }
        }
    }
}

void printWordCounts() {
    printf("Word Frequency Count:\n");
    printf("----------------------\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s : %d\n", wordList[i].word, wordList[i].count);
    }
}

void freeMemory() {
    for (int i = 0; i < wordCount; i++) {
        free(wordList[i].word);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    processFile(file);
    fclose(file);

    sortWords();
    printWordCounts();
    freeMemory();

    return EXIT_SUCCESS;
}