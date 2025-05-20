//GPT-4o-mini DATASET v1.0 Category: Text to Morse code conversion ; Style: Alan Turing
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100
#define MAX_MORSE_LENGTH 500

// Morse code mapping for alphabets and numbers
const char *morseCode[] = {
    ".-",   "-...", "-.-.", "-..",  ".",   "..-.", "--.",  "....",
    "..",   ".---", "-.-",  ".-..", "--",  "-.",   "---",  ".--.", 
    "--.-", ".-.",  "...",  "-",    "..-",  "...-",  ".--",  "-..-",
    "-.--", "--..", "-----", ".----", "..---", "...--", "....-", "...-.",
    "....", ".-" 
};

// Corresponding characters for the Morse code mapping
const char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

void convertToMorse(const char *input, char *output) {
    memset(output, 0, MAX_MORSE_LENGTH);
    int length = strlen(input);
    for (int i = 0; i < length; i++) {
        char ch = toupper(input[i]);
        if (ch >= 'A' && ch <= 'Z') {
            strcat(output, morseCode[ch - 'A']);
        } else if (ch >= '0' && ch <= '9') {
            strcat(output, morseCode[26 + (ch - '0')]);
        } else if (ch == ' ') {
            strcat(output, " / "); // Separator for words
        }
        strcat(output, " "); // Space between letters
    }
}

void getInput(char *input) {
    printf("Enter text to convert to Morse code (max 100 characters): ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0; // Remove trailing newline
}

void displayMorseCode(const char *morse) {
    printf("Morse Code Representation:\n%s\n", morse);
}

int main() {
    char input[MAX_INPUT_LENGTH];
    char morse[MAX_MORSE_LENGTH];

    // Get user input
    getInput(input);

    // Convert to Morse code
    convertToMorse(input, morse);

    // Display Morse code
    displayMorseCode(morse);

    return 0;
}