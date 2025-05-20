//Falcon-180B DATASET v1.0 Category: Encryption ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

// Function to encrypt the message using the given key
void encrypt(char *message, char *key) {
    int i, j, key_index;
    char encrypted_message[MAX_MESSAGE_LENGTH];

    // Initialize the key index to 0
    key_index = 0;

    // Loop through each character in the message
    for (i = 0; message[i]!= '\0'; i++) {
        // Convert the character to uppercase
        message[i] = toupper(message[i]);

        // Get the ASCII value of the character
        int ascii_value = (int) message[i];

        // Get the corresponding character from the key
        char key_character = key[key_index % strlen(key)];

        // Encrypt the character using the key character
        char encrypted_character = (ascii_value + (int) key_character - 65) % 26 + 65;

        // Add the encrypted character to the encrypted message
        encrypted_message[i] = encrypted_character;

        // Increment the key index
        key_index++;
    }

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt the message using the given key
void decrypt(char *message, char *key) {
    int i, j, key_index;
    char decrypted_message[MAX_MESSAGE_LENGTH];

    // Initialize the key index to 0
    key_index = 0;

    // Loop through each character in the message
    for (i = 0; message[i]!= '\0'; i++) {
        // Convert the character to uppercase
        message[i] = toupper(message[i]);

        // Get the ASCII value of the character
        int ascii_value = (int) message[i];

        // Get the corresponding character from the key
        char key_character = key[key_index % strlen(key)];

        // Decrypt the character using the key character
        char decrypted_character = (ascii_value - (int) key_character + 26) % 26 + 65;

        // Add the decrypted character to the decrypted message
        decrypted_message[i] = decrypted_character;

        // Increment the key index
        key_index++;
    }

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    // Prompt the user to enter the message
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);

    // Prompt the user to enter the key
    printf("Enter the encryption key: ");
    scanf("%s", key);

    // Encrypt the message using the given key
    encrypt(message, key);

    // Decrypt the encrypted message using the given key
    decrypt(message, key);

    return 0;
}