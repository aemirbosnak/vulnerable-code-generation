//MISTRAL-7B DATASET v1.0 Category: Cryptographic hash function ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

#define HASH_LENGTH 32 // Default hash length: 32 bytes (128 bits)

void HashMyString(const char *input, unsigned char *output, size_t hashLength) {
    unsigned char md5[MD5_DIGEST_LENGTH];

    // Initialize the MD5 context
    MD5_CTX md5ctx;
    MD5_Init(&md5ctx);

    // Hash the input string
    size_t inputLength = strlen(input);
    MD5_Update(&md5ctx, input, inputLength);
    MD5_Final(md5, &md5ctx);

    // Copy the MD5 hash to the output buffer
    if (hashLength > MD5_DIGEST_LENGTH) {
        fprintf(stderr, "Error: Output hash size exceeds MD5 digest length\n");
        exit(EXIT_FAILURE);
    }
    memcpy(output, md5, hashLength);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input> <output> [<hash_length>]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *input = argv[1];
    char *output = argv[2];
    size_t hashLength = HASH_LENGTH;

    if (argc > 3 && strchr(argv[3], '.') && strlen(argv[3]) > 1) {
        hashLength = atoi(argv[3]);
    }

    unsigned char outputHash[MD5_DIGEST_LENGTH];
    HashMyString(input, outputHash, hashLength);

    // Output the hash in hexadecimal format
    for (size_t i = 0; i < hashLength; ++i) {
        printf("%02x", outputHash[i]);
    }
    printf("\n");

    return EXIT_SUCCESS;
}