//FormAI DATASET v1.0 Category: Modern Encryption ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_SIZE 128
#define BLOCK_SIZE 16

typedef struct {
    unsigned char round_key[KEY_SIZE / 8];
    unsigned char counter[BLOCK_SIZE];
    unsigned int block_count;
} ctx;

void generate_round_key(unsigned char* round_key) {
    int i;
    srand(time(NULL));

    for (i = 0; i < KEY_SIZE / 8; i++) {
        round_key[i] = rand() & 0xFF;
    }
}

void xor_block(unsigned char* a, unsigned char* b) {
    int i;
    for (i = 0; i < BLOCK_SIZE; i++) {
        a[i] ^= b[i];
    }
}

void increment_block(unsigned char* counter) {
    int i;

    for (i = BLOCK_SIZE - 1; i >= 0 && ++counter[i] == 0; i--);
}

void encrypt_block(unsigned char* plain_text, unsigned char* round_key, unsigned char* counter, unsigned char* cipher_text) {
    int i;
    unsigned char keystream[BLOCK_SIZE];

    for (i = 0; i < BLOCK_SIZE; i++) {
        keystream[i] = counter[i];
    }

    for (i = 0; i < KEY_SIZE / 8; i += BLOCK_SIZE) {
        xor_block(&keystream[0], &round_key[i]);
    }

    xor_block(plain_text, keystream);
    memcpy(cipher_text, plain_text, BLOCK_SIZE);
}

void encrypt(ctx* context, unsigned char* plain_text, size_t size, unsigned char* cipher_text) {
    int i, j;

    for (i = 0; i < size; i += BLOCK_SIZE) {
        encrypt_block(&plain_text[i], context->round_key, context->counter, &cipher_text[i]);
        increment_block(context->counter);
    }

    context->block_count += size / BLOCK_SIZE;
}

void init_ctx(ctx* context) {
    generate_round_key(context->round_key);

    int i;
    for (i = 0; i < BLOCK_SIZE; i++) {
        context->counter[i] = 0;
    }

    context->block_count = 0;
}

int main() {
    ctx context;
    init_ctx(&context);

    unsigned char message[] = "This is a test message to be encrypted with our algorithm.";
    size_t length = strlen(message);

    // Add padding to ensure message length is divisible by block size
    size_t padded_length = length + (BLOCK_SIZE - (length % BLOCK_SIZE));
    unsigned char* padded_message = (unsigned char*)malloc(padded_length);
    memcpy(padded_message, message, length);
    memset(padded_message + length, (padded_length - length), padded_length - length);

    unsigned char* encrypted_message = (unsigned char*)malloc(padded_length);

    encrypt(&context, padded_message, padded_length, encrypted_message);

    printf("Encrypted Message: ");

    for (int i = 0; i < padded_length; i++) {
        printf("%02X ", encrypted_message[i]);
    }

    printf("\nBlock count: %u\n", context.block_count);

    free(padded_message);
    free(encrypted_message);

    return 0;
}