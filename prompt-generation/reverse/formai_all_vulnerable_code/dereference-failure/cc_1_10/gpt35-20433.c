//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: statistical
// C Word Frequency Counter Example Program
// Written by [Your Name]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

#define MAX_WORD_LENGTH 100

// Function prototypes
int isDelimiter(char c);
void countWords(char *str, int *wordCounts);

int main() {

    // Read input string
    char inputString[10000];
    printf("Enter text to count word frequency:\n");
    fgets(inputString, 10000, stdin);

    // Tokenize input string into words
    int wordCounts[MAX_WORD_LENGTH] = {0}; // Initialize all counts to 0
    countWords(inputString, wordCounts);

    // Print word frequency table in descending order
    printf("\nWord frequency table:\n");
    for (int count = MAX_WORD_LENGTH; count > 0; count--) { // Descending order
        for (int i = 0; i < MAX_WORD_LENGTH; i++) {
            if (wordCounts[i] == count) {
                printf("%-20s %d\n", (i == 0 ? "<space>" : i == '\n' ? "<newline>" : (char[]) { i }), count);
            }
        }
    }

    return 0;
}

// Returns true if c is a delimiter (i.e. whitespace or punctuation)
int isDelimiter(char c) {
    return isspace(c) || ispunct(c);
}

// Increments wordCounts array for each word in str
void countWords(char *str, int *wordCounts) {
    char word[MAX_WORD_LENGTH] = {0}, lastChar = '\0';
    int i, j, isWord = 0;

    for (i = 0, j = 0; i <= strlen(str); i++) {
        if (!isDelimiter(str[i])) { // If current character is not a delimiter
            word[j++] = str[i]; // Add it to current word
            isWord = 1;
            lastChar = str[i];
        }
        else if (isWord) { // If current character is a delimiter and previous character was not
            if (word[0] != '\0') { // Ignore empty strings
                // Increment count for this word
                int len = strlen(word);
                if (word[len-1] == '\n') { // Remove trailing '\n' character
                    word[len-1] = '\0';
                }
                wordCounts[(int)(lastChar)]++;
            }
            // Reset current word
            memset(word, 0, sizeof(word));
            j = 0;
            isWord = 0;
        }
    }
}