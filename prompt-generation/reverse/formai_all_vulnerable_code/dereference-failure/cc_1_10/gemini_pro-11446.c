//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the alien language dictionary
char alienDictionary[26][26] = {
    {"abcdefghijklmnopqrstuvwxyz"},
    {"etaoinshrdlcumwfgypbvkjxqz"},
    {"etaoinshrdlcufmwygpbvkjxqz"},
    {"etaoinsrdlcumfwgypbvkjxqz"},
    {"etaoinsrdlcumfwygpbvkjxqz"},
    {"etaoinsrdlcumfwygpbvkjxqz"},
    {"etaoinsrdlcumfwygpbvkjxqz"},
    {"etaoinsrdlcumfwygpbvkjxqz"},
    {"etaoinsrdlcumfwygpbvkjxqz"},
    {"etaoinsrdlcumfwygpbvkjxqz"},
    {"etaoinsrdlcumfwygpbvkjxqz"},
    {"etaoinsrdlcumfwygpbvkjxqz"},
    {"etaoinsrdlcumfwygpbvkjxqz"},
    {"etaoinsrdlcumfwygpbvkjxqz"},
    {"etaoinsrdlcumfwygpbvkjxqz"},
    {"etaoinsrdlcumfwygpbvkjxqz"},
    {"etaoinsrdlcumfwygpbvkjxqz"},
    {"etaoinsrdlcumfwygpbvkjxqz"},
    {"etaoinsrdlcumfwygpbvkjxqz"},
    {"etaoinsrdlcumfwygpbvkjxqz"},
    {"etaoinsrdlcumfwygpbvkjxqz"},
    {"etaoinsrdlcumfwygpbvkjxqz"},
    {"etaoinsrdlcumfwygpbvkjxqz"},
    {"etaoinsrdlcumfwygpbvkjxqz"}
};

// Function to translate a string from English to Alien
char *translateToAlien(char *english) {
    // Allocate memory for the translated string
    char *alien = malloc(strlen(english) + 1);

    // Translate each character in the string
    for (int i = 0; i < strlen(english); i++) {
        alien[i] = alienDictionary[english[i] - 'a'][rand() % 26];
    }

    // Null-terminate the translated string
    alien[strlen(english)] = '\0';

    // Return the translated string
    return alien;
}

// Function to translate a string from Alien to English
char *translateFromAlien(char *alien) {
    // Allocate memory for the translated string
    char *english = malloc(strlen(alien) + 1);

    // Translate each character in the string
    for (int i = 0; i < strlen(alien); i++) {
        for (int j = 0; j < 26; j++) {
            if (alien[i] == alienDictionary[j][rand() % 26]) {
                english[i] = j + 'a';
                break;
            }
        }
    }

    // Null-terminate the translated string
    english[strlen(alien)] = '\0';

    // Return the translated string
    return english;
}

// Main function
int main() {
    // Get the input string from the user
    char *inputString;
    printf("Enter the string you want to translate: ");
    scanf("%s", inputString);

    // Translate the string from English to Alien
    char *alienString = translateToAlien(inputString);

    // Print the translated string
    printf("Translated string: %s\n", alienString);

    // Translate the string back from Alien to English
    char *englishString = translateFromAlien(alienString);

    // Print the translated string
    printf("Translated back to original string: %s\n", englishString);

    // Free the allocated memory
    free(alienString);
    free(englishString);

    return 0;
}