//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000

typedef struct {
    char word[50];
    int frequency;
} WordFrequency;

int compareFrequency(const void *a, const void *b) {
    const WordFrequency *aItem = (const WordFrequency *)a;
    const WordFrequency *bItem = (const WordFrequency *)b;

    return bItem->frequency - aItem->frequency;
}

int main() {
    // initialize variables
    char *text = malloc(sizeof(char) * MAX_WORDS * 50);
    char *word;
    FILE *file;
    WordFrequency *wordFreq = malloc(sizeof(WordFrequency) * MAX_WORDS);
    int numWords = 0;
    int i, j;

    // open file
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    // read in words from file
    while (fscanf(file, "%s", text + (numWords * 50)) != EOF) {
        numWords++;
    }

    // sanitize each word and count frequency
    for (i = 0; i < numWords; i++) {
        word = text + (i * 50);

        // convert to lowercase
        for (j = 0; word[j]; j++) {
            word[j] = tolower(word[j]);
        }

        // remove punctuation
        size_t len = strlen(word);
        if (ispunct(word[len - 1])) {
            word[len - 1] = '\0';
            len--;
        }
        for (j = 0; j < len; j++) {
            if (ispunct(word[j])) {
                memmove(&word[j], &word[j + 1], len - j);
                len--;
                j--;
            }
        }

        // count frequency
        for (j = 0; j < numWords; j++) {
            if (strcmp(word, wordFreq[j].word) == 0) {
                wordFreq[j].frequency++;
                break;
            }
        }
        if (j == numWords) {
            strcpy(wordFreq[numWords].word, word);
            wordFreq[numWords].frequency = 1;
            numWords++;
        }
    }

    // sort by frequency
    qsort(wordFreq, numWords, sizeof(WordFrequency), compareFrequency);

    // print results
    for (i = 0; i < numWords; i++) {
        printf("%-20s%5d\n", wordFreq[i].word, wordFreq[i].frequency);
    }

    // close file and free memory
    fclose(file);
    free(text);
    free(wordFreq);

    return 0;
}