//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare a function to perform the necessary string manipulation.
char *decode_message(char *message, int key);

// Define the main function.
int main() {
    // Declare a character array to store the message.
    char message[] = "The quick brown fox jumps over the lazy dog.";

    // Declare a variable to store the key.
    int key = 3;

    // Decode the message using the specified key.
    char *decoded_message = decode_message(message, key);

    // Print the original and decoded messages.
    printf("Original message: %s\n", message);
    printf("Decoded message: %s\n", decoded_message);

    // Free the allocated memory for the decoded message.
    free(decoded_message);

    return 0;
}

// Define the function to perform the string manipulation.
char *decode_message(char *message, int key) {
    // Calculate the length of the message.
    int length = strlen(message);

    // Allocate memory for the decoded message.
    char *decoded_message = malloc(length + 1);

    // Decode each character in the message.
    for (int i = 0; i < length; i++) {
        char character = message[i];

        // Check if the character is a letter.
        if (isalpha(character)) {
            // Shift the character backward by the specified key.
            character -= key;

            // Wrap the character around if it goes below 'a' or 'A'.
            if (character < 'a') {
                character += 26;
            } else if (character < 'A') {
                character += 26;
            }
        }

        // Store the decoded character in the decoded message.
        decoded_message[i] = character;
    }

    // Add the null-terminator to the decoded message.
    decoded_message[length] = '\0';

    // Return the decoded message.
    return decoded_message;
}