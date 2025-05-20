//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64
#define MAX_WORDS 1000

typedef struct {
    char *word;
    int count;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    int numWords = 0;
    int maxWords = MAX_WORDS;
    WordFrequency *wordFrequencies = malloc(maxWords * sizeof(WordFrequency));

    if (wordFrequencies == NULL) {
        fprintf(stderr, "Error: could not allocate memory for word frequencies.\n");
        exit(1);
    }

    file = fopen("example.txt", "r");

    if (file == NULL) {
        fprintf(stderr, "Error: could not open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            if (numWords >= maxWords) {
                fprintf(stderr, "Error: maximum number of words reached.\n");
                exit(1);
            }

            strcpy(wordFrequencies[numWords].word, token);
            wordFrequencies[numWords].count = 1;

            numWords++;

            token = strtok(NULL, ",.?!;:");
        }
    }

    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].count);
    }

    free(wordFrequencies);
    fclose(file);

    return 0;
}