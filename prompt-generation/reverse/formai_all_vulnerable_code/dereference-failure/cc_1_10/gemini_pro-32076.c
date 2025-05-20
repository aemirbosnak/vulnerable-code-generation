//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    int key_len;
} cipher_key;

// Function to generate a random key of specified length
cipher_key generate_key(int key_len) {
    char *key = malloc(key_len);
    for (int i = 0; i < key_len; i++) {
        key[i] = rand() % 256;
    }
    return (cipher_key) { key, key_len };
}

// Function to encrypt a message using a key
char *encrypt(char *message, cipher_key key) {
    char *encrypted_message = malloc(strlen(message) + 1);
    for (int i = 0; i < strlen(message); i++) {
        encrypted_message[i] = message[i] ^ key.key[i % key.key_len];
    }
    encrypted_message[strlen(message)] = '\0';
    return encrypted_message;
}

// Function to decrypt an encrypted message using a key
char *decrypt(char *encrypted_message, cipher_key key) {
    char *decrypted_message = malloc(strlen(encrypted_message) + 1);
    for (int i = 0; i < strlen(encrypted_message); i++) {
        decrypted_message[i] = encrypted_message[i] ^ key.key[i % key.key_len];
    }
    decrypted_message[strlen(encrypted_message)] = '\0';
    return decrypted_message;
}

// Function to free the memory allocated for a key
void free_key(cipher_key key) {
    free(key.key);
}

// Function to test the above functions
void test_encryption(char *message) {
    // Generate a random key
    cipher_key key = generate_key(16);

    // Encrypt the message
    char *encrypted_message = encrypt(message, key);

    // Decrypt the encrypted message
    char *decrypted_message = decrypt(encrypted_message, key);

    // Free the memory allocated for the key and encrypted message
    free_key(key);
    free(encrypted_message);

    // Print the original message and decrypted message
    printf("Original message: %s\n", message);
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    // Message to be encrypted
    char *message = "This is a secret message";

    // Test the encryption and decryption functions
    test_encryption(message);

    return 0;
}