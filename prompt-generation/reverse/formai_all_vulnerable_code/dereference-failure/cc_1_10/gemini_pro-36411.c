//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption function
char* encrypt(char* plaintext, char* key) {
    int key_length = strlen(key);
    int plaintext_length = strlen(plaintext);

    char* ciphertext = malloc(plaintext_length + 1);
    memset(ciphertext, 0, plaintext_length + 1);

    for (int i = 0; i < plaintext_length; i++) {
        ciphertext[i] = plaintext[i] ^ key[i % key_length];
    }

    return ciphertext;
}

// Define the decryption function
char* decrypt(char* ciphertext, char* key) {
    int key_length = strlen(key);
    int ciphertext_length = strlen(ciphertext);

    char* plaintext = malloc(ciphertext_length + 1);
    memset(plaintext, 0, ciphertext_length + 1);

    for (int i = 0; i < ciphertext_length; i++) {
        plaintext[i] = ciphertext[i] ^ key[i % key_length];
    }

    return plaintext;
}

// Main function
int main() {
    char* plaintext = "Hello, world!";
    char* key = "SECRET";

    printf("Plaintext: %s\n", plaintext);

    char* ciphertext = encrypt(plaintext, key);

    printf("Ciphertext: %s\n", ciphertext);

    char* decrypted_plaintext = decrypt(ciphertext, key);

    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    return 0;
}