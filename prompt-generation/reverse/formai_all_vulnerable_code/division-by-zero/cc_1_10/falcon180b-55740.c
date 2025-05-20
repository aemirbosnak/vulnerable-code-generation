//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 32
#define MAX_BLOCK_SIZE 16

typedef struct {
    char key[MAX_KEY_SIZE];
    char block[MAX_BLOCK_SIZE];
} block_t;

void generate_key(char* key) {
    for (int i = 0; i < strlen(key); i++) {
        key[i] = toupper(key[i]);
    }
}

void generate_block(block_t* block) {
    for (int i = 0; i < MAX_BLOCK_SIZE; i++) {
        block->block[i] = rand() % 26 + 'A';
    }
}

void encrypt(block_t* block) {
    char key[MAX_KEY_SIZE];
    generate_key(block->key);
    for (int i = 0; i < MAX_BLOCK_SIZE; i++) {
        block->block[i] = block->block[i] + key[i % strlen(key)];
    }
}

void decrypt(block_t* block) {
    char key[MAX_KEY_SIZE];
    generate_key(block->key);
    for (int i = 0; i < MAX_BLOCK_SIZE; i++) {
        block->block[i] = block->block[i] - key[i % strlen(key)];
    }
}

int main() {
    block_t block;
    strcpy(block.key, "secretkey");
    generate_block(&block);
    encrypt(&block);
    printf("Encrypted block: %s\n", block.block);
    decrypt(&block);
    printf("Decrypted block: %s\n", block.block);
    return 0;
}