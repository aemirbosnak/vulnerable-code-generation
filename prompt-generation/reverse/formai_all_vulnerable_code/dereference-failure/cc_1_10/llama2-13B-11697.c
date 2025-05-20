//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_LEN 10
#define MSG_LEN 256

// Generate a random key
void generate_key(char *key) {
    int i, j;
    for (i = 0; i < KEY_LEN; i++) {
        key[i] = 'a' + (rand() % 26);
    }
}

// Encrypt a message
void encrypt(char *message, char *key) {
    int i, j, k;
    char c, d;

    // Initialize the encryption vector
    for (i = 0; i < MSG_LEN; i++) {
        message[i] = 'z';
    }

    // Loop through each character of the message
    for (i = 0; i < strlen(message); i++) {
        c = message[i];

        // Calculate the substitution cipher
        d = (c + (rand() % 26)) % 26;

        // Encrypt the character
        message[i] = d + key[d];
    }
}

// Decrypt a message
void decrypt(char *message, char *key) {
    int i, j, k;
    char c, d;

    // Initialize the decryption vector
    for (i = 0; i < MSG_LEN; i++) {
        message[i] = 'z';
    }

    // Loop through each character of the message
    for (i = 0; i < strlen(message); i++) {
        c = message[i];

        // Calculate the substitution cipher
        d = (c - key[c]) % 26;

        // Decrypt the character
        message[i] = d;
    }
}

int main() {
    char message[] = "Hello, world!";
    char key[] = "GeniusCoder";

    // Generate a random key
    generate_key(key);

    // Encrypt the message
    encrypt(message, key);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt(message, key);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}