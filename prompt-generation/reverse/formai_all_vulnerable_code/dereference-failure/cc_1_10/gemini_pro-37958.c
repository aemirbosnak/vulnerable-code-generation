//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input> <output>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *input = fopen(argv[1], "rb");
    if (input == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    FILE *output = fopen(argv[2], "wb");
    if (output == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    SHA256_CTX ctx;
    SHA256_Init(&ctx);

    char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), input)) > 0) {
        SHA256_Update(&ctx, buffer, bytes_read);
    }

    if (ferror(input)) {
        perror("fread");
        return EXIT_FAILURE;
    }

    unsigned char digest[SHA256_DIGEST_LENGTH];
    SHA256_Final(digest, &ctx);

    fwrite(digest, sizeof(digest), 1, output);

    if (ferror(output)) {
        perror("fwrite");
        return EXIT_FAILURE;
    }

    fclose(input);
    fclose(output);

    return EXIT_SUCCESS;
}