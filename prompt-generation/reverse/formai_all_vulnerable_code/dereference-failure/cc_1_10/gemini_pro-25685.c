//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

// Custom hash function using SHA256
unsigned char* custom_hash(const unsigned char* data, size_t len)
{
    unsigned char* hash = malloc(SHA256_DIGEST_LENGTH);
    if (!hash) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(1);
    }

    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, data, len);
    SHA256_Final(hash, &ctx);

    return hash;
}

// Custom collision-resistant hash function using a combination of SHA256 and XOR
unsigned char* collision_resistant_hash(const unsigned char* data, size_t len)
{
    unsigned char* hash1 = custom_hash(data, len);
    unsigned char* hash2 = custom_hash(hash1, SHA256_DIGEST_LENGTH);

    // XOR the two hashes to create a collision-resistant hash
    unsigned char* collision_resistant_hash = malloc(SHA256_DIGEST_LENGTH);
    if (!collision_resistant_hash) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        collision_resistant_hash[i] = hash1[i] ^ hash2[i];
    }

    free(hash1);
    free(hash2);

    return collision_resistant_hash;
}

int main()
{
    // Test the custom hash function
    const char* message = "This is a test message";
    unsigned char* hash = custom_hash((unsigned char*)message, strlen(message));
    printf("Custom hash: ");
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    // Test the collision-resistant hash function
    hash = collision_resistant_hash((unsigned char*)message, strlen(message));
    printf("Collision-resistant hash: ");
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    free(hash);

    return 0;
}