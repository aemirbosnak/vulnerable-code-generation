//FormAI DATASET v1.0 Category: Modern Encryption ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Generate a random key for encryption */
void generateKey(char *key, int keyLength) {
    int i;
    for(i = 0; i < keyLength; i++) {
        key[i] = (rand() % 26) + 'A'; // Only uppercase letters allowed
    }
    key[i] = '\0'; // Null character
}

/* Encrypt the plaintext message using the given key */
void encrypt(char *plaintext, char *key, char *ciphertext) {
    int i;
    int plaintextLength = strlen(plaintext);
    for(i = 0; i < plaintextLength; i++) {
        ciphertext[i] = ((plaintext[i] - 'A') + (key[i] - 'A')) % 26 + 'A';
    }
    ciphertext[i] = '\0'; // Null character
}

/* Decrypt the ciphertext message using the given key */
void decrypt(char *ciphertext, char *key, char *plaintext) {
    int i;
    int ciphertextLength = strlen(ciphertext);
    for(i = 0; i < ciphertextLength; i++) {
        plaintext[i] = (((ciphertext[i] - 'A') - (key[i] - 'A')) + 26) % 26 + 'A';
    }
    plaintext[i] = '\0'; // Null character
}

int main() {
    char plaintext[] = "HELLO WORLD";
    char key[strlen(plaintext)];
    char ciphertext[strlen(plaintext)];
    char decryptedText[strlen(plaintext)];
    
    /* Generate a key for encryption */
    generateKey(key, strlen(plaintext));
    
    /* Encrypt the plaintext message */
    encrypt(plaintext, key, ciphertext);    
    
    printf("Plaintext: %s\n", plaintext);
    printf("Key: %s\n", key);
    printf("Ciphertext: %s\n", ciphertext);
    
    /* Decrypt the ciphertext message */
    decrypt(ciphertext, key, decryptedText);
    
    printf("Decrypted Text: %s\n", decryptedText);
    
    return 0;
}