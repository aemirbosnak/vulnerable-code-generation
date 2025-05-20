//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *plaintext;
    size_t plaintext_len;
    char *ciphertext;
    size_t ciphertext_len;
} crypto_buffer;

crypto_buffer *crypto_buffer_new(const char *plaintext)
{
    crypto_buffer *buf = malloc(sizeof(crypto_buffer));
    if (!buf)
        return NULL;

    buf->plaintext = malloc(strlen(plaintext) + 1);
    if (!buf->plaintext) {
        free(buf);
        return NULL;
    }

    strcpy(buf->plaintext, plaintext);
    buf->plaintext_len = strlen(buf->plaintext);
    buf->ciphertext = NULL;
    buf->ciphertext_len = 0;

    return buf;
}

void crypto_buffer_free(crypto_buffer *buf)
{
    if (!buf)
        return;

    free(buf->plaintext);
    free(buf->ciphertext);
    free(buf);
}

int crypto_encrypt(crypto_buffer *buf, const char *key)
{
    int i, j, k;
    size_t key_len = strlen(key);

    if (!buf || !key)
        return -1;

    buf->ciphertext = malloc(buf->plaintext_len + 1);
    if (!buf->ciphertext)
        return -1;

    for (i = 0, j = 0; i < buf->plaintext_len; i++) {
        k = j % key_len;
        buf->ciphertext[i] = buf->plaintext[i] ^ key[k];
        j++;
    }

    buf->ciphertext[buf->plaintext_len] = '\0';
    buf->ciphertext_len = buf->plaintext_len;

    return 0;
}

int crypto_decrypt(crypto_buffer *buf, const char *key)
{
    int i, j, k;
    size_t key_len = strlen(key);

    if (!buf || !key)
        return -1;

    if (!buf->ciphertext)
        return -1;

    for (i = 0, j = 0; i < buf->ciphertext_len; i++) {
        k = j % key_len;
        buf->plaintext[i] = buf->ciphertext[i] ^ key[k];
        j++;
    }

    buf->plaintext[buf->ciphertext_len] = '\0';
    buf->plaintext_len = buf->ciphertext_len;

    free(buf->ciphertext);
    buf->ciphertext = NULL;
    buf->ciphertext_len = 0;

    return 0;
}

int main(int argc, char *argv[])
{
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <plaintext> <key>\n", argv[0]);
        return EXIT_FAILURE;
    }

    crypto_buffer *buf = crypto_buffer_new(argv[1]);
    if (!buf) {
        fprintf(stderr, "Failed to allocate memory for the crypto buffer\n");
        return EXIT_FAILURE;
    }

    int ret = crypto_encrypt(buf, argv[2]);
    if (ret < 0) {
        fprintf(stderr, "Failed to encrypt the plaintext\n");
        crypto_buffer_free(buf);
        return EXIT_FAILURE;
    }

    printf("Ciphertext: %s\n", buf->ciphertext);

    ret = crypto_decrypt(buf, argv[2]);
    if (ret < 0) {
        fprintf(stderr, "Failed to decrypt the ciphertext\n");
        crypto_buffer_free(buf);
        return EXIT_FAILURE;
    }

    printf("Plaintext: %s\n", buf->plaintext);

    crypto_buffer_free(buf);

    return EXIT_SUCCESS;
}