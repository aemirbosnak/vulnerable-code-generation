//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: automated
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1024

int main(int argc, char **argv) {
    char *key, *plaintext, *ciphertext, *decryptedtext;
    int keylen, plaintextlen, ciphertextlen, decryptedtextlen;
    FILE *fp;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s key plaintext ciphertext\n", argv[0]);
        return EXIT_FAILURE;
    }

    key = argv[1];
    keylen = strlen(key);
    plaintext = argv[2];
    plaintextlen = strlen(plaintext);

    // Encrypt the plaintext using the key
    ciphertext = malloc(BUFSIZE);
    ciphertextlen = encrypt(plaintext, plaintextlen, key, keylen, ciphertext);
    if (ciphertextlen == -1) {
        fprintf(stderr, "Error encrypting plaintext.\n");
        return EXIT_FAILURE;
    }

    // Decrypt the ciphertext using the key
    decryptedtext = malloc(BUFSIZE);
    decryptedtextlen = decrypt(ciphertext, ciphertextlen, key, keylen, decryptedtext);
    if (decryptedtextlen == -1) {
        fprintf(stderr, "Error decrypting ciphertext.\n");
        return EXIT_FAILURE;
    }

    // Write the ciphertext and decrypted text to files
    fp = fopen(argv[3], "w");
    if (fp == NULL) {
        fprintf(stderr, "Error opening ciphertext file.\n");
        return EXIT_FAILURE;
    }
    fwrite(ciphertext, ciphertextlen, 1, fp);
    fclose(fp);

    fp = fopen("decrypted.txt", "w");
    if (fp == NULL) {
        fprintf(stderr, "Error opening decrypted text file.\n");
        return EXIT_FAILURE;
    }
    fwrite(decryptedtext, decryptedtextlen, 1, fp);
    fclose(fp);

    // Check that the decrypted text matches the plaintext
    assert(strcmp(decryptedtext, plaintext) == 0);

    // Free the allocated memory
    free(ciphertext);
    free(decryptedtext);

    return EXIT_SUCCESS;
}

int encrypt(const char *plaintext, int plaintextlen, const char *key, int keylen,
            char *ciphertext) {
    int i, j, k;
    for (i = 0, j = 0, k = 0; i < plaintextlen; i++) {
        ciphertext[i] = plaintext[i] ^ key[k];
        k = (k + 1) % keylen;
    }
    return plaintextlen;
}

int decrypt(const char *ciphertext, int ciphertextlen, const char *key, int keylen,
            char *decryptedtext) {
    int i, j, k;
    for (i = 0, j = 0, k = 0; i < ciphertextlen; i++) {
        decryptedtext[i] = ciphertext[i] ^ key[k];
        k = (k + 1) % keylen;
    }
    return ciphertextlen;
}