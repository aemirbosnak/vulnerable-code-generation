//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Encrypt a string using a simple XOR cipher.
 *
 * @param plaintext The plaintext to encrypt.
 * @param key The encryption key.
 * @return The ciphertext.
 */
char *encrypt(char *plaintext, char *key) {
    char *ciphertext = malloc(strlen(plaintext) + 1);
    int keylen = strlen(key);

    for (int i = 0; i < strlen(plaintext); i++) {
        ciphertext[i] = plaintext[i] ^ key[i % keylen];
    }

    ciphertext[strlen(plaintext)] = '\0';

    return ciphertext;
}

/*
 * Decrypt a string using a simple XOR cipher.
 *
 * @param ciphertext The ciphertext to decrypt.
 * @param key The decryption key.
 * @return The plaintext.
 */
char *decrypt(char *ciphertext, char *key) {
    char *plaintext = malloc(strlen(ciphertext) + 1);
    int keylen = strlen(key);

    for (int i = 0; i < strlen(ciphertext); i++) {
        plaintext[i] = ciphertext[i] ^ key[i % keylen];
    }

    plaintext[strlen(ciphertext)] = '\0';

    return plaintext;
}

int main() {
    char *plaintext = "Hello, world!";
    char *key = "secret";

    char *ciphertext = encrypt(plaintext, key);
    printf("Ciphertext: %s\n", ciphertext);

    char *decryptedtext = decrypt(ciphertext, key);
    printf("Decrypted text: %s\n", decryptedtext);

    free(ciphertext);
    free(decryptedtext);

    return 0;
}