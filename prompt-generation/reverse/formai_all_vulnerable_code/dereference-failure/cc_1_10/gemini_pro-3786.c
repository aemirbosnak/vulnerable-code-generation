//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define KEY_LENGTH 16
#define BLOCK_SIZE 16

// Function to generate a random key
void generate_key(unsigned char *key) {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random key
    for (int i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 256;
    }
}

// Function to encrypt a block of data
void encrypt_block(unsigned char *plaintext, unsigned char *ciphertext, unsigned char *key) {
    // Add the key to the plaintext
    for (int i = 0; i < BLOCK_SIZE; i++) {
        ciphertext[i] = plaintext[i] + key[i];
    }
}

// Function to decrypt a block of data
void decrypt_block(unsigned char *ciphertext, unsigned char *plaintext, unsigned char *key) {
    // Subtract the key from the ciphertext
    for (int i = 0; i < BLOCK_SIZE; i++) {
        plaintext[i] = ciphertext[i] - key[i];
    }
}

// Function to encrypt a message
void encrypt_message(unsigned char *message, unsigned char *ciphertext, unsigned char *key) {
    // Get the length of the message
    int message_length = strlen(message);

    // Pad the message to a multiple of the block size
    int padded_message_length = (message_length + BLOCK_SIZE - 1) / BLOCK_SIZE * BLOCK_SIZE;
    unsigned char *padded_message = malloc(padded_message_length);
    memcpy(padded_message, message, message_length);
    memset(padded_message + message_length, 0, padded_message_length - message_length);

    // Encrypt the message
    for (int i = 0; i < padded_message_length; i += BLOCK_SIZE) {
        encrypt_block(padded_message + i, ciphertext + i, key);
    }

    // Free the padded message
    free(padded_message);
}

// Function to decrypt a message
void decrypt_message(unsigned char *ciphertext, unsigned char *message, unsigned char *key) {
    // Get the length of the ciphertext
    int ciphertext_length = strlen(ciphertext);

    // Decrypt the message
    for (int i = 0; i < ciphertext_length; i += BLOCK_SIZE) {
        decrypt_block(ciphertext + i, message + i, key);
    }

    // Remove the padding from the decrypted message
    int message_length = strlen(message);
    while (message_length > 0 && message[message_length - 1] == 0) {
        message_length--;
    }
    message[message_length] = '\0';
}

// Main function
int main() {
    // Generate a random key
    unsigned char key[KEY_LENGTH];
    generate_key(key);

    // Get the message to be encrypted
    char message[] = "Hello, world!";

    // Encrypt the message
    unsigned char ciphertext[strlen(message) + BLOCK_SIZE - 1];
    encrypt_message(message, ciphertext, key);

    // Decrypt the message
    unsigned char decrypted_message[strlen(ciphertext)];
    decrypt_message(ciphertext, decrypted_message, key);

    // Print the encrypted and decrypted messages
    printf("Encrypted message: %s\n", ciphertext);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}