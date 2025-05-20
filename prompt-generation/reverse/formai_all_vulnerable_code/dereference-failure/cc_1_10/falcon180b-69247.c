//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_FILE_SIZE 1000000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compare(const void *a, const void *b) {
    WordCount *word1 = (WordCount *)a;
    WordCount *word2 = (WordCount *)b;
    return strcmp(word1->word, word2->word);
}

int main() {
    FILE *inputFile;
    char inputBuffer[MAX_FILE_SIZE];
    int inputSize;
    char *word;
    WordCount wordCounts[10000];
    int numWords = 0;
    int i;

    printf("Enter the input file name: ");
    scanf("%s", inputBuffer);

    inputFile = fopen(inputBuffer, "r");
    if (inputFile == NULL) {
        printf("Error: could not open file %s\n", inputBuffer);
        return 1;
    }

    inputSize = fread(inputBuffer, sizeof(char), MAX_FILE_SIZE, inputFile);
    if (ferror(inputFile)) {
        printf("Error: could not read file %s\n", inputBuffer);
        return 1;
    }

    inputBuffer[inputSize] = '\0';
    word = strtok(inputBuffer, ",.?!;:\"'");

    while (word!= NULL) {
        if (numWords >= 10000) {
            printf("Error: too many unique words in file\n");
            return 1;
        }

        strcpy(wordCounts[numWords].word, word);
        wordCounts[numWords].count = 1;
        numWords++;

        word = strtok(NULL, ",.?!;:\"'");
    }

    qsort(wordCounts, numWords, sizeof(WordCount), compare);

    printf("Word Count:\n");
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    fclose(inputFile);
    return 0;
}