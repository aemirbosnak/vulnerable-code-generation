//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

// Function to print the hash in a readable format
void print_hash(unsigned char hash[SHA256_DIGEST_LENGTH]) {
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

// Function to calculate the SHA-256 hash
void calculate_sha256(const char* string) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, string, strlen(string));
    SHA256_Final(hash, &sha256);

    printf("SHA-256 hash of '%s': ", string);
    print_hash(hash);
}

// Function to read a file and calculate its hash
void calculate_file_hash(const char* filename) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    unsigned char buffer[1024];
    SHA256_CTX sha256;
    int bytesRead;

    FILE* file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return;
    }

    SHA256_Init(&sha256);
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) != 0) {
        SHA256_Update(&sha256, buffer, bytesRead);
    }
    SHA256_Final(hash, &sha256);
    
    fclose(file);
    printf("SHA-256 hash of file '%s': ", filename);
    print_hash(hash);
}

// Main function demonstrating the use of the hash functions
int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <string> or %s <file_path>\n", argv[0], argv[0]);
        return 1;
    }

    // Option 1: Hash a string
    if (argc == 2 && strchr(argv[1], '.') == NULL) {
        calculate_sha256(argv[1]);
    }

    // Option 2: Hash a file
    else if (argc == 2) {
        calculate_file_hash(argv[1]);
    }

    // Option 3: Hash multiple strings
    else if (argc > 2) {
        for (int i = 1; i < argc; i++) {
            calculate_sha256(argv[i]);
        }
    }

    return 0;
}