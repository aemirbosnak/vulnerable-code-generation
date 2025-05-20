//FormAI DATASET v1.0 Category: Modern Encryption ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 16
#define KEY_SIZE 32

typedef unsigned char byte;

struct CipherState {
    byte key[KEY_SIZE];
    byte counter[BLOCK_SIZE];
};

void print_bytes(byte *data, int size) {
    for (int i = 0; i < size; i++) {
        printf("%02X ", data[i]);
    }
    printf("\n");
}

void xor(byte *dst, byte *src1, byte *src2, int size) {
    for (int i = 0; i < size; i++) {
        dst[i] = src1[i] ^ src2[i];
    }
}

void init_cipher_state(struct CipherState *state, byte *key, byte *counter) {
    memcpy(state->key, key, KEY_SIZE);
    memcpy(state->counter, counter, BLOCK_SIZE);
}

void increment_counter(struct CipherState *state) {
    for (int i = BLOCK_SIZE - 1; i >= 0; i--) {
        if (state->counter[i] == 0xFF) {
            state->counter[i] = 0x00;
        }
        else {
            state->counter[i]++;
            break;
        }
    }
}

void encrypt_block(struct CipherState *state, byte *block) {
    byte keystream[BLOCK_SIZE];
    xor(keystream, state->key, state->counter, BLOCK_SIZE);
    xor(block, block, keystream, BLOCK_SIZE);
    increment_counter(state);
}

void encrypt(struct CipherState *state, byte *data, int size) {
    for (int i = 0; i < size; i += BLOCK_SIZE) {
        encrypt_block(state, data + i);
    }
}

int main() {
    byte key[KEY_SIZE] = { 0 };
    byte counter[BLOCK_SIZE] = { 0 };

    struct CipherState state;
    init_cipher_state(&state, key, counter);

    byte data[] = { 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B };
    int size = sizeof(data);

    printf("Plaintext: ");
    print_bytes(data, size);

    encrypt(&state, data, size);

    printf("Ciphertext: ");
    print_bytes(data, size);

    return 0;
}