//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char *word;
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    int i, j;
    int numWords = 0;
    WordCount *wordCounts = NULL;

    // Open the file
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Read the file and count the words
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        numWords = 0;
        for (i = 0; i < strlen(line); i++) {
            if (isspace(line[i])) {
                word[numWords] = '\0';
                numWords++;
            } else {
                strncat(word, &line[i], 1);
            }
        }
        word[numWords] = '\0';
        numWords++;

        // Add the words to the word count array
        wordCounts = realloc(wordCounts, sizeof(WordCount) * numWords);
        for (j = 0; j < numWords; j++) {
            wordCounts[j].word = strdup(word[j]);
            wordCounts[j].count = 1;
        }
    }

    // Sort the word count array alphabetically
    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);

    // Print the word count
    printf("Word Count:\n");
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    // Free the memory used by the word count array
    for (i = 0; i < numWords; i++) {
        free(wordCounts[i].word);
    }
    free(wordCounts);

    // Close the file
    fclose(file);

    return 0;
}