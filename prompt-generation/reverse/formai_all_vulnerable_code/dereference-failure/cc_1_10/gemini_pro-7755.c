//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code dictionary
const char *morseCodeDictionary[] = {
    ".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",  "....", "..",   ".---",
    "-.-",  ".-..", "--",   "-.",   "...",  "-",    ".----", "..---", "...--", "....-",
    ".....", "-....", "--...", "---..", "----.", "-----", ".-.-.-", "--..--", ".-.-.",
    "-....-", "-..-.", "-.--.", "-.--.-", ".-...", "---",   ".--.",  "--.-.", ".-..",
    "--",   "-",     ".-",    "-..",   "--",   "---",   ".----", "..----", "...---",
    "....--", ".....-", "-....-", "--...-", "---...", "---.--", "----..", "-----.",
    "-.--.-", ".-.-.-", "--..--", "..--..", ".-..-.", ".----.", "-....-", "-.-.--",
    "-..--.", "-.--.-", ".-....", "..-...", "...-..-", "....-.", ".....-", "---..."
};

// Convert a character to Morse code
char *convertCharacterToMorseCode(char character) {
    if (character >= 'a' && character <= 'z') {
        character = character - 32;
    }

    int index = character - 'A';

    if (index < 0 || index >= 26) {
        return NULL;
    }

    return (char *)morseCodeDictionary[index];
}

// Convert a string to Morse code
char *convertStringToMorseCode(char *string) {
    char *morseCode = malloc(strlen(string) * 5 + 1);

    int i;
    int index = 0;

    for (i = 0; i < strlen(string); i++) {
        char *characterMorseCode = convertCharacterToMorseCode(string[i]);

        if (characterMorseCode != NULL) {
            strcpy(&morseCode[index], characterMorseCode);
            index += strlen(characterMorseCode);
            morseCode[index++] = ' ';
        }
    }

    morseCode[index] = '\0';

    return morseCode;
}

// Print Morse code
void printMorseCode(char *morseCode) {
    printf("Morse code: %s\n", morseCode);
}

int main() {
    char *string = "HELLO WORLD";

    char *morseCode = convertStringToMorseCode(string);

    printMorseCode(morseCode);

    free(morseCode);

    return 0;
}