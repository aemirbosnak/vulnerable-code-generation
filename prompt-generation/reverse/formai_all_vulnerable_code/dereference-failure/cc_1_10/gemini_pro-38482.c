//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a word and its count
typedef struct {
    char* word;
    int count;
} WordCount;

// Function to compare two WordCount structs by their word
int compareWords(const void* a, const void* b) {
    const WordCount* wa = (const WordCount*)a;
    const WordCount* wb = (const WordCount*)b;
    return strcmp(wa->word, wb->word);
}

// Function to count the occurrences of each word in a string
void countWords(char* text, WordCount** words, int* wordCount) {
    // Split the text into words using strtok
    char* word = strtok(text, " ");
    while (word != NULL) {
        // Allocate memory for the word and copy it into the struct
        WordCount* wc = malloc(sizeof(WordCount));
        wc->word = malloc(strlen(word) + 1);
        strcpy(wc->word, word);
        wc->count = 1;

        // Check if the word is already in the array
        int index = 0;
        while (index < *wordCount && strcmp(wc->word, words[index]->word) != 0) {
            index++;
        }

        // If the word is not in the array, add it
        if (index == *wordCount) {
            words = realloc(words, (*wordCount + 1) * sizeof(WordCount*));
            words[*wordCount] = wc;
            (*wordCount)++;
        } else {
            // If the word is already in the array, increment its count
            words[index]->count++;
            free(wc->word);
            free(wc);
        }

        // Get the next word
        word = strtok(NULL, " ");
    }
}

// Function to print the words and their counts in descending order
void printWords(WordCount** words, int wordCount) {
    // Sort the words by their count
    qsort(words, wordCount, sizeof(WordCount*), compareWords);

    // Print the words and their counts
    for (int i = wordCount - 1; i >= 0; i--) {
        printf("%s: %d\n", words[i]->word, words[i]->count);
    }
}

// Main function
int main() {
    // Get the input text from the user
    char text[1024];
    printf("Enter some text: ");
    fgets(text, 1024, stdin);

    // Create an array of WordCount structs to store the words and their counts
    WordCount** words = malloc(0);
    int wordCount = 0;

    // Count the occurrences of each word in the text
    countWords(text, words, &wordCount);

    // Print the words and their counts in descending order
    printWords(words, wordCount);

    // Free the memory allocated for the words and their counts
    for (int i = 0; i < wordCount; i++) {
        free(words[i]->word);
        free(words[i]);
    }
    free(words);

    return 0;
}