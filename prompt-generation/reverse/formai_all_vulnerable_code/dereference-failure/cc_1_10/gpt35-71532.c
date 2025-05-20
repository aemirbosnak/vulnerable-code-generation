//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Morse code characters and their corresponding symbols as strings
const char *morseAlphabet[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", " "};
const char *morseSymbols[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", " "};

// Function to convert a character to its Morse code symbol
const char *charToMorse(const char ch) {
    // Convert character to uppercase
    const char upperCh = toupper(ch);

    // Loop through the list of Morse code characters
    for (int i = 0; i < 27; ++i) {
        // If the character matches the current Morse code character, return the corresponding symbol
        if (upperCh == morseSymbols[i][0]) {
            return morseAlphabet[i];
        }
    }

    // If no match is found, return an empty string
    return "";
}

// Function to convert a string to its Morse code representation
char *stringToMorse(const char *str) {
    // Allocate memory for the Morse code string
    char *morseStr;
    morseStr = (char *)malloc(strlen(str) * 7);

    // Loop through the characters in the string
    for (int i = 0; i < strlen(str); ++i) {
        // If the current character is a space, add a forward slash to the Morse code string
        if (str[i] == ' ') {
            strcat(morseStr, "/");
        } else {
            // Otherwise, add the Morse code representation of the character to the Morse code string
            strcat(morseStr, charToMorse(str[i]));
        }

        // Add a space between each Morse code character to make the output easier to read
        strcat(morseStr, " ");
    }

    // Return the Morse code string
    return morseStr;
}

int main() {
    // Get the input string from the user
    char input[100];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Remove the newline character from the input string
    input[strcspn(input, "\n")] = 0;

    // Convert the input string to Morse code and print the result
    printf("Morse code: %s\n", stringToMorse(input));

    return 0;
}