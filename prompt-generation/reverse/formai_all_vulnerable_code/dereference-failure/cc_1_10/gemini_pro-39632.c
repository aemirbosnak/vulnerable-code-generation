//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold the data for each word
typedef struct {
    char *word;
    int count;
} WordCount;

// Function to compare two WordCount structures by count
int compareWordCount(const void *a, const void *b) {
    const WordCount *wc1 = (const WordCount *)a;
    const WordCount *wc2 = (const WordCount *)b;

    return wc2->count - wc1->count;
}

int main() {
    // Allocate memory for the array of WordCount structures
    WordCount *wordCounts = malloc(1000 * sizeof(WordCount));

    // Initialize the array of WordCount structures
    for (int i = 0; i < 1000; i++) {
        wordCounts[i].word = NULL;
        wordCounts[i].count = 0;
    }

    // Read the input text from stdin
    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, stdin) != -1) {
        // Tokenize the line into words
        char *token = strtok(line, " ");
        while (token != NULL) {
            // Find the WordCount structure for the token
            WordCount *wc = NULL;
            for (int i = 0; i < 1000; i++) {
                if (wordCounts[i].word == NULL) {
                    wc = &wordCounts[i];
                    break;
                } else if (strcmp(wordCounts[i].word, token) == 0) {
                    wc = &wordCounts[i];
                    break;
                }
            }

            // If the WordCount structure for the token was not found, create a new one
            if (wc == NULL) {
                wc = &wordCounts[0];
                while (wc->word != NULL) {
                    wc++;
                }
                wc->word = strdup(token);
                wc->count = 0;
            }

            // Increment the count for the WordCount structure
            wc->count++;

            // Get the next token
            token = strtok(NULL, " ");
        }

        // Free the line
        free(line);
        line = NULL;
        len = 0;
    }

    // Sort the array of WordCount structures by count
    qsort(wordCounts, 1000, sizeof(WordCount), compareWordCount);

    // Print the top 10 most frequent words
    for (int i = 0; i < 10; i++) {
        if (wordCounts[i].word != NULL) {
            printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
        }
    }

    // Free the memory allocated for the array of WordCount structures
    for (int i = 0; i < 1000; i++) {
        if (wordCounts[i].word != NULL) {
            free(wordCounts[i].word);
        }
    }
    free(wordCounts);

    return 0;
}