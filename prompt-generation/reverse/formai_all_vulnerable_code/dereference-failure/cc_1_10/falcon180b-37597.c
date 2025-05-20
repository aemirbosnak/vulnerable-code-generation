//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random key
void generate_key(char *key, int length) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int charset_length = strlen(charset);
    for (int i = 0; i < length; i++) {
        key[i] = charset[rand() % charset_length];
    }
}

// Function to encrypt a message using a key
void encrypt_message(char *message, char *key, char *encrypted_message) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    for (int i = 0; i < message_length; i++) {
        encrypted_message[i] = message[i] ^ key[i % key_length];
    }
    encrypted_message[message_length] = '\0';
}

// Function to decrypt an encrypted message using a key
void decrypt_message(char *encrypted_message, char *key, char *decrypted_message) {
    int encrypted_message_length = strlen(encrypted_message);
    int key_length = strlen(key);
    for (int i = 0; i < encrypted_message_length; i++) {
        decrypted_message[i] = encrypted_message[i] ^ key[i % key_length];
    }
    decrypted_message[encrypted_message_length] = '\0';
}

int main() {
    // Generate a random key
    char key[10];
    generate_key(key, 10);

    // Encrypt a message using the key
    char message[] = "Hello, World!";
    char encrypted_message[strlen(message) + 1];
    encrypt_message(message, key, encrypted_message);

    // Decrypt the encrypted message using the key
    char decrypted_message[strlen(message) + 1];
    decrypt_message(encrypted_message, key, decrypted_message);

    // Print the original message, encrypted message, and decrypted message
    printf("Original message: %s\n", message);
    printf("Encrypted message: %s\n", encrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}