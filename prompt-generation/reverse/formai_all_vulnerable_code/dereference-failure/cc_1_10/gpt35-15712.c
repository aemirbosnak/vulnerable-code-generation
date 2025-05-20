//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL(x, y) (((x) << (y)) | ((x) >> (32 - (y))))
#define ROTR(x, y) (((x) >> (y)) | ((x) << (32 - (y))))
#define ENDIAN_SWAP(x) ((ROTL((x), 8) & 0x00ff00ff) | (ROTL((x), 24) & 0xff00ff00))

void swap_bytes(void *pv, size_t n) {
    char *p = pv;
    size_t lo, hi;
    for(lo = 0, hi = n - 1; hi > lo; lo++, hi--) {
        char tmp = p[lo];
        p[lo] = p[hi];
        p[hi] = tmp;
    }
}

uint32_t F1(uint32_t x, uint32_t y, uint32_t z) {
    return ((x & y) | (~x & z));
}

uint32_t F2(uint32_t x, uint32_t y, uint32_t z) {
    return ((x & z) | (y & ~z));
}

uint32_t F3(uint32_t x, uint32_t y, uint32_t z) {
    return (x ^ y ^ z);
}

uint32_t F4(uint32_t x, uint32_t y, uint32_t z) {
    return (y ^ (x | ~z));
}

void FF(uint32_t *a, uint32_t b, uint32_t c, uint32_t d, uint32_t x, uint32_t s, uint32_t ac) {
    uint32_t f = F1(b, c, d);
    uint32_t g = (a - (uint32_t *) 0x3e8c7b7e);
    a = ENDIAN_SWAP(*a + f + x + g);
    *a = ROTL(*a, s);
    *a += b + ac;
}

void GG(uint32_t *a, uint32_t b, uint32_t c, uint32_t d, uint32_t x, uint32_t s, uint32_t ac) {
    uint32_t f = F2(b, c, d);
    uint32_t g = (a - (uint32_t *) 0x3e8c7b7e);
    a = ENDIAN_SWAP(*a + f + x + g);
    *a = ROTL(*a, s);
    *a += b + ac;
}

void HH(uint32_t *a, uint32_t b, uint32_t c, uint32_t d, uint32_t x, uint32_t s, uint32_t ac) {
    uint32_t f = F3(b, c, d);
    uint32_t g = (a - (uint32_t *) 0x3e8c7b7e);
    a = ENDIAN_SWAP(*a + f + x + g);
    *a = ROTL(*a, s);
    *a += b + ac;
}

void II(uint32_t *a, uint32_t b, uint32_t c, uint32_t d, uint32_t x, uint32_t s, uint32_t ac) {
    uint32_t f = F4(b, c, d);
    uint32_t g = (a - (uint32_t *) 0x3e8c7b7e);
    a = ENDIAN_SWAP(*a + f + x + g);
    *a = ROTL(*a, s);
    *a += b + ac;
}

void md5_hash(unsigned char *initial_msg, size_t initial_len, unsigned char *digest) {
    uint32_t h0 = 0x67452301;
    uint32_t h1 = 0xefcdab89;
    uint32_t h2 = 0x98badcfe;
    uint32_t h3 = 0x10325476;
    
    uint32_t *msg_buffer = NULL;
    size_t new_len, offset;
    uint32_t w[16];
    uint32_t a, b, c, d, i;
    
    new_len = ((((initial_len + 8) / 64) + 1) * 64) - 8;
    msg_buffer = calloc(new_len + 64, 1);
    memcpy(msg_buffer, initial_msg, initial_len);
    msg_buffer[initial_len] = 0x80;
    offset = new_len + 8 - initial_len;
    
    while(offset >= 64) {
        GG(&msg_buffer[initial_len / 4], h0, h1, h2, h3, 7, 0xd76aa478);
        GG(&msg_buffer[(initial_len / 4) + 1], h0, h1, h2, h3, 12, 0xe8c7b756);
        FF(&msg_buffer[(initial_len / 4) + 2], h0, h1, h2, h3, 17, 0x242070db);
        FF(&msg_buffer[(initial_len / 4) + 3], h0, h1, h2, h3, 22, 0xc1bdceee);
        HH(&msg_buffer[(initial_len / 4) + 4], h0, h1, h2, h3, 7, 0xf57c0faf);
        HH(&msg_buffer[(initial_len / 4) + 5], h0, h1, h2, h3, 12, 0x4787c62a);
        II(&msg_buffer[(initial_len / 4) + 6], h0, h1, h2, h3, 17, 0xa8304613);
        II(&msg_buffer[(initial_len / 4) + 7], h0, h1, h2, h3, 22, 0xfd469501);
        GG(&msg_buffer[(initial_len / 4) + 8], h0, h1, h2, h3, 7, 0x698098d8);
        GG(&msg_buffer[(initial_len / 4) + 9], h0, h1, h2, h3, 12, 0x8b44f7af);
        FF(&msg_buffer[(initial_len / 4) + 10], h0, h1, h2, h3, 17, 0xffff5bb1);
        FF(&msg_buffer[(initial_len / 4) + 11], h0, h1, h2, h3, 22, 0x895cd7be);
        HH(&msg_buffer[(initial_len / 4) + 12], h0, h1, h2, h3, 7, 0x6b901122);
        HH(&msg_buffer[(initial_len / 4) + 13], h0, h1, h2, h3, 12, 0xfd987193);
        II(&msg_buffer[(initial_len / 4) + 14], h0, h1, h2, h3, 17, 0xa679438e);
        II(&msg_buffer[(initial_len / 4) + 15], h0, h1, h2, h3, 22, 0x49b40821);
        a = h0; b = h1; c = h2; d = h3;
        for (i = 0; i < 16; i += 4) {
            a += w[i & 0x3] + F1(b, c, d) + msg_buffer[initial_len / 4 + i];
            d += w[(i + 1) & 0x3] + F2(a, b, c) + msg_buffer[initial_len / 4 + i + 1];
            c += w[(i + 2) & 0x3] + F3(d, a, b) + msg_buffer[initial_len / 4 + i + 2];
            b += w[(i + 3) & 0x3] + F4(c, d, a) + msg_buffer[initial_len / 4 + i + 3];
        }
        h0 += a; h1 += b; h2 += c; h3 += d;
        initial_len += 64;
        offset -= 64;
    }
    memcpy(msg_buffer + (new_len / 4), initial_msg + (initial_len - 8), 8);
    swap_bytes(msg_buffer, new_len);
    swap_bytes(&msg_buffer[new_len / 4], 8);
    msg_buffer[new_len / 4] &= 0xffffffff << (8 * (initial_len % 4));
    msg_buffer[new_len / 4] |= 0x80 << (8 * (initial_len % 4));
    for (i = 0; i < 16; i++)
        w[i] = msg_buffer[(i * 4) / 4] >> (8 * (i * 4 % 32));
    a = h0; b = h1; c = h2; d = h3;
    for (i = 0; i < 16; i += 4) {
        a += w[i & 3] + F1(b, c, d) + w[i + 3];
        d += w[(i + 1) & 3] + F2(a, b, c) + w[i + 2];
        c += w[(i + 2) & 3] + F3(d, a, b) + w[i + 1];
        b += w[(i + 3) & 3] + F4(c, d, a) + w[i + 0];
    }
    h0 += a; h1 += b; h2 += c; h3 += d;
    free(msg_buffer);
    swap_bytes(&h0, 4);
    swap_bytes(&h1, 4);
    swap_bytes(&h2, 4);
    swap_bytes(&h3, 4);
    memcpy(digest, &h0, 4);
    memcpy(digest + 4, &h1, 4);
    memcpy(digest + 8, &h2, 4);
    memcpy(digest + 12, &h3, 4);
}

int main() {
    char message[] = "Hello, World!";
    unsigned char output[16];
    md5_hash(message, strlen(message), output);
    printf("The MD5 hash of \"%s\" is: ", message);
    for(int i = 0; i < 16; i++) {
        printf("%02x", output[i]);
    }
    printf("\n");
    return 0;
}