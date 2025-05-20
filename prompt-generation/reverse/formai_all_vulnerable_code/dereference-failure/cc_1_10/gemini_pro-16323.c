//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Retro-style formatting macros
#define BEEP printf("\a")
#define CLEAR printf("\033[2J")
#define GOTOXY(x,y) printf("\033[%d;%dH", (y), (x))

// Alien language dictionary
char *alien_dictionary[] = {
    "AAA", "BBB", "CCC", "DDD", "EEE",
    "FFF", "GGG", "HHH", "III", "JJJ",
    "KKK", "LLL", "MMM", "NNN", "OOO",
    "PPP", "QQQ", "RRR", "SSS", "TTT",
    "UUU", "VVV", "WWW", "XXX", "YYY",
    "ZZZ"
};

// Function to translate a string from English to Alien
char *translate_to_alien(char *english) {
    int len = strlen(english);
    char *alien = malloc(len * 3 + 1); // Allocate memory for the translated string
    int i;

    for (i = 0; i < len; i++) {
        char letter = english[i];

        // Convert the letter to uppercase
        if (letter >= 'a' && letter <= 'z') {
            letter -= 32;
        }

        // Find the corresponding Alien word in the dictionary
        int index = letter - 'A';
        if (index >= 0 && index < 26) {
            strcpy(alien + i * 3, alien_dictionary[index]);
        } else {
            alien[i * 3] = '*';
            alien[i * 3 + 1] = '*';
            alien[i * 3 + 2] = '*';
        }
    }

    alien[len * 3] = '\0'; // Null-terminate the translated string

    return alien;
}

// Main function
int main() {
    // Clear the screen and move the cursor to the top-left corner
    CLEAR;
    GOTOXY(1, 1);

    // Print the title of the program
    printf("Alien Language Translator\n\n");

    // Get the English string from the user
    char english[101];
    printf("Enter an English string to translate: ");
    scanf("%s", english);

    // Translate the string to Alien
    char *alien = translate_to_alien(english);

    // Print the translated string
    printf("\nThe translation in Alien is: %s\n", alien);

    // Free the allocated memory
    free(alien);

    // Beep to indicate that the translation is complete
    BEEP;

    return 0;
}