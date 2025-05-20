//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

// Function to calculate the SHA256 hash of a file
char *sha256_hash(const char *filename)
{
    // Allocate memory for the hash
    char *hash = malloc(SHA256_DIGEST_LENGTH);

    // Open the file
    FILE *file = fopen(filename, "rb");
    if (file == NULL)
    {
        fprintf(stderr, "Error opening file\n");
        return NULL;
    }

    // Create the SHA256 context
    SHA256_CTX sha256;
    SHA256_Init(&sha256);

    // Read the file in chunks and update the hash
    char buffer[1024];
    while (fread(buffer, sizeof(char), sizeof(buffer), file))
    {
        SHA256_Update(&sha256, buffer, sizeof(buffer));
    }

    // Finalize the hash
    SHA256_Final((unsigned char *)hash, &sha256);

    // Close the file
    fclose(file);

    // Return the hash
    return hash;
}

// Function to compare two hashes
int compare_hashes(const char *hash1, const char *hash2)
{
    // Compare the hashes
    int result = memcmp(hash1, hash2, SHA256_DIGEST_LENGTH);

    // Return the result
    return result;
}

// Main function
int main()
{
    // Calculate the hashes of two files
    char *hash1 = sha256_hash("file1.txt");
    char *hash2 = sha256_hash("file2.txt");

    // Compare the hashes
    int result = compare_hashes(hash1, hash2);

    // Print the result
    if (result == 0)
    {
        printf("The files have the same hash\n");
    }
    else
    {
        printf("The files have different hashes\n");
    }

    // Free the memory
    free(hash1);
    free(hash2);

    return 0;
}