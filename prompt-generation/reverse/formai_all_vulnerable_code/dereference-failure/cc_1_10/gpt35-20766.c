//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h> // Required for OpenSSL functions

// Function to print hash value of input string
void printHash(unsigned char* hash, int length) {
    int i;
    for (i = 0; i < length; i++) {
        printf("%02x ", hash[i]);
    }
    printf("\n");
}

// Function to compute hash of input string using OpenSSL
unsigned char* computeHash(char* input, const EVP_MD* type) {
    EVP_MD_CTX* mdctx;
    const unsigned char* data;
    unsigned char* hash;
    unsigned int length;

    // Initialize digest context
    if ((mdctx = EVP_MD_CTX_new()) == NULL) {
        printf("Error in EVP_MD_CTX_new()\n");
        return NULL;
    }

    // Initialize digest type
    if (1 != EVP_DigestInit_ex(mdctx, type, NULL)) {
        printf("Error in EVP_DigestInit_ex()\n");
        return NULL;
    }

    // Update digest with input data
    data = (unsigned char*) input;
    if (1 != EVP_DigestUpdate(mdctx, data, strlen(input))) {
        printf("Error in EVP_DigestUpdate()\n");
        return NULL;
    }

    // Compute digest
    hash = (unsigned char*) malloc(EVP_MD_size(type));
    if (1 != EVP_DigestFinal_ex(mdctx, hash, &length)) {
        printf("Error in EVP_DigestFinal_ex()\n");
        return NULL;
    }

    // Clear digest context
    EVP_MD_CTX_free(mdctx);

    return hash;
}

int main() {
    char input[100];
    const EVP_MD* type;
    unsigned char* hash;

    // Get input string
    printf("Enter string to hash: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character

    // Select hash type (SHA256, SHA384, SHA512)
    printf("Select hash type (256/384/512): ");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 256:
            type = EVP_sha256();
            break;
        case 384:
            type = EVP_sha384();
            break;
        case 512:
            type = EVP_sha512();
            break;
        default:
            printf("Invalid choice\n");
            return 0;
    }

    // Compute and print hash
    hash = computeHash(input, type);
    printf("Hash value of \"%s\" using SHA%d: ", input, choice);
    printHash(hash, EVP_MD_size(type));
    free(hash);

    return 0;
}