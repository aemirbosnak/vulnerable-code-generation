//GPT-4o-mini DATASET v1.0 Category: Text to Morse code conversion ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Definition of Morse Code array
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

// Function to convert letter to uppercase
char toUpperCase(char c) {
    return toupper(c);
}

// Function to convert a single character to Morse code
void charToMorse(char c, char *output) {
    if (isalpha(c)) {
        int index = toUpperCase(c) - 'A';  // Convert A-Z to 0-25
        strcpy(output, morseCode[index]);  // Copy corresponding Morse code
    } else if (isdigit(c)) {
        // Digit conversion (0-9)
        int index = c - '0';  // Convert 0-9 to 0-9
        const char *morseDigits[] = {
            "-----", // 0
            ".----", // 1
            "..---", // 2
            "...--", // 3
            "....-", // 4
            ".....", // 5
            "-....", // 6
            "--...", // 7
            "---..", // 8
            "----."  // 9
        };
        strcpy(output, morseDigits[index]);
    } else if (c == ' ') {
        strcpy(output, "/"); // Use '/' to denote space
    } else {
        strcpy(output, "?"); // Unknown characters
    }
}

// Function to convert a string to Morse code
void stringToMorse(const char *input, char *output) {
    output[0] = '\0'; // Initialize output string
    char morseCharacter[7]; // To hold each Morse code character

    for (int i = 0; i < strlen(input); i++) {
        charToMorse(input[i], morseCharacter);
        strcat(output, morseCharacter); // Append Morse code
        if (input[i] != ' ') {
            strcat(output, " "); // Add space between letters
        }
    }
}

// Main function
int main() {
    char textInput[256];
    char morseOutput[1024];

    printf("=====================================\n");
    printf("         Morse Code Converter        \n");
    printf("=====================================\n");
    printf("Enter your text (Max 255 characters): ");
    fgets(textInput, sizeof(textInput), stdin);
    
    // Removing newline character from input
    textInput[strcspn(textInput, "\n")] = 0;

    // Convert input string to Morse code
    stringToMorse(textInput, morseOutput);

    // Display the Morse code
    printf("Morse Code Output:\n%s\n", morseOutput);
    
    return 0;
}