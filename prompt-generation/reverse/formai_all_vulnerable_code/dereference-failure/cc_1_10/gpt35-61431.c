//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define MAX_BUF_SIZE 1024

// Function to compute the SHA256 hash of a given input message
void ComputeSHA256Hash(const unsigned char *input, size_t input_len, unsigned char **digest, unsigned int *digest_len)
{
    // Create a SHA256 context
    EVP_MD_CTX *mdctx = EVP_MD_CTX_new();
    if (mdctx == NULL) {
        fprintf(stderr, "Error creating EVP_MD_CTX object.\n");
        exit(EXIT_FAILURE);
    }

    // Initialize the context for SHA256 hashing
    if (!EVP_DigestInit_ex(mdctx, EVP_sha256(), NULL)) {
        fprintf(stderr, "Error initializing EVP digest.\n");
        exit(EXIT_FAILURE);
    }

    // Feed the input message to the context for hashing
    if (!EVP_DigestUpdate(mdctx, input, input_len)) {
        fprintf(stderr, "Error feeding input data to EVP digest.\n");
        exit(EXIT_FAILURE);
    }

    // Get the SHA256 hash value
    if (!EVP_DigestFinal_ex(mdctx, *digest, digest_len)) {
        fprintf(stderr, "Error getting EVP digest.\n");
        exit(EXIT_FAILURE);
    }

    // Clean up the context
    EVP_MD_CTX_free(mdctx);
}

int main()
{
    // Read the input file
    FILE *input_file = fopen("input.txt", "rb");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening input file.\n");
        exit(EXIT_FAILURE);
    }

    // Allocate a buffer to store the input data
    unsigned char input_buf[MAX_BUF_SIZE] = {0};

    // Read the input data into the buffer
    size_t bytes_read = fread(input_buf, 1, MAX_BUF_SIZE, input_file);
    if (bytes_read == 0) {
        fprintf(stderr, "Error reading input data.\n");
        exit(EXIT_FAILURE);
    }

    // Close the input file
    fclose(input_file);

    // Compute the SHA256 hash of the input data
    unsigned int digest_len = EVP_MD_size(EVP_sha256());
    unsigned char *digest = malloc(digest_len);
    if (digest == NULL) {
        fprintf(stderr, "Error allocating memory for hash.\n");
        exit(EXIT_FAILURE);
    }
    ComputeSHA256Hash(input_buf, bytes_read, &digest, &digest_len);

    // Print the hash value
    for (int i = 0; i < digest_len; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");

    // Free the hash buffer
    free(digest);

    return 0;
}