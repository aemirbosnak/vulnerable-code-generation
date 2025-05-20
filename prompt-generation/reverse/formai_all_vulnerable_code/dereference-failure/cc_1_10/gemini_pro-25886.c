//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Define the maximum input buffer size
#define MAX_BUF_SIZE 1024

// Define the data structure for a word count
typedef struct WordCount {
    char *word;
    int count;
} WordCount;

// Define the comparison function for qsort
int compareWordCounts(const void *a, const void *b) {
    const WordCount *wc1 = (const WordCount *) a;
    const WordCount *wc2 = (const WordCount *) b;

    return strcmp(wc1->word, wc2->word);
}

// Main function
int main(int argc, char **argv) {
    // Check if the user has provided a filename
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the input file
    FILE *fp = fopen(argv[1], "r");

    // Check if the file could be opened
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Allocate memory for the input buffer
    char *buf = malloc(MAX_BUF_SIZE);

    // Check if the memory could be allocated
    if (buf == NULL) {
        fprintf(stderr, "Error allocating memory for input buffer\n");
        return EXIT_FAILURE;
    }

    // Initialize the word count map
    WordCount *wordCounts = malloc(sizeof(WordCount) * MAX_BUF_SIZE);

    // Check if the memory could be allocated
    if (wordCounts == NULL) {
        fprintf(stderr, "Error allocating memory for word count map\n");
        return EXIT_FAILURE;
    }

    // Initialize the word count map
    memset(wordCounts, 0, sizeof(WordCount) * MAX_BUF_SIZE);

    // Read the file line by line
    while (fgets(buf, MAX_BUF_SIZE, fp)) {
        // Tokenize the line into words
        char *token = strtok(buf, " ");

        // Iterate over the words
        while (token) {
            // Convert the word to lowercase
            for (int i = 0; i < strlen(token); i++) {
                token[i] = tolower(token[i]);
            }

            // Check if the word is already in the map
            WordCount *wc = NULL;
            for (int i = 0; i < MAX_BUF_SIZE; i++) {
                if (strcmp(token, wordCounts[i].word) == 0) {
                    wc = &wordCounts[i];
                    break;
                }
            }

            // If the word is not in the map, add it
            if (wc == NULL) {
                for (int i = 0; i < MAX_BUF_SIZE; i++) {
                    if (wordCounts[i].word == NULL) {
                        wordCounts[i].word = strdup(token);
                        wordCounts[i].count = 1;
                        break;
                    }
                }
            } else {
                // If the word is in the map, increment its count
                wc->count++;
            }

            // Get the next token
            token = strtok(NULL, " ");
        }
    }

    // Close the input file
    fclose(fp);

    // Sort the word counts
    qsort(wordCounts, MAX_BUF_SIZE, sizeof(WordCount), compareWordCounts);

    // Print the word counts
    for (int i = 0; i < MAX_BUF_SIZE; i++) {
        if (wordCounts[i].word != NULL) {
            printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
        }
    }

    // Free the memory allocated for the input buffer
    free(buf);

    // Free the memory allocated for the word count map
    for (int i = 0; i < MAX_BUF_SIZE; i++) {
        if (wordCounts[i].word != NULL) {
            free(wordCounts[i].word);
        }
    }
    free(wordCounts);

    return EXIT_SUCCESS;
}