//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store word frequency
typedef struct WordFrequency {
    char word[20];
    int frequency;
} WordFrequency;

// Function to compare words
int compareWords(WordFrequency *a, WordFrequency *b) {
    return strcmp(a->word, b->word);
}

// Function to find the most frequent words in a text
void findMostFrequentWords(char *text, int maxWords) {
    // Create an array of WordFrequency structures
    WordFrequency **words = malloc(maxWords * sizeof(WordFrequency));

    // Tokenize the text into words
    char *word = strtok(text, " ");

    // Iterate over the words and store their frequency
    int i = 0;
    while (word) {
        int found = 0;
        for (int j = 0; j < maxWords; j++) {
            if (strcmp(words[j]->word, word) == 0) {
                words[j]->frequency++;
                found = 1;
                break;
            }
        }
        if (!found) {
            words[maxWords - 1] = malloc(sizeof(WordFrequency));
            words[maxWords - 1]->word[0] = '\0';
            words[maxWords - 1]->frequency = 1;
            maxWords++;
        }
        word = strtok(NULL, " ");
    }

    // Sort the words by frequency
    qsort(words, maxWords, sizeof(WordFrequency), compareWords);

    // Print the most frequent words
    printf("Most frequent words:\n");
    for (int i = 0; i < maxWords; i++) {
        printf("%s: %d\n", words[i]->word, words[i]->frequency);
    }

    // Free the memory
    free(words);
}

int main() {
    char text[] = "This is a sample text with many words. The most frequent words are the, a, and is.";
    int maxWords = 100;
    findMostFrequentWords(text, maxWords);

    return 0;
}