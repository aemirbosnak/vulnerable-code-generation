//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEY_LENGTH 256
#define MAX_BLOCK_SIZE 16

// Function to generate a random key of given length
void generate_key(char *key, int key_length) {
    srand(time(NULL)); // Seed the random number generator with current time
    for (int i = 0; i < key_length; i++) {
        key[i] = rand() % 256; // Generate a random number between 0 and 255 and store in key[i]
    }
}

// Function to encrypt a message using the given key
void encrypt(char *message, char *key) {
    int message_length = strlen(message);
    int key_length = strlen(key);

    // Pad the message with zeros to make it a multiple of the block size
    int padding_length = MAX_BLOCK_SIZE - (message_length % MAX_BLOCK_SIZE);
    char padding[MAX_BLOCK_SIZE];
    for (int i = 0; i < padding_length; i++) {
        padding[i] = 0;
    }
    strcat(message, padding);

    // Encrypt the message using XOR with the key
    for (int i = 0; i < message_length; i++) {
        message[i] ^= key[i % key_length];
    }
}

// Function to decrypt an encrypted message using the given key
void decrypt(char *encrypted_message, char *key) {
    int encrypted_message_length = strlen(encrypted_message);
    int key_length = strlen(key);

    // Remove the padding from the encrypted message
    int padding_length = encrypted_message[encrypted_message_length - 1];
    encrypted_message[encrypted_message_length - padding_length - 1] = '\0';

    // Decrypt the message using XOR with the key
    for (int i = 0; i < encrypted_message_length - padding_length; i++) {
        encrypted_message[i] ^= key[i % key_length];
    }
}

int main() {
    char message[] = "Hello, world!";
    char key[MAX_KEY_LENGTH];
    generate_key(key, strlen(key));
    encrypt(message, key);
    decrypt(message, key);
    printf("%s\n", message);
    return 0;
}