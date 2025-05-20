//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTLEFT(x, n) (((x) << (n)) | ((x) >> (32-(n))))

uint32_t *hash(const char *input) {
    int i, j;
    uint32_t *state, *message, *k;
    uint32_t h0 = 0x6A09E667, h1 = 0xBB67AE85, h2 = 0x3C6EF372, h3 = 0xA54FF53A; 
    uint64_t len;
    len = strlen(input);

    // allocate memory for the message and state array 
    message = calloc(((len+8)/64)+1, 64);
    state = calloc(4, sizeof(uint32_t));

    memcpy(message, input, len);

    // append bit '1'
    message[len] = 0x80;

    // append length in bits
    message[((len+8)/64)*16+14] = (len>>32);
    message[((len+8)/64)*16+15] = len;

    k = (uint32_t *)"\x42\x8a\x2f\x1d\xbf\xb5\xd6\xd0\x4e\x9b\x34\xfb\xa5\x4c\x5b\x72";
    for (i=0; i<((len+8)/64)+1; i++) {
        uint32_t *w = &message[i*16];

        uint32_t a = h0, b = h1, c = h2, d = h3;

        for (j=0; j<64; j++) {
            uint32_t f, g;

            if (j < 16) {
                f = (b & c) | ((~b) & d);
                g = j;
            } else if (j < 32) {
                f = (d & b) | ((~d) & c);
                g = (5*j + 1) % 16;
            } else if (j < 48) {
                f = b ^ c ^ d;
                g = (3*j + 5) % 16;
            } else {
                f = c ^ (b | (~d));
                g = (7*j) % 16;
            }

            uint32_t temp = d;
            d = c;
            c = b;
            b = b + ROTLEFT((a + f + k[g] + w[g]), 7);
            a = temp;
        }

        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;
    }

    // free memory from message array
    free(message);

    // allocate memory for final hash value
    uint32_t *hash_value = calloc(4, sizeof(uint32_t));
    hash_value[0] = h0;
    hash_value[1] = h1;
    hash_value[2] = h2;
    hash_value[3] = h3;

    // free memory from state array
    free(state);

    return hash_value;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    uint32_t *hash_value = hash(argv[1]);
    printf("Hash value of \"%s\": %08x%08x%08x%08x\n", argv[1], hash_value[0], hash_value[1], hash_value[2], hash_value[3]);

    // free memory from hash value
    free(hash_value);

    return 0;
}