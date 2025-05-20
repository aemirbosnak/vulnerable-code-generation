//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL(x, n) ((x) << (n)) | ((x) >> (32 - (n))) // rotation left operations
#define BYTE_SWAP(x) ((ROTL(x, 8) & 0x00FF00FF) | (ROTL(x, 24) & 0xFF00FF00)) // byte swapping operations
#define CH(x, y, z) (((x) & (y)) ^ ((~(x)) & (z)))
#define MAJ(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))

// SHA-256 initial hash values
const uint32_t SHA256_H[] = {
    0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 
    0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
};

// SHA-256 round constants
const uint32_t SHA256_K[] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 
    0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5, 
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 
    0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174, 
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 
    0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da, 
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 
    0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967, 
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 
    0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 
    0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070, 
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 
    0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3, 
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

// SHA-256 algorithm functions
uint32_t sha256_ch(uint32_t x, uint32_t y, uint32_t z) {
    return CH(x, y, z);
}

uint32_t sha256_maj(uint32_t x, uint32_t y, uint32_t z) {
    return MAJ(x, y, z);
}

uint32_t sha256_sig0(uint32_t x) {
    return ROTL(x, 2) ^ ROTL(x, 13) ^ ROTL(x, 22);
}

uint32_t sha256_sig1(uint32_t x) {
    return ROTL(x, 6) ^ ROTL(x, 11) ^ ROTL(x, 25);
}

uint32_t sha256_SIG0(uint32_t x) {
    return ROTL(x, 7) ^ ROTL(x, 18) ^ (x >> 3);
}

uint32_t sha256_SIG1(uint32_t x) {
    return ROTL(x, 17) ^ ROTL(x, 19) ^ (x >> 10);
}

// SHA-256 message padding function
void sha256_pad(uint8_t *m, uint64_t m_length, uint8_t **padded_m, uint64_t *padded_m_length) {
    uint64_t msg_bits = m_length * 8;
    uint32_t pad_size = (msg_bits % 512 < 448) ? (448 - msg_bits % 512) : (960 - msg_bits % 512);
    *padded_m_length = m_length + pad_size / 8 + 8;
    *padded_m = calloc(*padded_m_length, sizeof(uint8_t));
    memcpy(*padded_m, m, m_length);
    (*padded_m)[m_length] = 0x80;
    for (int i = 1; i <= pad_size / 8; i++) {
        (*padded_m)[*padded_m_length - i] = (uint8_t)(msg_bits >> (8 * (i - 1)));
    }
}

// SHA-256 hash function main implementation
void sha256_hash(uint8_t *m, uint64_t m_length, uint8_t *h) {
    uint64_t padded_m_length;
    uint8_t *padded_m;
    sha256_pad(m, m_length, &padded_m, &padded_m_length);
    uint32_t nb_blocks = padded_m_length / 64;
    uint32_t nb_rounds = 64;
    uint32_t W[64];
    uint32_t a, b, c, d, e, f, g, h_, T1, T2;

    // initialize message digest state
    uint32_t H[8];
    memcpy(H, SHA256_H, 8 * sizeof(uint32_t));

    for (uint32_t i = 0; i < nb_blocks; i++) {
        // populate message schedule
        for (uint32_t t = 0; t < 16; t++) {
            W[t] = ((uint32_t)padded_m[i * 64 + 4 * t] << 24) 
                 | ((uint32_t)padded_m[i * 64 + 4 * t + 1] << 16)
                 | ((uint32_t)padded_m[i * 64 + 4 * t + 2] << 8)
                 | ((uint32_t)padded_m[i * 64 + 4 * t + 3]);
        }
        for (uint32_t t = 16; t < 64; t++) {
            W[t] = sha256_SIG1(W[t - 2]) + W[t - 7] + sha256_SIG0(W[t - 15]) + W[t - 16];
        }

        // initialize working variables
        a = H[0];
        b = H[1];
        c = H[2];
        d = H[3];
        e = H[4];
        f = H[5];
        g = H[6];
        h_ = H[7];

        // main encryption loop
        for (uint32_t t = 0; t < nb_rounds; t++) {
            T1 = h_ + sha256_sig1(e) + sha256_ch(e, f, g) + SHA256_K[t] + W[t];
            T2 = sha256_sig0(a) + sha256_maj(a, b, c);
            h_ = g;
            g = f;
            f = e;
            e = d + T1;
            d = c;
            c = b;
            b = a;
            a = T1 + T2;
        }

        // update message digest state
        H[0] += a;
        H[1] += b;
        H[2] += c;
        H[3] += d;
        H[4] += e;
        H[5] += f;
        H[6] += g;
        H[7] += h_;
    }

    // write message digest to output buffer
    for (int i = 0; i < 8; i++) {
        h[4 * i] = (uint8_t)(H[i] >> 24);
        h[4 * i + 1] = (uint8_t)(H[i] >> 16);
        h[4 * i + 2] = (uint8_t)(H[i] >> 8);
        h[4 * i + 3] = (uint8_t)H[i];
    }

    free(padded_m);
}

int main() {
    uint8_t *msg = (uint8_t*)"The quick brown fox jumps over the lazy dog";
    uint64_t msg_length = strlen((char*)msg);
    uint8_t hash[32];
    sha256_hash(msg, msg_length, hash);
    for (int i = 0; i < 32; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
    return 0;
}