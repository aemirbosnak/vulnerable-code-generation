//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cryptographic key
#define KEY "mysecretkey"

// Encryption function
char* encrypt(char* plaintext) {
    int len = strlen(plaintext);
    char* ciphertext = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        ciphertext[i] = plaintext[i] ^ KEY[i % strlen(KEY)];
    }
    ciphertext[len] = '\0';
    return ciphertext;
}

// Decryption function
char* decrypt(char* ciphertext) {
    int len = strlen(ciphertext);
    char* plaintext = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        plaintext[i] = ciphertext[i] ^ KEY[i % strlen(KEY)];
    }
    plaintext[len] = '\0';
    return plaintext;
}

int main() {
    // Plaintext message
    char* plaintext = "Hello, world!";

    // Encrypt the message
    char* ciphertext = encrypt(plaintext);

    // Print the ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext
    char* decrypted_plaintext = decrypt(ciphertext);

    // Print the decrypted plaintext
    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    // Free the allocated memory
    free(ciphertext);
    free(decrypted_plaintext);

    return 0;
}