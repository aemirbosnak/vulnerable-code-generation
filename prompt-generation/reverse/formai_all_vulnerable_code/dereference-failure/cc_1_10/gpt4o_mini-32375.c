//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 1024
#define SHIFT_AMOUNT 3

void encrypt(char *plainText, char *encryptedText) {
    int i = 0;
    while (plainText[i] != '\0' && i < MAX_MESSAGE_LENGTH) {
        // Encrypt only alphabetic characters
        if (plainText[i] >= 'A' && plainText[i] <= 'Z') {
            encryptedText[i] = ((plainText[i] - 'A' + SHIFT_AMOUNT) % 26) + 'A';
        } else if (plainText[i] >= 'a' && plainText[i] <= 'z') {
            encryptedText[i] = ((plainText[i] - 'a' + SHIFT_AMOUNT) % 26) + 'a';
        } else {
            encryptedText[i] = plainText[i]; // Non-alphabetic characters remain unchanged
        }
        i++;
    }
    encryptedText[i] = '\0'; // Null-terminate the string
}

void decrypt(char *encryptedText, char *decryptedText) {
    int i = 0;
    while (encryptedText[i] != '\0' && i < MAX_MESSAGE_LENGTH) {
        // Decrypt only alphabetic characters
        if (encryptedText[i] >= 'A' && encryptedText[i] <= 'Z') {
            decryptedText[i] = ((encryptedText[i] - 'A' - SHIFT_AMOUNT + 26) % 26) + 'A';
        } else if (encryptedText[i] >= 'a' && encryptedText[i] <= 'z') {
            decryptedText[i] = ((encryptedText[i] - 'a' - SHIFT_AMOUNT + 26) % 26) + 'a';
        } else {
            decryptedText[i] = encryptedText[i]; // Non-alphabetic characters remain unchanged
        }
        i++;
    }
    decryptedText[i] = '\0'; // Null-terminate the string
}

void printUsage() {
    printf("C Encryption Program\n");
    printf("Usage: ./encryption <encrypt|decrypt> <message>\n");
    printf("Example: ./encryption encrypt \"Hello, World!\"\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printUsage();
        return 1; // Exit with an error code
    }

    char *operation = argv[1];
    char *message = argv[2];
    char encryptedText[MAX_MESSAGE_LENGTH];
    char decryptedText[MAX_MESSAGE_LENGTH];

    // Determine operation
    if (strcmp(operation, "encrypt") == 0) {
        encrypt(message, encryptedText);
        printf("Encrypted Message: %s\n", encryptedText);
    } else if (strcmp(operation, "decrypt") == 0) {
        decrypt(message, decryptedText);
        printf("Decrypted Message: %s\n", decryptedText);
    } else {
        printUsage();
        return 1; // Exit with an error code
    }

    return 0; // Successful completion
}