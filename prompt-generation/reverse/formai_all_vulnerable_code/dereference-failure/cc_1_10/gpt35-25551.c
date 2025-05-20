//FormAI DATASET v1.0 Category: Encryption ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// XOR with a randomly generated key
void xor_encrypt(char* plaintext, int key) {
    int plaintext_len = strlen(plaintext);
    char* ciphertext = (char*)malloc(sizeof(char) * (plaintext_len + 1));

    // XOR each character with the key
    for (int i = 0; i < plaintext_len; i++) {
        ciphertext[i] = plaintext[i] ^ key;
    }

    // Null-terminate string
    ciphertext[plaintext_len] = '\0';

    printf("Encrypted ciphertext: %s\n", ciphertext);
}

// Decryption function, XOR with same key
void xor_decrypt(char* ciphertext, int key) {
    int ciphertext_len = strlen(ciphertext);
    char* plaintext = (char*)malloc(sizeof(char) * (ciphertext_len + 1));

    // XOR each character with the key
    for (int i = 0; i < ciphertext_len; i++) {
        plaintext[i] = ciphertext[i] ^ key;
    }

    // Null-terminate string
    plaintext[ciphertext_len] = '\0';

    printf("Decrypted plaintext: %s\n", plaintext);
}

int main() {
    char message[256];
    int key;

    printf("Enter your message to encrypt: ");
    fgets(message, 256, stdin);

    printf("Enter the key (integer between 0 and 255): ");
    scanf("%d", &key);

    // Call encryption function
    xor_encrypt(message, key);

    // Call decryption function
    xor_decrypt(message, key);

    return 0;
}