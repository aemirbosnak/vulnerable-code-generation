//Falcon-180B DATASET v1.0 Category: Encryption ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

// Function to encrypt the message using the key
void encrypt(char message[], char key[]) {
    int i, j;
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        // Convert message to uppercase
        message[i] = toupper(message[i]);
        // Encrypt the message using the key
        if (isalpha(message[i])) {
            message[i] = ((message[i] - 'A' + key[j] - 'A') % 26) + 'A';
            j = (j + 1) % strlen(key);
        }
    }
}

// Function to decrypt the message using the key
void decrypt(char message[], char key[]) {
    int i, j;
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        // Convert message to uppercase
        message[i] = toupper(message[i]);
        // Decrypt the message using the key
        if (isalpha(message[i])) {
            message[i] = ((message[i] - 'A' - key[j] + 26) % 26) + 'A';
            j = (j + 1) % strlen(key);
        }
    }
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    // Get the message from the user
    printf("Enter the message to be encrypted/decrypted: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    // Remove the newline character from the message
    message[strcspn(message, "\n")] = '\0';

    // Get the key from the user
    printf("Enter the key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);

    // Remove the newline character from the key
    key[strcspn(key, "\n")] = '\0';

    // Encrypt the message using the key
    encrypt(message, key);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the encrypted message using the key
    decrypt(message, key);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}