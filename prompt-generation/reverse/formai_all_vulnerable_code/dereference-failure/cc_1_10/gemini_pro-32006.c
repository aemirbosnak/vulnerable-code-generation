//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a string using the Caesar cipher
char *caesar_encrypt(char *plaintext, int key) {
    char *ciphertext = malloc(strlen(plaintext) + 1);

    for (int i = 0; i < strlen(plaintext); i++) {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            ciphertext[i] = ((plaintext[i] - 'a' + key) % 26) + 'a';
        } else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            ciphertext[i] = ((plaintext[i] - 'A' + key) % 26) + 'A';
        } else {
            ciphertext[i] = plaintext[i];
        }
    }

    ciphertext[strlen(plaintext)] = '\0';

    return ciphertext;
}

// Function to decrypt a string using the Caesar cipher
char *caesar_decrypt(char *ciphertext, int key) {
    char *plaintext = malloc(strlen(ciphertext) + 1);

    for (int i = 0; i < strlen(ciphertext); i++) {
        if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            plaintext[i] = ((ciphertext[i] - 'a' - key + 26) % 26) + 'a';
        } else if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            plaintext[i] = ((ciphertext[i] - 'A' - key + 26) % 26) + 'A';
        } else {
            plaintext[i] = ciphertext[i];
        }
    }

    plaintext[strlen(ciphertext)] = '\0';

    return plaintext;
}

int main() {
    // Get the plaintext from the user
    char plaintext[100];
    printf("Enter the plaintext: ");
    fgets(plaintext, 100, stdin);

    // Get the key from the user
    int key;
    printf("Enter the key: ");
    scanf("%d", &key);

    // Encrypt the plaintext using the Caesar cipher
    char *ciphertext = caesar_encrypt(plaintext, key);

    // Print the ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext using the Caesar cipher
    char *decryptedtext = caesar_decrypt(ciphertext, key);

    // Print the decrypted text
    printf("Decrypted text: %s\n", decryptedtext);

    // Free the allocated memory
    free(ciphertext);
    free(decryptedtext);

    return 0;
}