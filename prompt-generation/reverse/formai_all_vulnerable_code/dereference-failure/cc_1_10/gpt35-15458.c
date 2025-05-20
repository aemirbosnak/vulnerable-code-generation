//FormAI DATASET v1.0 Category: Modern Encryption ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message using modern encryption algorithm
char* modernEncrypt(char* message, int numShifts) {
    int length = strlen(message);
    char* encryptedMessage = (char*) malloc(sizeof(char) * (length + 1));

    // Loop through each character in the message
    for (int i = 0; i < length; i++) {
        char character = message[i];
        int asciiVal = (int) character;

        // Shift the character by the given number of shifts
        for (int j = 0; j < numShifts; j++) {
            asciiVal++;

            // If the ascii value goes beyond the printable character range, loop back to the start
            if (asciiVal > 126) {
                asciiVal = 32;
            }
        }

        // Append the shifted character to the encrypted message
        encryptedMessage[i] = (char) asciiVal;
    }

    // Add null terminator to encrypted message
    encryptedMessage[length] = '\0';

    return encryptedMessage;
}

int main() {
    // Get message to encrypt and number of shifts from user
    char message[100];
    int numShifts;
    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);
    printf("Enter number of shifts: ");
    scanf("%d", &numShifts);

    // Encrypt message using modern encryption algorithm
    char* encryptedMessage = modernEncrypt(message, numShifts);

    // Output the original message and the encrypted message
    printf("Original message: %s", message);
    printf("Encrypted message: %s", encryptedMessage);

    // Remember to free dynamically allocated memory
    free(encryptedMessage);

    return 0;
}