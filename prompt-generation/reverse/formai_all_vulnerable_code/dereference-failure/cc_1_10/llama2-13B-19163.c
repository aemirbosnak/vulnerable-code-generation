//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_LENGTH 16
#define MESSAGE_LENGTH 32

// Function to generate a random key
void generate_key(unsigned char *key) {
    int i;
    for (i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 256;
    }
}

// Function to encrypt a message
void encrypt_message(unsigned char *message, unsigned char *key) {
    int i, j;
    for (i = 0; i < MESSAGE_LENGTH; i++) {
        for (j = 0; j < KEY_LENGTH; j++) {
            message[i] = (message[i] + key[j]) % 256;
        }
    }
}

// Function to decrypt an encrypted message
void decrypt_message(unsigned char *message, unsigned char *key) {
    int i, j;
    for (i = 0; i < MESSAGE_LENGTH; i++) {
        for (j = 0; j < KEY_LENGTH; j++) {
            message[i] = (message[i] - key[j]) % 256;
        }
    }
}

int main() {
    unsigned char message[] = "Hello, world!";
    unsigned char key[KEY_LENGTH];
    generate_key(key);

    // Encrypt the message
    encrypt_message(message, key);

    // Print the encrypted message
    printf("Encrypted message: ");
    for (int i = 0; i < MESSAGE_LENGTH; i++) {
        printf("%02x", message[i]);
    }
    printf("\n");

    // Decrypt the message
    decrypt_message(message, key);

    // Print the decrypted message
    printf("Decrypted message: ");
    for (int i = 0; i < MESSAGE_LENGTH; i++) {
        printf("%02x", message[i]);
    }
    printf("\n");

    return 0;
}