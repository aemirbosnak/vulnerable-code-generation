//Falcon-180B DATASET v1.0 Category: Text processing ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024
#define MAX_WORD 256

typedef struct {
    char *word;
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wcA = (WordCount *)a;
    WordCount *wcB = (WordCount *)b;

    if (wcA->count > wcB->count) {
        return -1;
    } else if (wcA->count < wcB->count) {
        return 1;
    } else {
        return 0;
    }
}

void printWordCounts(WordCount *wordCounts, int numWords) {
    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main() {
    char *filename = "example.txt";
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    char line[MAX_LINE];
    int numWords = 0;
    WordCount *wordCounts = NULL;

    while (fgets(line, MAX_LINE, file)!= NULL) {
        char *token = strtok(line, " ");

        while (token!= NULL) {
            numWords++;

            WordCount *wc = realloc(wordCounts, sizeof(WordCount) * numWords);

            if (wc == NULL) {
                printf("Error: Out of memory\n");
                exit(1);
            }

            wordCounts[numWords - 1].word = token;
            wordCounts[numWords - 1].count = 1;

            token = strtok(NULL, " ");
        }
    }

    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);
    printWordCounts(wordCounts, numWords);

    free(wordCounts);
    fclose(file);

    return 0;
}