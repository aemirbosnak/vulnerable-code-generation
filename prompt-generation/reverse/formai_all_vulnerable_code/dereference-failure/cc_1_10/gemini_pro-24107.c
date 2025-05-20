//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFLEN 1024

// Function to encrypt a string using a key
char *encrypt(char *plaintext, char *key) {
    int keylen = strlen(key);
    int ptlen = strlen(plaintext);
    char *ciphertext = malloc(ptlen + 1); // +1 for null terminator

    for (int i = 0; i < ptlen; i++) {
        ciphertext[i] = plaintext[i] ^ key[i % keylen]; // XOR plaintext with key
    }

    ciphertext[ptlen] = '\0'; // Null-terminate the ciphertext
    return ciphertext;
}

// Function to decrypt a string using a key
char *decrypt(char *ciphertext, char *key) {
    int keylen = strlen(key);
    int ctlen = strlen(ciphertext);
    char *plaintext = malloc(ctlen + 1); // +1 for null terminator

    for (int i = 0; i < ctlen; i++) {
        plaintext[i] = ciphertext[i] ^ key[i % keylen]; // XOR ciphertext with key
    }

    plaintext[ctlen] = '\0'; // Null-terminate the plaintext
    return plaintext;
}

int main() {
    char plaintext[] = "The quick brown fox jumps over the lazy dog";
    char key[] = "secret";
    char *ciphertext;
    char *decryptedtext;

    // Encrypt the plaintext using the key
    ciphertext = encrypt(plaintext, key);

    // Print the ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext using the key
    decryptedtext = decrypt(ciphertext, key);

    // Print the decrypted text
    printf("Decrypted text: %s\n", decryptedtext);

    return 0;
}