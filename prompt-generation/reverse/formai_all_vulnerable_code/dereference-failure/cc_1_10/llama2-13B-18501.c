//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_KEY_LENGTH 16
#define MAX_MESSAGE_LENGTH 1024

// Function to generate a random key
void generate_key(char *key) {
    int i, j;
    for (i = 0; i < MAX_KEY_LENGTH; i++) {
        key[i] = 'a' + (rand() % 26);
    }
}

// Function to encrypt a message
void encrypt(char *message, char *key) {
    int i, j, k;
    for (i = 0; i < strlen(message); i++) {
        j = message[i] - 'a';
        k = (j + (key[i % strlen(key)] - 'a')) % 26;
        message[i] = (char)('a' + k);
    }
}

// Function to decrypt an encrypted message
void decrypt(char *message, char *key) {
    int i, j, k;
    for (i = 0; i < strlen(message); i++) {
        j = message[i] - 'a';
        k = (j - (key[i % strlen(key)] - 'a')) % 26;
        message[i] = (char)('a' + k);
    }
}

int main() {
    char key[MAX_KEY_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    generate_key(key);
    printf("Original message: ");
    gets(message);
    encrypt(message, key);
    printf("Encrypted message: ");
    puts(message);
    decrypt(message, key);
    printf("Decrypted message: ");
    puts(message);
    return 0;
}