//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 32          // Size of the hash in bytes
#define INPUT_BUFFER 256      // Size for input buffer
#define BLOCK_SIZE 64         // Size of a block in bytes
#define rounds 64             // Number of rounds for hash computation

// Function Prototypes
void hash(const char *input, unsigned char *output);
void process_block(const unsigned char *block, unsigned char *hash);
void print_hash(const unsigned char *hash);

// Main function
int main(int argc, char *argv[]) {
    char input[INPUT_BUFFER];
    unsigned char hash_output[HASH_SIZE];

    // Print banner and instructions
    printf("=== Simple C Cryptographic Hash Function ===\n");
    printf("Usage: %s <input_string>\n", argv[0]);
    printf("Or, enter a string to hash:\n");

    // Check if input is provided through command line
    if (argc > 1) {
        strncpy(input, argv[1], INPUT_BUFFER);
    } else {
        printf("Input: ");
        fgets(input, INPUT_BUFFER, stdin);
        input[strcspn(input, "\n")] = 0; // remove newline
    }

    // Perform hashing
    hash(input, hash_output);

    // Print the resulting hash
    printf("Hash: ");
    print_hash(hash_output);
    
    return 0;
}

// Hash function
void hash(const char *input, unsigned char *output) {
    unsigned char buffer[BLOCK_SIZE] = {0};
    size_t input_len = strlen(input);
    size_t offset = 0;

    // Process each block of the input
    while (input_len > 0) {
        size_t to_copy = (input_len > BLOCK_SIZE) ? BLOCK_SIZE : input_len;
        memcpy(buffer, input + offset, to_copy);
        process_block(buffer, output);
        input_len -= to_copy;
        offset += to_copy;
        memset(buffer, 0, BLOCK_SIZE); // Clear buffer for security
    }
}

// Block processing function
void process_block(const unsigned char *block, unsigned char *hash) {
    unsigned char temp[HASH_SIZE];
    size_t i;

    // Initially copy the current hash state
    memcpy(temp, hash, HASH_SIZE);

    // Simple mixing mechanism
    for (i = 0; i < HASH_SIZE; i++) {
        temp[i] ^= block[i % BLOCK_SIZE];
        
        // Rounds of simple pseudo computation (for demonstration)
        for (int r = 0; r < rounds; r++) {
            temp[i] += (i + r) ^ (temp[(i + 1) % HASH_SIZE]);
            temp[i] = (temp[i] << 1) | (temp[i] >> 7); // Simple rotation
        }
    }

    // Update the hash with the processed temp
    memcpy(hash, temp, HASH_SIZE);
}

// Print hash in hexadecimal format
void print_hash(const unsigned char *hash) {
    for (int i = 0; i < HASH_SIZE; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}