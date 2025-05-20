//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

// Function to generate a random key
void generate_key(unsigned char* key) {
    time_t t;
    time(&t);
    srand(t);

    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }
}

// Function to encrypt a message using the key
void encrypt(unsigned char* message, unsigned char* key, unsigned char* ciphertext) {
    for (int i = 0; i < strlen(message); i++) {
        ciphertext[i] = message[i] ^ key[i % KEY_SIZE];
    }
}

// Function to decrypt a message using the key
void decrypt(unsigned char* ciphertext, unsigned char* key, unsigned char* message) {
    for (int i = 0; i < strlen(ciphertext); i++) {
        message[i] = ciphertext[i] ^ key[i % KEY_SIZE];
    }
}

int main() {
    // Generate a random key
    unsigned char key[KEY_SIZE];
    generate_key(key);

    // Generate a message to encrypt
    unsigned char message[BLOCK_SIZE];
    strcpy(message, "Hello World!");

    // Allocate memory for the ciphertext
    unsigned char* ciphertext = (unsigned char*) malloc(BLOCK_SIZE + 1);

    // Encrypt the message using the key
    encrypt(message, key, ciphertext);

    // Print the encrypted message
    printf("Encrypted message: %s\n", ciphertext);

    // Decrypt the message using the key
    unsigned char decrypted_message[BLOCK_SIZE];
    decrypt(ciphertext, key, decrypted_message);

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}