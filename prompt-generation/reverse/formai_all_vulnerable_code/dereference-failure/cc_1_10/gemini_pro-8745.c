//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: decentralized
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <openssl/aes.h>

#define KEY_SIZE 32
#define BLOCK_SIZE 16

typedef struct {
    unsigned char key[KEY_SIZE];
    unsigned char iv[BLOCK_SIZE];
    AES_KEY encrypt_key;
    AES_KEY decrypt_key;
} crypto_state;

void init_crypto_state(crypto_state *state, unsigned char *key, unsigned char *iv) {
    memcpy(state->key, key, KEY_SIZE);
    memcpy(state->iv, iv, BLOCK_SIZE);
    AES_set_encrypt_key(state->key, KEY_SIZE * 8, &state->encrypt_key);
    AES_set_decrypt_key(state->key, KEY_SIZE * 8, &state->decrypt_key);
}

void encrypt_block(crypto_state *state, unsigned char *plaintext, unsigned char *ciphertext) {
    AES_encrypt(plaintext, ciphertext, &state->encrypt_key);
}

void decrypt_block(crypto_state *state, unsigned char *ciphertext, unsigned char *plaintext) {
    AES_decrypt(ciphertext, plaintext, &state->decrypt_key);
}

void encrypt_stream(crypto_state *state, FILE *plaintext, FILE *ciphertext) {
    unsigned char buffer[BLOCK_SIZE];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, BLOCK_SIZE, plaintext)) > 0) {
        if (bytes_read < BLOCK_SIZE) {
            memset(buffer + bytes_read, 0, BLOCK_SIZE - bytes_read);
        }
        encrypt_block(state, buffer, buffer);
        fwrite(buffer, 1, BLOCK_SIZE, ciphertext);
    }
}

void decrypt_stream(crypto_state *state, FILE *ciphertext, FILE *plaintext) {
    unsigned char buffer[BLOCK_SIZE];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, BLOCK_SIZE, ciphertext)) > 0) {
        decrypt_block(state, buffer, buffer);
        fwrite(buffer, 1, bytes_read, plaintext);
    }
}

int main(int argc, char **argv) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <key> <iv> <input> <output>\n", argv[0]);
        return 1;
    }

    crypto_state state;
    init_crypto_state(&state, argv[1], argv[2]);

    FILE *input = fopen(argv[3], "rb");
    if (input == NULL) {
        perror("fopen");
        return 1;
    }

    FILE *output = fopen(argv[4], "wb");
    if (output == NULL) {
        perror("fopen");
        return 1;
    }

    if (strcmp(argv[3], "-") == 0) {
        encrypt_stream(&state, stdin, output);
    } else {
        encrypt_stream(&state, input, output);
    }

    fclose(input);
    fclose(output);

    return 0;
}