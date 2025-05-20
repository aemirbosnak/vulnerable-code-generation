//LLAMA2-13B DATASET v1.0 Category: Spell checking ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100

// Gratitude-themed function to check if a word is spelled correctly
int is_word_spelled_correctly(char *word) {
    int i, j;
    for (i = 0; word[i] != '\0'; i++) {
        // Check if the current letter is in the correct position
        if (word[i] == 'e' && (word[i - 1] == 'a' || word[i - 1] == 'o' || word[i - 1] == 'i')) {
            // If the current letter is 'e' and the previous letter is 'a', 'o', or 'i',
            // then the word is spelled correctly
            continue;
        }
        // Check if the current letter is in the correct position (2)
        if (word[i] == 'a' && (word[i - 1] == 'n' || word[i - 1] == 'd')) {
            // If the current letter is 'a' and the previous letter is 'n' or 'd',
            // then the word is spelled correctly
            continue;
        }
        // If the current letter is not in the correct position, return an error
        return 0;
    }
    // If the word is spelled correctly, return 1
    return 1;
}

int main() {
    // Declare a pointer to a character array to store the word to be checked
    char *word = NULL;

    // Ask the user for a word to check
    printf("Enter a word to check: ");
    fgets(word, MAX_LENGTH, stdin);

    // Check if the word is spelled correctly
    if (is_word_spelled_correctly(word)) {
        // If the word is spelled correctly, print a grateful message
        printf("Thank you for the correct word! You are truly brilliant.\n");
    } else {
        // If the word is not spelled correctly, print an error message
        printf("I apologize, but the word you provided is not spelled correctly. Please try again.\n");
    }

    // Free the memory allocated for the word
    free(word);

    return 0;
}