//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare a structure to represent a word
typedef struct Word {
    char *word;
    int count;
} Word;

// Function to compare two words
int compareWords(const void *a, const void *b) {
    const Word *wa = (const Word *)a;
    const Word *wb = (const Word *)b;
    return strcmp(wa->word, wb->word);
}

// Function to count the occurrences of each word in a text file
void countWords(const char *filename) {
    // Open the text file for reading
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Create an array to store the words
    const int MAX_WORDS = 10000;
    Word words[MAX_WORDS];
    int numWords = 0;

    // Read the text file line by line
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        // Tokenize the line into words
        char *token = strtok(line, " ");
        while (token != NULL) {
            // Convert the word to lowercase
            char *lowercaseToken = strdup(token);
            for (int i = 0; i < strlen(lowercaseToken); i++) {
                lowercaseToken[i] = tolower(lowercaseToken[i]);
            }

            // Check if the word is already in the array
            int found = 0;
            for (int i = 0; i < numWords; i++) {
                if (strcmp(words[i].word, lowercaseToken) == 0) {
                    words[i].count++;
                    found = 1;
                    break;
                }
            }

            // If the word is not in the array, add it
            if (!found) {
                words[numWords].word = lowercaseToken;
                words[numWords].count = 1;
                numWords++;
            }

            // Get the next token
            token = strtok(NULL, " ");
        }
    }

    // Close the text file
    fclose(file);

    // Sort the words in alphabetical order
    qsort(words, numWords, sizeof(Word), compareWords);

    // Print the words and their counts
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    countWords(argv[1]);

    return EXIT_SUCCESS;
}