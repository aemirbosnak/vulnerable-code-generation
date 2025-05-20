//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare an array of Morse code characters
const char *morseCode[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-",
    "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-",
    ".....", "-....", "--...", "---..", "----.", "-----", " ", "/"
};

// Declare an array of corresponding English characters
const char *englishCharacters[] = {
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
    "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T",
    "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3",
    "4", "5", "6", "7", "8", "9", " ", "/"
};

// Function to convert a single character to Morse code
char *charToMorse(char c) {
    int index = -1;

    // Loop through the English characters to find the index of the given character
    for (int i = 0; i < 27; i++) {
        if (c == englishCharacters[i][0]) {
            index = i;
            break;
        }
    }

    // If the character is not found, return an empty string
    if (index == -1) {
        return "";
    }

    // Return the corresponding Morse code character
    return morseCode[index];
}

// Function to convert a string to Morse code
char *stringToMorse(char *str) {
    int len = strlen(str);
    char *morseCodeStr = malloc(len * 5 + 1); // Allocate enough space for the Morse code string
    morseCodeStr[0] = '\0'; // Initialize the string with a null character

    // Loop through each character in the string
    for (int i = 0; i < len; i++) {
        // Append the Morse code representation of the character to the Morse code string
        strcat(morseCodeStr, charToMorse(str[i]));

        // Append a space to separate the characters
        strcat(morseCodeStr, " ");
    }

    // Remove the trailing space
    morseCodeStr[strlen(morseCodeStr) - 1] = '\0';

    return morseCodeStr;
}

// Main function
int main() {
    // Declare a variable to store the input string
    char input[256];

    // Prompt the user to enter a string
    printf("Enter a string to convert to Morse code: ");
    scanf("%s", input);

    // Convert the string to Morse code
    char *morseCodeStr = stringToMorse(input);

    // Print the Morse code string
    printf("Morse code: %s\n", morseCodeStr);

    // Free the allocated memory
    free(morseCodeStr);

    return 0;
}