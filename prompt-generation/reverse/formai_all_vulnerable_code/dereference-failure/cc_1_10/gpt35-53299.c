//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: minimalist
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct _hash_value {
    uint32_t a;
    uint32_t b;
    uint32_t c;
    uint32_t d;
} hash_value;

#define LEFT_ROTATE(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

hash_value md5(const void *message, size_t length) {
    const uint8_t *msg = (const uint8_t *) message;
    uint32_t a0 = 0x67452301;
    uint32_t b0 = 0xEFCDAB89;
    uint32_t c0 = 0x98BADCFE;
    uint32_t d0 = 0x10325476;

    uint32_t *words;
    int num_words = ((length + 8) / 64 + 1) * 16;
    words = (uint32_t *) calloc(num_words, sizeof(uint32_t));
    for (int i = 0; i < length; i++) {
        words[i / 4] |= msg[i] << ((i % 4) * 8);
    }
    words[length / 4] |= 0x80 << ((length % 4) * 8);
    words[num_words - 2] = length * 8;

    for (int i = 0; i < num_words; i += 16) {
        uint32_t a = a0;
        uint32_t b = b0;
        uint32_t c = c0;
        uint32_t d = d0;
        for (int j = 0; j < 64; j++) {
            uint32_t f, g;
            if (j < 16) {
                f = (b & c) | (~b & d);
                g = j;
            } else if (j < 32) {
                f = (d & b) | (~d & c);
                g = (5 * j + 1) % 16;
            } else if (j < 48) {
                f = b ^ c ^ d;
                g = (3 * j + 5) % 16;
            } else {
                f = c ^ (b | ~d);
                g = (7 * j) % 16;
            }
            uint32_t temp = d;
            d = c;
            c = b;
            b = b + LEFT_ROTATE((a + f + 0x5A827999 + words[i + g]), 7);
            a = temp;
        }
        a0 += a;
        b0 += b;
        c0 += c;
        d0 += d;
    }

    free(words);

    hash_value result = {a0, b0, c0, d0};
    return result;
}

int main() {
    char message[] = "Hello, world!";
    hash_value result = md5(message, sizeof(message)-1);
    printf("MD5(");
    for(int i=0; i<sizeof(message)-1; i++)
        printf("%c", message[i]);
    printf(") = %08x%08x%08x%08x\n", result.a, result.b, result.c, result.d);
    return 0;
}