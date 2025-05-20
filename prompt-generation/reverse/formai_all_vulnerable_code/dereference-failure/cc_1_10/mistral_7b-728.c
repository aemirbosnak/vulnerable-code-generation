//MISTRAL-7B DATASET v1.0 Category: Encryption ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 16
#define BUFFER_SIZE 1024

void encrypt_file(const char *input_file, const char *output_file, const char *key) {
    FILE *input = fopen(input_file, "rb");
    FILE *output = fopen(output_file, "wb");

    if (!input || !output) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    unsigned char iv[BLOCK_SIZE];
    RAND_bytes(iv, BLOCK_SIZE);

    AES_KEY aes_key;
    AES_set_encrypt_key((unsigned char *)key, KEY_SIZE * 8, &aes_key);

    unsigned char buffer[BUFFER_SIZE];
    int len;

    while ((len = fread(buffer, 1, BUFFER_SIZE, input))) {
        unsigned char *data = malloc(len + BLOCK_SIZE);
        memcpy(data, buffer, len);
        memset(data + len, 0x00, BLOCK_SIZE - len);

        AES_cbc_encrypt(data, data, len, &aes_key, iv, AES_ENCRYPT);

        fwrite(data, len + BLOCK_SIZE, 1, output);
        free(data);
    }

    fclose(input);
    fclose(output);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s input_file output_file key\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    encrypt_file(argv[1], argv[2], argv[3]);
    return EXIT_SUCCESS;
}