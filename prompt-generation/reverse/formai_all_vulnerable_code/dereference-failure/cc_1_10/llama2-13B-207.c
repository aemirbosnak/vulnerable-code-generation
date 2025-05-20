//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: random
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define KEY_SIZE 16
#define MESSAGE_SIZE 256

// Generate a random key
void generate_key(char *key) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = (rand() % 26) + 'A';
    }
}

// Encrypt a message
void encrypt_message(char *message, char *key) {
    int i, j;
    char c;
    for (i = 0; i < MESSAGE_SIZE; i++) {
        c = message[i];
        for (j = 0; j < KEY_SIZE; j++) {
            c = (c + key[j]) % 26;
        }
        message[i] = c;
    }
}

// Decrypt a message
void decrypt_message(char *message, char *key) {
    int i, j;
    char c;
    for (i = 0; i < MESSAGE_SIZE; i++) {
        c = message[i];
        for (j = 0; j < KEY_SIZE; j++) {
            c = (c - key[j]) % 26;
        }
        message[i] = c;
    }
}

int main() {
    char message[] = "This is a secret message";
    char key[] = "This is a random key";

    generate_key(key);

    encrypt_message(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt_message(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}