//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_WORDS 1000

typedef struct {
    char *word;
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wc1 = (WordCount *)a;
    WordCount *wc2 = (WordCount *)b;

    return strcmp(wc1->word, wc2->word);
}

void printWordCounts(WordCount *wordCounts, int numWords) {
    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *token;
    WordCount wordCounts[MAX_NUM_WORDS];
    int numWords = 0;

    fp = fopen("logfile.txt", "r");

    if (fp == NULL) {
        printf("Error: could not open logfile.txt\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        token = strtok(line, " ");

        while (token!= NULL) {
            if (numWords >= MAX_NUM_WORDS) {
                printf("Error: too many words in logfile.txt\n");
                return 2;
            }

            int j;
            for (j = 0; j < numWords; j++) {
                if (strcmp(wordCounts[j].word, token) == 0) {
                    wordCounts[j].count++;
                    break;
                }
            }

            if (j == numWords) {
                strcpy(wordCounts[numWords].word, token);
                wordCounts[numWords].count = 1;
                numWords++;
            }

            token = strtok(NULL, " ");
        }
    }

    fclose(fp);

    printWordCounts(wordCounts, numWords);

    return 0;
}