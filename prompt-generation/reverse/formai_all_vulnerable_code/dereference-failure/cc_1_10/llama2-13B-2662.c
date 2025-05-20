//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEY_LENGTH 20
#define MAX_MESSAGE_LENGTH 50

// Function to generate a random key
void generate_key(char *key) {
    int i;
    for (i = 0; i < MAX_KEY_LENGTH; i++) {
        key[i] = 'a' + (rand() % 26);
    }
}

// Function to encrypt a message
void encrypt(char *message, char *key) {
    int i, j;
    for (i = 0; i < strlen(message); i++) {
        for (j = 0; j < strlen(key); j++) {
            if (message[i] == key[j]) {
                message[i] = message[i] + (key[j] - 'a');
            }
        }
    }
}

// Function to decrypt an encrypted message
void decrypt(char *message, char *key) {
    int i, j;
    for (i = 0; i < strlen(message); i++) {
        for (j = 0; j < strlen(key); j++) {
            if (message[i] == message[i] - (key[j] - 'a')) {
                message[i] = message[i] - (key[j] - 'a');
            }
        }
    }
}

int main() {
    char message[] = "Hello, World!";
    char key[] = "supersecretkey";
    generate_key(key);
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);
    return 0;
}