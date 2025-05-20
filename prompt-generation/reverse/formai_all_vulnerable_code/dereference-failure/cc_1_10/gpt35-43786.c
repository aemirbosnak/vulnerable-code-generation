//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: random
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define ROTL(x,n) ((x) << (n)) | ((x) >> (32 - (n)))
#define ROTR(x,n) ((x) >> (n)) | ((x) << (32 - (n)))
#define CH(x,y,z) ((x) & (y)) ^ (~(x) & (z))
#define MAJ(x,y,z) ((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z))
#define SIG0(x) ROTR(x,2) ^ ROTR(x,13) ^ ROTR(x,22)
#define SIG1(x) ROTR(x,6) ^ ROTR(x,11) ^ ROTR(x,25)
#define sig0(x) ROTR(x,7) ^ ROTR(x,18) ^ ((x) >> 3)
#define sig1(x) ROTR(x,17) ^ ROTR(x,19) ^ ((x) >> 10)

void sha256(uint8_t *msg, size_t len, uint8_t hash[32])
{
    uint32_t h[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };
    
    uint32_t k[64] = {
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
        0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2,
    };
    
    len += 9;
    size_t new_len = len + (64 - (len % 64));
    uint8_t *msg_new = (uint8_t *) malloc(new_len);
    memcpy(msg_new, msg, len - 9);
    memset(msg_new + len - 9, 0, new_len - len);
    msg_new[len - 9] = 0x80;
    uint64_t len_bits = (uint64_t) len * 8;
    memcpy(msg_new + new_len - 8, &len_bits, 8);
    
    for (size_t i = 0; i < new_len; i += 64) {
        uint32_t w[64];
        for (size_t j = i; j < i + 64; j += 4) {
            w[(j - i) / 4] = (msg_new[j] << 24) | (msg_new[j + 1] << 16) |
                             (msg_new[j + 2] << 8) | (msg_new[j + 3]);
        }
        uint32_t a = h[0], b = h[1], c = h[2], d = h[3], e = h[4],
                 f = h[5], g = h[6], h_ = h[7];
        
        for (size_t j = 0; j < 64; j++) {
            uint32_t t1 = h_ + SIG1(e) + CH(e,f,g) + k[j] + w[j];
            uint32_t t2 = SIG0(a) + MAJ(a,b,c);
            h_ = g;
            g = f;
            f = e;
            e = d + t1;
            d = c;
            c = b;
            b = a;
            a = t1 + t2;
        }
        
        h[0] += a; h[1] += b; h[2] += c; h[3] += d;
        h[4] += e; h[5] += f; h[6] += g; h[7] += h_;
    }
    
    for (int i = 0; i < 8; i++) {
        hash[i * 4] = h[i] >> 24;
        hash[i * 4 + 1] = (h[i] >> 16) & 0xff;
        hash[i * 4 + 2] = (h[i] >> 8) & 0xff;
        hash[i * 4 + 3] = h[i] & 0xff;
    }
    
    free(msg_new);
}

int main()
{
    uint8_t msg[] = "This is a test message that will be hashed using my unique cryptographic hash function";
    uint8_t hash[32];
    sha256(msg, strlen((const char *) msg), hash);
    printf("Hash: ");
    for (int i = 0; i < 32; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
    return 0;
}