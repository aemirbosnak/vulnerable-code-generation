//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

typedef struct {
    char *word;
    int count;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *)a;
    WordFrequency *wordB = (WordFrequency *)b;

    return strcmp(wordA->word, wordB->word);
}

void printFrequencies(WordFrequency *frequencies, int numFrequencies) {
    qsort(frequencies, numFrequencies, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numFrequencies; i++) {
        printf("%s: %d\n", frequencies[i].word, frequencies[i].count);
    }
}

int main() {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    char *word;
    int numWords = 0;
    WordFrequency *frequencies;

    file = fopen("resume.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    frequencies = (WordFrequency *)malloc(sizeof(WordFrequency) * 1000);

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        numWords = 0;
        word = strtok(line, " ");

        while (word!= NULL) {
            int index = 0;
            while (index < numWords && strcmp(frequencies[index].word, word)!= 0) {
                index++;
            }

            if (index == numWords) {
                frequencies[numWords].word = strdup(word);
                frequencies[numWords].count = 1;
                numWords++;
            } else {
                frequencies[index].count++;
            }

            word = strtok(NULL, " ");
        }
    }

    fclose(file);

    printFrequencies(frequencies, numWords);

    for (int i = 0; i < numWords; i++) {
        free(frequencies[i].word);
    }

    free(frequencies);

    return 0;
}