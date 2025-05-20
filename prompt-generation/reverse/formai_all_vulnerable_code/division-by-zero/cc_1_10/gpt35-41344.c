//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defines the maximum length of the public key
#define MAX_KEY_LENGTH 512

// Defines the maximum length of messages that can be encrypted
#define MAX_MESSAGE_LENGTH 256

// Define our public key struct
typedef struct PublicKey
{
    unsigned long long e, n; // Two large prime numbers (e and n) that are used in encryption
} PublicKey;

// Function to encrypt a message with the public key
void encrypt_message(char* message, PublicKey* public_key)
{
    // Calculate the length of the message
    size_t message_length = strlen(message);

    // Create a buffer to hold the encrypted message
    char encrypted_message[MAX_MESSAGE_LENGTH];

    // Loop through each character in the message
    for (size_t i = 0; i < message_length; i++)
    {
        // Convert the character to its ASCII value
        unsigned char character = message[i];

        // Encrypt the ASCII value using the provided public key
        unsigned long long encrypted_character = 1;
        for (unsigned long long j = 0; j < public_key->e; j++)
        {
            encrypted_character = (encrypted_character * character) % public_key->n;
        }

        // Add the encrypted character to the encrypted message buffer
        sprintf(&encrypted_message[strlen(encrypted_message)], "%llu", encrypted_character);
    }

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);
}

int main()
{
    // Initialize our public key
    PublicKey public_key;

    // Prompt the user to enter the public key values
    char key_input[MAX_KEY_LENGTH];
    printf("Enter the public key values (e,n): ");
    fgets(key_input, MAX_KEY_LENGTH, stdin);

    // Parse the public key values from the input
    char* token = strtok(key_input, ",");
    public_key.e = strtoull(token, NULL, 10);
    token = strtok(NULL, ",");
    public_key.n = strtoull(token, NULL, 10);

    // Prompt the user to enter a message to encrypt
    char message[MAX_MESSAGE_LENGTH];
    printf("Enter the message you would like to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    // Encrypt the message using the public key
    encrypt_message(message, &public_key);

    return 0;
}