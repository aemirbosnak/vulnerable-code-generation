//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
char* morseCodeTable[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
    ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"
};

// Function to convert a character to Morse code
char* charToMorse(char character) {
    int index = character - 'a';
    if (index >= 0 && index < 26) {
        return morseCodeTable[index];
    } else {
        return "";
    }
}

// Function to convert a string to Morse code
char* stringToMorse(char* string) {
    int length = strlen(string);
    char* morseCode = malloc(length * 5 + 1); // Allocate enough space for each character and the spaces between them
    int index = 0;
    for (int i = 0; i < length; i++) {
        char* morse = charToMorse(string[i]);
        strcat(morseCode, morse);
        strcat(morseCode, " ");
        index += strlen(morse) + 1;
    }
    morseCode[index - 1] = '\0'; // Remove the trailing space
    return morseCode;
}

// Main function
int main() {
    char* string = "Hello World!";

    // Convert the string to Morse code
    char* morseCode = stringToMorse(string);

    // Print the Morse code
    printf("Morse code: %s\n", morseCode);

    // Free the allocated memory
    free(morseCode);

    return 0;
}