//FormAI DATASET v1.0 Category: Modern Encryption ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK_SIZE 16

typedef unsigned char byte;

void encrypt(byte *plaintext, byte *key, size_t length)
{
    byte *iv = malloc(CHUNK_SIZE * sizeof(byte));
    byte *output = malloc(length * sizeof(byte));

    size_t i, j, k;
    byte prev = 0;

    for (i = 0; i < length; i += CHUNK_SIZE) {
        memcpy(iv, &plaintext[i], CHUNK_SIZE);

        for (j = 0; j < CHUNK_SIZE; j++) {
            prev ^= iv[j];
        }

        output[i] = iv[0] ^ key[0];
        prev = output[i];

        for (j = 1; j < CHUNK_SIZE; j++) {
            output[i + j] = iv[j] ^ key[j] ^ output[i + j - 1];
            prev ^= output[i + j];
        }

        for (k = i; k < i + CHUNK_SIZE; k++) {
            plaintext[k] = output[k];
        }
    }

    free(iv);
    free(output);
}

void decrypt(byte *plaintext, byte *key, size_t length)
{
    byte *iv = malloc(CHUNK_SIZE * sizeof(byte));
    byte *output = malloc(length * sizeof(byte));

    size_t i, j, k;
    byte prev = 0;

    for (i = 0; i < length; i += CHUNK_SIZE) {
        memcpy(iv, &plaintext[i], CHUNK_SIZE);

        for (j = 0; j < CHUNK_SIZE; j++) {
            prev ^= iv[j];
        }

        output[i] = iv[0] ^ key[0];
        prev = iv[0];

        for (j = 1; j < CHUNK_SIZE; j++) {
            output[i + j] = iv[j] ^ key[j] ^ iv[j - 1];
            prev ^= output[i + j - 1];
        }

        for (k = i; k < i + CHUNK_SIZE; k++) {
            plaintext[k] = output[k];
        }
    }

    free(iv);
    free(output);
}

int main(void)
{
    byte plaintext[] = "Hello, World!";
    byte key[] = "secretkey123456";

    encrypt(plaintext, key, sizeof(plaintext));

    printf("Encrypted text: %s\n", plaintext);

    decrypt(plaintext, key, sizeof(plaintext));

    printf("Decrypted text: %s\n", plaintext);

    return 0;
}