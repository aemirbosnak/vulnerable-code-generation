//Falcon2-11B DATASET v1.0 Category: Cryptography Implementation ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to encrypt a message using a simple substitution cipher
void encrypt(char* message, char* key) {
    int len = strlen(message);
    int i, j;
    char c;

    // Convert the key into an array
    for (i = 0; i < len; i++) {
        key[i] = key[i] + 65;
    }

    // Encrypt the message
    for (i = 0; i < len; i++) {
        c = message[i];
        j = (c - 65) % len;
        message[i] = key[j];
    }
}

// Function to decrypt a message using the same substitution cipher
void decrypt(char* message, char* key) {
    int len = strlen(message);
    int i, j;
    char c;

    // Convert the key into an array
    for (i = 0; i < len; i++) {
        key[i] = key[i] - 65;
    }

    // Decrypt the message
    for (i = 0; i < len; i++) {
        c = message[i];
        j = (c - 65) % len;
        message[i] = key[j];
    }
}

int main() {
    char message[] = "Hello, World!";
    char key[] = "abcdefghijklmnopqrstuvwxyz";
    char encrypted[strlen(message)];
    char decrypted[strlen(message)];

    // Encrypt the message
    encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted);

    // Decrypt the encrypted message
    decrypt(encrypted, key);
    printf("Decrypted message: %s\n", decrypted);

    return 0;
}