//Falcon-180B DATASET v1.0 Category: Encryption ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 256
#define MAX_MESSAGE_SIZE 1024

// Function to generate a key of length 'key_size'
void generate_key(unsigned char* key, int key_size) {
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 256;
    }
}

// Function to encrypt the message using the key
void encrypt(unsigned char* message, int message_size, unsigned char* key) {
    for (int i = 0; i < message_size; i++) {
        message[i] ^= key[i % strlen((char*)key)];
    }
}

// Function to decrypt the message using the key
void decrypt(unsigned char* message, int message_size, unsigned char* key) {
    for (int i = 0; i < message_size; i++) {
        message[i] ^= key[i % strlen((char*)key)];
    }
}

int main() {
    unsigned char key[MAX_KEY_SIZE];
    unsigned char message[MAX_MESSAGE_SIZE];

    // Generate a key of length 'key_size'
    generate_key(key, strlen((char*)"secret_key"));

    // Encrypt the message using the key
    strcpy((char*)message, "Hello, World!");
    encrypt(message, strlen((char*)message), key);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the message using the key
    decrypt(message, strlen((char*)message), key);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}