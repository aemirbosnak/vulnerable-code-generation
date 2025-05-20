//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a word
typedef struct {
    char *word;
    int count;
} Word;

// Define a function to compare two words
int compareWords(const void *a, const void *b) {
    Word *word1 = (Word *)a;
    Word *word2 = (Word *)b;
    return strcmp(word1->word, word2->word);
}

// Define a function to count the occurrences of each word in a text file
void countWords(char *filename) {
    // Open the text file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Create an array to store the words
    Word *words = NULL;
    int numWords = 0;

    // Read the text file line by line
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        // Tokenize the line into words
        char *token = strtok(line, " ");
        while (token != NULL) {
            // Remove any punctuation from the word
            char *cleanToken = malloc(strlen(token) + 1);
            int j = 0;
            for (int i = 0; i < strlen(token); i++) {
                if (token[i] >= 'a' && token[i] <= 'z') {
                    cleanToken[j] = token[i];
                    j++;
                } else if (token[i] >= 'A' && token[i] <= 'Z') {
                    cleanToken[j] = token[i] + 32;
                    j++;
                }
            }
            cleanToken[j] = '\0';

            // Find the word in the array of words
            int found = 0;
            for (int i = 0; i < numWords; i++) {
                if (strcmp(cleanToken, words[i].word) == 0) {
                    words[i].count++;
                    found = 1;
                    break;
                }
            }

            // If the word was not found, add it to the array of words
            if (!found) {
                words = realloc(words, (numWords + 1) * sizeof(Word));
                words[numWords].word = cleanToken;
                words[numWords].count = 1;
                numWords++;
            }

            // Get the next token
            token = strtok(NULL, " ");
        }
    }

    // Close the text file
    fclose(file);

    // Sort the array of words by frequency
    qsort(words, numWords, sizeof(Word), compareWords);

    // Print the array of words
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    // Free the allocated memory
    for (int i = 0; i < numWords; i++) {
        free(words[i].word);
    }
    free(words);
}

// Define the main function
int main(int argc, char *argv[]) {
    // Check the command line arguments
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Count the occurrences of each word in the text file
    countWords(argv[1]);

    return EXIT_SUCCESS;
}