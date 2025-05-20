//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define KEY_SIZE 16
#define MESSAGE_SIZE 256

// Function to generate a random key
void generate_key() {
    int i, j;
    char key[KEY_SIZE];

    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }

    printf("Generated key: %s\n", key);
}

// Function to encrypt a message
void encrypt_message(char *message, char *key) {
    int i, j, k;
    char encrypted[MESSAGE_SIZE];

    for (i = 0; i < MESSAGE_SIZE; i++) {
        encrypted[i] = message[i];
    }

    for (i = 0; i < KEY_SIZE; i++) {
        for (j = 0; j < MESSAGE_SIZE; j++) {
            k = (encrypted[j] + key[i]) % 26;
            encrypted[j] = k + 'a';
        }
    }

    printf("Encrypted message: %s\n", encrypted);
}

// Function to decrypt an encrypted message
void decrypt_message(char *encrypted, char *key) {
    int i, j, k;
    char message[MESSAGE_SIZE];

    for (i = 0; i < MESSAGE_SIZE; i++) {
        message[i] = encrypted[i] - 'a';
    }

    for (i = 0; i < KEY_SIZE; i++) {
        for (j = 0; j < MESSAGE_SIZE; j++) {
            k = (message[j] - key[i]) % 26;
            message[j] = k + 'a';
        }
    }

    printf("Decrypted message: %s\n", message);
}

int main() {
    char message[] = "Hello, World!";
    char key[] = "Giraffe";

    generate_key();
    encrypt_message(message, key);
    decrypt_message(message, key);

    return 0;
}