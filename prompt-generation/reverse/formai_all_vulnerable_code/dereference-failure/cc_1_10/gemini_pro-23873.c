//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold word and its count
typedef struct WordCount {
    char *word;
    int count;
} WordCount;

// Function to compare two WordCount structures
int compareWordCount(const void *a, const void *b) {
    const WordCount *wc1 = (const WordCount *)a;
    const WordCount *wc2 = (const WordCount *)b;

    return strcmp(wc1->word, wc2->word);
}

// Function to count words in a file
int countWords(FILE *file, WordCount **words) {
    char buffer[1024];
    int wordCount = 0;
    int wordIndex = 0;

    // Allocate memory for the first word
    *words = malloc(sizeof(WordCount));

    // Read the file line by line
    while (fgets(buffer, sizeof(buffer), file)) {
        // Tokenize the line into words
        char *token = strtok(buffer, " ");

        // While there are more words in the line
        while (token) {
            // Find the word in the array
            int index = -1;
            for (int i = 0; i < wordIndex; i++) {
                if (strcmp((*words)[i].word, token) == 0) {
                    index = i;
                    break;
                }
            }

            // If the word was not found, add it to the array
            if (index == -1) {
                (*words)[wordIndex].word = strdup(token);
                (*words)[wordIndex].count = 0;
                wordIndex++;

                // Allocate memory for the next word
                *words = realloc(*words, (wordIndex + 1) * sizeof(WordCount));
            }

            // Increment the count of the word
            (*words)[index].count++;

            // Get the next word
            token = strtok(NULL, " ");
        }

        wordCount++;
    }

    return wordCount;
}

// Function to print the word counts
void printWordCounts(WordCount *words, int wordCount) {
    // Sort the words by count
    qsort(words, wordCount, sizeof(WordCount), compareWordCount);

    // Print the word counts
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    // Open the file
    FILE *file = fopen("text.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Count the words in the file
    WordCount *words;
    int wordCount = countWords(file, &words);

    // Print the word counts
    printWordCounts(words, wordCount);

    // Free the memory allocated for the words
    for (int i = 0; i < wordCount; i++) {
        free(words[i].word);
    }
    free(words);

    // Close the file
    fclose(file);

    return EXIT_SUCCESS;
}