//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char *word;
    int count;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *)a;
    WordFrequency *wordB = (WordFrequency *)b;
    return strcmp(wordA->word, wordB->word);
}

void printWordFrequencies(WordFrequency *wordFrequencies, int numWords) {
    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].count);
    }
}

int main() {
    char *filename = "input.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[100];
    char *word;
    int numWords = 0;
    WordFrequency *wordFrequencies = malloc(MAX_WORDS * sizeof(WordFrequency));

    while (fgets(line, sizeof(line), file)!= NULL) {
        char *token = strtok(line, " ");
        while (token!= NULL) {
            if (numWords >= MAX_WORDS) {
                printf("Reached maximum number of words.\n");
                break;
            }
            word = strdup(token);
            WordFrequency *existingWord = bsearch(word, wordFrequencies, numWords, sizeof(WordFrequency), compareWords);
            if (existingWord == NULL) {
                existingWord = realloc(wordFrequencies, (numWords + 1) * sizeof(WordFrequency));
                existingWord[numWords].word = word;
                existingWord[numWords].count = 1;
                numWords++;
            } else {
                existingWord->count++;
            }
            token = strtok(NULL, " ");
        }
    }

    printWordFrequencies(wordFrequencies, numWords);

    free(wordFrequencies);
    fclose(file);

    return 0;
}