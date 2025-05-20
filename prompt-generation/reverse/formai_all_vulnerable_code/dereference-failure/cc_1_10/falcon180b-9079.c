//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 1024
#define MAX_MESSAGE_SIZE 4096

// XOR encryption function
void xor_encrypt(char* message, int key_size, char* key) {
    int i;
    char* result = malloc(strlen(message) + 1); // allocate memory for the encrypted message
    for (i = 0; i < strlen(message); i++) {
        result[i] = message[i] ^ key[i % key_size];
    }
    result[strlen(message)] = '\0';
    printf("Encrypted message: %s\n", result);
    free(result);
}

// XOR decryption function
void xor_decrypt(char* message, int key_size, char* key) {
    int i;
    char* result = malloc(strlen(message) + 1); // allocate memory for the decrypted message
    for (i = 0; i < strlen(message); i++) {
        result[i] = message[i] ^ key[i % key_size];
    }
    result[strlen(message)] = '\0';
    printf("Decrypted message: %s\n", result);
    free(result);
}

int main() {
    char message[MAX_MESSAGE_SIZE];
    char key[MAX_KEY_SIZE];
    int key_size;

    // prompt the user for a message to encrypt/decrypt
    printf("Enter a message to encrypt/decrypt: ");
    fgets(message, MAX_MESSAGE_SIZE, stdin);

    // prompt the user for a key to use for encryption/decryption
    printf("Enter a key to use for encryption/decryption: ");
    fgets(key, MAX_KEY_SIZE, stdin);

    // remove newline character from the key
    key[strcspn(key, "\n")] = '\0';

    // get the key size from the user
    printf("Enter the size of the key (up to %d): ", MAX_KEY_SIZE);
    scanf("%d", &key_size);

    // encrypt the message using XOR encryption
    xor_encrypt(message, key_size, key);

    // decrypt the encrypted message using XOR decryption
    xor_decrypt(message, key_size, key);

    return 0;
}