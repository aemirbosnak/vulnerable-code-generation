//GPT-4o-mini DATASET v1.0 Category: Text to Morse code conversion ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_CODE_LENGTH 256

// Structure to hold Morse code for each character
typedef struct {
    char character;
    const char *morse;
} MorseCode;

// Morse code mappings
MorseCode morseCodeMap[] = {
    {'A', ".-"},    {'B', "-..."},  {'C', "-.-."},  {'D', "-.."},
    {'E', "."},     {'F', "..-."},  {'G', "--."},   {'H', "...."},
    {'I', ".."},    {'J', ".---"},  {'K', "-.-"},   {'L', ".-.."},
    {'M', "--"},    {'N', "-."},    {'O', "---"},   {'P', ".--."},
    {'Q', "--.-"},  {'R', ".-."},   {'S', "..."},   {'T', "-"},
    {'U', "..-"},   {'V', "...-"},  {'W', ".--"},   {'X', "-..-"},
    {'Y', "-.--"},  {'Z', "--.."},
    {'0', "-----"}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"},
    {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."},
    {'8', "---.."}, {'9', "----."},
    {' ', "/"},
    {'.', ".-.-.-"}, {',', "--..--"}, {'?', "..--.."}, {'\'', ".----."},
    {'!', "-.-.--"}, {'/', "-..-."}, {'(', "-.--."}, {'-', "-....-"},
    {')', "-.--.-"}, {'&', ".-..."}, {':', "---..."}, {';', "-.-.-."},
    {'=', "-...-"}, {'+', ".-.-."}, {'_', "..--.-"}, {'"', ".-..-."},
    {'$', "...-..-"}, {'@', ".--.-."}
};

// Function declarations
void initMorseCodeLookup(MorseCode* map, int size);
const char* charToMorse(char input);
void convertToMorse(const char* input, char* output);
void printUsage(const char* progName);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printUsage(argv[0]);
        return EXIT_FAILURE;
    }

    // Prepare the input and output buffers
    const char* input = argv[1];
    char output[MAX_CODE_LENGTH];

    // Convert input text to Morse code
    convertToMorse(input, output);
    printf("Original: %s\nMorse: %s\n", input, output);

    return EXIT_SUCCESS;
}

// Initialize the Morse code lookup table
void initMorseCodeLookup(MorseCode* map, int size) {
    for (int i = 0; i < size; ++i) {
        map[i].character = toupper(map[i].character);
    }
}

// Convert a single character to Morse code
const char* charToMorse(char input) {
    input = toupper(input);
    for (int i = 0; i < sizeof(morseCodeMap) / sizeof(morseCodeMap[0]); ++i) {
        if (morseCodeMap[i].character == input) {
            return morseCodeMap[i].morse;
        }
    }
    return " ";  // Return space for unsupported characters
}

// Convert a given string into Morse code
void convertToMorse(const char* input, char* output) {
    output[0] = '\0';  // Initialize output as empty string

    for (size_t i = 0; i < strlen(input); ++i) {
        const char* morse = charToMorse(input[i]);
        strcat(output, morse);
        if (input[i + 1] != '\0') {
            strcat(output, " ");  // Add a space for separation except for the last character
        }
    }
}

// Print usage information
void printUsage(const char* progName) {
    printf("Usage: %s <text_to_convert>\n", progName);
    printf("Converts the provided text into Morse code. Supported characters include:\n");
    printf("A-Z, 0-9, and common punctuation such as . , ? ' ! / ( ) - & : ; = + _ \" $ @\n");
}