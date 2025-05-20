//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 26

// Your secret cipher key generator
char* generateKey(int keyLength) {
    char* key = malloc(keyLength + 1);
    int i;
    for (i = 0; i < keyLength; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[keyLength] = '\0';
    return key;
}

// The enigmatic encryption algorithm
char* encrypt(char* plaintext, char* key) {
    int keyLength = strlen(key);
    int plaintextLength = strlen(plaintext);
    char* ciphertext = malloc(plaintextLength + 1);
    int i;
    for (i = 0; i < plaintextLength; i++) {
        int keyIndex = i % keyLength;
        int shift = key[keyIndex] - 'a';
        ciphertext[i] = (plaintext[i] + shift - 'a') % 26 + 'a';
    }
    ciphertext[plaintextLength] = '\0';
    return ciphertext;
}

// Unveiling the secrecy: Decryption
char* decrypt(char* ciphertext, char* key) {
    int keyLength = strlen(key);
    int ciphertextLength = strlen(ciphertext);
    char* plaintext = malloc(ciphertextLength + 1);
    int i;
    for (i = 0; i < ciphertextLength; i++) {
        int keyIndex = i % keyLength;
        int shift = key[keyIndex] - 'a';
        plaintext[i] = (ciphertext[i] - shift - 'a') % 26 + 'a';
    }
    plaintext[ciphertextLength] = '\0';
    return plaintext;
}

// The grand finale: Concealing a secret message
int main() {
    // Generate a random key
    printf("Generating a random cipher key...\n");
    int keyLength = rand() % MAX_KEY_LEN + 1;
    char* key = generateKey(keyLength);
    printf("Your key: %s\n", key);

    // Encode a secret message
    printf("Enter your secret message: ");
    char plaintext[100];
    scanf(" %[^\n]", plaintext);
    char* ciphertext = encrypt(plaintext, key);
    printf("Encrypted message: %s\n", ciphertext);

    // Decode the encrypted message
    printf("Decrypting the message...\n");
    char* decryptedMessage = decrypt(ciphertext, key);
    printf("Decrypted message: %s\n", decryptedMessage);

    // Free the allocated memory
    free(key);
    free(ciphertext);
    free(decryptedMessage);
    return 0;
}