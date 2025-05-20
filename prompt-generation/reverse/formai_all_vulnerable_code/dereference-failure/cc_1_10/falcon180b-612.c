//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORD_COUNT 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readFile(FILE *file, WordCount *wordCounts, int count) {
    char word[MAX_WORD_LENGTH];
    int i;

    while (fscanf(file, "%s", word)!= EOF) {
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        if (strlen(word) > 0 && strlen(word) <= MAX_WORD_LENGTH) {
            int index = 0;
            while (index < count && strcmp(wordCounts[index].word, word)!= 0) {
                index++;
            }
            if (index == count) {
                wordCounts[count].word[0] = '\0';
                strcat(wordCounts[count].word, word);
                wordCounts[count].count = 1;
                count++;
            } else {
                wordCounts[index].count++;
            }
        }
    }
}

void writeFile(FILE *file, WordCount *wordCounts, int count) {
    int i;

    for (i = 0; i < count; i++) {
        fprintf(file, "%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main() {
    FILE *inputFile, *outputFile;
    WordCount wordCounts[MAX_WORD_COUNT];
    int count = 0;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    readFile(inputFile, wordCounts, count);

    writeFile(outputFile, wordCounts, count);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}