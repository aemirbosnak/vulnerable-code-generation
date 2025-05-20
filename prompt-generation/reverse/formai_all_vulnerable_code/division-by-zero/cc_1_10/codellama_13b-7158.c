//Code Llama-13B DATASET v1.0 Category: Encryption ; Style: accurate
// C Encryption Example Program

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_LENGTH 100

// Encryption function
void encrypt(char *text, char *key) {
    int i, j;
    int len = strlen(text);
    int klen = strlen(key);

    for (i = 0; i < len; i++) {
        text[i] = text[i] ^ key[i % klen];
    }
}

// Decryption function
void decrypt(char *text, char *key) {
    int i, j;
    int len = strlen(text);
    int klen = strlen(key);

    for (i = 0; i < len; i++) {
        text[i] = text[i] ^ key[i % klen];
    }
}

int main() {
    char text[MAX_LENGTH];
    char key[MAX_LENGTH];

    // Input the text to be encrypted
    printf("Enter the text to be encrypted: ");
    fgets(text, MAX_LENGTH, stdin);

    // Input the encryption key
    printf("Enter the encryption key: ");
    fgets(key, MAX_LENGTH, stdin);

    // Encrypt the text
    encrypt(text, key);

    // Print the encrypted text
    printf("Encrypted text: %s\n", text);

    // Decrypt the text
    decrypt(text, key);

    // Print the decrypted text
    printf("Decrypted text: %s\n", text);

    return 0;
}