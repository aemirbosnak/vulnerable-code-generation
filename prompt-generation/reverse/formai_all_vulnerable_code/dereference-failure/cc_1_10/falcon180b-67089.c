//Falcon-180B DATASET v1.0 Category: Encryption ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

typedef struct {
    char key[KEY_SIZE];
    int rounds;
} EncryptionContext;

void generate_key(char* key, int key_size) {
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 256;
    }
}

void encrypt(EncryptionContext* ctx, char* input, char* output) {
    int input_len = strlen(input);
    int output_len = input_len + KEY_SIZE - 1;

    char* state = malloc(output_len * sizeof(char));
    memset(state, 0, output_len);

    int state_pos = 0;
    for (int i = 0; i < input_len; i += BLOCK_SIZE) {
        char* input_block = input + i;
        char* state_block = state + state_pos;

        for (int j = 0; j < BLOCK_SIZE; j++) {
            state_block[j] = input_block[j] ^ ctx->key[state_pos % KEY_SIZE];
        }

        state_pos++;
    }

    memcpy(output, state, output_len);
    free(state);
}

void decrypt(EncryptionContext* ctx, char* input, char* output) {
    int input_len = strlen(input);
    int output_len = input_len - KEY_SIZE + 1;

    char* state = malloc(output_len * sizeof(char));
    memset(state, 0, output_len);

    int state_pos = 0;
    for (int i = 0; i < input_len; i += BLOCK_SIZE) {
        char* input_block = input + i;
        char* state_block = state + state_pos;

        for (int j = 0; j < BLOCK_SIZE; j++) {
            state_block[j] = input_block[j] ^ ctx->key[(state_pos + j) % KEY_SIZE];
        }

        state_pos++;
    }

    memcpy(output, state, output_len);
    free(state);
}

int main() {
    EncryptionContext ctx;
    generate_key(ctx.key, KEY_SIZE);
    ctx.rounds = 10;

    char* input = "Hello, World!";
    char* output = malloc(strlen(input) + KEY_SIZE - 1);

    encrypt(&ctx, input, output);
    printf("Encrypted: %s\n", output);

    decrypt(&ctx, output, output);
    printf("Decrypted: %s\n", output);

    free(output);
    return 0;
}