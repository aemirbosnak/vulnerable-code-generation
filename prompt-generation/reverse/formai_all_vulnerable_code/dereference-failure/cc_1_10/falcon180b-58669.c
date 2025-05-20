//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordPair;

int main() {
    FILE *inputFile, *outputFile;
    char line[MAX_WORD_LENGTH];
    WordPair words[MAX_WORDS];
    int numWords = 0;
    int i;

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

    while (fgets(line, MAX_WORD_LENGTH, inputFile)!= NULL) {
        if (numWords >= MAX_WORDS) {
            printf("Error: too many words.\n");
            exit(1);
        }
        strcpy(words[numWords].word, line);
        printf("Enter the translation for %s: ", line);
        fgets(words[numWords].translation, MAX_WORD_LENGTH, stdin);
        numWords++;
    }

    for (i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s %s\n", words[i].word, words[i].translation);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}