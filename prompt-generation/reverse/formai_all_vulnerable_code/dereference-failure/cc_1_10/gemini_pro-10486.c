//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a string using a key
char *encrypt(char *plaintext, char *key) {
    char *ciphertext = malloc(strlen(plaintext) + 1);
    int keylen = strlen(key);
    int i, j;
    for (i = 0, j = 0; i < strlen(plaintext); i++, j++) {
        if (j == keylen)
            j = 0;
        ciphertext[i] = plaintext[i] ^ key[j];
    }
    ciphertext[i] = '\0';
    return ciphertext;
}

// Function to decrypt a string using a key
char *decrypt(char *ciphertext, char *key) {
    char *plaintext = malloc(strlen(ciphertext) + 1);
    int keylen = strlen(key);
    int i, j;
    for (i = 0, j = 0; i < strlen(ciphertext); i++, j++) {
        if (j == keylen)
            j = 0;
        plaintext[i] = ciphertext[i] ^ key[j];
    }
    plaintext[i] = '\0';
    return plaintext;
}

// Main function
int main() {
    char *plaintext = "Hello, world!";
    char *key = "secret";

    // Encrypt the plaintext using the key
    char *ciphertext = encrypt(plaintext, key);

    // Decrypt the ciphertext using the key
    char *decryptedtext = decrypt(ciphertext, key);

    // Print the original plaintext, the encrypted ciphertext, and the decrypted plaintext
    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);
    printf("Decrypted plaintext: %s\n", decryptedtext);

    // Free the allocated memory
    free(ciphertext);
    free(decryptedtext);

    return 0;
}