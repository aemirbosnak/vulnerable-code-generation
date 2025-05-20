//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declaration of a custom encryption function
char* encrypt(char* plaintext, char* key);

// Declaration of a custom decryption function
char* decrypt(char* ciphertext, char* key);

int main() {
    // Initialize the plaintext and key
    char plaintext[] = "Hello, world!";
    char key[] = "my_secret_key";

    // Encrypt the plaintext using the custom encryption function
    char* ciphertext = encrypt(plaintext, key);

    // Print the ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext using the custom decryption function
    char* decryptedtext = decrypt(ciphertext, key);

    // Print the decrypted text
    printf("Decrypted text: %s\n", decryptedtext);

    return 0;
}

// Implementation of the custom encryption function
char* encrypt(char* plaintext, char* key) {
    // Get the length of the plaintext and key
    int plaintext_len = strlen(plaintext);
    int key_len = strlen(key);

    // Create a buffer to store the ciphertext
    char* ciphertext = (char*)malloc(plaintext_len + 1);

    // Encrypt the plaintext using a simple XOR operation
    for (int i = 0; i < plaintext_len; i++) {
        ciphertext[i] = plaintext[i] ^ key[i % key_len];
    }

    // Add a null terminator to the ciphertext
    ciphertext[plaintext_len] = '\0';

    // Return the ciphertext
    return ciphertext;
}

// Implementation of the custom decryption function
char* decrypt(char* ciphertext, char* key) {
    // Get the length of the ciphertext and key
    int ciphertext_len = strlen(ciphertext);
    int key_len = strlen(key);

    // Create a buffer to store the decrypted text
    char* decryptedtext = (char*)malloc(ciphertext_len + 1);

    // Decrypt the ciphertext using a simple XOR operation
    for (int i = 0; i < ciphertext_len; i++) {
        decryptedtext[i] = ciphertext[i] ^ key[i % key_len];
    }

    // Add a null terminator to the decrypted text
    decryptedtext[ciphertext_len] = '\0';

    // Return the decrypted text
    return decryptedtext;
}