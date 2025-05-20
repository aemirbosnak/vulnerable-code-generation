//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

// Predefined colors for artistic output
#define COLOR_RED "\033[0;31m"
#define COLOR_GREEN "\033[0;32m"
#define COLOR_YELLOW "\033[0;33m"
#define COLOR_BLUE "\033[0;34m"
#define COLOR_MAGENTA "\033[0;35m"
#define COLOR_CYAN "\033[0;36m"
#define COLOR_WHITE "\033[0;37m"
#define COLOR_RESET "\033[0m"

// Function to generate a SHA256 hash
unsigned char* sha256(const unsigned char *input, size_t length)
{
    unsigned char *hash = malloc(SHA256_DIGEST_LENGTH);
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input, length);
    SHA256_Final(hash, &sha256);
    return hash;
}

// Function to convert a byte array to a hexadecimal string
char* hex_string(const unsigned char *input, size_t length)
{
    char *hex_str = malloc(2 * length + 1);
    for (int i = 0; i < length; i++) {
        sprintf(hex_str + 2 * i, "%02x", input[i]);
    }
    hex_str[2 * length] = '\0';
    return hex_str;
}

// Main function
int main(int argc, char **argv)
{
    // Get the input string from the user
    char input[1024];
    printf(COLOR_YELLOW "Enter a string to hash: " COLOR_RESET);
    scanf("%s", input);

    // Calculate the SHA256 hash of the input string
    unsigned char *hash = sha256((unsigned char *)input, strlen(input));

    // Convert the hash to a hexadecimal string
    char *hex_hash = hex_string(hash, SHA256_DIGEST_LENGTH);

    // Print the original string and its SHA256 hash
    printf(COLOR_GREEN "Original string: " COLOR_RESET "%s\n", input);
    printf(COLOR_BLUE "SHA256 hash: " COLOR_RESET "%s\n", hex_hash);

    // Free the allocated memory
    free(hash);
    free(hex_hash);

    return 0;
}