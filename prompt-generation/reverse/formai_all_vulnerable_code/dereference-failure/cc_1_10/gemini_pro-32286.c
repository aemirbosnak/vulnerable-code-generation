//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A struct to represent a word and its count
typedef struct {
    char *word;
    int count;
} WordCount;

// A function to compare two WordCount structs by count
int compareWordCount(const void *a, const void *b) {
    WordCount *wordCountA = (WordCount *)a;
    WordCount *wordCountB = (WordCount *)b;
    return wordCountB->count - wordCountA->count;
}

// A function to count the occurrences of each word in a string
WordCount *countWords(char *string) {
    // Allocate memory for the array of WordCount structs
    WordCount *wordCounts = malloc(sizeof(WordCount) * 100);

    // Tokenize the string into words
    char *token = strtok(string, " ");
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
            wordCounts[i].word = malloc(strlen(token) + 1);
            strcpy(wordCounts[i].word, token);
            wordCounts[i].count = 1;
            i++;
        }

        // Get the next token
        token = strtok(NULL, " ");
    }

    // Reallocate memory for the array to the correct size
    wordCounts = realloc(wordCounts, sizeof(WordCount) * i);

    // Sort the array by count
    qsort(wordCounts, i, sizeof(WordCount), compareWordCount);

    // Return the array
    return wordCounts;
}

// A function to print the top 10 words and their counts
void printTopWords(WordCount *wordCounts, int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main() {
    // Get the input string from the user
    char string[100];
    printf("Enter a string: ");
    fgets(string, 100, stdin);

    // Count the occurrences of each word in the string
    WordCount *wordCounts = countWords(string);

    // Print the top 10 words and their counts
    printTopWords(wordCounts, 10);

    // Free the memory allocated for the array of WordCount structs
    for (int i = 0; i < 100; i++) {
        free(wordCounts[i].word);
    }
    free(wordCounts);

    return 0;
}