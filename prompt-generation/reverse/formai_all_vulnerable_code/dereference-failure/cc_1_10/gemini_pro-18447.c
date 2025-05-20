//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Alien language dictionary
const char* alien_dict[] = {
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
    "k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
    "u", "v", "w", "x", "y", "z", "aa", "ab", "ac", "ad",
    "ae", "af", "ag", "ah", "ai", "aj", "ak", "al", "am", "an",
    "ao", "ap", "aq", "ar", "as", "at", "au", "av", "aw", "ax",
    "ay", "az", "ba", "bb", "bc", "bd", "be", "bf", "bg", "bh",
    "bi", "bj", "bk", "bl", "bm", "bn", "bo", "bp", "bq", "br",
    "bs", "bt", "bu", "bv", "bw", "bx", "by", "bz", "ca", "cb",
    "cc", "cd", "ce", "cf", "cg", "ch", "ci", "cj", "ck", "cl",
    "cm", "cn", "co", "cp", "cq", "cr", "cs", "ct", "cu", "cv",
    "cw", "cx", "cy", "cz", "da", "db", "dc", "dd", "de", "df",
    "dg", "dh", "di", "dj", "dk", "dl", "dm", "dn", "do", "dp",
    "dq", "dr", "ds", "dt", "du", "dv", "dw", "dx", "dy", "dz",
    "ea", "eb", "ec", "ed", "ee", "ef", "eg", "eh", "ei", "ej",
    "ek", "el", "em", "en", "eo", "ep", "eq", "er", "es", "et",
    "eu", "ev", "ew", "ex", "ey", "ez"
};

// Define the maximum length of an Alien word
#define MAX_WORD_LEN 10

// Function to translate an Alien word to English
char* alien_to_english(char* alien_word) {
    // Allocate memory for the English translation
    char* english_word = malloc(MAX_WORD_LEN + 1);

    // Initialize the English translation to the empty string
    english_word[0] = '\0';

    // Iterate over the characters in the Alien word
    int i = 0;
    while (alien_word[i] != '\0') {
        // Get the index of the character in the Alien dictionary
        int index = -1;
        for (int j = 0; j < sizeof(alien_dict) / sizeof(char*); j++) {
            if (strcmp(alien_dict[j], alien_word + i) == 0) {
                index = j;
                break;
            }
        }

        // If the character was found in the dictionary, append it to the English translation
        if (index != -1) {
            strcat(english_word, alien_dict[index + 1]);
        }

        // Increment the index to the next character in the Alien word
        i++;
    }

    // Return the English translation
    return english_word;
}

// Function to translate an English word to Alien
char* english_to_alien(char* english_word) {
    // Allocate memory for the Alien translation
    char* alien_word = malloc(MAX_WORD_LEN * 2 + 1);

    // Initialize the Alien translation to the empty string
    alien_word[0] = '\0';

    // Iterate over the characters in the English word
    int i = 0;
    while (english_word[i] != '\0') {
        // Get the index of the character in the English dictionary
        int index = -1;
        for (int j = 0; j < sizeof(alien_dict) / sizeof(char*); j++) {
            if (strcmp(alien_dict[j + 1], english_word + i) == 0) {
                index = j;
                break;
            }
        }

        // If the character was found in the dictionary, append it to the Alien translation
        if (index != -1) {
            strcat(alien_word, alien_dict[index]);
        }

        // Increment the index to the next character in the English word
        i++;
    }

    // Return the Alien translation
    return alien_word;
}

// Main function
int main(int argc, char** argv) {
    // Check if the user provided an Alien or English word
    if (argc != 3) {
        printf("Usage: %s <alien word> <english word>\n", argv[0]);
        return 1;
    }

    // Translate the Alien word to English
    char* english_word = alien_to_english(argv[1]);

    // Print the English translation
    printf("English translation: %s\n", english_word);

    // Translate the English word to Alien
    char* alien_word = english_to_alien(argv[2]);

    // Print the Alien translation
    printf("Alien translation: %s\n", alien_word);

    // Free the memory allocated for the translations
    free(english_word);
    free(alien_word);

    return 0;
}