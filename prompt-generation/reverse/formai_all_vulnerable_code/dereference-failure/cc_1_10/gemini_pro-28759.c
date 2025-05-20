//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_MORSE_CODE_LENGTH 4096

// Morse code table
const char *morse_code_table[] = {
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
    "--..",  // Z
    "-----", // 0
    ".----", // 1
    "..---", // 2
    "...--", // 3
    "....-", // 4
    ".....", // 5
    "-....", // 6
    "--...", // 7
    "---..", // 8
    "----.", // 9
    " ",     // space
};

// Function to convert a character to Morse code
char *char_to_morse_code(char character) {
    // Convert the character to uppercase
    character = toupper(character);

    // Check if the character is a letter
    if (character >= 'A' && character <= 'Z') {
        // Return the Morse code for the letter
        return morse_code_table[character - 'A'];
    }

    // Check if the character is a number
    if (character >= '0' && character <= '9') {
        // Return the Morse code for the number
        return morse_code_table[character - '0' + 26];
    }

    // Check if the character is a space
    if (character == ' ') {
        // Return the Morse code for a space
        return morse_code_table[36];
    }

    // Return an empty string for any other character
    return "";
}

// Function to convert a string to Morse code
char *string_to_morse_code(char *string) {
    // Allocate memory for the Morse code string
    char *morse_code = malloc(MAX_MORSE_CODE_LENGTH);

    // Initialize the Morse code string
    morse_code[0] = '\0';

    // Loop through each character in the string
    for (int i = 0; i < strlen(string); i++) {
        // Convert the character to Morse code
        char *morse_code_character = char_to_morse_code(string[i]);

        // Append the Morse code for the character to the Morse code string
        strcat(morse_code, morse_code_character);

        // Append a space to the Morse code string
        strcat(morse_code, " ");
    }

    // Return the Morse code string
    return morse_code;
}

// Main function
int main() {
    // Get the input string from the user
    char input_string[MAX_INPUT_LENGTH];
    printf("Enter a string to convert to Morse code: ");
    fgets(input_string, MAX_INPUT_LENGTH, stdin);

    // Convert the string to Morse code
    char *morse_code = string_to_morse_code(input_string);

    // Print the Morse code
    printf("Morse code: %s\n", morse_code);

    // Free the memory allocated for the Morse code string
    free(morse_code);

    return 0;
}