//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    size_t size;
    char *data;
} Ciphertext;

Ciphertext *encrypt(const char *plaintext, const char *key) {
    size_t plaintext_len = strlen(plaintext);
    size_t key_len = strlen(key);

    Ciphertext *ciphertext = malloc(sizeof(Ciphertext));
    ciphertext->data = malloc(plaintext_len + 1);
    ciphertext->size = plaintext_len;

    for (size_t i = 0; i < plaintext_len; i++) {
        ciphertext->data[i] = plaintext[i] ^ key[i % key_len];
    }

    ciphertext->data[plaintext_len] = '\0';

    return ciphertext;
}

char *decrypt(const Ciphertext *ciphertext, const char *key) {
    size_t key_len = strlen(key);
    char *plaintext = malloc(ciphertext->size + 1);

    for (size_t i = 0; i < ciphertext->size; i++) {
        plaintext[i] = ciphertext->data[i] ^ key[i % key_len];
    }

    plaintext[ciphertext->size] = '\0';

    return plaintext;
}

int main() {
    const char *plaintext = "This is a secret message.";
    const char *key = "My secret key";

    Ciphertext *ciphertext = encrypt(plaintext, key);

    printf("Ciphertext: %s\n", ciphertext->data);

    char *decrypted_plaintext = decrypt(ciphertext, key);

    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    free(ciphertext->data);
    free(ciphertext);
    free(decrypted_plaintext);

    return 0;
}