//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Alien language dictionary
const char *alien_dict[] = {
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
    "k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
    "u", "v", "w", "x", "y", "z", "A", "B", "C", "D",
    "E", "F", "G", "H", "I", "J", "K", "L", "M", "N",
    "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X",
    "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7",
    "8", "9", " ", ",", ".", "?", "!", ";", ":", "'",
    "\"", "-", "_", "+", "=", "*", "/", "%", "^", "&",
    "|", "~", "`", "[", "]", "{", "}", "(", ")", "<",
    ">", "=", "+", "-", "*", "/", "%", "^", "&", "|",
    "~", "`", "[", "]", "{", "}", "(", ")", "<", ">",
    "=", "+", "-", "*", "/", "%", "^", "&", "|", "~",
    "`", "[", "]", "{", "}", "(", ")", "<", ">", "=",
    "+", "-", "*", "/", "%", "^", "&", "|", "~", "`"
};

// Define the English language dictionary
const char *english_dict[] = {
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
    "k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
    "u", "v", "w", "x", "y", "z", "A", "B", "C", "D",
    "E", "F", "G", "H", "I", "J", "K", "L", "M", "N",
    "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X",
    "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7",
    "8", "9", " ", ",", ".", "?", "!", ";", ":", "'",
    "\"", "-", "_", "+", "=", "*", "/", "%", "^", "&",
    "|", "~", "`", "[", "]", "{", "}", "(", ")", "<",
    ">", "=", "+", "-", "*", "/", "%", "^", "&", "|",
    "~", "`", "[", "]", "{", "}", "(", ")", "<", ">",
    "=", "+", "-", "*", "/", "%", "^", "&", "|", "~",
    "`", "[", "]", "{", "}", "(", ")", "<", ">", "=",
    "+", "-", "*", "/", "%", "^", "&", "|", "~", "`"
};

// Translate a string from Alien language to English language
char *alien_to_english(char *alien_string) {
    char *english_string = malloc(strlen(alien_string) + 1);
    for (int i = 0; i < strlen(alien_string); i++) {
        for (int j = 0; j < sizeof(alien_dict) / sizeof(char *); j++) {
            if (strcmp(alien_string + i, alien_dict[j]) == 0) {
                english_string[i] = english_dict[j];
            }
        }
    }
    english_string[strlen(alien_string)] = '\0';
    return english_string;
}

// Translate a string from English language to Alien language
char *english_to_alien(char *english_string) {
    char *alien_string = malloc(strlen(english_string) + 1);
    for (int i = 0; i < strlen(english_string); i++) {
        for (int j = 0; j < sizeof(english_dict) / sizeof(char *); j++) {
            if (strcmp(english_string + i, english_dict[j]) == 0) {
                alien_string[i] = alien_dict[j];
            }
        }
    }
    alien_string[strlen(english_string)] = '\0';
    return alien_string;
}

// Main function
int main() {
    // Get the input string from the user
    char *input_string = malloc(100);
    printf("Enter the input string: ");
    scanf("%s", input_string);

    // Translate the input string from Alien language to English language
    char *english_string = alien_to_english(input_string);

    // Print the translated string
    printf("The translated string is: %s\n", english_string);

    // Translate the translated string from English language to Alien language
    char *alien_string = english_to_alien(english_string);

    // Print the re-translated string
    printf("The re-translated string is: %s\n", alien_string);

    // Free the allocated memory
    free(input_string);
    free(english_string);
    free(alien_string);

    return 0;
}