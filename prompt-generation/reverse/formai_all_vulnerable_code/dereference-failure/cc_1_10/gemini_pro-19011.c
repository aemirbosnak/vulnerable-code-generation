//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

// Define the input string
const char *input = "The quick brown fox jumps over the lazy dog";

// Define the hash function
void hash_function(const char *input, unsigned char *output)
{
    // Create a SHA256 context
    SHA256_CTX ctx;
    SHA256_Init(&ctx);

    // Update the context with the input string
    SHA256_Update(&ctx, input, strlen(input));

    // Finalize the context and get the hash value
    SHA256_Final(output, &ctx);
}

// Print the hash value
void print_hash(unsigned char *hash)
{
    int i;

    // Print the hash value in hexadecimal format
    for (i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        printf("%02x", hash[i]);
    }

    printf("\n");
}

int main()
{
    // Allocate memory for the hash value
    unsigned char *hash = malloc(SHA256_DIGEST_LENGTH);

    // Hash the input string
    hash_function(input, hash);

    // Print the hash value
    print_hash(hash);

    // Free the allocated memory
    free(hash);

    return 0;
}