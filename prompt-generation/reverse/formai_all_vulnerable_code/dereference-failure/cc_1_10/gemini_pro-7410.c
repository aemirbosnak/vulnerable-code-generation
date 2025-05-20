//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

char *encrypt(char *plaintext, char *key) {
    int key_length = strlen(key);
    int plaintext_length = strlen(plaintext);

    char *ciphertext = malloc(plaintext_length + 1);
    if (ciphertext == NULL) {
        return NULL;
    }

    for (int i = 0; i < plaintext_length; i++) {
        ciphertext[i] = plaintext[i] ^ key[i % key_length];
    }

    ciphertext[plaintext_length] = '\0';

    return ciphertext;
}

char *decrypt(char *ciphertext, char *key) {
    int key_length = strlen(key);
    int ciphertext_length = strlen(ciphertext);

    char *plaintext = malloc(ciphertext_length + 1);
    if (plaintext == NULL) {
        return NULL;
    }

    for (int i = 0; i < ciphertext_length; i++) {
        plaintext[i] = ciphertext[i] ^ key[i % key_length];
    }

    plaintext[ciphertext_length] = '\0';

    return plaintext;
}

int main() {
    char *plaintext = "Hello, world!";
    char *key = "secret";

    char *ciphertext = encrypt(plaintext, key);
    if (ciphertext == NULL) {
        return EXIT_FAILURE;
    }

    printf("Ciphertext: %s\n", ciphertext);

    char *decrypted_plaintext = decrypt(ciphertext, key);
    if (decrypted_plaintext == NULL) {
        return EXIT_FAILURE;
    }

    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    free(ciphertext);
    free(decrypted_plaintext);

    return EXIT_SUCCESS;
}