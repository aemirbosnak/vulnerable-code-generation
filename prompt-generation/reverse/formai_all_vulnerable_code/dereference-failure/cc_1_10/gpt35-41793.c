//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define ROTLEFT(a,b) ((a << b) | (a >> (32 - b)))

uint32_t *MD5(const uint8_t *initial_msg, size_t initial_len) {

    // Message padding and length variables
    uint8_t *msg = NULL;
    int new_len, offset;
    uint32_t w[16];
    const uint32_t K[] = {
            0x5a827999, 0x6ed9eba1, 0x8f1bbcdc, 0xca62c1d6
    };
    uint32_t a, b, c, d, i, f, g, temp;

    // Initialize hash variables
    a = 0x67452301;
    b = 0xefcdab89;
    c = 0x98badcfe;
    d = 0x10325476;

    // Pre-processing: pad the message to a multiple of 64 bytes
    new_len = ((initial_len + 8 + 63) / 64) * 64;
    msg = (uint8_t *) calloc(new_len, 1);
    memcpy(msg, initial_msg, initial_len);
    msg[initial_len] = 0x80;
    offset = initial_len % 64;
    if (offset > 56) {
        offset = 64 - offset;
        memset(msg + initial_len + 1, 0, offset);
        initial_len += offset;
        offset = 0;
    }
    memset(msg + initial_len + 1, 0, 56 - offset);
    *(uint64_t *) (msg + new_len - 8) = (uint64_t) initial_len * 8;

    // Process message in 16-word blocks
    for (i = 0; i < new_len; i += 64) {
        memcpy(w, msg + i, 64);
        for (int j = 0; j < 16; j++) {
            w[j] = (uint32_t) w[j * 4] + (uint32_t) w[j * 4 + 1] * 256 + (uint32_t) w[j * 4 + 2] * 65536 +
                   (uint32_t) w[j * 4 + 3] * 16777216;
        }
        uint32_t olda = a;
        uint32_t oldb = b;
        uint32_t oldc = c;
        uint32_t oldd = d;
        for (uint32_t j = 0; j < 64; j++) {
            if (j < 16) {
                f = (b & c) | ((~b) & d);
                g = j;
            } else if (j < 32) {
                f = (d & b) | ((~d) & c);
                g = (5 * j + 1) % 16;
            } else if (j < 48) {
                f = b ^ c ^ d;
                g = (3 * j + 5) % 16;
            } else {
                f = c ^ (b | (~d));
                g = (7 * j) % 16;
            }
            temp = d;
            d = c;
            c = b;
            b = b + ROTLEFT((a + f + K[j / 16] + w[g]), (j % 16));
            a = temp;
        }
        a += olda;
        b += oldb;
        c += oldc;
        d += oldd;
    }

    // Clean up and return the hash
    free(msg);
    uint32_t *hash = (uint32_t *) malloc(16);
    hash[0] = a;
    hash[1] = b;
    hash[2] = c;
    hash[3] = d;
    return hash;
}

int main(void) {
    char message[] = "hello world";
    uint32_t *hash = MD5((uint8_t *) message, strlen(message));
    printf("MD5 Hash: %08x%08x%08x%08x\n", hash[0], hash[1], hash[2], hash[3]);
    free(hash);
    return 0;
}