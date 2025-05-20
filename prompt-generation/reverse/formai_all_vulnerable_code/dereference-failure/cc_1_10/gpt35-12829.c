//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL(v, n) (((v) << (n)) | ((v) >> (32 - (n))))
#define ROTR(v, n) (((v) >> (n)) | ((v) << (32 - (n))))
#define Io(x) (x ^ 0x6578616c) 
#define II(p) (ROTR(p, 22) ^ ROTR(p, 13) ^ ROTR(p, 2))
#define GG(p, a, b, c, d, x, s) \
    a += ((b & c) | (~b & d)) + x + 0x5a827999; \
    a = ROTL(a, s); \
    a += b;
#define HH(p, a, b, c, d, x, s) \
    a += (b ^ c ^ d) + x + 0x6ed9eba1; \
    a = ROTL(a, s); \
    a += b;
#define II(p, a, b, c, d, x, s) \
    a += (c ^ (b | ~d)) + x + 0x8f1bbcdc; \
    a = ROTL(a, s); \
    a += b;

void md5_hash(uint32_t *msg, size_t msg_size, uint32_t *digest) {
    uint32_t a = 0x67452301, b = 0xefcdab89,
             c = 0x98badcfe, d = 0x10325476;
    for (size_t i = 0; i < msg_size; i += 16) {
        uint32_t aa = a, bb = b, cc = c, dd = d;
        for (size_t j = 0; j < 4; j++) {
            GG(i+j, a, b, c, d, msg[(i % msg_size) + (j<<2)], 7)
            GG(i+j+4, d, a, b, c, msg[(i % msg_size) + (j<<2) + 1], 12)
            GG(i+j+8, c, d, a, b, msg[(i % msg_size) + (j<<2) + 2], 17)
            GG(i+j+12, b, c, d, a, msg[(i % msg_size) + (j<<2) + 3], 22)
        }
        for (size_t j = 0; j < 4; j++) {
            HH(i+j, a, b, c, d, msg[(i % msg_size) + ((j<<2)+1)%16], 5)
            HH(i+j+4, d, a, b, c, msg[(i % msg_size) + ((j<<2)+5)%16], 9)
            HH(i+j+8, c, d, a, b, msg[(i % msg_size) + ((j<<2)+9)%16], 14)
            HH(i+j+12, b, c, d, a, msg[(i % msg_size) + ((j<<2)+13)%16], 20)
        }
        for (size_t j = 0; j < 4; j++) {
            II(i+j, a, b, c, d, msg[(i % msg_size) + ((j<<2)+5)%16], 4)
            II(i+j+4, d, a, b, c, msg[(i % msg_size) + ((j<<2)+8)%16], 11)
            II(i+j+8, c, d, a, b, msg[(i % msg_size) + ((j<<2)+11)%16], 16)
            II(i+j+12, b, c, d, a, msg[(i % msg_size) + ((j<<2)+14)%16], 23)
        }
        a += aa, b += bb, c += cc, d += dd;
    }
    digest[0] = a, digest[1] = b, digest[2] = c, digest[3] = d;
}

int main() {
    char *str = "Hello World!";
    size_t str_len = strlen(str);
    uint32_t *msg = calloc((str_len + 9) >> 2, sizeof(uint32_t));
    uint32_t *digest = malloc(16);

    memcpy(msg, str, str_len);
    msg[str_len>>2] |= 1u << ((str_len&3)<<3);
    msg[(str_len + 8)>>2] = str_len << 3;
    md5_hash(msg, (str_len + 64) >> 6, digest);
    printf("MD5 Hash: ");
    for (size_t i = 0; i < 4; i++) {
        printf("%08x", digest[i]);
    }
    printf("\n");

    free(msg), free(digest);
    return 0;
}