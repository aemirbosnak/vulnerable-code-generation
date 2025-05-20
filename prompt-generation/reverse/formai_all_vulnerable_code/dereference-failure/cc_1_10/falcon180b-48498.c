//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    FILE *inputFile, *outputFile;
    char line[MAX_WORD_LENGTH];
    WordCount words[MAX_WORDS];
    int numWords = 0;
    int i;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    srand(time(NULL));
    for (i = 0; i < numWords; i++) {
        strcpy(words[i].word, "");
        words[i].count = 0;
    }

    while (fgets(line, MAX_WORD_LENGTH, inputFile)!= NULL) {
        char *word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            int wordIndex = rand() % numWords;
            if (words[wordIndex].word[0] == '\0') {
                strcpy(words[wordIndex].word, word);
                words[wordIndex].count = 1;
                numWords++;
            } else if (strcmp(words[wordIndex].word, word) == 0) {
                words[wordIndex].count++;
            }
            word = strtok(NULL, ",.?!;:");
        }
    }

    for (i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s: %d\n", words[i].word, words[i].count);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}