//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    FILE *inputFile, *outputFile;
    char line[MAX_WORD_LENGTH];
    WordCount words[MAX_WORDS];
    int numWords = 0;
    int i;

    // Open input and output files
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Read input file and count word frequencies
    while (fgets(line, MAX_WORD_LENGTH, inputFile)!= NULL) {
        char *word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            for (i = 0; i < numWords; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == numWords) {
                if (numWords >= MAX_WORDS) {
                    printf("Error: too many unique words.\n");
                    exit(1);
                }
                strncpy(words[numWords].word, word, MAX_WORD_LENGTH);
                words[numWords].count = 1;
                numWords++;
            }
            word = strtok(NULL, ",.?!;:");
        }
    }

    // Sort words by frequency
    qsort(words, numWords, sizeof(WordCount), compareWords);

    // Write output file
    fprintf(outputFile, "Word\tFrequency\n");
    for (i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s\t%d\n", words[i].word, words[i].count);
    }

    // Close files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}