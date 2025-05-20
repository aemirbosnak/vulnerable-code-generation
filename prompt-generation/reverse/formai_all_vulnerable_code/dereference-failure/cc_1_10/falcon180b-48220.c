//Falcon-180B DATASET v1.0 Category: Text processing ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1000
#define MAX_NUM_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareStrings(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    FILE *inputFile;
    char line[MAX_LINE_LENGTH];
    int numWords = 0;
    WordCount *wordCounts = malloc(MAX_NUM_WORDS * sizeof(WordCount));

    inputFile = fopen("input.txt", "r");

    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, inputFile)!= NULL) {
        char *words[MAX_NUM_WORDS];
        int numWordsInLine = 0;

        // Tokenize the line into words
        char *token = strtok(line, " \t\n\r");
        while (token!= NULL && numWordsInLine < MAX_NUM_WORDS) {
            words[numWordsInLine] = token;
            numWordsInLine++;
            token = strtok(NULL, " \t\n\r");
        }

        // Count the frequency of each word
        for (int i = 0; i < numWordsInLine; i++) {
            WordCount *wordCount = bsearch(words[i], wordCounts, numWords, sizeof(WordCount), compareStrings);

            if (wordCount == NULL) {
                // Word not found, add it to the list
                wordCounts[numWords] = (WordCount){.word = words[i],.count = 1};
                numWords++;
            } else {
                // Word found, increment its count
                wordCount->count++;
            }
        }
    }

    // Sort the word counts by frequency
    qsort(wordCounts, numWords, sizeof(WordCount), compareStrings);

    // Print the word counts
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    free(wordCounts);
    fclose(inputFile);

    return 0;
}