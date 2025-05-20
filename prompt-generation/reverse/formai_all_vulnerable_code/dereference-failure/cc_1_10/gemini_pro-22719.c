//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

// Function to calculate the SHA256 hash of a string
unsigned char* sha256(const char *str)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str, strlen(str));
    SHA256_Final(hash, &sha256);
    return hash;
}

// Function to print the hash in a hex string format
void print_hex(unsigned char *hash)
{
    int i;
    for (i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

// Function to generate a random string of a given length
char *generate_random_string(int length)
{
    char *random_string = malloc(length + 1);
    int i;
    for (i = 0; i < length; i++) {
        random_string[i] = (rand() % 26) + 'a';
    }
    random_string[length] = '\0';
    return random_string;
}

// Main function
int main()
{
    // Generate a random string of length 100
    int length = 100;
    char *random_string = generate_random_string(length);

    // Calculate the SHA256 hash of the random string
    unsigned char *hash = sha256(random_string);

    // Print the hash in a hex string format
    printf("SHA256 hash of the random string: ");
    print_hex(hash);

    // Free the memory allocated for the random string
    free(random_string);

    return 0;
}