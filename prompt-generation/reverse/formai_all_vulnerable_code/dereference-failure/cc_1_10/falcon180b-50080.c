//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define KEY_LENGTH 16
#define BLOCK_SIZE 64
#define ROUNDS 16

typedef struct {
    int size;
    unsigned char *data;
} Block;

void encrypt(Block *block, unsigned char *key) {
    unsigned char *data = block->data;
    int size = block->size;
    int i, j;
    unsigned char round_key[KEY_LENGTH];

    for (i = 0; i < ROUNDS; i++) {
        for (j = 0; j < KEY_LENGTH; j++) {
            round_key[j] = key[i * KEY_LENGTH + j];
        }
        int offset = i * BLOCK_SIZE;
        int k;
        for (k = 0; k < BLOCK_SIZE; k++) {
            if (k % 2 == 0) {
                data[offset + k] ^= round_key[k / 2];
            } else {
                data[offset + k] ^= round_key[15 - (k / 2)];
            }
        }
    }
}

void decrypt(Block *block, unsigned char *key) {
    encrypt(block, key);
}

void generate_key(unsigned char *key) {
    srand(time(NULL));
    int i;
    for (i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 256;
    }
}

int main() {
    Block block;
    unsigned char key[KEY_LENGTH];

    printf("Enter message: ");
    fgets(block.data, BLOCK_SIZE, stdin);
    block.size = strlen(block.data);

    printf("Enter key: ");
    fgets(key, KEY_LENGTH, stdin);

    generate_key(key);

    encrypt(&block, key);

    printf("Encrypted message: ");
    for (int i = 0; i < block.size; i++) {
        printf("%02X ", block.data[i]);
    }
    printf("\n");

    decrypt(&block, key);

    printf("Decrypted message: %s\n", block.data);

    return 0;
}