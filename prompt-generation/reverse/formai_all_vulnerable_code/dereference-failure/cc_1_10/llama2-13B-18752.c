//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define KEY_SIZE 16
#define MAX_MESSAGE_LENGTH 100

// Function to generate a random key
void generate_key(char *key) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = (char)('a' + (rand() % 26));
    }
}

// Function to encrypt a message
void encrypt(char *message, char *key) {
    int i, j, k;
    for (i = 0; i < strlen(message); i++) {
        // Shift the letter in the message by the corresponding position in the key
        j = (i % strlen(key)) * 2;
        k = (i % strlen(key)) % 2;
        if (k == 0) {
            message[i] = message[i] ^ key[j];
        } else {
            message[i] = message[i] ^ key[j + 1];
        }
    }
}

// Function to decrypt an encrypted message
void decrypt(char *message, char *key) {
    int i, j, k;
    for (i = 0; i < strlen(message); i++) {
        // Shift the letter in the message by the corresponding position in the key
        j = (i % strlen(key)) * 2;
        k = (i % strlen(key)) % 2;
        if (k == 0) {
            message[i] = message[i] ^ key[j];
        } else {
            message[i] = message[i] ^ key[j + 1];
        }
    }
}

int main() {
    char message[] = "This is a secret message";
    char key[] = "This is a secret key";
    int message_len = strlen(message);
    int key_len = strlen(key);

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