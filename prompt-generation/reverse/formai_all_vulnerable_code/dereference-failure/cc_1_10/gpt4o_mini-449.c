//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/sha.h>

#define HASH_LENGTH SHA256_DIGEST_LENGTH // SHA-256 produces a 256-bit hash (32 bytes)

void print_hash(unsigned char hash[HASH_LENGTH]) {
    for (int i = 0; i < HASH_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

void hash_input(const char *input) {
    unsigned char hash[HASH_LENGTH];
    SHA256((unsigned char *)input, strlen(input), hash);
    
    printf("Input: %s\n", input);
    printf("SHA-256 Hash: ");
    print_hash(hash);
}

void file_hash(const char *filename) {
    unsigned char hash[HASH_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);

    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file");
        return;
    }

    unsigned char buffer[1024];
    size_t bytesRead;
    
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file))) {
        SHA256_Update(&sha256, buffer, bytesRead);
    }
    SHA256_Final(hash, &sha256);
    fclose(file);

    printf("File: %s\n", filename);
    printf("SHA-256 Hash: ");
    print_hash(hash);
}

void usage(const char *program_name) {
    fprintf(stderr, "Usage: %s -i <input_string> | -f <filename>\n", program_name);
    fprintf(stderr, "  -i: Compute hash of the input string.\n");
    fprintf(stderr, "  -f: Compute hash of the contents of the specified file.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "-i") == 0) {
        hash_input(argv[2]);
    } else if (strcmp(argv[1], "-f") == 0) {
        file_hash(argv[2]);
    } else {
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}