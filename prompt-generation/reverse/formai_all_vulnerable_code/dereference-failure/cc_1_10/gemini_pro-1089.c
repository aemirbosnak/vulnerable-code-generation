//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Morse code table
typedef struct {
    char character;
    char *morseCode;
} MorseCodeEntry;

MorseCodeEntry morseCodeTable[] = {
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

// Define the size of the Morse code table
#define MORSE_CODE_TABLE_SIZE (sizeof(morseCodeTable) / sizeof(MorseCodeEntry))

// Function to convert a character to Morse code
char *charToMorseCode(char character) {
    for (int i = 0; i < MORSE_CODE_TABLE_SIZE; i++) {
        if (morseCodeTable[i].character == character) {
            return morseCodeTable[i].morseCode;
        }
    }
    return NULL;
}

// Function to convert a string to Morse code
char *stringToMorseCode(char *string) {
    char *morseCode = malloc(strlen(string) * 5);
    int index = 0;
    for (int i = 0; i < strlen(string); i++) {
        char *characterMorseCode = charToMorseCode(string[i]);
        if (characterMorseCode != NULL) {
            strcpy(morseCode + index, characterMorseCode);
            index += strlen(characterMorseCode);
            morseCode[index++] = ' ';
        }
    }
    return morseCode;
}

// Function to print the Morse code
void printMorseCode(char *morseCode) {
    printf("%s\n", morseCode);
}

// Main function
int main() {
    char *string = "HELLO WORLD";
    char *morseCode = stringToMorseCode(string);
    printMorseCode(morseCode);
    free(morseCode);
    return 0;
}