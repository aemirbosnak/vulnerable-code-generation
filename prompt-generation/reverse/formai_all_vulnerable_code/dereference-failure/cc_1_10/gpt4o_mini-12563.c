//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

// Function Prototypes
void compute_sha256(const char *input, unsigned char output[SHA256_DIGEST_LENGTH]);
void print_hash(unsigned char hash[SHA256_DIGEST_LENGTH]);
char *get_input(void);
void handle_error(const char *error_message);

int main() {
    char *input_string = get_input();
    unsigned char hash[SHA256_DIGEST_LENGTH];

    compute_sha256(input_string, hash);
    print_hash(hash);

    free(input_string);
    return 0;
}

// Function to compute SHA-256 hash
void compute_sha256(const char *input, unsigned char output[SHA256_DIGEST_LENGTH]) {
    SHA256((unsigned char*)input, strlen(input), output);
}

// Function to print the hash in hexadecimal format
void print_hash(unsigned char hash[SHA256_DIGEST_LENGTH]) {
    printf("SHA-256 Hash: ");
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

// Function to get user input
char *get_input(void) {
    char *input = NULL;
    size_t len = 0;

    printf("Enter a string to hash: ");
    ssize_t read = getline(&input, &len, stdin);
    if (read == -1) {
        handle_error("Error reading input.");
    }

    // Remove the newline character if present
    input[strcspn(input, "\n")] = 0; 
    return input;
}

// Function to handle errors
void handle_error(const char *error_message) {
    perror(error_message);
    exit(EXIT_FAILURE);
}