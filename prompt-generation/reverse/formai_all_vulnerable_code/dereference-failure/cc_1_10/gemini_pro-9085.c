//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char character;
    char *morseCode;
} MorseCodeMapping;

// Array of Morse code mappings
const MorseCodeMapping morseCodeMappings[] = {
    {'A', ".-"},
    {'B', "-..."},
    {'C', "-.-."},
    {'D', "-.."},
    {'E', "."},
    {'F', "..-."},
    {'G', "--."},
    {'H', "...."},
    {'I', ".."},
    {'J', ".---"},
    {'K', "-.-"},
    {'L', ".-.."},
    {'M', "--"},
    {'N', "-."},
    {'O', "---"},
    {'P', ".--."},
    {'Q', "--.-"},
    {'R', ".-."},
    {'S', "..."},
    {'T', "-"},
    {'U', "..-"},
    {'V', "...-"},
    {'W', ".--"},
    {'X', "-..-"},
    {'Y', "-.--"},
    {'Z', "--.."},
    {'0', "-----"},
    {'1', ".----"},
    {'2', "..---"},
    {'3', "...--"},
    {'4', "....-"},
    {'5', "....."},
    {'6', "-...."},
    {'7', "--..."},
    {'8', "---.."},
    {'9', "----."},
    {' ', " "}
};

// Function to convert a character to Morse code
char *characterToMorseCode(char character) {
    for (int i = 0; i < sizeof(morseCodeMappings) / sizeof(MorseCodeMapping); i++) {
        if (morseCodeMappings[i].character == character) {
            return morseCodeMappings[i].morseCode;
        }
    }
    return NULL;
}

// Function to convert a string to Morse code
char *stringToMorseCode(char *string) {
    char *morseCode = malloc(strlen(string) * 5);
    int index = 0;
    for (int i = 0; i < strlen(string); i++) {
        char *morseCodeCharacter = characterToMorseCode(string[i]);
        if (morseCodeCharacter != NULL) {
            strcpy(morseCode + index, morseCodeCharacter);
            index += strlen(morseCodeCharacter);
        }
    }
    return morseCode;
}

// Function to print Morse code
void printMorseCode(char *morseCode) {
    for (int i = 0; i < strlen(morseCode); i++) {
        if (morseCode[i] == '.') {
            printf("· ");
        } else if (morseCode[i] == '-') {
            printf("- ");
        } else {
            printf(" ");
        }
    }
    printf("\n");
}

// Main function
int main() {
    char *string = "Hello World";
    char *morseCode = stringToMorseCode(string);
    printMorseCode(morseCode);
    free(morseCode);
    return 0;
}