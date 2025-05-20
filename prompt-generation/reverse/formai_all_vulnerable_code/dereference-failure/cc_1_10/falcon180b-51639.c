//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    FILE *file;
    char line[1000];
    char *word;
    WordCount *wordCounts = malloc(MAX_WORDS * sizeof(WordCount));
    int numWords = 0;

    if (wordCounts == NULL) {
        printf("Error: could not allocate memory for word counts.\n");
        exit(1);
    }

    file = fopen("spam.txt", "r");

    if (file == NULL) {
        printf("Error: could not open spam.txt for reading.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        word = strtok(line, ",.!?;:");

        while (word!= NULL) {
            if (numWords >= MAX_WORDS) {
                printf("Error: reached maximum number of words.\n");
                exit(1);
            }

            WordCount *currentWordCount = &wordCounts[numWords];
            strcpy(currentWordCount->word, word);
            currentWordCount->count = 1;

            numWords++;

            word = strtok(NULL, ",.!?;:");
        }
    }

    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    free(wordCounts);

    return 0;
}