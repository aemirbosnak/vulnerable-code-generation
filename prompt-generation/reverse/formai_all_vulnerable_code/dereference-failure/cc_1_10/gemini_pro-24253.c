//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: portable
#include <stdint.h>
#include <stdio.h>
#include <string.h>

// GF(2^8) finite field multiplication, used in HashLib
uint8_t gf_mul(uint8_t a, uint8_t b) {
    uint8_t p = 0;
    for (int i = 0; i < 8; i++) {
        if ((b & 1) != 0) {
            p ^= a;
        }
        a <<= 1;
        b >>= 1;
        if (a >= 128) {
            a ^= 0x11b;
        }
    }
    return p;
}

// Core HashLib function
void hashl(uint8_t *h, const uint8_t *m, size_t mlen) {
    const uint8_t rcons[10] = {
        0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36
    };
    const size_t bs = 32;

    uint8_t state[bs];
    memcpy(state, h, bs);
    for (size_t i = 0; i < mlen; i += bs) {
        for (int j = 0; j < 4; j++) {
            uint8_t t[bs];
            memcpy(t, state + j * 8, bs);
            for (int k = 0; k < 8; k++) {
                t[k] = gf_mul(t[k], rcons[(i / bs) * 4 + k]);
            }
            uint8_t s[bs];
            memcpy(s, t, bs);
            for (int k = 0; k < 8; k++) {
                s[k] = gf_mul(s[k], 2);
            }
            for (int k = 0; k < bs; k++) {
                state[k] ^= t[k] ^ s[k] ^ m[i + k];
            }
        }
    }
    memcpy(h, state, bs);
}

// HashLib hash function
void hashl_hash(uint8_t *h, const void *m, size_t mlen) {
    uint8_t zero[32] = {0};
    hashl(h, zero, 32);
    hashl(h, m, mlen);
}

int main() {
    uint8_t h[32];
    hashl_hash(h, "Hello, world!", 13);
    printf("SHA-256 hash: ");
    for (int i = 0; i < 32; i++) {
        printf("%02x", h[i]);
    }
    printf("\n");
    return 0;
}