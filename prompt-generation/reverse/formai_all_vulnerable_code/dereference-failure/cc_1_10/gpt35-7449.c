//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Define maximum word length and maximum number of unique words to be printed
#define MAX_WORD_LENGTH 50
#define MAX_UNIQUE_WORDS 1000

// Define structure for each unique word encountered
typedef struct Word {
    char word[MAX_WORD_LENGTH];
    int frequency;
} Word;

// Function to check if a character is a valid word character (letter or apostrophe)
int isWordChar(char c) {
    return isalpha(c) || c == '\'';
}

// Function to convert a string to lowercase
void toLowerCase(char* str) {
    int i;
    for (i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to compare two Word structs for use in qsort()
int wordCompare(const void* p1, const void* p2) {
    const Word* word1 = (const Word*) p1;
    const Word* word2 = (const Word*) p2;
    return strcmp(word1->word, word2->word);
}

int main() {
    // Initialize array for unique words
    Word* uniqueWords = malloc(MAX_UNIQUE_WORDS * sizeof(Word));
    int numUniqueWords = 0;

    // Initialize array for word buffer
    char* wordBuffer = malloc(MAX_WORD_LENGTH + 1);
    int wordLength = 0;

    // Loop through input, character by character
    char c;
    while ((c = getchar()) != EOF) {
        if (isWordChar(c)) {
            // If this character is part of a word, add it to the word buffer
            wordBuffer[wordLength++] = c;
            if (wordLength > MAX_WORD_LENGTH) {
                // If the word buffer exceeds the maximum word length, ignore the rest of the word and reset the buffer
                while ((c = getchar()) != EOF && isWordChar(c));
                wordLength = 0;
            }
        } else {
            // If this character is not a word character and there is a word in the buffer, process the word
            if (wordLength > 0) {
                // Null-terminate the word buffer
                wordBuffer[wordLength] = '\0';

                // Convert the word to lowercase
                toLowerCase(wordBuffer);

                // Search for the word in the unique word list
                int i;
                for (i = 0; i < numUniqueWords; i++) {
                    if (strcmp(uniqueWords[i].word, wordBuffer) == 0) {
                        // If the word is found, increment its frequency and reset the word buffer
                        uniqueWords[i].frequency++;
                        break;
                    }
                }
                if (i == numUniqueWords) {
                    // If the word is not found, add it to the unique word list and reset the word buffer
                    if (numUniqueWords >= MAX_UNIQUE_WORDS) {
                        // If the maximum number of unique words has been reached, stop processing the input
                        break;
                    }
                    strcpy(uniqueWords[numUniqueWords].word, wordBuffer);
                    uniqueWords[numUniqueWords].frequency = 1;
                    numUniqueWords++;
                }

                wordLength = 0;
            }
        }
    }

    // Sort the unique word list by word
    qsort(uniqueWords, numUniqueWords, sizeof(Word), wordCompare);

    // Print the unique word list with frequencies
    int i;
    for (i = 0; i < numUniqueWords; i++) {
        printf("%s: %d\n", uniqueWords[i].word, uniqueWords[i].frequency);
    }

    // Free memory
    free(uniqueWords);
    free(wordBuffer);

    return 0;
}