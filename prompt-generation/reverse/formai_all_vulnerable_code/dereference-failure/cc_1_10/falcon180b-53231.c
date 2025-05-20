//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: high level of detail
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int main() {
    FILE *file;
    char line[100000];
    char *word;
    char *delimiters = ",.?!;:\"'()[]{}<>";
    int numWords = 0;
    WordFrequency *wordFrequencies = malloc(MAX_NUM_WORDS * sizeof(WordFrequency));

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        numWords = 0;
        word = strtok(line, delimiters);
        while (word!= NULL) {
            if (numWords >= MAX_NUM_WORDS) {
                printf("Error: Too many words.\n");
                exit(1);
            }
            strcpy(wordFrequencies[numWords].word, word);
            wordFrequencies[numWords].frequency = 1;
            numWords++;
            word = strtok(NULL, delimiters);
        }
    }

    fclose(file);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }

    free(wordFrequencies);
    return 0;
}