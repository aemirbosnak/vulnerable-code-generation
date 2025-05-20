//FormAI DATASET v1.0 Category: Modern Encryption ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message
char* encrypt(char* message, int key)
{
    int len = strlen(message);
    char* result = (char*) malloc(len * sizeof(char));

    // Loop through each character in the message
    for (int i = 0; i < len; i++) 
    {
        // Convert the character to its ASCII code
        int ascii = (int)message[i];

        // Apply the encryption formula
        int encrypted = (ascii + key) % 128;

        // Convert the encrypted code back to a character
        result[i] = (char)(encrypted);
    }

    return result;
}

// Function to decrypt the message
char* decrypt(char* message, int key)
{
    int len = strlen(message);
    char* result = (char*) malloc(len * sizeof(char));

    // Loop through each character in the message
    for (int i = 0; i < len; i++) 
    {
        // Convert the character to its ASCII code
        int ascii = (int)message[i];

        // Apply the decryption formula
        int decrypted = (ascii - key + 128) % 128;

        // Convert the decrypted code back to a character
        result[i] = (char)(decrypted);
    }

    return result;
}

int main() 
{
    // Encryption and decryption key
    int key = 5;

    // Message to be encrypted
    char* message = "This is a secret message";

    // Encrypt the message
    char* encrypted_message = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted_message);

    // Decrypt the message
    char* decrypted_message = decrypt(encrypted_message, key);
    printf("Decrypted message: %s\n", decrypted_message);

    // Free the memory used by the messages
    free(encrypted_message);
    free(decrypted_message);

    return 0;
}