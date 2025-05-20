//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This is the key for encryption. It can be any string.
char key[] = "I love cheese";

// This function encrypts the given string using the XOR cipher.
char *encrypt(char *plaintext) {
    int keylen = strlen(key);
    char *ciphertext = malloc(strlen(plaintext) + 1);
    for (int i = 0; i < strlen(plaintext); i++) {
        ciphertext[i] = plaintext[i] ^ key[i % keylen];
    }
    ciphertext[strlen(plaintext)] = '\0';
    return ciphertext;
}

// This function decrypts the given string using the XOR cipher.
char *decrypt(char *ciphertext) {
    int keylen = strlen(key);
    char *plaintext = malloc(strlen(ciphertext) + 1);
    for (int i = 0; i < strlen(ciphertext); i++) {
        plaintext[i] = ciphertext[i] ^ key[i % keylen];
    }
    plaintext[strlen(ciphertext)] = '\0';
    return plaintext;
}

int main() {
    // Get the plaintext from the user.
    printf("Enter the plaintext: ");
    char *plaintext = malloc(1024);
    fgets(plaintext, 1024, stdin);

    // Encrypt the plaintext using the XOR cipher.
    char *ciphertext = encrypt(plaintext);

    // Print the ciphertext.
    printf("The ciphertext is: %s\n", ciphertext);

    // Decrypt the ciphertext using the XOR cipher.
    char *decryptedtext = decrypt(ciphertext);

    // Print the decrypted text.
    printf("The decrypted text is: %s\n", decryptedtext);

    // Free the allocated memory.
    free(plaintext);
    free(ciphertext);
    free(decryptedtext);

    return 0;
}