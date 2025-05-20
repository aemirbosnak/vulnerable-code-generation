//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH+1];
    int frequency;
} WordFrequency;

WordFrequency words[MAX_WORDS];
int numWords = 0;

char *readWord(FILE *file) {
    char word[MAX_WORD_LENGTH+1];
    char c;
    int i = 0;
    while ((c = fgetc(file))!= EOF && isalnum(c)) {
        if (i >= MAX_WORD_LENGTH) {
            printf("Error: Word is too long\n");
            exit(1);
        }
        word[i++] = tolower(c);
    }
    word[i] = '\0';
    return strdup(word);
}

void countWord(char *word) {
    int i;
    for (i = 0; i < numWords; i++) {
        if (strcmp(words[i].word, word) == 0) {
            words[i].frequency++;
            return;
        }
    }
    if (numWords >= MAX_WORDS) {
        printf("Error: Too many words\n");
        exit(1);
    }
    strcpy(words[numWords].word, word);
    words[numWords].frequency = 1;
    numWords++;
}

void printFrequencies(FILE *file) {
    int i;
    for (i = 0; i < numWords; i++) {
        fprintf(file, "%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }
    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file\n");
        return 1;
    }
    FILE *outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output file\n");
        fclose(inputFile);
        return 1;
    }
    char *word;
    while ((word = readWord(inputFile))!= NULL) {
        countWord(word);
    }
    printFrequencies(outputFile);
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}