//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: random
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define KEY_SIZE 16
#define MESSAGE_SIZE 256

// Function to generate a random key
void generate_key(unsigned char *key) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = (unsigned char)rand() % 256;
    }
}

// Function to encrypt a message
void encrypt_message(const unsigned char *message, unsigned char *encrypted_message, const unsigned char *key) {
    int i, j;
    for (i = 0; i < MESSAGE_SIZE; i++) {
        unsigned char temp = message[i];
        for (j = 0; j < KEY_SIZE; j++) {
            temp = (temp + key[j]) % 256;
        }
        encrypted_message[i] = temp;
    }
}

// Function to decrypt an encrypted message
void decrypt_message(const unsigned char *encrypted_message, unsigned char *message, const unsigned char *key) {
    int i, j;
    for (i = 0; i < MESSAGE_SIZE; i++) {
        unsigned char temp = encrypted_message[i];
        for (j = 0; j < KEY_SIZE; j++) {
            temp = (temp - key[j]) % 256;
        }
        message[i] = temp;
    }
}

int main() {
    unsigned char message[] = "Hello, world!";
    unsigned char key[KEY_SIZE];
    generate_key(key);
    unsigned char encrypted_message[MESSAGE_SIZE];

    encrypt_message(message, encrypted_message, key);

    printf("Encrypted message: ");
    for (int i = 0; i < MESSAGE_SIZE; i++) {
        printf("%02x", encrypted_message[i]);
    }
    printf("\n");

    decrypt_message(encrypted_message, message, key);

    printf("Decrypted message: ");
    for (int i = 0; i < MESSAGE_SIZE; i++) {
        printf("%02x", message[i]);
    }
    printf("\n");

    return 0;
}