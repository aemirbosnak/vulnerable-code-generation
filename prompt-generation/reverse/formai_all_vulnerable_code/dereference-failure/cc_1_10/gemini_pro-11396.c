//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: thoughtful
/*
* Encrypted Alien Language Translator
* Decodes a series of encrypted messages using a custom alien language decoder ring.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the alien language decoder ring.
const char *ALIEN_DECODER_RING = "NOPQRSTUVWXYZABCDEFGHIJKLM";

// Function to decode a single alien word.
char *decodeWord(const char *word) {
    // Allocate memory to store the decoded word.
    char *decodedWord = (char *)malloc(strlen(word) + 1);
    if (decodedWord == NULL) {
        perror("Error allocating memory for decoded word");
        exit(1);
    }

    // Decode the word character by character.
    int i;
    for (i = 0; i < strlen(word); i++) {
        char c = word[i];
        int index = strchr(ALIEN_DECODER_RING, c) - ALIEN_DECODER_RING;
        if (index < 0 || index >= strlen(ALIEN_DECODER_RING)) {
            // Character not found in decoder ring.
            decodedWord[i] = c;
        } else {
            // Decode the character.
            decodedWord[i] = ALIEN_DECODER_RING[index];
        }
    }

    // Null-terminate the decoded word.
    decodedWord[i] = '\0';

    // Return the decoded word.
    return decodedWord;
}

// Function to decode a message.
char *decodeMessage(const char *message) {
    // Allocate memory to store the decoded message.
    char *decodedMessage = (char *)malloc(strlen(message) + 1);
    if (decodedMessage == NULL) {
        perror("Error allocating memory for decoded message");
        exit(1);
    }

    // Decode the message word by word.
    int i = 0;
    int j = 0;
    while (i < strlen(message)) {
        // Find the end of the current word.
        while (message[i] != ' ' && i < strlen(message)) {
            i++;
        }

        // Decode the current word.
        char *decodedWord = decodeWord(message + j);

        // Copy the decoded word to the decoded message.
        strcat(decodedMessage, decodedWord);

        // Free the memory allocated for the decoded word.
        free(decodedWord);

        // Skip the white space between words.
        while (message[i] == ' ' && i < strlen(message)) {
            i++;
        }

        // Increment the index of the decoded message.
        j = i;
    }

    // Null-terminate the decoded message.
    decodedMessage[j] = '\0';

    // Return the decoded message.
    return decodedMessage;
}

// Main function.
int main() {
    // Get the encrypted message from the user.
    printf("Enter the encrypted message: ");
    char message[1024];
    fgets(message, sizeof(message), stdin);

    // Decode the message.
    char *decodedMessage = decodeMessage(message);

    // Print the decoded message.
    printf("The decoded message is: %s\n", decodedMessage);

    // Free the memory allocated for the decoded message.
    free(decodedMessage);

    return 0;
}