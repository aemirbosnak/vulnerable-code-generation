//Falcon-180B DATASET v1.0 Category: Text processing ; Style: Alan Turing
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCE_LENGTH 1000
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *) a;
    WordFrequency *wordB = (WordFrequency *) b;

    return strcmp(wordA->word, wordB->word);
}

int getFrequency(char *sentence, char *word) {
    int frequency = 0;
    char *token;
    token = strtok(sentence, " ");

    while (token!= NULL) {
        if (strcmp(token, word) == 0) {
            frequency++;
        }
        token = strtok(NULL, " ");
    }

    return frequency;
}

void displayWords(WordFrequency *wordArray, int numWords) {
    qsort(wordArray, numWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordArray[i].word, wordArray[i].frequency);
    }
}

int main() {
    FILE *inputFile;
    char sentence[MAX_SENTENCE_LENGTH];
    char word[MAX_WORD_LENGTH];
    char *token;
    WordFrequency wordArray[MAX_WORDS];
    int numWords = 0;

    inputFile = fopen("input.txt", "r");

    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    while (fgets(sentence, MAX_SENTENCE_LENGTH, inputFile)!= NULL) {
        token = strtok(sentence, " ");

        while (token!= NULL) {
            strcpy(word, token);
            numWords++;

            if (numWords == MAX_WORDS) {
                printf("Maximum number of words reached.\n");
                exit(1);
            }

            WordFrequency *existingWord = bsearch(word, wordArray, numWords, sizeof(WordFrequency), compareWords);

            if (existingWord == NULL) {
                strcpy(existingWord->word, word);
                existingWord->frequency = getFrequency(sentence, word);
            } else {
                existingWord->frequency++;
            }

            token = strtok(NULL, " ");
        }
    }

    fclose(inputFile);

    displayWords(wordArray, numWords);

    return 0;
}