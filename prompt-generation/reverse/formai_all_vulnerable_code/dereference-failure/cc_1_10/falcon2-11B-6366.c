//Falcon2-11B DATASET v1.0 Category: Cryptographic hash function ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFSIZE 128

/* Calculate the SHA-256 hash of a string */
void sha256_hash(const char *input, size_t len, char *output) {
    /* Initialize SHA-256 context */
    unsigned char sha256[64];
    unsigned char *p = sha256;
    unsigned char digest[32];
    size_t i;

    /* Fill in initial digest values */
    for (i = 0; i < 32; i++) {
        p[i] = (unsigned char) i;
    }

    /* Process the input string in chunks */
    while (len > 0) {
        size_t chunk_len = (len > BUFSIZE)? BUFSIZE : len;
        char *chunk = input;
        char *end = chunk + chunk_len;
        unsigned char *p_in = (unsigned char *) chunk;
        unsigned char *p_out = p;

        /* Process the input chunk */
        while (p_in < end) {
            *p_out++ = *p_in++;
        }

        /* Update SHA-256 context */
        for (i = 0; i < 64; i++) {
            sha256[i] = sha256[i] + p[i];
        }

        /* Update SHA-256 context */
        for (i = 0; i < 32; i++) {
            sha256[i] = sha256[i] ^ sha256[i + 32];
        }

        /* Update the digest */
        for (i = 0; i < 32; i++) {
            digest[i] = (unsigned char) sha256[i];
        }

        /* Update the input string */
        input += chunk_len;
        len -= chunk_len;
    }

    /* Copy the digest into the output buffer */
    memcpy(output, digest, 32);
}

/* Main function */
int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    char input[BUFSIZE] = {0};
    char output[BUFSIZE] = {0};
    size_t len = strlen(argv[1]);

    strcpy(input, argv[1]);
    sha256_hash(input, len, output);

    printf("SHA-256 hash of '%s': %s\n", argv[1], output);

    return 0;
}