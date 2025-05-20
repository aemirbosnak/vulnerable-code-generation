//GPT-4o-mini DATASET v1.0 Category: Text to Morse code conversion ; Style: distributed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Morse Code Representation
const char *morseCode[] = {
    ".-",    // A
    "-...",  // B
    "-.-.",  // C
    "-..",   // D
    ".",     // E
    "..-.",  // F
    "--.",   // G
    "....",  // H
    "..",    // I
    ".---",  // J
    "-.-",   // K
    ".-..",  // L
    "--",    // M
    "-.",    // N
    "---",   // O
    ".--.",  // P
    "--.-",  // Q
    ".-.",   // R
    "...",   // S
    "-",     // T
    "..-",   // U
    "...-",  // V
    ".--",   // W
    "-..-",  // X
    "-.--",  // Y
    "--.."   // Z
};

// Function to get Morse Code for given character
const char* getMorseCode(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return morseCode[ch - 'A'];
    } 
    else if (ch >= 'a' && ch <= 'z') {
        return morseCode[ch - 'a'];
    } 
    else if (ch == ' ') {
        return " "; // Return space for space character
    }
    return ""; // Return empty for unsupported characters
}

// Function to convert given text to Morse Code
void textToMorse(const char *text, char *output) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        const char *morse = getMorseCode(text[i]);
        if (*morse != '\0') {
            strcat(output, morse);
            strcat(output, " "); // Add space between codes
        }
    }
    output[strlen(output) - 1] = '\0'; // Remove the last space
}

// Main function
int main() {
    char text[256]; // Input text buffer
    char morseOutput[1024] = ""; // Output Morse code buffer

    printf("Enter text to convert to Morse code (A-Z, a-z, space): ");
    fgets(text, sizeof(text), stdin);

    // Remove newline character from input if exists
    text[strcspn(text, "\n")] = 0;

    // Convert text to Morse code
    textToMorse(text, morseOutput);

    // Print the Morse code output
    printf("Morse Code: %s\n", morseOutput);

    return 0;
}