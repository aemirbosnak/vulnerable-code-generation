//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Key for encryption and decryption
#define KEY "MySecretK3y!"

// Function to encrypt a string using XOR encryption
char *encrypt(char *plaintext) {
    int keylen = strlen(KEY);
    int textlen = strlen(plaintext);

    // Allocate memory for the encrypted text
    char *ciphertext = malloc(textlen + 1);
    if (ciphertext == NULL) {
        return NULL;
    }

    // Perform XOR encryption
    for (int i = 0; i < textlen; i++) {
        ciphertext[i] = plaintext[i] ^ KEY[i % keylen];
    }

    // Terminate the encrypted string
    ciphertext[textlen] = '\0';

    return ciphertext;
}

// Function to decrypt a string using XOR encryption
char *decrypt(char *ciphertext) {
    int keylen = strlen(KEY);
    int textlen = strlen(ciphertext);

    // Allocate memory for the decrypted text
    char *plaintext = malloc(textlen + 1);
    if (plaintext == NULL) {
        return NULL;
    }

    // Perform XOR decryption
    for (int i = 0; i < textlen; i++) {
        plaintext[i] = ciphertext[i] ^ KEY[i % keylen];
    }

    // Terminate the decrypted string
    plaintext[textlen] = '\0';

    return plaintext;
}

// Main function
int main() {
    // Get the plaintext from the user
    char plaintext[100];
    printf("Enter the plaintext: ");
    fgets(plaintext, 100, stdin);

    // Encrypt the plaintext
    char *ciphertext = encrypt(plaintext);
    if (ciphertext == NULL) {
        printf("Error: Could not allocate memory for ciphertext.\n");
        return 1;
    }

    // Print the encrypted text
    printf("Encrypted text: %s\n", ciphertext);

    // Decrypt the ciphertext
    char *decryptedtext = decrypt(ciphertext);
    if (decryptedtext == NULL) {
        printf("Error: Could not allocate memory for decrypted text.\n");
        return 1;
    }

    // Print the decrypted text
    printf("Decrypted text: %s\n", decryptedtext);

    // Free the allocated memory
    free(ciphertext);
    free(decryptedtext);

    return 0;
}