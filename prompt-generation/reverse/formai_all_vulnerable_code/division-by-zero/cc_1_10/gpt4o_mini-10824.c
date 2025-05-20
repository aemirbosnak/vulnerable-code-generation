//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Prototypes
void encryptDecrypt(char *input, char *output, char *key);
void takeUserInput(char *buffer, size_t size);

int main() {
    char input[256]; // Buffer for user input
    char output[256]; // Buffer for output (to store encrypted/decrypted text)
    char key[256]; // Key for encryption
    char choice;

    printf("Welcome to the Energetic Encryption Program!\n");
    printf("===========================================\n");

    // Asking user for an encryption key
    printf("Please enter your encryption key (max 255 characters): ");
    takeUserInput(key, sizeof(key));

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Encrypt a message\n");
        printf("2. Decrypt a message\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        choice = getchar();
        getchar(); // Clear the newline character from input buffer

        switch (choice) {
            case '1':
                printf("Enter the message to encrypt: ");
                takeUserInput(input, sizeof(input));
                encryptDecrypt(input, output, key);
                printf("Encrypted Message: %s\n", output);
                break;

            case '2':
                printf("Enter the message to decrypt: ");
                takeUserInput(input, sizeof(input));
                encryptDecrypt(input, output, key);
                printf("Decrypted Message: %s\n", output);
                break;

            case '3':
                printf("Exiting... Stay secure!\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to encrypt or decrypt a message using XOR
void encryptDecrypt(char *input, char *output, char *key) {
    size_t keyLength = strlen(key);
    size_t inputLength = strlen(input);

    for (size_t i = 0; i < inputLength; i++) {
        output[i] = input[i] ^ key[i % keyLength]; // XOR operation
    }
    output[inputLength] = '\0'; // Null terminate the output
}

// Utility function to safely take user input
void takeUserInput(char *buffer, size_t size) {
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove trailing newline
}