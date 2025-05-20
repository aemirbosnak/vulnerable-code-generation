//GPT-4o-mini DATASET v1.0 Category: Text to Morse code conversion ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 256

typedef struct {
    char letter;
    const char *morse;
} MorseCode;

MorseCode morseTable[] = {
    {'A', ".-"},   {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},
    {'E', "."},    {'F', "..-."}, {'G', "--."},  {'H', "...."},
    {'I', ".."},   {'J', ".---"}, {'K', "-.-"},  {'L', ".-.."},
    {'M', "--"},   {'N', "-."},   {'O', "---"},  {'P', ".--."},
    {'Q', "--.-"}, {'R', ".-."},  {'S', "..."},  {'T', "-"},
    {'U', "..-"},  {'V', "...-"}, {'W', ".--"},  {'X', "-..-"},
    {'Y', "-.--"}, {'Z', "--.."},
    {'0', "-----"}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"},
    {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."},
    {'8', "---.."}, {'9', "----."},
    {' ', "/"}
};

void convertToMorse(const char *input, char *output) {
    output[0] = '\0'; // Initialize output string

    for (int i = 0; input[i] != '\0'; i++) {
        char upperChar = toupper(input[i]);
        for (int j = 0; j < sizeof(morseTable) / sizeof(morseTable[0]); j++) {
            if (morseTable[j].letter == upperChar) {
                strcat(output, morseTable[j].morse);
                strcat(output, " "); // Add space between Morse code letters
                break;
            }
        }
    }
}

void displayHelp() {
    printf("Morse Code Converter\n");
    printf("Usage: ./morse_converter \"<text>\"\n");
    printf("Converts text to Morse code.\n");
}

int main(int argc, char *argv[]) {
    // Check correct number of arguments
    if (argc != 2) {
        displayHelp();
        return 1;
    }

    // Allocate sufficient space for output
    char morseOutput[MAX_LENGTH];
    const char *inputText = argv[1];

    // Convert input text to Morse code
    convertToMorse(inputText, morseOutput);

    // Display the result
    printf("Input: '%s'\n", inputText);
    printf("Morse Code: '%s'\n", morseOutput);

    return 0;
}