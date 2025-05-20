//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void initializeWordFrequency(WordFrequency *wordFrequency, char *word) {
    strcpy(wordFrequency->word, word);
    wordFrequency->frequency = 1;
}

void updateWordFrequency(WordFrequency *wordFrequency) {
    wordFrequency->frequency++;
}

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *)a;
    WordFrequency *wordB = (WordFrequency *)b;

    return strcmp(wordA->word, wordB->word);
}

void printWordFrequency(WordFrequency *wordFrequency) {
    printf("%s: %d\n", wordFrequency->word, wordFrequency->frequency);
}

int main() {
    FILE *file;
    char line[1000];
    char word[MAX_WORD_LENGTH];
    WordFrequency wordFrequency[MAX_WORDS];
    int numWords = 0;

    file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        char *token;
        int i;

        for (i = 0; i < numWords; i++) {
            if (wordFrequency[i].frequency == 0) {
                break;
            }
        }

        if (i == numWords) {
            printf("Maximum number of words reached.\n");
            exit(1);
        }

        token = strtok(line, ",.!?;:\"'()[]{}<>");
        while (token!= NULL) {
            if (strlen(token) > MAX_WORD_LENGTH) {
                printf("Error: Word \"%s\" is too long.\n", token);
                exit(1);
            }

            if (isalpha(token[0])) {
                strcpy(word, token);
                strcpy(wordFrequency[i].word, word);
                initializeWordFrequency(&wordFrequency[i], word);
            }

            token = strtok(NULL, ",.!?;:\"'()[]{}<>");
        }

        numWords++;
    }

    qsort(wordFrequency, numWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        printWordFrequency(&wordFrequency[i]);
    }

    return 0;
}