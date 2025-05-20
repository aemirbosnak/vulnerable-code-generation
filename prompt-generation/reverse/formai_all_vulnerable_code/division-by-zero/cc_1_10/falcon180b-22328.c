//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to encrypt the message using a key
void encrypt(char *message, char *key)
{
    int i, j;
    char encrypted_message[100];

    // Initialize the encrypted message to blank
    memset(encrypted_message, 0, sizeof(encrypted_message));

    // Loop through each character in the message
    for (i = 0; message[i]!= '\0'; i++)
    {
        // Get the ASCII value of the character
        int ascii_value = message[i];

        // Shift the ASCII value by the key
        int shifted_ascii_value = ascii_value + key[i % strlen(key)];

        // Convert the shifted ASCII value back to a character
        char encrypted_character = shifted_ascii_value;

        // Add the encrypted character to the encrypted message
        strcat(encrypted_message, &encrypted_character);
    }

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt the message using the same key
void decrypt(char *encrypted_message, char *key)
{
    int i, j;
    char decrypted_message[100];

    // Initialize the decrypted message to blank
    memset(decrypted_message, 0, sizeof(decrypted_message));

    // Loop through each character in the encrypted message
    for (i = 0; encrypted_message[i]!= '\0'; i++)
    {
        // Get the ASCII value of the character
        int ascii_value = encrypted_message[i];

        // Shift the ASCII value back by the key
        int shifted_ascii_value = ascii_value - key[i % strlen(key)];

        // Convert the shifted ASCII value back to a character
        char decrypted_character = shifted_ascii_value;

        // Add the decrypted character to the decrypted message
        strcat(decrypted_message, &decrypted_character);
    }

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);
}

// Main function
int main()
{
    char message[100];
    char key[100];

    // Get the message from the user
    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    // Get the key from the user
    printf("Enter a key to encrypt the message: ");
    scanf("%s", key);

    // Encrypt the message using the key
    encrypt(message, key);

    // Decrypt the encrypted message using the same key
    decrypt(message, key);

    return 0;
}