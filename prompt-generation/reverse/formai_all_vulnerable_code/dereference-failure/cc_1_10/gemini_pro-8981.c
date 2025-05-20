//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function Prototypes
char *encrypt(char *plaintext, char *key);
char *decrypt(char *ciphertext, char *key);

int main() {
    // Initialize variables
    char plaintext[] = "The quick brown fox jumps over the lazy dog";
    char key[] = "My secret key";
    char *ciphertext;
    char *decryptedText;

    // Encrypt the plaintext
    ciphertext = encrypt(plaintext, key);

    // Decrypt the ciphertext
    decryptedText = decrypt(ciphertext, key);

    // Print the plaintext, ciphertext, and decrypted text
    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);
    printf("Decrypted Text: %s\n", decryptedText);

    // Free the allocated memory
    free(ciphertext);
    free(decryptedText);

    return 0;
}

// Function to encrypt the plaintext using the key
char *encrypt(char *plaintext, char *key) {
    int plaintextLength = strlen(plaintext);
    int keyLength = strlen(key);
    int i, j;
    char *ciphertext = malloc(plaintextLength + 1);

    for (i = 0, j = 0; i < plaintextLength; i++) {
        ciphertext[i] = plaintext[i] ^ key[j];
        j = (j + 1) % keyLength;
    }

    ciphertext[plaintextLength] = '\0';
    return ciphertext;
}

// Function to decrypt the ciphertext using the key
char *decrypt(char *ciphertext, char *key) {
    int ciphertextLength = strlen(ciphertext);
    int keyLength = strlen(key);
    int i, j;
    char *decryptedText = malloc(ciphertextLength + 1);

    for (i = 0, j = 0; i < ciphertextLength; i++) {
        decryptedText[i] = ciphertext[i] ^ key[j];
        j = (j + 1) % keyLength;
    }

    decryptedText[ciphertextLength] = '\0';
    return decryptedText;
}