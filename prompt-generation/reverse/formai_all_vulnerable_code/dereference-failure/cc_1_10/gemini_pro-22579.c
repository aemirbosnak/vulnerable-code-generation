//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom data type for a word and its frequency
typedef struct {
    char *word;
    int frequency;
} WordFreq;

// Define a custom function to compare two WordFreq structs by frequency
int compareWordFreq(const void *a, const void *b) {
    return ((WordFreq *)a)->frequency - ((WordFreq *)b)->frequency;
}

int main() {
    // Initialize variables to store the input text and the spam score
    char inputText[1024];
    int spamScore = 0;

    // Prompt the user to enter the input text
    printf("Enter the text you want to check for spam: ");
    fgets(inputText, sizeof(inputText), stdin);

    // Tokenize the input text into words and count their frequency
    char *token = strtok(inputText, " ");
    int numWords = 0;
    WordFreq *wordFreqs = NULL;
    while (token != NULL) {
        // Check if the word is already in the word frequency list
        int found = 0;
        for (int i = 0; i < numWords; i++) {
            if (strcmp(token, wordFreqs[i].word) == 0) {
                wordFreqs[i].frequency++;
                found = 1;
                break;
            }
        }

        // If the word is not found, add it to the list
        if (!found) {
            wordFreqs = realloc(wordFreqs, (numWords + 1) * sizeof(WordFreq));
            wordFreqs[numWords].word = strdup(token);
            wordFreqs[numWords].frequency = 1;
            numWords++;
        }

        // Get the next token
        token = strtok(NULL, " ");
    }

    // Sort the word frequency list by frequency
    qsort(wordFreqs, numWords, sizeof(WordFreq), compareWordFreq);

    // Calculate the spam score based on the frequency of spam-related keywords
    for (int i = 0; i < numWords; i++) {
        if (strstr(wordFreqs[i].word, "money") != NULL) {
            spamScore += wordFreqs[i].frequency * 10;
        } else if (strstr(wordFreqs[i].word, "offer") != NULL) {
            spamScore += wordFreqs[i].frequency * 5;
        } else if (strstr(wordFreqs[i].word, "free") != NULL) {
            spamScore += wordFreqs[i].frequency * 3;
        }
    }

    // Print the spam score
    printf("Spam score: %d\n", spamScore);

    // Free the allocated memory
    for (int i = 0; i < numWords; i++) {
        free(wordFreqs[i].word);
    }
    free(wordFreqs);

    return 0;
}