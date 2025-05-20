//Falcon-180B DATASET v1.0 Category: Text processing ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char *word;
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wordCountA = (WordCount *)a;
    WordCount *wordCountB = (WordCount *)b;

    return strcmp(wordCountA->word, wordCountB->word);
}

void printWordCounts(WordCount *wordCounts, int count) {
    qsort(wordCounts, count, sizeof(WordCount), compareWords);

    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    WordCount wordCounts[1000];
    int wordCount = 0;

    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        char *token = strtok(line, " ");

        while (token!= NULL) {
            strcpy(word, token);

            int i;
            for (i = 0; i < wordCount; i++) {
                if (strcmp(wordCounts[i].word, word) == 0) {
                    wordCounts[i].count++;
                    break;
                }
            }

            if (i == wordCount) {
                strcpy(wordCounts[wordCount].word, word);
                wordCounts[wordCount].count = 1;
                wordCount++;
            }

            token = strtok(NULL, " ");
        }
    }

    printWordCounts(wordCounts, wordCount);

    return 0;
}