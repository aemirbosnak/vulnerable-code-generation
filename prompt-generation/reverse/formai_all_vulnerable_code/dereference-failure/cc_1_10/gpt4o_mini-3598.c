//GPT-4o-mini DATASET v1.0 Category: Text to Morse code conversion ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Morse code representation for A-Z and 0-9
const char *morseCode[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-",
    ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-",
    ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-",
    ".....", "-....", "--...", "---..", "----."
};

// Function to convert character to Morse code
const char *charToMorse(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return morseCode[ch - 'A'];
    } else if (ch >= '0' && ch <= '9') {
        return morseCode[ch - '0' + 26];
    } else if (ch == ' ') {
        return " ";
    } else {
        return ""; // Return empty string for unsupported characters
    }
}

// Function to convert a string to Morse code
void stringToMorse(const char *input, char *output) {
    int index = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        const char *morse = charToMorse(input[i]);
        if (morse[0] != '\0') {
            strcpy(&output[index], morse);
            index += strlen(morse);
            output[index++] = ' '; // space between characters
        }
    }
    output[index - 1] = '\0'; // Replace last space with null terminator
}

// Function to print Morse code
void printMorse(const char *morseCode) {
    printf("Morse Code: %s\n", morseCode);
}

// Main function
int main() {
    char input[256];
    char output[1024];

    printf("Enter a message to convert to Morse code (A-Z, 0-9): ");
    fgets(input, sizeof(input), stdin);
    
    // Convert input to uppercase
    for (int i = 0; input[i]; i++) {
        input[i] = toupper(input[i]);
    }

    // Convert to Morse code
    stringToMorse(input, output);

    // Print the result
    printMorse(output);

    return 0;
}