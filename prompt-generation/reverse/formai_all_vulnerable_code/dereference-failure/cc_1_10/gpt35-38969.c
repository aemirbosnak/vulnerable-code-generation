//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50

typedef struct WordFrequency {
    char* word;
    int frequency;
} WordFrequency;

int compare(const void* a, const void* b) {
    const WordFrequency* wf1 = *(const WordFrequency**)a;
    const WordFrequency* wf2 = *(const WordFrequency**)b;
    return wf2->frequency - wf1->frequency;
}

int main() {
    printf("Welcome to the C Word Frequency Counter!\n\n");
    printf("Please enter the name of the file you would like to process: ");

    char fileName[256];
    scanf("%s", fileName);

    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("\nUnable to open file. Please check the file name and try again.\n");
        return 0;
    }

    printf("\nProcessing file \"%s\"...", fileName);

    WordFrequency** wordFrequencies = NULL;
    int numWords = 0;
    char buffer[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", buffer) != EOF) {
        for (int i = 0; i < strlen(buffer); i++) {
            buffer[i] = tolower(buffer[i]);
        }

        int foundIndex = -1;
        for (int i = 0; i < numWords; i++) {
            if (strcmp(wordFrequencies[i]->word, buffer) == 0) {
                foundIndex = i;
                break;
            }
        }

        if (foundIndex != -1) {
            wordFrequencies[foundIndex]->frequency++;
        }
        else {
            WordFrequency* newWordFrequency = malloc(sizeof(WordFrequency));
            newWordFrequency->word = malloc(sizeof(char) * (strlen(buffer) + 1));
            strcpy(newWordFrequency->word, buffer);
            newWordFrequency->frequency = 1;

            wordFrequencies = realloc(wordFrequencies, sizeof(WordFrequency*) * (numWords + 1));
            wordFrequencies[numWords] = newWordFrequency;
            numWords++;
        }
    }

    qsort(wordFrequencies, numWords, sizeof(WordFrequency*), compare);

    printf(" done.\n\n");

    printf("There are %d distinct words in the file, with the following frequencies:\n\n", numWords);
    for (int i = 0; i < numWords; i++) {
        printf("%-20s %d\n", wordFrequencies[i]->word, wordFrequencies[i]->frequency);
    }

    for (int i = 0; i < numWords; i++) {
        free(wordFrequencies[i]->word);
        free(wordFrequencies[i]);
    }
    free(wordFrequencies);

    fclose(file);

    return 0;
}