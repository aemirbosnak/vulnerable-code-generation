//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define NUM_WORDS 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    FILE *inputFile, *outputFile;
    char line[MAX_WORD_LENGTH];
    WordCount words[NUM_WORDS];
    int numWords = 0;

    // Open input and output files
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    // Read input file and count words
    while (fgets(line, MAX_WORD_LENGTH, inputFile)!= NULL) {
        int wordLength = strlen(line);
        if (wordLength > MAX_WORD_LENGTH) {
            printf("Error: word is too long.\n");
            exit(1);
        }
        strcpy(words[numWords].word, line);
        words[numWords].count = 1;
        numWords++;
    }
    fclose(inputFile);

    // Sort words alphabetically
    for (int i = 0; i < numWords - 1; i++) {
        for (int j = i + 1; j < numWords; j++) {
            if (strcmp(words[i].word, words[j].word) > 0) {
                WordCount temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    // Write output file
    for (int i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s %d\n", words[i].word, words[i].count);
    }
    fclose(outputFile);

    return 0;
}