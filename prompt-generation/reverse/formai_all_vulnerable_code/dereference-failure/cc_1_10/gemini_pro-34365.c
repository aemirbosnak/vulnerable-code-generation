//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 1024

// Function to encrypt a message using the Caesar cipher
char *caesar_encrypt(char *message, int key) {
    char *encrypted = malloc(strlen(message) + 1);
    for (int i = 0; i < strlen(message); i++) {
        encrypted[i] = (message[i] + key - 'a') % 26 + 'a';
    }
    encrypted[strlen(message)] = '\0';
    return encrypted;
}

// Function to decrypt a message using the Caesar cipher
char *caesar_decrypt(char *message, int key) {
    char *decrypted = malloc(strlen(message) + 1);
    for (int i = 0; i < strlen(message); i++) {
        decrypted[i] = (message[i] - key + 'a') % 26 + 'a';
    }
    decrypted[strlen(message)] = '\0';
    return decrypted;
}

// Function to perform a brute-force attack on a Caesar cipher
void caesar_brute_force(char *message) {
    for (int key = 0; key < 26; key++) {
        printf("Key %d: %s\n", key, caesar_decrypt(message, key));
    }
}

int main() {
    char *message = "helloworld";
    int key = 3;

    // Encrypt the message
    char *encrypted = caesar_encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted);

    // Decrypt the message
    char *decrypted = caesar_decrypt(encrypted, key);
    printf("Decrypted message: %s\n", decrypted);

    // Perform a brute-force attack
    caesar_brute_force(encrypted);

    return 0;
}