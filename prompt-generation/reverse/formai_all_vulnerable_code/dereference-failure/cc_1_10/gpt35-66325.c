//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define ROTL(x,n) (((x)<<(n))|((x)>>(32-(n))))

uint32_t F(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) | ((~x) & z);
}

uint32_t G(uint32_t x, uint32_t y, uint32_t z) {
    return (x & z) | (y & (~z));
}

uint32_t H(uint32_t x, uint32_t y, uint32_t z) {
    return x ^ y ^ z;
}

uint32_t I(uint32_t x, uint32_t y, uint32_t z) {
    return y ^ (x | (~z));
}

void encode(uint8_t *output, uint32_t *input, uint32_t len) {
    unsigned int i, j;
    for (i = 0, j = 0; j < len; i++, j += 4) {
        output[j] = (input[i] >> 0) & 0xff;
        output[j + 1] = (input[i] >> 8) & 0xff;
        output[j + 2] = (input[i] >> 16) & 0xff;
        output[j + 3] = (input[i] >> 24) & 0xff;
    }
}

void decode(uint32_t *output, uint8_t *input, uint32_t len) {
    unsigned int i, j;
    for (i = 0, j = 0; j < len; i++, j += 4) {
        output[i] = ((uint32_t) input[j]) | (((uint32_t) input[j + 1]) << 8) |
                    (((uint32_t) input[j + 2]) << 16) | (((uint32_t) input[j + 3]) << 24);
    }
}

char *MD5(char *message) {
    uint32_t h0, h1, h2, h3;
    uint8_t *msg = NULL;
    uint32_t input_len;
    uint64_t bits_len;
    uint8_t padding[64];
    uint32_t *buffer = NULL;
    uint32_t a, b, c, d;
    uint32_t aa, bb, cc, dd;
    uint32_t i;

    h0 = 0x67452301;
    h1 = 0xEFCDAB89;
    h2 = 0x98BADCFE;
    h3 = 0x10325476;

    input_len = (uint32_t) strlen(message);

    bits_len = input_len * 8 + 8;

    while (bits_len % 512 != 448) {
        bits_len += 8;
    }

    bits_len /= 8;

    msg = (unsigned char *) malloc(bits_len + 8);

    memset(msg, 0, bits_len + 8);

    memcpy(msg, message, input_len);

    msg[input_len] = 0x80;

    for (i = 0; i < 8; i++) {
        padding[i] = (uint8_t) ((bits_len >> (i * 8)) & 0x00000000000000ff);
    }

    memcpy(msg + bits_len, padding, 8);

    buffer = (uint32_t *) malloc(64);

    memset(buffer, 0, 64);

    while (input_len--) {

        buffer[input_len >> 2] |= msg[input_len] << ((input_len % 4) * 8);

        for (i = 0; i < 16; i++) {
            uint32_t temp = buffer[i];
            buffer[i] = ((temp << 8) | (temp >> 24));
        }

        a = h0;
        b = h1;
        c = h2;
        d = h3;

        for (i = 0; i < 64; i++) {

            if (i < 16) {
                buffer[i] = ((buffer[i] << 3) | (buffer[i] >> 29)) + F(b, c, d) + a +
                            0x5A827999 + buffer[i];
            } else if (i < 32) {
                buffer[i] = ((buffer[i] << 7) | (buffer[i] >> 25)) + G(b, c, d) + a +
                            0x6ED9EBA1 + buffer[(5 * i + 1) % 16];
            } else if (i < 48) {
                buffer[i] = ((buffer[i] << 11) | (buffer[i] >> 21)) + H(b, c, d) + a +
                            0x8F1BBCDC + buffer[(3 * i + 5) % 16];
            } else {
                buffer[i] = ((buffer[i] << 19) | (buffer[i] >> 13)) + I(b, c, d) + a +
                            0xCA62C1D6 + buffer[(7 * i) % 16];
            }

            a = d;
            d = c;
            c = b;
            b = buffer[i];

        }

        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;

    }

    free(buffer);
    free(msg);

    aa = ((h0 << 8) | (h0 >> 24));
    bb = ((h1 << 8) | (h1 >> 24));
    cc = ((h2 << 8) | (h2 >> 24));
    dd = ((h3 << 8) | (h3 >> 24));

    char *result = (char *) malloc(33);

    sprintf(result, "%08x%08x%08x%08x", aa, bb, cc, dd);

    return result;

}

int main() {

    char *test_string1 = "Hello, World!";
    char *test_string2 = "Hash me, please!";
    char *test_string3 = "A quick brown fox jumps over the lazy dog.";

    printf("Testing MD5 hash function.\n");
    printf("Hash of '%s': %s\n", test_string1, MD5(test_string1));
    printf("Hash of '%s': %s\n", test_string2, MD5(test_string2));
    printf("Hash of '%s': %s\n", test_string3, MD5(test_string3));

    return 0;
}