//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

// Function to generate a random key
void generate_key(char *key) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }
}

// Function to encrypt a message
void encrypt(char *message, char *key) {
    int i, j;
    char plaintext[BLOCK_SIZE];
    char ciphertext[BLOCK_SIZE];

    for (i = 0, j = 0; i < strlen(message); i += BLOCK_SIZE, j++) {
        strncpy(plaintext, message + i, BLOCK_SIZE);
        plaintext[j] = '\0';

        int key_index = 0;
        for (int k = 0; k < BLOCK_SIZE; k++) {
            ciphertext[k] = plaintext[k] ^ key[key_index];
            key_index = (key_index + 1) % KEY_SIZE;
        }

        strcat(ciphertext, ciphertext);
    }

    printf("Encrypted message: %s\n", ciphertext);
}

// Function to decrypt a message
void decrypt(char *ciphertext, char *key) {
    int i, j;
    char plaintext[BLOCK_SIZE];
    char decrypted_text[BLOCK_SIZE];

    for (i = 0, j = 0; i < strlen(ciphertext); i += BLOCK_SIZE, j++) {
        strncpy(plaintext, ciphertext + i, BLOCK_SIZE);
        plaintext[j] = '\0';

        int key_index = 0;
        for (int k = 0; k < BLOCK_SIZE; k++) {
            decrypted_text[k] = plaintext[k] ^ key[key_index];
            key_index = (key_index + 1) % KEY_SIZE;
        }

        strcat(decrypted_text, decrypted_text);
    }

    printf("Decrypted message: %s\n", decrypted_text);
}

int main() {
    char message[100] = "Hello, world!";
    char key[KEY_SIZE];

    generate_key(key);

    printf("Original message: %s\n", message);
    encrypt(message, key);
    decrypt(message, key);

    return 0;
}