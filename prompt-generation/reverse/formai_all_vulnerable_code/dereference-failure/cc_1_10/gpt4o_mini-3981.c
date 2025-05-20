//GPT-4o-mini DATASET v1.0 Category: Text to Morse code conversion ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MORSE_CODE_COUNT 36

// Morse code mapping for letters and numbers
const char *morseCode[MORSE_CODE_COUNT][2] = {
    {"A", ".-"}, {"B", "-..."}, {"C", "-.-."}, {"D", "-.."}, {"E", "."},
    {"F", "..-."}, {"G", "--."}, {"H", "...."}, {"I", ".."}, {"J", ".---"},
    {"K", "-.-"}, {"L", ".-.."}, {"M", "--"}, {"N", "-."}, {"O", "---"},
    {"P", ".--."}, {"Q", "--.-"}, {"R", ".-."}, {"S", "..."}, {"T", "-"},
    {"U", "..-"}, {"V", "...-"}, {"W", ".--"}, {"X", "-..-"}, {"Y", "-.--"},
    {"Z", "--.."}, {"0", "-----"}, {"1", ".----"}, {"2", "..---"},
    {"3", "...--"}, {"4", "....-"}, {"5", "....."}, {"6", "-...."},
    {"7", "--..."}, {"8", "---.."}, {"9", "----."},
    {" ", "/"} // Space
};

// Function to convert text to Morse code
void convertToMorse(const char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        char currentChar = toupper(text[i]);
        int found = 0;

        // Check for matching Morse code
        for (int j = 0; j < MORSE_CODE_COUNT; j++) {
            if (strcmp(morseCode[j][0], (char[]){currentChar, '\0'}) == 0) {
                printf("%s ", morseCode[j][1]);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("? "); // Unknown character
        }
    }
    printf("\n");
}

// Function to allocate memory for user input
char *getUserInput() {
    char *buffer = NULL;
    size_t bufsize = 0;

    printf("Enter the text to convert to Morse code: ");
    getline(&buffer, &bufsize, stdin);
    
    // Remove the newline character
    buffer[strcspn(buffer, "\n")] = 0;

    return buffer;
}

// Main function
int main() {
    printf("Welcome to the Text to Morse Code Converter!\n");
    printf("------------------------------------------------\n");

    // Get user input
    char *userInput = getUserInput();
    
    // Convert input to Morse code
    printf("Morse Code: ");
    convertToMorse(userInput);
    
    // Free allocated memory
    free(userInput);
    
    printf("Thank you for using the converter!\n");
    return 0;
}