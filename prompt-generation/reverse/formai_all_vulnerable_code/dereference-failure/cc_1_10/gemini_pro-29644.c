//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LENGTH 100

typedef struct {
    char *word;
    int count;
} WordCount;

WordCount wordCounts[MAX_WORDS];
int numWords = 0;

int compareWordCounts(const void *a, const void *b) {
    WordCount *wc1 = (WordCount *)a;
    WordCount *wc2 = (WordCount *)b;
    return wc2->count - wc1->count;
}

int main() {
    // Read input from standard input
    char input[MAX_LENGTH];
    while (fgets(input, MAX_LENGTH, stdin) != NULL) {
        // Tokenize the input into words
        char *token = strtok(input, " ");
        while (token != NULL) {
            // Check if the word is already in the array
            int i;
            for (i = 0; i < numWords; i++) {
                if (strcmp(wordCounts[i].word, token) == 0) {
                    wordCounts[i].count++;
                    break;
                }
            }

            // If the word is not in the array, add it
            if (i == numWords) {
                wordCounts[numWords].word = strdup(token);
                wordCounts[numWords].count = 1;
                numWords++;
            }

            // Get the next token
            token = strtok(NULL, " ");
        }
    }

    // Sort the word counts in descending order
    qsort(wordCounts, numWords, sizeof(WordCount), compareWordCounts);

    // Print the top 10 words
    printf("Top 10 most frequent words:\n");
    for (int i = 0; i < 10 && i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    // Free the allocated memory
    for (int i = 0; i < numWords; i++) {
        free(wordCounts[i].word);
    }

    return 0;
}