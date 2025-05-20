//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the alphabet for our cipher
#define ALPHABET_SIZE 26
char ALPHABET[ALPHABET_SIZE] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

// Function to encrypt a message using the Vigenere cipher
char* vigenere_encrypt(char* message, char* key) {
    int message_len = strlen(message);
    int key_len = strlen(key);
    char* encrypted_message = malloc(message_len + 1); // +1 for null terminator

    // Loop through each character in the message
    for (int i = 0; i < message_len; i++) {
        // Get the index of the current character in the alphabet
        int message_char_index = strchr(ALPHABET, message[i]) - ALPHABET;

        // Get the index of the current key character in the alphabet
        int key_char_index = strchr(ALPHABET, key[i % key_len]) - ALPHABET;

        // Encrypt the character using the Vigenere cipher
        int encrypted_char_index = (message_char_index + key_char_index) % ALPHABET_SIZE;
        encrypted_message[i] = ALPHABET[encrypted_char_index];
    }

    // Add a null terminator to the end of the encrypted message
    encrypted_message[message_len] = '\0';

    return encrypted_message;
}

// Function to decrypt a message using the Vigenere cipher
char* vigenere_decrypt(char* encrypted_message, char* key) {
    int encrypted_message_len = strlen(encrypted_message);
    int key_len = strlen(key);
    char* decrypted_message = malloc(encrypted_message_len + 1); // +1 for null terminator

    // Loop through each character in the encrypted message
    for (int i = 0; i < encrypted_message_len; i++) {
        // Get the index of the current character in the alphabet
        int encrypted_char_index = strchr(ALPHABET, encrypted_message[i]) - ALPHABET;

        // Get the index of the current key character in the alphabet
        int key_char_index = strchr(ALPHABET, key[i % key_len]) - ALPHABET;

        // Decrypt the character using the Vigenere cipher
        int decrypted_char_index = (encrypted_char_index - key_char_index + ALPHABET_SIZE) % ALPHABET_SIZE;
        decrypted_message[i] = ALPHABET[decrypted_char_index];
    }

    // Add a null terminator to the end of the decrypted message
    decrypted_message[encrypted_message_len] = '\0';

    return decrypted_message;
}

int main() {
    // Get the message to encrypt from the user
    char message[100];
    printf("Enter the message to encrypt: ");
    scanf("%s", message);

    // Get the key to use for encryption from the user
    char key[100];
    printf("Enter the key to use for encryption: ");
    scanf("%s", key);

    // Encrypt the message using the Vigenere cipher
    char* encrypted_message = vigenere_encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted_message);

    // Decrypt the encrypted message using the Vigenere cipher
    char* decrypted_message = vigenere_decrypt(encrypted_message, key);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}