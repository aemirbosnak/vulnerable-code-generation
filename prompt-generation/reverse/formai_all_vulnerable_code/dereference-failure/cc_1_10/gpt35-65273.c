//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

typedef struct {
    char* word;
    int count;
} wordCount;

char* getNextWord(FILE* fp) {
    char* word = (char*) malloc(sizeof(char) * MAX_WORD_LENGTH);
    int index = 0;
    char c;

    while (!isalpha(c = fgetc(fp)) && c != EOF);

    while (isalpha(c)) {
        word[index++] = tolower(c);
        c = fgetc(fp);
    }
    word[index] = '\0';

    return index > 0 ? word : NULL;
}

wordCount* processFile(char* fileName, int* numWords) {
    FILE* fp;
    char* word;
    wordCount* wordCounts = (wordCount*) malloc(sizeof(wordCount) * MAX_WORDS);
    int wordIndex = 0;

    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Could not open file '%s' for reading.\n", fileName);
        exit(1);
    }

    while ((word = getNextWord(fp)) != NULL) {
        // Check if word already exists in wordCounts
        int found = 0;
        for (int i = 0; i < wordIndex; i++) {
            if (strcmp(wordCounts[i].word, word) == 0) {
                wordCounts[i].count++;
                found = 1;
                break;
            }
        }
        // Otherwise, add word to wordCounts
        if (!found) {
            wordCounts[wordIndex].word = word;
            wordCounts[wordIndex].count = 1;
            wordIndex++;
        }
        if (wordIndex >= MAX_WORDS) {
            printf("ERROR: Maximum number of words exceeded.\n");
            exit(1);
        }
    }

    fclose(fp);
    *numWords = wordIndex;
    return wordCounts;
}

void sortWords(wordCount* wordCounts, int numWords) {
    // Bubble sort
    int swapped;
    do {
        swapped = 0;
        for (int i = 1; i < numWords; i++) {
            if (wordCounts[i-1].count < wordCounts[i].count) {
                // Swap words
                wordCount temp = wordCounts[i-1];
                wordCounts[i-1] = wordCounts[i];
                wordCounts[i] = temp;
                swapped = 1;
            }
        }
    } while (swapped);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: word_freq <file>\n");
        exit(1);
    }

    int numWords;
    wordCount* wordCounts = processFile(argv[1], &numWords);

    sortWords(wordCounts, numWords);

    printf("WORD COUNTS:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    // Free memory
    for (int i = 0; i < numWords; i++) {
        free(wordCounts[i].word);
    }
    free(wordCounts);

    return 0;
}