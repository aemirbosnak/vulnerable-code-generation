//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Alien language dictionary
const char *alien_dict[] = {
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
    "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T",
    "U", "V", "W", "X", "Y", "Z", "a", "b", "c", "d",
    "e", "f", "g", "h", "i", "j", "k", "l", "m", "n",
    "o", "p", "q", "r", "s", "t", "u", "v", "w", "x",
    "y", "z", "0", "1", "2", "3", "4", "5", "6", "7",
    "8", "9", "!", "@", "#", "$", "%", "^", "&", "*",
    "(", ")", "-", "_", "=", "+", "[", "]", "{", "}",
    ";", ":", ",", ".", "/", "<", ">", "?", "|", "~"
};

// Alien language translation function
char *alien_translate(const char *alien_text) {
    // Allocate memory for the translated text
    char *translated_text = malloc(strlen(alien_text) + 1);

    // Initialize the translated text
    translated_text[0] = '\0';

    // Iterate over the alien text
    for (int i = 0; i < strlen(alien_text); i++) {
        // Find the index of the alien character in the dictionary
        int index = -1;
        for (int j = 0; j < sizeof(alien_dict) / sizeof(char *); j++) {
            if (strcmp(alien_text[i], alien_dict[j]) == 0) {
                index = j;
                break;
            }
        }

        // If the alien character is not found in the dictionary, add it to the translated text
        if (index == -1) {
            strcat(translated_text, alien_text[i]);
        } else {
            // Append the translated character to the translated text
            strcat(translated_text, alien_dict[index]);
        }
    }

    // Return the translated text
    return translated_text;
}

// Main function
int main() {
    // Get the alien text from the user
    char alien_text[100];
    printf("Enter the alien text: ");
    gets(alien_text);

    // Translate the alien text
    char *translated_text = alien_translate(alien_text);

    // Print the translated text
    printf("Translated text: %s\n", translated_text);

    // Free the memory allocated for the translated text
    free(translated_text);

    return 0;
}