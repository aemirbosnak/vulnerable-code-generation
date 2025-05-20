//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define HASH_SIZE SHA256_DIGEST_LENGTH
#define BUFFER_SIZE 1024

void handleErrors(const char *error) {
    fprintf(stderr, "Error: %s\n", error);
    exit(EXIT_FAILURE);
}

void printHash(unsigned char hash[HASH_SIZE]) {
    for (int i = 0; i < HASH_SIZE; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

void computeSHA256(const char *input, unsigned char hash[HASH_SIZE]) {
    SHA256_CTX sha256;
    if (SHA256_Init(&sha256) != 1) {
        handleErrors("SHA256 Initialization Failed");
    }
    if (SHA256_Update(&sha256, input, strlen(input)) != 1) {
        handleErrors("SHA256 Update Failed");
    }
    if (SHA256_Final(hash, &sha256) != 1) {
        handleErrors("SHA256 Finalization Failed");
    }
}

char* readInput() {
    char *buffer = malloc(BUFFER_SIZE);
    if (!buffer) {
        handleErrors("Memory Allocation Failed");
    }
    
    printf("Enter the string to hash: ");
    if (!fgets(buffer, BUFFER_SIZE, stdin)) {
        free(buffer);
        handleErrors("Input Reading Failed");
    }
    
    buffer[strcspn(buffer, "\n")] = 0; // Remove trailing newline
    return buffer;
}

int main() {
    unsigned char hash[HASH_SIZE];

    char *input = readInput();
    
    computeSHA256(input, hash);
    
    printf("SHA-256 Hash: ");
    printHash(hash);

    free(input); // Clean up allocated memory
    return 0;
}