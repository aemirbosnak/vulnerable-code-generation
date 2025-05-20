//GPT-4o-mini DATASET v1.0 Category: Text to Morse code conversion ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 256
#define MAX_MORSE_LENGTH 512

// Morse code representation for each letter and digit
const char *morse_code_mapping[36] = {
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

void to_upper_case(char *input) {
    for (size_t i = 0; input[i]; i++) {
        input[i] = toupper((unsigned char)input[i]);
    }
}

void encode_to_morse(const char *input, char *output) {
    output[0] = '\0'; // Initialize output string

    for (size_t i = 0; input[i]; i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            strcat(output, morse_code_mapping[input[i] - 'A']);
            strcat(output, " "); // Add space between letters
        } else if (input[i] >= '0' && input[i] <= '9') {
            strcat(output, morse_code_mapping[input[i] - '0' + 26]); // Adjust index for digits
            strcat(output, " "); // Add space between numbers
        } else if (input[i] == ' ') {
            strcat(output, "  "); // Two spaces for a gap between words
        }
    }
}

void get_input(char *input) {
    printf("Enter text to convert to Morse code (up to %d characters): ", MAX_INPUT_LENGTH - 1);
    fgets(input, MAX_INPUT_LENGTH, stdin);
    
    // Remove newline character from fgets input
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }
}

int main() {
    char *input_text = (char *)malloc(MAX_INPUT_LENGTH * sizeof(char));
    char *morse_output = (char *)malloc(MAX_MORSE_LENGTH * sizeof(char));

    if (input_text == NULL || morse_output == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    get_input(input_text);
    
    to_upper_case(input_text);
    encode_to_morse(input_text, morse_output);

    printf("Morse code: %s\n", morse_output);

    // Cleanup
    free(input_text);
    free(morse_output);

    return EXIT_SUCCESS;
}