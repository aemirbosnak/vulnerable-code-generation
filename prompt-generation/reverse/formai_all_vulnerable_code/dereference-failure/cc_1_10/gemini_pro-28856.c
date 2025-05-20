//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to encode a string using Claude Shannon's method
char *encodeShannon(char *input) {
    // Calculate the length of the input string
    int length = strlen(input);

    // Create an output string twice the length of the input string
    char *output = malloc(2 * length + 1);

    // Encode each character in the input string
    for (int i = 0; i < length; i++) {
        // Get the current character
        char c = input[i];

        // Convert the character to its binary representation
        char binary[8];
        for (int j = 0; j < 8; j++) {
            binary[j] = (c & (1 << (7 - j))) ? '1' : '0';
        }

        // Add the binary representation to the output string
        strcat(output, binary);
    }

    // Add a null terminator to the output string
    output[2 * length] = '\0';

    // Return the encoded string
    return output;
}

// Function to decode a string using Claude Shannon's method
char *decodeShannon(char *input) {
    // Calculate the length of the input string
    int length = strlen(input);

    // Create an output string half the length of the input string
    char *output = malloc(length / 2 + 1);

    // Decode each 8-bit binary sequence in the input string
    for (int i = 0; i < length; i += 8) {
        // Get the current 8-bit binary sequence
        char binary[8];
        for (int j = 0; j < 8; j++) {
            binary[j] = input[i + j];
        }

        // Convert the binary sequence to a character
        char c = 0;
        for (int j = 0; j < 8; j++) {
            c |= (binary[j] == '1') << (7 - j);
        }

        // Add the character to the output string
        strncat(output, &c, 1);
    }

    // Add a null terminator to the output string
    output[length / 2] = '\0';

    // Return the decoded string
    return output;
}

// Main function
int main() {
    // Get the input string from the user
    char input[100];
    printf("Enter a string to be encoded: ");
    gets(input);

    // Encode the string using Claude Shannon's method
    char *encoded = encodeShannon(input);

    // Print the encoded string
    printf("Encoded string: %s\n", encoded);

    // Decode the string using Claude Shannon's method
    char *decoded = decodeShannon(encoded);

    // Print the decoded string
    printf("Decoded string: %s\n", decoded);

    // Free the allocated memory
    free(encoded);
    free(decoded);

    return 0;
}