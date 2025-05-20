//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define HASH_SIZE 64
#define BLOCK_SIZE 64
#define HASH_TYPE SHA256

// Function to initialize the hash context
void init_hash(SHA256_CTX *hash_ctx) {
    SHA256_Init(hash_ctx);
}

// Function to update the hash context with data
void update_hash(SHA256_CTX *hash_ctx, const void *data, size_t data_len) {
    SHA256_Update(hash_ctx, data, data_len);
}

// Function to finalize the hash context and return the hash
void finalize_hash(SHA256_CTX *hash_ctx, unsigned char *hash) {
    SHA256_Final(hash, hash_ctx);
}

// Function to generate a hash from a string
void generate_hash(const char *input, unsigned char *hash) {
    SHA256_CTX hash_ctx;
    init_hash(&hash_ctx);
    update_hash(&hash_ctx, input, strlen(input));
    finalize_hash(&hash_ctx, hash);
}

// Function to compare two hashes
int compare_hash(const unsigned char *hash1, const unsigned char *hash2) {
    if (memcmp(hash1, hash2, HASH_SIZE) == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <input>\n", argv[0]);
        return 1;
    }

    char input[BLOCK_SIZE + 1] = {0};
    strncpy(input, argv[1], BLOCK_SIZE);

    unsigned char hash[HASH_SIZE] = {0};
    generate_hash(input, hash);

    printf("Input: %s\n", input);
    printf("Hash: ");
    for (int i = 0; i < HASH_SIZE; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}