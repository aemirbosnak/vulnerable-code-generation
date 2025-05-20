//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold a word and its count
typedef struct {
    char *word;
    int count;
} WordCount;

// Function to compare two WordCount structs by word
int wordCountCompare(const void *a, const void *b) {
    const WordCount *wa = (const WordCount *)a;
    const WordCount *wb = (const WordCount *)b;
    return strcmp(wa->word, wb->word);
}

// Function to count the occurrences of each word in a string
WordCount *countWords(const char *str) {
    // Allocate memory for the array of WordCount structs
    WordCount *wordCounts = malloc(sizeof(WordCount) * 1000);
    if (wordCounts == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    // Tokenize the string into words
    char *token = strtok(str, " ");
    int i = 0;
    while (token != NULL) {
        // Check if the word is already in the array
        int found = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(token, wordCounts[j].word) == 0) {
                wordCounts[j].count++;
                found = 1;
                break;
            }
        }

        // If the word is not in the array, add it
        if (!found) {
            wordCounts[i].word = strdup(token);
            if (wordCounts[i].word == NULL) {
                perror("strdup");
                exit(EXIT_FAILURE);
            }
            wordCounts[i].count = 1;
            i++;
        }

        // Get the next word
        token = strtok(NULL, " ");
    }

    // Sort the array by word
    qsort(wordCounts, i, sizeof(WordCount), wordCountCompare);

    // Return the array of WordCount structs
    return wordCounts;
}

// Function to print the word counts
void printWordCounts(const WordCount *wordCounts, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

// Main function
int main() {
    // Get the input string from the user
    char str[1000];
    printf("Enter a string: ");
    fgets(str, 1000, stdin);

    // Count the occurrences of each word in the string
    WordCount *wordCounts = countWords(str);

    // Print the word counts
    printWordCounts(wordCounts, 10);

    // Free the memory allocated for the array of WordCount structs
    for (int i = 0; i < 10; i++) {
        free(wordCounts[i].word);
    }
    free(wordCounts);

    return 0;
}