//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
static const char *morse_table[] = {
    ".-",    // A
    "-...", // B
    "-.-.", // C
    "-..",  // D
    ".",     // E
    "..-.", // F
    "--.",  // G
    "....", // H
    "..",   // I
    ".---", // J
    "-.-",  // K
    ".-.." // L
    // ... more
};

// Function to convert a character to Morse code
static char *character_to_morse(char character) {
    // Convert the character to uppercase
    character = toupper(character);

    // Check if the character is in the Morse code table
    if (character < 'A' || character > 'Z') {
        return NULL;
    }

    // Return the Morse code for the character
    return (char *)morse_table[character - 'A'];
}

// Function to convert a string to Morse code
static char *string_to_morse(const char *string) {
    // Allocate memory for the Morse code string
    char *morse_string = malloc(strlen(string) * 5);
    if (morse_string == NULL) {
        return NULL;
    }

    // Convert each character in the string to Morse code
    int i = 0;
    int j = 0;
    while (string[i] != '\0') {
        char *morse_character = character_to_morse(string[i]);
        if (morse_character != NULL) {
            strcpy(&morse_string[j], morse_character);
            j += strlen(morse_character);
            morse_string[j++] = ' ';
        }
        i++;
    }

    // Add a null terminator to the Morse code string
    morse_string[j] = '\0';

    // Return the Morse code string
    return morse_string;
}

// Main function
int main(int argc, char **argv) {
    // Check if the user provided a string to convert
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Convert the string to Morse code
    char *morse_string = string_to_morse(argv[1]);
    if (morse_string == NULL) {
        fprintf(stderr, "Error converting string to Morse code\n");
        return EXIT_FAILURE;
    }

    // Print the Morse code string
    printf("%s\n", morse_string);

    // Free the memory allocated for the Morse code string
    free(morse_string);

    return EXIT_SUCCESS;
}