//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORD_COUNT 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void* a, const void* b) {
    const WordCount* wordA = (const WordCount*)a;
    const WordCount* wordB = (const WordCount*)b;

    return strcmp(wordA->word, wordB->word);
}

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    WordCount* wordCounts = malloc(sizeof(WordCount) * MAX_WORD_COUNT);
    if (wordCounts == NULL) {
        printf("Error allocating memory for word counts.\n");
        exit(1);
    }

    int wordCount = 0;

    char word[MAX_WORD_LENGTH];
    char ch;
    while ((ch = fgetc(inputFile))!= EOF) {
        if (isalpha(ch)) {
            word[0] = ch;
            int wordLength = 1;

            while ((ch = fgetc(inputFile))!= EOF && isalpha(ch)) {
                if (wordLength >= MAX_WORD_LENGTH) {
                    break;
                }

                word[wordLength++] = ch;
            }

            word[wordLength] = '\0';

            for (int i = 0; i < wordCount; ++i) {
                if (strcmp(wordCounts[i].word, word) == 0) {
                    wordCounts[i].count++;
                    break;
                }
            }

            if (wordCount >= MAX_WORD_COUNT) {
                printf("Maximum word count reached.\n");
                break;
            }

            WordCount newWordCount = {.word = word,.count = 1 };
            wordCounts[wordCount++] = newWordCount;
        }
    }

    fclose(inputFile);

    qsort(wordCounts, wordCount, sizeof(WordCount), compareWords);

    for (int i = 0; i < wordCount; ++i) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    free(wordCounts);

    return 0;
}