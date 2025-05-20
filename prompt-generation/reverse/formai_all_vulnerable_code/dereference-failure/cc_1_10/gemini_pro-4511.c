//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define BUF_SIZE 1024
#define KEY_SIZE 16

// Generate a random key of specified size
unsigned char* generate_key(int size) {
    unsigned char* key = malloc(size);
    for (int i = 0; i < size; i++) {
        key[i] = rand() % 256;
    }
    return key;
}

// Encrypt a message using a key
unsigned char* encrypt(unsigned char* message, int message_len, unsigned char* key, int key_len) {
    unsigned char* ciphertext = malloc(message_len);
    for (int i = 0; i < message_len; i++) {
        ciphertext[i] = message[i] ^ key[i % key_len];
    }
    return ciphertext;
}

// Decrypt a ciphertext using a key
unsigned char* decrypt(unsigned char* ciphertext, int ciphertext_len, unsigned char* key, int key_len) {
    unsigned char* plaintext = malloc(ciphertext_len);
    for (int i = 0; i < ciphertext_len; i++) {
        plaintext[i] = ciphertext[i] ^ key[i % key_len];
    }
    return plaintext;
}

// Print a buffer of bytes as a hex string
void print_hex(unsigned char* buffer, int buffer_len) {
    for (int i = 0; i < buffer_len; i++) {
        printf("%02x", buffer[i]);
    }
    printf("\n");
}

// Main function
int main(int argc, char** argv) {
    // Check for command line arguments
    if (argc != 3) {
        printf("Usage: %s <message> <key>", argv[0]);
        return 1;
    }

    // Get the message and key from the command line arguments
    char* message = argv[1];
    int message_len = strlen(message);
    unsigned char* key = generate_key(KEY_SIZE);

    // Encrypt the message
    unsigned char* ciphertext = encrypt(message, message_len, key, KEY_SIZE);

    // Print the ciphertext
    printf("Ciphertext (hex): ");
    print_hex(ciphertext, message_len);

    // Decrypt the ciphertext
    unsigned char* plaintext = decrypt(ciphertext, message_len, key, KEY_SIZE);

    // Print the plaintext
    printf("Plaintext: %s\n", plaintext);

    // Free the allocated memory
    free(key);
    free(ciphertext);
    free(plaintext);

    return 0;
}