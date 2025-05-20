//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key.
#define KEY "my secret key"

// Function to encrypt a string using the XOR cipher.
char *xor_encrypt(char *plaintext) {
    int key_len = strlen(KEY);
    int plaintext_len = strlen(plaintext);

    // Allocate memory for the ciphertext.
    char *ciphertext = malloc(plaintext_len + 1);
    if (ciphertext == NULL) {
        fprintf(stderr, "Error allocating memory for ciphertext.\n");
        exit(1);
    }

    // Encrypt the plaintext character by character.
    for (int i = 0; i < plaintext_len; i++) {
        ciphertext[i] = plaintext[i] ^ KEY[i % key_len];
    }

    // Terminate the ciphertext with a null character.
    ciphertext[plaintext_len] = '\0';

    return ciphertext;
}

// Function to decrypt a string using the XOR cipher.
char *xor_decrypt(char *ciphertext) {
    int key_len = strlen(KEY);
    int ciphertext_len = strlen(ciphertext);

    // Allocate memory for the plaintext.
    char *plaintext = malloc(ciphertext_len + 1);
    if (plaintext == NULL) {
        fprintf(stderr, "Error allocating memory for plaintext.\n");
        exit(1);
    }

    // Decrypt the ciphertext character by character.
    for (int i = 0; i < ciphertext_len; i++) {
        plaintext[i] = ciphertext[i] ^ KEY[i % key_len];
    }

    // Terminate the plaintext with a null character.
    plaintext[ciphertext_len] = '\0';

    return plaintext;
}

// Main function.
int main() {
    // Get the plaintext from the user.
    char *plaintext = NULL;
    size_t plaintext_len = 0;
    if (getline(&plaintext, &plaintext_len, stdin) == -1) {
        fprintf(stderr, "Error reading plaintext.\n");
        exit(1);
    }

    // Encrypt the plaintext.
    char *ciphertext = xor_encrypt(plaintext);

    // Print the ciphertext.
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext.
    char *decrypted_plaintext = xor_decrypt(ciphertext);

    // Print the decrypted plaintext.
    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    // Free the allocated memory.
    free(plaintext);
    free(ciphertext);
    free(decrypted_plaintext);

    return 0;
}