//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 100000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    const WordFrequency *wordA = (const WordFrequency *)a;
    const WordFrequency *wordB = (const WordFrequency *)b;

    if (wordA->frequency > wordB->frequency)
        return -1;
    else if (wordA->frequency < wordB->frequency)
        return 1;
    else
        return 0;
}

int main() {
    FILE *file;
    char line[1024];
    char *word;
    char *saveptr;
    WordFrequency words[MAX_NUM_WORDS];
    int numWords = 0;
    int i;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        word = strtok_r(line, ",.?!;:\"'", &saveptr);
        while (word!= NULL) {
            if (numWords >= MAX_NUM_WORDS) {
                printf("Maximum number of words reached.\n");
                exit(1);
            }

            strcpy(words[numWords].word, word);
            words[numWords].frequency = 1;
            numWords++;

            word = strtok_r(NULL, ",.?!;:\"'", &saveptr);
        }
    }

    fclose(file);

    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }

    return 0;
}