//GPT-4o-mini DATASET v1.0 Category: Text to Morse code conversion ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 256
#define DOT '.'
#define DASH '-'
#define SPACE ' '

const char *morseCodeMap[36] = {
    "01", // A - 01
    "1000", // B - 1000
    "1010", // C - 1010
    "100", // D - 100
    "0", // E - 0
    "0010", // F - 0010
    "110", // G - 110
    "0000", // H - 0000
    "00", // I - 00
    "0111", // J - 0111
    "101", // K - 101
    "0100", // L - 0100
    "11", // M - 11
    "10", // N - 10
    "111", // O - 111
    "0110", // P - 0110
    "1001", // Q - 1001
    "000", // R - 000
    "00", // S - 00
    "1", // T - 1
    "001", // U - 001
    "0001", // V - 0001
    "011", // W - 011
    "1000", // X - 1000
    "1011", // Y - 1011
    "1100", // Z - 1100
    "00000", // 0 - 00000
    "10000", // 1 - 10000
    "11000", // 2 - 11000
    "11100", // 3 - 11100
    "11110", // 4 - 11110
    "11111", // 5 - 11111
    "01111", // 6 - 01111
    "00111", // 7 - 00111
    "00011", // 8 - 00011
    "00001" // 9 - 00001
};

const char *getMorseCode(char ch) {
    if (isalpha(ch)) {
        return morseCodeMap[toupper(ch) - 'A'];
    } else if (isdigit(ch)) {
        return morseCodeMap[ch - '0' + 26]; // Offset for numbers
    }
    return "";
}

void convertToMorse(const char *input, char *output) {
    char morseChar[10];
    output[0] = '\0'; // Initialize output buffer

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == SPACE) {
            strcat(output, " / "); // Separator for words
            continue;
        }

        const char *code = getMorseCode(input[i]);
        if (strlen(code) > 0) {
            strcat(output, code);
            strcat(output, " "); // Separator for letters
        }
    }
}

void printUsage() {
    printf("Usage: morse_converter <text_to_convert>\n");
    printf("Convert the provided text into Morse code.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printUsage();
        return EXIT_FAILURE;
    }

    char input[MAX_INPUT_LENGTH];
    char output[MAX_INPUT_LENGTH * 5]; // Allocate enough space for output

    // Read input text
    strncpy(input, argv[1], MAX_INPUT_LENGTH - 1);
    input[MAX_INPUT_LENGTH - 1] = '\0'; // Null-terminate to prevent overflow

    // Convert the text to Morse code
    convertToMorse(input, output);
    
    // Output the result
    printf("Input Text: %s\n", input);
    printf("Morse Code: %s\n", output);

    return EXIT_SUCCESS;
}