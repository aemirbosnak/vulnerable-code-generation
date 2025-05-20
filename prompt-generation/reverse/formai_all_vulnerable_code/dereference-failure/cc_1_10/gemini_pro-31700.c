//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a string using a simple XOR encryption algorithm
char* encrypt(char* plaintext, unsigned char key) {
    size_t len = strlen(plaintext);
    char* ciphertext = malloc(len + 1);
    
    for (size_t i = 0; i < len; i++) {
        ciphertext[i] = plaintext[i] ^ key;
    }
    ciphertext[len] = '\0'; // Null-terminate the ciphertext string

    return ciphertext;
}

// Function to decrypt a string that was encrypted using the XOR encryption algorithm
char* decrypt(char* ciphertext, unsigned char key) {
    size_t len = strlen(ciphertext);
    char* plaintext = malloc(len + 1);

    for (size_t i = 0; i < len; i++) {
        plaintext[i] = ciphertext[i] ^ key;
    }
    plaintext[len] = '\0'; // Null-terminate the plaintext string

    return plaintext;
}

int main() {
    // Define the plaintext string to be encrypted
    char* plaintext = "This is a secret message.";

    // Define the encryption key
    unsigned char encryption_key = 0x42; // Any value can be used as the encryption key

    // Encrypt the plaintext using the XOR encryption algorithm
    char* ciphertext = encrypt(plaintext, encryption_key);

    // Print the encrypted ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext using the XOR encryption algorithm
    char* decrypted_plaintext = decrypt(ciphertext, encryption_key);

    // Print the decrypted plaintext
    printf("Plaintext: %s\n", decrypted_plaintext);

    // Free the allocated memory
    free(ciphertext);
    free(decrypted_plaintext);

    return 0;
}