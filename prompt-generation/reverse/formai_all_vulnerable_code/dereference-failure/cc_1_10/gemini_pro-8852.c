//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Forward declarations
char *encrypt(char *plaintext, char *key);
char *decrypt(char *ciphertext, char *key);

int main(int argc, char **argv) {
    // Check for the required number of arguments
    if (argc != 4) {
        printf("Usage: %s <plaintext> <key> <encrypt|decrypt>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the plaintext, key, and operation
    char *plaintext = argv[1];
    char *key = argv[2];
    char *operation = argv[3];

    // Encrypt or decrypt the message
    char *result;
    if (strcmp(operation, "encrypt") == 0) {
        result = encrypt(plaintext, key);
    } else if (strcmp(operation, "decrypt") == 0) {
        result = decrypt(plaintext, key);
    } else {
        printf("Invalid operation: %s\n", operation);
        return EXIT_FAILURE;
    }

    // Print the result
    printf("%s\n", result);

    // Free the allocated memory
    free(result);

    return EXIT_SUCCESS;
}

// Encrypt the plaintext using the key
char *encrypt(char *plaintext, char *key) {
    // Calculate the length of the key and plaintext
    int key_len = strlen(key);
    int plaintext_len = strlen(plaintext);

    // Allocate memory for the ciphertext
    char *ciphertext = malloc(plaintext_len + 1);
    if (ciphertext == NULL) {
        return NULL;
    }

    // Encrypt the plaintext character by character
    for (int i = 0; i < plaintext_len; i++) {
        ciphertext[i] = plaintext[i] ^ key[i % key_len];
    }

    // Terminate the ciphertext with a null character
    ciphertext[plaintext_len] = '\0';

    // Return the ciphertext
    return ciphertext;
}

// Decrypt the ciphertext using the key
char *decrypt(char *ciphertext, char *key) {
    // Calculate the length of the key and ciphertext
    int key_len = strlen(key);
    int ciphertext_len = strlen(ciphertext);

    // Allocate memory for the plaintext
    char *plaintext = malloc(ciphertext_len + 1);
    if (plaintext == NULL) {
        return NULL;
    }

    // Decrypt the ciphertext character by character
    for (int i = 0; i < ciphertext_len; i++) {
        plaintext[i] = ciphertext[i] ^ key[i % key_len];
    }

    // Terminate the plaintext with a null character
    plaintext[ciphertext_len] = '\0';

    // Return the plaintext
    return plaintext;
}