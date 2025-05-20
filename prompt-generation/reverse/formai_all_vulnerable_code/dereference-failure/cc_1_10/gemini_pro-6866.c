//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

static uint8_t *
xor_encrypt(const uint8_t * plaintext,
            const size_t plaintext_len,
            const uint8_t * key,
            const size_t key_len)
{
    uint8_t * ciphertext = malloc(plaintext_len);
    if (ciphertext == NULL) {
        fprintf(stderr, "** Memory allocation failed. **\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < plaintext_len; i++) {
        ciphertext[i] = plaintext[i] ^ key[i % key_len];
    }

    return ciphertext;
}

static uint8_t *
xor_decrypt(const uint8_t * ciphertext,
            const size_t ciphertext_len,
            const uint8_t * key,
            const size_t key_len)
{
    return xor_encrypt(ciphertext, ciphertext_len, key, key_len);
}

int
main(void)
{
    const char * plaintext = "This is a secret message.";
    const char * key = "abcdefghijklmnopqrstuvwxyz";

    puts("** Original plaintext: **");
    puts(plaintext);

    size_t plaintext_len = strlen(plaintext);

    printf("\n** Key: **");
    for (size_t i = 0; i < strlen(key); i++) {
        printf("%c", key[i]);
    }
    puts("");

    uint8_t * ciphertext = xor_encrypt(plaintext, plaintext_len, key, strlen(key));

    printf("\n** Encrypted ciphertext: **");
    for (size_t i = 0; i < plaintext_len; i++) {
        printf("%02x", ciphertext[i]);
    }
    puts("");

    uint8_t * decrypted_plaintext = xor_decrypt(ciphertext, plaintext_len, key, strlen(key));

    puts("\n** Decrypted plaintext: **");
    puts(decrypted_plaintext);

    free(ciphertext);
    free(decrypted_plaintext);

    return EXIT_SUCCESS;
}