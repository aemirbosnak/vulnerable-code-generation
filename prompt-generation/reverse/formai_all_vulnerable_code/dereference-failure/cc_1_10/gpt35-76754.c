//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

// Forward declaration of alien language translation function
char* translate_to_english(char* alien_word);

int main() {
    char alien_word[50];
    printf("Enter word in alien language: ");
    fgets(alien_word, 50, stdin);

    // Remove newline character from string input
    alien_word[strcspn(alien_word, "\n")] = 0;

    printf("Translation: %s\n", translate_to_english(alien_word));
    return 0;
}

/**
 * This function translates an alien word to English.
 * The rules of the alien language are as follows:
 * 1. The first letter of each word is capitalized.
 * 2. The second letter of each word is replaced with 'z'.
 * 3. 'y' is replaced with 'i'.
 * 4. 'x' is replaced with 'e'.
 **/
char* translate_to_english(char* alien_word) {
    int len = strlen(alien_word);
    char* english_word = malloc(len + 1);
    int i = 0;

    // Capitalize first letter of first word
    english_word[i++] = alien_word[0] - 32;

    // Loop through remaining characters of input string
    for (; i < len; i++) {
        char curr_char = alien_word[i];
        // Replace second letter with 'z'
        if (i == 1) {
            english_word[i] = 'z';
        }
        // Replace 'y' with 'i'
        else if (curr_char == 'y') {
            english_word[i] = 'i';
        }
        // Replace 'x' with 'e'
        else if (curr_char == 'x') {
            english_word[i] = 'e';
        }
        // Copy over all other characters as-is
        else {
            english_word[i] = curr_char;
        }
    }

    // Add null terminator
    english_word[i] = '\0';
    return english_word;
}