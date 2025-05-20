//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_WORDS 100

typedef struct {
    char *word;
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wc1 = (WordCount *) a;
    WordCount *wc2 = (WordCount *) b;
    return strcmp(wc1->word, wc2->word);
}

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char word[MAX_LINE_LENGTH];
    WordCount words[MAX_NUM_WORDS];
    int numWords = 0;
    int i;

    // Open the log file for reading
    fp = fopen("logfile.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening log file.\n");
        exit(1);
    }

    // Read each line from the log file
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        // Convert the line to lowercase
        for (i = 0; i < strlen(line); i++) {
            line[i] = tolower(line[i]);
        }

        // Split the line into words
        char *token = strtok(line, " ");
        while (token!= NULL) {
            // Check if we've reached the maximum number of words
            if (numWords >= MAX_NUM_WORDS) {
                fprintf(stderr, "Error: Too many words in line.\n");
                exit(1);
            }

            strcpy(words[numWords].word, token);
            words[numWords].count = 1;
            numWords++;

            token = strtok(NULL, " ");
        }
    }

    // Sort the words by frequency
    qsort(words, numWords, sizeof(WordCount), compareWords);

    // Print the word count
    printf("Word count:\n");
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    fclose(fp);
    return 0;
}