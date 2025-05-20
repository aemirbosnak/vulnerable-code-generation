//GPT-4o-mini DATASET v1.0 Category: Text to Morse code conversion ; Style: careful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MESSAGE_LENGTH 1000

// Morse Code representations for the alphabet and numbers
const char *morseCodeDictionary[36] = {
    ".-",   // A
    "-...", // B
    "-.-.", // C
    "-..",  // D
    ".",    // E
    "..-.", // F
    "--.",  // G
    "....", // H
    "..",   // I
    ".---", // J
    "-.-",  // K
    ".-..", // L
    "--",   // M
    "-.",   // N
    "---",  // O
    ".--.", // P
    "--.-", // Q
    ".-.",  // R
    "...",  // S
    "-",    // T
    "..-",  // U
    "...-", // V
    ".--",  // W
    "-..-", // X
    "-.--", // Y
    "--..", // Z
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

char getMorseCode(char character) {
    if(character >= 'A' && character <= 'Z') {
        return morseCodeDictionary[character - 'A'];
    } else if(character >= '0' && character <= '9') {
        return morseCodeDictionary[26 + (character - '0')];
    } else if(character == ' ') {
        return "/"; // Represent space with '/'
    } else {
        return ""; // Unknown characters return empty
    }
}

void convertToMorseCode(char *input) {
    for(int i = 0; input[i] != '\0'; i++) {
        char upperChar = toupper(input[i]);
        const char *morseCode = getMorseCode(upperChar);
        
        if(morseCode[0] != '\0') {
            printf("%s ", morseCode);
        }
    }
    printf("\n");
}

void printUsage() {
    printf("Usage: morse_converter <message>\n");
    printf("Convert the provided message into Morse code.\n");
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printUsage();
        return 1;
    }

    // Joining all input arguments into a single string
    char input[MAX_MESSAGE_LENGTH];
    strcpy(input, argv[1]);
    for(int i = 2; i < argc; i++) {
        strcat(input, " ");
        strcat(input, argv[i]);
    }

    printf("Input Message: %s\n", input);
    printf("Morse Code: ");
    convertToMorseCode(input);
    
    return 0;
}