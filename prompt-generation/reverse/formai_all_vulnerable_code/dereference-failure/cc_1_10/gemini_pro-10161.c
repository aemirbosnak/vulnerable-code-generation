//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Morse code alphabet
char *morseAlphabet[] = {
    ".-","-...","-.-.","-..",".","..-.","--.",
    "....","..",".---","-.-",".--","--","-.",
    "---",".--.","--.-",".-.","...","-","..-",
    "...-","----",".----","--..","-.--","---.",
    "..--","-....","--...","-.-.--"
};

// Define the alphabet
char *alphabet = "abcdefghijklmnopqrstuvwxyz";

// Convert a character to Morse code
char *toMorse(char c) {
    int index = strchr(alphabet, c) - alphabet;
    return morseAlphabet[index];
}

// Convert a string to Morse code
char *toMorseString(char *str) {
    int len = strlen(str);
    char *morseCode = malloc(len * 5); // Allocate enough space for the Morse code
    int i;
    for (i = 0; i < len; i++) {
        strcat(morseCode, toMorse(str[i]));
        strcat(morseCode, " ");
    }
    return morseCode;
}

// Print the Morse code representation of a string
void printMorse(char *str) {
    printf("%s\n", toMorseString(str));
}

int main() {
    // Get the input string from the user
    char *str = malloc(100);
    printf("Enter a string to convert to Morse code: ");
    scanf("%s", str);

    // Convert the string to Morse code
    char *morseCode = toMorseString(str);

    // Print the Morse code representation of the string
    printf("The Morse code representation of '%s' is: %s\n", str, morseCode);

    // Free the allocated memory
    free(str);
    free(morseCode);

    return 0;
}