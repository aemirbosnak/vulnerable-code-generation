//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the alien language alphabet and its English equivalents
char alien_alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
char english_alphabet[] = "tneiamljsabcdefghckopqruvxyzTNEIAMLSABCDEFGHCKOPQRUVXYZ0123456789";

// Function to translate an alien string to English
char *translate_alien_to_english(char *alien_string) {
    // Allocate memory for the translated string
    char *english_string = malloc(strlen(alien_string) + 1);

    // Translate each character in the alien string to its English equivalent
    for (int i = 0; i < strlen(alien_string); i++) {
        for (int j = 0; j < strlen(alien_alphabet); j++) {
            if (alien_string[i] == alien_alphabet[j]) {
                english_string[i] = english_alphabet[j];
            }
        }
    }

    // Add the null terminator to the end of the translated string
    english_string[strlen(alien_string)] = '\0';

    // Return the translated string
    return english_string;
}

// Function to translate an English string to alien
char *translate_english_to_alien(char *english_string) {
    // Allocate memory for the translated string
    char *alien_string = malloc(strlen(english_string) + 1);

    // Translate each character in the English string to its alien equivalent
    for (int i = 0; i < strlen(english_string); i++) {
        for (int j = 0; j < strlen(english_alphabet); j++) {
            if (english_string[i] == english_alphabet[j]) {
                alien_string[i] = alien_alphabet[j];
            }
        }
    }

    // Add the null terminator to the end of the translated string
    alien_string[strlen(english_string)] = '\0';

    // Return the translated string
    return alien_string;
}

// Main function
int main() {
    // Get the alien string from the user
    char alien_string[100];
    printf("Enter the alien string: ");
    scanf("%s", alien_string);

    // Translate the alien string to English
    char *english_string = translate_alien_to_english(alien_string);

    // Print the translated string
    printf("The English translation is: %s\n", english_string);

    // Free the memory allocated for the translated string
    free(english_string);

    // Get the English string from the user
    char english_string2[100];
    printf("Enter the English string: ");
    scanf("%s", english_string2);

    // Translate the English string to alien
    char *alien_string2 = translate_english_to_alien(english_string2);

    // Print the translated string
    printf("The alien translation is: %s\n", alien_string2);

    // Free the memory allocated for the translated string
    free(alien_string2);

    return 0;
}