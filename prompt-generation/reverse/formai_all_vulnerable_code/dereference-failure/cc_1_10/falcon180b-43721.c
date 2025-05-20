//Falcon-180B DATASET v1.0 Category: File handling ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_WORDS 1000

typedef struct {
    char *word;
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    const WordCount *wordA = a;
    const WordCount *wordB = b;
    return strcmp(wordA->word, wordB->word);
}

void printWordCounts(WordCount *wordCounts, int numWords) {
    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    FILE *inputFile = NULL;
    WordCount wordCounts[MAX_NUM_WORDS] = { 0 };
    int numWords = 0;
    char *token;

    // Open input file
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    // Read input file line by line
    while (fgets(line, MAX_LINE_LENGTH, inputFile)!= NULL) {
        numWords = 0;
        token = strtok(line, " ");
        while (token!= NULL) {
            if (numWords >= MAX_NUM_WORDS) {
                printf("Error: Maximum number of words exceeded.\n");
                return 1;
            }
            int wordLength = strlen(token);
            if (wordLength > 0 && isalpha(token[0])) {
                wordCounts[numWords].word = malloc(wordLength + 1);
                if (wordCounts[numWords].word == NULL) {
                    printf("Error: Could not allocate memory.\n");
                    return 1;
                }
                strcpy(wordCounts[numWords].word, token);
                wordCounts[numWords].count = 1;
                numWords++;
            }
            token = strtok(NULL, " ");
        }
    }

    // Close input file
    fclose(inputFile);

    // Print word counts
    printWordCounts(wordCounts, numWords);

    return 0;
}