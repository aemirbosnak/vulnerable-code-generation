//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 128
#define BLOCK_SIZE 16

typedef struct {
    unsigned char key[KEY_SIZE];
    unsigned char iv[BLOCK_SIZE];
} aes_key_t;

void aes_init_key(aes_key_t *key, const unsigned char *pass, unsigned int len) {
    // ...
}

void aes_encrypt(aes_key_t *key, const unsigned char *in, unsigned int in_len, unsigned char *out) {
    // ...
}

void aes_decrypt(aes_key_t *key, const unsigned char *in, unsigned int in_len, unsigned char *out) {
    // ...
}

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <key> <in> <out>\n", argv[0]);
        return EXIT_FAILURE;
    }

    aes_key_t key;
    aes_init_key(&key, (const unsigned char *)argv[1], strlen(argv[1]));

    FILE *in = fopen(argv[2], "rb");
    if (in == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    FILE *out = fopen(argv[3], "wb");
    if (out == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    unsigned char buf[BLOCK_SIZE];
    size_t len;
    while ((len = fread(buf, 1, BLOCK_SIZE, in)) > 0) {
        aes_encrypt(&key, buf, len, buf);
        fwrite(buf, 1, len, out);
    }

    fclose(in);
    fclose(out);

    return EXIT_SUCCESS;
}