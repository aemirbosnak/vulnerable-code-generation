//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to analyze a text document for clues
void AnalyzeDocument(char *document) {
    // Initialize variables
    int wordCount = 0;
    int sentenceCount = 0;
    int punctuationCount = 0;
    int letterCount = 0;
    int digitCount = 0;
    int whitespaceCount = 0;
    int averageWordLength = 0;
    int longestWordLength = 0;
    char longestWord[100];

    // Tokenize the document into words
    char *word = strtok(document, " ");
    while (word != NULL) {
        // Increment the word count
        wordCount++;

        // Increment the letter count
        letterCount += strlen(word);

        // Increment the punctuation count if the word contains punctuation
        if (strchr(word, '.') || strchr(word, ',') || strchr(word, '!') || strchr(word, '?')) {
            punctuationCount++;
        }

        // Increment the digit count if the word contains digits
        if (strchr(word, '0') || strchr(word, '1') || strchr(word, '2') || strchr(word, '3') || strchr(word, '4') || strchr(word, '5') || strchr(word, '6') || strchr(word, '7') || strchr(word, '8') || strchr(word, '9')) {
            digitCount++;
        }

        // Increment the whitespace count if the word contains whitespace
        if (strchr(word, ' ')) {
            whitespaceCount++;
        }

        // Update the longest word length and longest word
        if (strlen(word) > longestWordLength) {
            longestWordLength = strlen(word);
            strcpy(longestWord, word);
        }

        // Tokenize the next word
        word = strtok(NULL, " ");
    }

    // Calculate the sentence count
    sentenceCount = punctuationCount + 1;

    // Calculate the average word length
    averageWordLength = letterCount / wordCount;

    // Print the results
    printf("Word count: %d\n", wordCount);
    printf("Sentence count: %d\n", sentenceCount);
    printf("Punctuation count: %d\n", punctuationCount);
    printf("Letter count: %d\n", letterCount);
    printf("Digit count: %d\n", digitCount);
    printf("Whitespace count: %d\n", whitespaceCount);
    printf("Average word length: %d\n", averageWordLength);
    printf("Longest word: %s\n", longestWord);
}

int main() {
    // Load the text document
    char *document = "The Adventure of the Speckled Band.txt";
    FILE *file = fopen(document, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read the text document into a string
    char *text = malloc(100000);
    fread(text, 1, 100000, file);
    fclose(file);

    // Analyze the text document
    AnalyzeDocument(text);

    // Free the allocated memory
    free(text);

    return 0;
}