//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 100

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

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[MAX_WORD_LEN];
    WordCount wordCounts[MAX_WORDS];
    int numWords = 0;

    while (fgets(line, MAX_WORD_LEN, fp)!= NULL) {
        // Remove newline character
        line[strcspn(line, "\n")] = '\0';

        // Convert line to lowercase
        char *lcLine = strdup(line);
        for (int i = 0; i < strlen(lcLine); i++) {
            lcLine[i] = tolower(lcLine[i]);
        }

        // Tokenize line
        char *token = strtok(lcLine, ",.!?;:");
        while (token!= NULL) {
            int wordLen = strlen(token);
            if (wordLen > 0 && wordLen <= MAX_WORD_LEN) {
                // Check if word already exists in wordCounts
                for (int j = 0; j < numWords; j++) {
                    if (strcmp(wordCounts[j].word, token) == 0) {
                        wordCounts[j].count++;
                        break;
                    }
                }

                // Add new word to wordCounts
                if (numWords >= MAX_WORDS) {
                    printf("Maximum number of words reached.\n");
                    break;
                }

                wordCounts[numWords].word = strdup(token);
                wordCounts[numWords].count = 1;
                numWords++;
            }

            token = strtok(NULL, ",.!?;:");
        }

        free(lcLine);
    }

    fclose(fp);
    printWordCounts(wordCounts, numWords);

    return 0;
}