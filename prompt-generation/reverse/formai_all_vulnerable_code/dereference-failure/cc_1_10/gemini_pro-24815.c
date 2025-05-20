//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the word and its count
typedef struct WordCount {
    char *word;
    int count;
} WordCount;

// Function to compare two WordCount structures
int compareWordCount(const void *a, const void *b) {
    WordCount *wordCountA = (WordCount *)a;
    WordCount *wordCountB = (WordCount *)b;

    return strcmp(wordCountA->word, wordCountB->word);
}

// Function to print the WordCount structure
void printWordCount(WordCount *wordCount) {
    printf("%s: %d\n", wordCount->word, wordCount->count);
}

// Function to count the words in a string
int countWords(char *string) {
    int count = 0;
    char *word;

    // strtok() tokenizes the string into individual words
    word = strtok(string, " ");

    // Loop through each word in the string
    while (word != NULL) {
        count++;

        // Get the next word in the string
        word = strtok(NULL, " ");
    }

    return count;
}

// Function to create a WordCount structure for a given word
WordCount *createWordCount(char *word) {
    WordCount *wordCount = malloc(sizeof(WordCount));
    wordCount->word = strdup(word);
    wordCount->count = 1;

    return wordCount;
}

// Function to add a word to the WordCount array
void addWordToArray(WordCount **wordCountArray, int *wordCountArraySize, char *word) {
    // Check if the word is already in the array
    for (int i = 0; i < *wordCountArraySize; i++) {
        if (strcmp(wordCountArray[i]->word, word) == 0) {
            // If the word is already in the array, increment its count
            wordCountArray[i]->count++;
            return;
        }
    }

    // If the word is not in the array, add it to the array
    *wordCountArraySize = *wordCountArraySize + 1;
    wordCountArray = realloc(wordCountArray, *wordCountArraySize * sizeof(WordCount *));
    wordCountArray[*wordCountArraySize - 1] = createWordCount(word);
}

// Function to free the memory allocated for the WordCount array
void freeWordCountArray(WordCount **wordCountArray, int wordCountArraySize) {
    for (int i = 0; i < wordCountArraySize; i++) {
        free(wordCountArray[i]->word);
        free(wordCountArray[i]);
    }

    free(wordCountArray);
}

// Main function
int main() {
    // Get the input string from the user
    char string[1000];
    printf("Enter a string: ");
    fgets(string, 1000, stdin);

    // Count the words in the string
    int wordCount = countWords(string);

    // Create an array to store the WordCount structures
    WordCount **wordCountArray = malloc(wordCount * sizeof(WordCount *));
    int wordCountArraySize = 0;

    // Tokenize the string and add each word to the array
    char *word;
    word = strtok(string, " ");
    while (word != NULL) {
        addWordToArray(wordCountArray, &wordCountArraySize, word);

        // Get the next word in the string
        word = strtok(NULL, " ");
    }

    // Sort the array in alphabetical order
    qsort(wordCountArray, wordCountArraySize, sizeof(WordCount *), compareWordCount);

    // Print the WordCount array
    for (int i = 0; i < wordCountArraySize; i++) {
        printWordCount(wordCountArray[i]);
    }

    // Free the memory allocated for the WordCount array
    freeWordCountArray(wordCountArray, wordCountArraySize);

    return 0;
}