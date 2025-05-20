//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int main() {
    FILE *inputFile;
    char line[MAX_WORD_LENGTH];
    WordFrequency words[MAX_WORDS];
    int numWords = 0;
    int i;

    inputFile = fopen("input.txt", "r");

    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    while (fgets(line, MAX_WORD_LENGTH, inputFile)!= NULL) {
        int wordLength = strlen(line);
        char *word = malloc(wordLength + 1);
        strcpy(word, line);

        for (i = 0; i < numWords; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }

        if (i == numWords) {
            if (numWords >= MAX_WORDS) {
                printf("Too many unique words in input file.\n");
                return 1;
            }

            strcpy(words[numWords].word, word);
            words[numWords].count = 1;
            numWords++;
        }
    }

    fclose(inputFile);

    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}