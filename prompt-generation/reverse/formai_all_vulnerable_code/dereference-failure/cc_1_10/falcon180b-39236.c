//Falcon-180B DATASET v1.0 Category: Text processing ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define MAX_WORD_COUNT 1000

typedef struct {
    char *word;
    int count;
} WordCount;

int main() {
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    char line[MAX_LINE_SIZE];
    WordCount wordCounts[MAX_WORD_COUNT];
    int numWords = 0;

    while (fgets(line, MAX_LINE_SIZE, inputFile)!= NULL) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            int i;
            for (i = 0; i < numWords; i++) {
                if (strcmp(word, wordCounts[i].word) == 0) {
                    wordCounts[i].count++;
                    break;
                }
            }
            if (i == numWords) {
                if (numWords >= MAX_WORD_COUNT) {
                    printf("Error: Maximum number of words reached.\n");
                    return 1;
                }
                wordCounts[numWords].word = strdup(word);
                wordCounts[numWords].count = 1;
                numWords++;
            }
            word = strtok(NULL, " ");
        }
    }

    fclose(inputFile);

    printf("Word counts:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    return 0;
}