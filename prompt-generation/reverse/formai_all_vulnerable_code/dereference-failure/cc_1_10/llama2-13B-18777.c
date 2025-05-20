//LLAMA2-13B DATASET v1.0 Category: Modern Encryption ; Style: calm
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define BLOCK_SIZE 16
#define KEY_SIZE 24

typedef struct {
    uint8_t key[KEY_SIZE];
    uint8_t block[BLOCK_SIZE];
} cipher_state;

void init_cipher(cipher_state *state) {
    memset(state->key, 0, KEY_SIZE);
    memset(state->block, 0, BLOCK_SIZE);
}

void encrypt(cipher_state *state, const uint8_t *plaintext, size_t plaintext_len) {
    size_t i, j;
    for (i = 0; i < plaintext_len; i += BLOCK_SIZE) {
        for (j = 0; j < BLOCK_SIZE; j++) {
            state->block[j] = plaintext[i + j] ^ state->key[j];
        }
        memcpy(state->block, state->block + j, BLOCK_SIZE - j);
    }
}

void decrypt(cipher_state *state, const uint8_t *ciphertext, size_t ciphertext_len) {
    size_t i, j;
    for (i = 0; i < ciphertext_len; i += BLOCK_SIZE) {
        for (j = 0; j < BLOCK_SIZE; j++) {
            state->block[j] = ciphertext[i + j] ^ state->key[j];
        }
        memcpy(state->block, state->block + j, BLOCK_SIZE - j);
    }
}

int main() {
    cipher_state state;
    init_cipher(&state);

    uint8_t plaintext[] = "The quick brown fox jumps over the lazy dog";
    size_t plaintext_len = sizeof(plaintext) / sizeof(plaintext[0]);

    uint8_t ciphertext[plaintext_len];
    encrypt(&state, plaintext, plaintext_len);
    memcpy(ciphertext, state.block, plaintext_len);

    printf("Original plaintext: %s\n", plaintext);
    printf("Encrypted ciphertext: %s\n", ciphertext);

    uint8_t decrypted[plaintext_len];
    decrypt(&state, ciphertext, plaintext_len);
    memcpy(decrypted, state.block, plaintext_len);

    printf("Decrypted plaintext: %s\n", decrypted);

    return 0;
}