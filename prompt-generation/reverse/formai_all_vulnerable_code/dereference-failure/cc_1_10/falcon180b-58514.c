//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    FILE *file;
    char line[1000];
    char word[MAX_WORD_LEN];
    WordCount *wordCounts = malloc(MAX_WORDS * sizeof(WordCount));
    int numWords = 0;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        char *token = strtok(line, ",.!?;:");
        while (token!= NULL) {
            strcpy(word, token);
            for (int i = 0; i < strlen(word); i++) {
                if (!isalpha(word[i])) {
                    word[i] = '\0';
                }
            }
            if (strlen(word) > 0) {
                WordCount *wordCount = bsearch(word, wordCounts, numWords, sizeof(WordCount), compareWords);
                if (wordCount == NULL) {
                    if (numWords >= MAX_WORDS) {
                        printf("Maximum number of words reached.\n");
                        break;
                    }
                    strcpy(wordCounts[numWords].word, word);
                    wordCounts[numWords].count = 1;
                    numWords++;
                } else {
                    wordCount->count++;
                }
            }
            token = strtok(NULL, ",.!?;:");
        }
    }

    fclose(file);

    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    free(wordCounts);

    return 0;
}