//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

// Define a structure to store word information
typedef struct Word {
    char *word;
    int frequency;
} Word;

// Function to compare words by frequency
int compareWords(Word *a, Word *b) {
    return b->frequency - a->frequency;
}

int main() {
    Word **words = NULL;
    int numWords = 0;
    char text[MAX_WORDS];

    // Get the text from the user
    printf("Enter text: ");
    fgets(text, MAX_WORDS, stdin);

    // Tokenize the text into words
    char *word = strtok(text, " ");
    while (word) {
        // Create a new word structure
        Word *newWord = malloc(sizeof(Word));
        newWord->word = strdup(word);
        newWord->frequency = 1;

        // Add the new word to the list
        words = realloc(words, (numWords + 1) * sizeof(Word *));
        words[numWords++] = newWord;
        word = strtok(NULL, " ");
    }

    // Sort the words by frequency
    qsort(words, numWords, sizeof(Word *), compareWords);

    // Print the sorted words
    printf("Sorted words by frequency:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i]->word, words[i]->frequency);
    }

    // Free the memory
    for (int i = 0; i < numWords; i++) {
        free(words[i]->word);
        free(words[i]);
    }
    free(words);

    return 0;
}