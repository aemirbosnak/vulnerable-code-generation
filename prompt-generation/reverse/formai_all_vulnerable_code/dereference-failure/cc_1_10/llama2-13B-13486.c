//LLAMA2-13B DATASET v1.0 Category: Modern Encryption ; Style: careful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define KEY_SIZE 10
#define MESSAGE_SIZE 256

// Function to generate a random key
void generate_key(char *key) {
    int i, j;
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = 'a' + (rand() % 26);
    }
}

// Function to encrypt the message using the Caesar Cipher
void caesar_encrypt(char *message, char *key) {
    int i, j;
    for (i = 0; i < MESSAGE_SIZE; i++) {
        char c = message[i];
        if (c >= 'a' && c <= 'z') {
            c = (c + key[i % strlen(key)]) % 26;
        } else if (c >= 'A' && c <= 'Z') {
            c = (c + key[i % strlen(key)]) % 26;
        }
        message[i] = c;
    }
}

// Function to encrypt the message using the Vigenere Cipher
void vigenere_encrypt(char *message, char *key) {
    int i, j;
    for (i = 0; i < MESSAGE_SIZE; i++) {
        char c = message[i];
        if (c >= 'a' && c <= 'z') {
            c = (c ^ key[i % strlen(key)]) % 26;
        } else if (c >= 'A' && c <= 'Z') {
            c = (c ^ key[i % strlen(key)]) % 26;
        }
        message[i] = c;
    }
}

// Function to encrypt the message using the XOR operation
void xor_encrypt(char *message, char *key) {
    int i, j;
    for (i = 0; i < MESSAGE_SIZE; i++) {
        char c = message[i];
        message[i] = c ^ key[i % strlen(key)];
    }
}

int main() {
    char message[] = "Hello, World!";
    char key[] = "secret";
    generate_key(key);

    // Encrypt the message using the Caesar Cipher
    caesar_encrypt(message, key);
    printf("Caesar Cipher Encryption: %s\n", message);

    // Encrypt the message using the Vigenere Cipher
    vigenere_encrypt(message, key);
    printf("Vigenere Cipher Encryption: %s\n", message);

    // Encrypt the message using the XOR operation
    xor_encrypt(message, key);
    printf("XOR Cipher Encryption: %s\n", message);

    return 0;
}