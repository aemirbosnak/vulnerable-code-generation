//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the alien language dictionary
struct alien_dict {
    char alien_char;
    char english_char;
};

// Define the size of the alien language dictionary
#define DICT_SIZE 26

// Define the alien language dictionary
struct alien_dict dict[DICT_SIZE] = {
    {'A', 'a'},
    {'B', 'b'},
    {'C', 'c'},
    {'D', 'd'},
    {'E', 'e'},
    {'F', 'f'},
    {'G', 'g'},
    {'H', 'h'},
    {'I', 'i'},
    {'J', 'j'},
    {'K', 'k'},
    {'L', 'l'},
    {'M', 'm'},
    {'N', 'n'},
    {'O', 'o'},
    {'P', 'p'},
    {'Q', 'q'},
    {'R', 'r'},
    {'S', 's'},
    {'T', 't'},
    {'U', 'u'},
    {'V', 'v'},
    {'W', 'w'},
    {'X', 'x'},
    {'Y', 'y'},
    {'Z', 'z'}
};

// Function to translate an alien language character to an English character
char alien_to_english(char alien_char) {
    for (int i = 0; i < DICT_SIZE; i++) {
        if (dict[i].alien_char == alien_char) {
            return dict[i].english_char;
        }
    }

    // If the alien character is not found in the dictionary, return the original character
    return alien_char;
}

// Function to translate an English character to an alien language character
char english_to_alien(char english_char) {
    for (int i = 0; i < DICT_SIZE; i++) {
        if (dict[i].english_char == english_char) {
            return dict[i].alien_char;
        }
    }

    // If the English character is not found in the dictionary, return the original character
    return english_char;
}

// Function to translate an alien language string to an English string
char *alien_to_english_string(char *alien_string) {
    char *english_string = malloc(strlen(alien_string) + 1);

    for (int i = 0; i < strlen(alien_string); i++) {
        english_string[i] = alien_to_english(alien_string[i]);
    }

    english_string[strlen(alien_string)] = '\0';

    return english_string;
}

// Function to translate an English string to an alien language string
char *english_to_alien_string(char *english_string) {
    char *alien_string = malloc(strlen(english_string) + 1);

    for (int i = 0; i < strlen(english_string); i++) {
        alien_string[i] = english_to_alien(english_string[i]);
    }

    alien_string[strlen(english_string)] = '\0';

    return alien_string;
}

// Main function
int main() {
    // Get the alien language string from the user
    char alien_string[100];
    printf("Enter an alien language string: ");
    scanf("%s", alien_string);

    // Translate the alien language string to an English string
    char *english_string = alien_to_english_string(alien_string);

    // Print the English string
    printf("English string: %s\n", english_string);

    // Free the memory allocated for the English string
    free(english_string);

    return 0;
}