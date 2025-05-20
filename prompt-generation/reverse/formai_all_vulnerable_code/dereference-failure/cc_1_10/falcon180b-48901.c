//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 100
#define MAX_NUM_WORDS 1000
#define MAX_INDEX_SIZE 1000

typedef struct {
    char word[MAX_WORD_SIZE];
    int index;
} WordIndex;

int main() {
    FILE *inputFile;
    FILE *indexFile;
    char inputLine[MAX_WORD_SIZE];
    char *word;
    int numWords = 0;
    int numIndexes = 0;
    WordIndex *indexes = (WordIndex*) malloc(MAX_NUM_WORDS * sizeof(WordIndex));

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    indexFile = fopen("index.txt", "w");
    if (indexFile == NULL) {
        printf("Error opening index file.\n");
        exit(1);
    }

    while (fgets(inputLine, MAX_WORD_SIZE, inputFile)!= NULL) {
        word = strtok(inputLine, " ");
        while (word!= NULL) {
            if (numWords >= MAX_NUM_WORDS) {
                printf("Maximum number of words exceeded.\n");
                exit(1);
            }
            strcpy(indexes[numWords].word, word);
            indexes[numWords].index = numIndexes;
            numIndexes++;
            numWords++;
            word = strtok(NULL, " ");
        }
    }

    fclose(inputFile);

    for (int i = 0; i < numWords; i++) {
        fprintf(indexFile, "%s %d\n", indexes[i].word, indexes[i].index);
    }

    fclose(indexFile);

    return 0;
}