//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Define the Alien language alphabet
char alien_alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789.,?! ";

// Define the English language alphabet
char english_alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,?! ";

// Function to translate an Alien character to English
char translate_char(char alien_char) {
    int index = 0;

    // Find the index of the character in the Alien alphabet
    while (alien_char != alien_alphabet[index]) {
        index++;
    }

    // Return the corresponding character from the English alphabet
    return english_alphabet[index];
}

// Function to translate an Alien string to English
char *translate_string(char *alien_string) {
    int i;
    char *english_string;

    // Allocate memory for the English string
    english_string = malloc(strlen(alien_string) + 1);

    // Translate each character in the Alien string
    for (i = 0; i < strlen(alien_string); i++) {
        english_string[i] = translate_char(alien_string[i]);
    }

    // Add the null terminator to the English string
    english_string[strlen(alien_string)] = '\0';

    // Return the English string
    return english_string;
}

// Main function
int main() {
    char *alien_string = "HELLO WORLD!";
    char *english_string;

    // Translate the Alien string to English
    english_string = translate_string(alien_string);

    // Print the English string
    printf("%s\n", english_string);

    // Free the memory allocated for the English string
    free(english_string);

    return 0;
}