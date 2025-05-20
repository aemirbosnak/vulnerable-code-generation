//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 16
#define MAX_BLOCK_SIZE 8

// Function to encrypt the message using the key
void encrypt(unsigned char* message, unsigned char* key, int message_size) {
    int i, j;
    unsigned char* encrypted_message = malloc(message_size + 1);

    for (i = 0, j = 0; i < message_size; i++) {
        encrypted_message[i] = message[i] ^ key[j];
        j = (j + 1) % MAX_KEY_SIZE;
    }

    encrypted_message[message_size] = '\0';

    printf("Encrypted message: %s\n", encrypted_message);
    free(encrypted_message);
}

// Function to decrypt the message using the key
void decrypt(unsigned char* encrypted_message, unsigned char* key, int message_size) {
    int i, j;
    unsigned char* decrypted_message = malloc(message_size + 1);

    for (i = 0, j = 0; i < message_size; i++) {
        decrypted_message[i] = encrypted_message[i] ^ key[j];
        j = (j + 1) % MAX_KEY_SIZE;
    }

    decrypted_message[message_size] = '\0';

    printf("Decrypted message: %s\n", decrypted_message);
    free(decrypted_message);
}

int main() {
    unsigned char* message = "Hello, World!";
    unsigned char* key = "secret_key";
    int message_size = strlen(message);

    printf("Original message: %s\n", message);
    encrypt(message, key, message_size);
    decrypt(message, key, message_size);

    return 0;
}