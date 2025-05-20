//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key.
#define KEY "my secret key"

// Encrypt the plaintext using the XOR cipher.
char *encrypt(char *plaintext) {
    int key_length = strlen(KEY);
    int plaintext_length = strlen(plaintext);
    char *ciphertext = malloc(plaintext_length + 1);

    for (int i = 0; i < plaintext_length; i++) {
        ciphertext[i] = plaintext[i] ^ KEY[i % key_length];
    }

    ciphertext[plaintext_length] = '\0';

    return ciphertext;
}

// Decrypt the ciphertext using the XOR cipher.
char *decrypt(char *ciphertext) {
    int key_length = strlen(KEY);
    int ciphertext_length = strlen(ciphertext);
    char *plaintext = malloc(ciphertext_length + 1);

    for (int i = 0; i < ciphertext_length; i++) {
        plaintext[i] = ciphertext[i] ^ KEY[i % key_length];
    }

    plaintext[ciphertext_length] = '\0';

    return plaintext;
}

// Print the usage information.
void usage() {
    printf("Usage: ./encrypt [plaintext]\n");
    printf("Example: ./encrypt Hello world\n");
}

// Main function.
int main(int argc, char **argv) {
    // Check if the user provided enough arguments.
    if (argc < 2) {
        usage();
        return 1;
    }

    // Get the plaintext from the command line arguments.
    char *plaintext = argv[1];

    // Encrypt the plaintext.
    char *ciphertext = encrypt(plaintext);

    // Print the ciphertext.
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext.
    char *decrypted_plaintext = decrypt(ciphertext);

    // Print the decrypted plaintext.
    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    // Free the allocated memory.
    free(ciphertext);
    free(decrypted_plaintext);

    return 0;
}