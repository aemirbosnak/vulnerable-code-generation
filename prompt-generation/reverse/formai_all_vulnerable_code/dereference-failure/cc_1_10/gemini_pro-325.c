//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 100

// Define the maximum number of words in a sentence
#define MAX_WORDS_IN_SENTENCE 1000

// Define the maximum number of characters in a line
#define MAX_LINE_LENGTH 1000

// Create a struct to store the word count
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

// Create a function to compare two WordCount structs
int compareWordCounts(const void *a, const void *b) {
    WordCount *wordCount1 = (WordCount *)a;
    WordCount *wordCount2 = (WordCount *)b;

    return strcmp(wordCount1->word, wordCount2->word);
}

// Create a function to count the words in a sentence
int countWords(char *sentence, WordCount **wordCounts) {
    // Initialize the word count
    int wordCount = 0;

    // Tokenize the sentence
    char *token = strtok(sentence, " ");

    // Iterate over the tokens
    while (token) {
        // Check if the token is already in the word count
        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(token, (*wordCounts)[i].word) == 0) {
                (*wordCounts)[i].count++;
                found = 1;
                break;
            }
        }

        // If the token is not already in the word count, add it
        if (!found) {
            (*wordCounts) = realloc(*wordCounts, (wordCount + 1) * sizeof(WordCount));
            strcpy((*wordCounts)[wordCount].word, token);
            (*wordCounts)[wordCount].count = 1;
            wordCount++;
        }

        // Get the next token
        token = strtok(NULL, " ");
    }

    return wordCount;
}

// Create a function to print the word count
void printWordCount(WordCount *wordCounts, int wordCount) {
    // Sort the word count
    qsort(wordCounts, wordCount, sizeof(WordCount), compareWordCounts);

    // Print the word count
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

// Create a function to get the input from the user
char *getInput() {
    // Allocate memory for the input
    char *input = malloc(MAX_LINE_LENGTH * sizeof(char));

    // Get the input from the user
    printf("Enter a sentence: ");
    fgets(input, MAX_LINE_LENGTH, stdin);

    // Remove the newline character from the input
    input[strlen(input) - 1] = '\0';

    return input;
}

// Create a function to free the memory allocated for the word count
void freeWordCount(WordCount *wordCounts, int wordCount) {
    // Free the memory allocated for the word count
    free(wordCounts);
}

// Main function
int main() {
    // Get the input from the user
    char *input = getInput();

    // Create an array to store the word count
    WordCount *wordCounts = NULL;

    // Count the words in the sentence
    int wordCount = countWords(input, &wordCounts);

    // Print the word count
    printWordCount(wordCounts, wordCount);

    // Free the memory allocated for the word count
    freeWordCount(wordCounts, wordCount);

    // Free the memory allocated for the input
    free(input);

    return 0;
}