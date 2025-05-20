//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define KEY_SIZE 16
#define MESSAGE_SIZE 256

// Function to generate a random key
void generate_key() {
    int i, j;
    static const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    char key[KEY_SIZE];

    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = alphabet[rand() % strlen(alphabet)];
    }

    printf("Generated key: %s\n", key);
}

// Function to encrypt the message
void encrypt_message(char *message, char *key) {
    int i, j, k;
    char cipher[MESSAGE_SIZE];

    // Step 1: XOR the message with the key
    for (i = 0; i < MESSAGE_SIZE; i++) {
        cipher[i] = message[i] ^ key[i % strlen(key)];
    }

    // Step 2: Shift the ciphertext by a random amount
    for (j = 0; j < MESSAGE_SIZE; j++) {
        k = rand() % MESSAGE_SIZE;
        cipher[j] = cipher[k];
        cipher[k] = cipher[j];
    }

    // Step 3: XOR the ciphertext with the key again
    for (i = 0; i < MESSAGE_SIZE; i++) {
        cipher[i] = cipher[i] ^ key[i % strlen(key)];
    }

    printf("Encrypted message: %s\n", cipher);
}

int main() {
    char message[] = "Hello, World!";
    char key[KEY_SIZE];

    generate_key();
    encrypt_message(message, key);

    return 0;
}