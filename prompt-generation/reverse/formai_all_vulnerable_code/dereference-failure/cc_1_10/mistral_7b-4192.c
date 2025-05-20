//MISTRAL-7B DATASET v1.0 Category: Cryptographic hash function ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <openssl/sha.h>
#include <time.h>

#define SALT_LENGTH 16
#define ITERATIONS 1000

void generateSalt(unsigned char salt[SALT_LENGTH]) {
    for (int i = 0; i < SALT_LENGTH; i++) {
        salt[i] = rand() & 0xFF;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <data>\n", argv[0]);
        return 1;
    }

    const char *inputData = argv[1];
    size_t inputDataLength = strlen(inputData);

    unsigned char inputBuffer[inputDataLength + SALT_LENGTH];
    memcpy(inputBuffer, inputData, inputDataLength);

    unsigned char salt[SALT_LENGTH];
    generateSalt(salt);

    unsigned char hash[SHA256_DIGEST_LENGTH];
    unsigned char combined[inputDataLength + SALT_LENGTH];

    memcpy(combined, inputBuffer, inputDataLength);
    memcpy(combined + inputDataLength, salt, SALT_LENGTH);

    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, combined, inputDataLength + SALT_LENGTH);
    SHA256_Final(hash, &sha256);

    for (int i = 0; i < ITERATIONS; i++) {
        SHA256_CTX sha256Iteration;
        SHA256_Init(&sha256Iteration);
        SHA256_Update(&sha256Iteration, hash, SHA256_DIGEST_LENGTH);
        SHA256_Final(hash, &sha256Iteration);
    }

    printf("Salt: ");
    for (int i = 0; i < SALT_LENGTH; i++) {
        printf("%02X", salt[i]);
    }
    printf("\n");

    printf("Hashed data: ");
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02X", hash[i]);
    }
    printf("\n");

    return 0;
}