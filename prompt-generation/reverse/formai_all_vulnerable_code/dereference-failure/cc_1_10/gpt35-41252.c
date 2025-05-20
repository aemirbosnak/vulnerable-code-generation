//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define maximum word length
#define MAX_WORD_LENGTH 50

// Struct to contain word and its frequency
typedef struct WordFrequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

// Function prototypes
int compareFrequencies(const void *a, const void *b);
void printFrequencies(WordFrequency *words, int numWords);

int main() {
    char filename[] = "example.txt"; // Replace with desired file name
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Initialize word array with one entry
    WordFrequency *words = malloc(sizeof(WordFrequency));
    words[0].frequency = 0;

    // Process file character by character
    int c;
    char currentWord[MAX_WORD_LENGTH];
    int wordIndex = 0;
    int numWords = 0;
    while ((c = fgetc(file)) != EOF) {
        if (isalpha(c)) {
            // If character is alphabetic, add to current word
            if (wordIndex < MAX_WORD_LENGTH) {
                currentWord[wordIndex++] = tolower(c); // Convert to lowercase
            }
        } else {
            // If character is not alphabetic, end current word and count frequency
            if (wordIndex > 0) {
                currentWord[wordIndex] = '\0'; // Add null terminator
                int wordFound = 0;
                for (int i = 0; i <= numWords; i++) {
                    if (strcmp(words[i].word, currentWord) == 0) {
                        words[i].frequency++;
                        wordFound = 1;
                        break;
                    }
                }
                if (!wordFound) {
                    numWords++;
                    words = realloc(words, (numWords + 1) * sizeof(WordFrequency));
                    strcpy(words[numWords].word, currentWord);
                    words[numWords].frequency = 1;
                }
                wordIndex = 0;
            }
        }
    }

    // Sort words by frequency
    qsort(words, numWords + 1, sizeof(WordFrequency), compareFrequencies);

    // Print word frequencies
    printFrequencies(words, numWords);

    // Close file and free memory
    fclose(file);
    free(words);

    return 0;
}

// Compare function for qsort
int compareFrequencies(const void *a, const void *b) {
    const WordFrequency *word1 = (const WordFrequency *) a;
    const WordFrequency *word2 = (const WordFrequency *) b;
    return (word1->frequency < word2->frequency) - (word1->frequency > word2->frequency);
}

// Function to print word frequencies
void printFrequencies(WordFrequency *words, int numWords) {
    printf("Word\tFrequency\n");
    for (int i = 0; i <= numWords; i++) {
        printf("%s\t%d\n", words[i].word, words[i].frequency);
    }
}