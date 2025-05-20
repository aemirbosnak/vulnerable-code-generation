//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: retro
// Encode and decode messages using a simple shift cipher.

#include <stdio.h>
#include <string.h>

// Global variables for the shift amount and message buffer.
int shift = 3;
char message[100];

// Function to encode a message.
void encode() {
    int i;
    // Iterate over each character in the message.
    for (i = 0; i < strlen(message); i++) {
        // Shift the character by the specified amount.
        message[i] += shift;
    }
}

// Function to decode a message.
void decode() {
    int i;
    // Iterate over each character in the message.
    for (i = 0; i < strlen(message); i++) {
        // Shift the character back by the specified amount.
        message[i] -= shift;
    }
}

// Function to print the help message.
void help() {
    printf("Usage: shift [-e|-d] message\n");
    printf("-e: Encode the message\n");
    printf("-d: Decode the message\n");
    printf("message: The message to be processed\n");
}

// Main function.
int main(int argc, char *argv[]) {
    // Check if the correct number of arguments was provided.
    if (argc != 3) {
        help();
        return 1;
    }

    // Parse the command line arguments.
    char *mode = argv[1];
    strcpy(message, argv[2]);

    // Check if the mode is valid.
    if (strcmp(mode, "-e") != 0 && strcmp(mode, "-d") != 0) {
        help();
        return 1;
    }

    // Process the message based on the mode.
    if (strcmp(mode, "-e") == 0) {
        encode();
    } else if (strcmp(mode, "-d") == 0) {
        decode();
    }

    // Print the encoded or decoded message.
    printf("%s\n", message);

    return 0;
}