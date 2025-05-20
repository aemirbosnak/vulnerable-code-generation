//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY  "Mycroft"

// Elementary, my dear Watson!
char *encrypt(char *plaintext) {
    int keylen = strlen(KEY);
    int ptlen = strlen(plaintext);

    char *ciphertext = malloc(ptlen + 1);
    if (!ciphertext) {
        return NULL; // Out of memory!
    }

    for (int i = 0; i < ptlen; i++) {
        ciphertext[i] = plaintext[i] ^ KEY[i % keylen];
    }
    ciphertext[ptlen] = '\0';

    return ciphertext;
}

// The game is afoot!
char *decrypt(char *ciphertext) {
    int keylen = strlen(KEY);
    int ctlen = strlen(ciphertext);

    char *plaintext = malloc(ctlen + 1);
    if (!plaintext) {
        return NULL; // Out of memory!
    }

    for (int i = 0; i < ctlen; i++) {
        plaintext[i] = ciphertext[i] ^ KEY[i % keylen];
    }
    plaintext[ctlen] = '\0';

    return plaintext;
}

int main() {
    char *plaintext = "The dog did it.";
    char *ciphertext = encrypt(plaintext);
    char *decryptedtext = decrypt(ciphertext);

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);
    printf("Decrypted text: %s\n", decryptedtext);

    free(ciphertext);
    free(decryptedtext);

    return 0;
}