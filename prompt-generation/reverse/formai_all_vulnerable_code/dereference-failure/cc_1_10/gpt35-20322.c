//FormAI DATASET v1.0 Category: Text Summarizer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 5000
#define MAX_OUTPUT_SIZE 1000

typedef struct WordCountPair {
    char word[50];
    int count;
} WordCountPair;

void printSummary(WordCountPair sortedList[], int numPairs) {
    printf("Here's a summary of the text:\n");
    for (int i = 0; i < numPairs; i++) {
        printf("%s: %d\n", sortedList[i].word, sortedList[i].count);
    }
}

int compareWordCountPairs(const void *a, const void *b) {
    WordCountPair *pairA = (WordCountPair *) a;
    WordCountPair *pairB = (WordCountPair *) b;
    return pairB->count - pairA->count;
}

int main() {
    printf("Enter text to be summarized:\n");
    char *input = malloc(sizeof(char) * MAX_INPUT_SIZE);
    fgets(input, MAX_INPUT_SIZE, stdin);

    printf("Summarizing...\n");

    int numPairs = 0;
    WordCountPair *pairs = malloc(sizeof(WordCountPair) * MAX_OUTPUT_SIZE);

    char *word = strtok(input, " ");
    while (word != NULL) {
        int found = 0;
        for (int i = 0; i < numPairs; i++) {
            if (strcmp(word, pairs[i].word) == 0) {
                pairs[i].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            WordCountPair newPair;
            strcpy(newPair.word, word);
            newPair.count = 1;
            pairs[numPairs] = newPair;
            numPairs++;
        }
        word = strtok(NULL, " ");
    }

    qsort(pairs, numPairs, sizeof(WordCountPair), compareWordCountPairs);
    WordCountPair *sortedPairs = malloc(sizeof(WordCountPair) * numPairs);
    memcpy(sortedPairs, pairs, sizeof(WordCountPair) * numPairs);
    printSummary(sortedPairs, numPairs);

    return 0;
}