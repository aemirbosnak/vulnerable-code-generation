//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

// Function to generate the key
void generate_key(char *key) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }
}

// Function to encrypt the message
void encrypt(char *message, char *key) {
    int i, j;
    char *result = (char*) malloc(strlen(message) + 1);

    for (i = 0, j = 0; i < strlen(message); i++, j++) {
        if (j == KEY_SIZE) {
            j = 0;
        }
        result[i] = message[i] ^ key[j];
    }

    result[strlen(message)] = '\0';
    printf("Encrypted message: %s\n", result);
}

// Function to decrypt the message
void decrypt(char *message, char *key) {
    int i, j;
    char *result = (char*) malloc(strlen(message) + 1);

    for (i = 0, j = 0; i < strlen(message); i++, j++) {
        if (j == KEY_SIZE) {
            j = 0;
        }
        result[i] = message[i] ^ key[j];
    }

    result[strlen(message)] = '\0';
    printf("Decrypted message: %s\n", result);
}

int main() {
    char message[100] = "Hello, world!";
    char key[KEY_SIZE];

    generate_key(key);
    encrypt(message, key);
    decrypt(message, key);

    return 0;
}