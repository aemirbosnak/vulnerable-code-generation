//GPT-4o-mini DATASET v1.0 Category: Text to Morse code conversion ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MESSAGE_LENGTH 256

// Morse code representation for each letter and digit
const char *morseCode[] = {
    ".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",  "....", 
    "..",   ".---", "-.-",  ".-..", "--",   "-.",   "---",  ".--.", 
    "--.-", ".-.",  "...",  "-",    "..-",   "...-",  ".--",  "-..-", 
    "-.--", "--..", "-----", ".----", "..---", "...--", "....-", "---..", 
    "----."
};

// Function declarations
void printMorse(const char* message);
void convertToMorse(char c);
void printUsage();

int main(int argc, char *argv[]) {
    // Check if user provided a message
    if (argc != 2) {
        printUsage();
        return EXIT_FAILURE;
    }

    // Create a string to hold the input message
    char message[MAX_MESSAGE_LENGTH];
    strncpy(message, argv[1], MAX_MESSAGE_LENGTH - 1);
    message[MAX_MESSAGE_LENGTH - 1] = '\0'; // Ensure null termination

    // Convert the input message to Morse code
    printMorse(message);

    return EXIT_SUCCESS;
}

// Function to print the usage of the program
void printUsage() {
    printf("Usage: morse_converter <message>\n");
    printf("Converts the given message to Morse code.\n");
}

// Function to print the Morse code for the given message
void printMorse(const char* message) {
    printf("Morse code for: \"%s\"\n", message);
    for (int i = 0; message[i] != '\0'; i++) {
        char c = toupper(message[i]);
        
        if (c == ' ') {
            printf("  "); // Space in Morse code is a pause
            continue;
        }

        // Convert character to Morse code
        convertToMorse(c);
        printf(" "); // Space between letters
    }
    printf("\n");
}

// Function to convert character to Morse code
void convertToMorse(char c) {
    if (isalpha(c)) {
        int index = c - 'A'; // For A-Z
        printf("%s", morseCode[index]);
    } else if (isdigit(c)) {
        int index = c - '0' + 26; // For 0-9
        printf("%s", morseCode[index]);
    } else {
        printf("?"); // Unknown character
    }
}