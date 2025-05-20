//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: statistical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BLOCK_SIZE 64

unsigned long long int h0 = 0x6a09e667bb67ae85;
unsigned long long int h1 = 0x3c6ef372a54ff53a;
unsigned long long int h2 = 0x510e527f9b05688c;
unsigned long long int h3 = 0x1f83d9ab5be0cd19;
unsigned long long int h4 = 0x428a2f9873d92c01;
unsigned long long int h5 = 0xb5c0fbcfe9b5dba5;
unsigned long long int h6 = 0xcb8d5ebc5c026c83;
unsigned long long int h7 = 0x2f815e9bdc6d1891;

unsigned long long int k[] =  {
    0x428a2f98d728ae22ULL, 0x7137449123ef65cdULL,
    0xb5c0fbcfec4d3b2fULL, 0xe9b5dba58189dbbcULL,
    0x3956c25bf348b538ULL, 0x59f111f1b605d019ULL,
    0x923f82a4af194f9bULL, 0xab1c5ed5da6d8118ULL,
    0xd807aa98a3030242ULL, 0x12835b0145706fbeULL,
    0x243185be4ee4b28cULL, 0x550c7dc3d5ffb4e2ULL,
    0x72be5d74f27b896fULL, 0x80deb1fe3b1696b1ULL,
    0x9bdc06a725c71235ULL, 0xc19bf174cf692694ULL,
    0xe49b69c19ef14ad2ULL, 0xefbe4786384f25e3ULL,
    0x0fc19dc68b8cd5b5ULL, 0x240ca1cc77ac9c65ULL,
    0x2de92c6f592b0275ULL, 0x4a7484aa6ea6e483ULL,
    0x5cb0a9dcbd41fbd4ULL, 0x76f988da831153b5ULL,
    0x983e5152ee66dfabULL, 0xa831c66d2db43210ULL,
    0xb00327c898fb213fULL, 0xbf597fc7beef0ee4ULL,
    0xc6e00bf33da88fc2ULL, 0xd5a79147930aa725ULL,
    0x06ca6351e003826fULL, 0x142929670a0e6e70ULL,
    0x27b70a8546d22ffcULL, 0x2e1b21385c26c926ULL,
    0x4d2c6dfc5ac42aedULL, 0x53380d139d95b3dfULL,
    0x650a73548baf63deULL, 0x766a0abb3c77b2a8ULL,
    0x81c2c92e47edaee6ULL, 0x92722c851482353bULL,
    0xa2bfe8a14cf10364ULL, 0xa81a664bbc423001ULL,
    0xc24b8b70d0f89791ULL, 0xc76c51a30654be30ULL,
    0xd192e819d6ef5218ULL, 0xd69906245565a910ULL,
    0xf40e35855771202aULL, 0x106aa07032bbd1b8ULL,
    0x19a4c116b8d2d0c8ULL, 0x1e376c085141ab53ULL,
    0x2748774cdf8eeb99ULL, 0x34b0bcb5e19b48a8ULL,
    0x391c0cb3c5c95a63ULL, 0x4ed8aa4ae3418acbULL,
    0x5b9cca4f7763e373ULL, 0x682e6ff3d6b2b8a3ULL,
    0x748f82ee5defb2fcULL, 0x78a5636f43172f60ULL,
    0x84c87814a1f0ab72ULL, 0x8cc702081a6439ecULL,
    0x90befffa23631e28ULL, 0xa4506cebde82bde9ULL,
    0xbef9a3f7b2c67915ULL, 0xc67178f2e372532bULL,
    0xca273eceea26619cULL, 0xd186b8c721c0c207ULL,
    0xeada7dd6cde0eb1eULL, 0xf57d4f7fee6ed178ULL,
    0x06f067aa72176fbaULL, 0x0a637dc5a2c898a6ULL,
    0x113f9804bef90daeULL, 0x1b710b35131c471bULL,
    0x28db77f523047d84ULL, 0x32caab7b40c72493ULL,
    0x3c9ebe0a15c9bebcULL, 0x431d67c49c100d4cULL,
    0x4cc5d4becb3e42b6ULL, 0x597f299cfc657e2aULL,
    0x5fcb6fab3ad6faecULL, 0x6c44198c4a475817ULL
};

void sha512(const unsigned char* message, unsigned long long int len, unsigned char* digest) {
    unsigned long long int message_len_bits = len * 8;
    unsigned long long int padding_len = BLOCK_SIZE - ((message_len_bits + 128) % BLOCK_SIZE);
    if (padding_len == BLOCK_SIZE) {
        padding_len = 0;
    }
    unsigned long long int padded_len = len + padding_len + 16;
    unsigned char* padded = (unsigned char*)malloc(padded_len);
    memcpy(padded, message, len);
    padded[len] = 0x80;
    memset(padded + len + 1, 0, padding_len);
    for (int i = 0; i < 8; i++) {
        padded[padded_len - 8 + i] = message_len_bits >> (8 * (7 - i));
    }
    unsigned long long int blocks = padded_len / BLOCK_SIZE;
    unsigned long long int w[80];
    unsigned long long int a, b, c, d, e, f, g, h, t1, t2;
    for (unsigned long long int i = 0; i < blocks; i++) {
        unsigned char* block = padded + (i * BLOCK_SIZE);
        for (int j = 0; j < 16; j++) {
            w[j] = (unsigned long long int)(block[j * 8]) << 56 |
                  (unsigned long long int)(block[j * 8 + 1]) << 48 |
                  (unsigned long long int)(block[j * 8 + 2]) << 40 |
                  (unsigned long long int)(block[j * 8 + 3]) << 32 |
                  (unsigned long long int)(block[j * 8 + 4]) << 24 |
                  (unsigned long long int)(block[j * 8 + 5]) << 16 |
                  (unsigned long long int)(block[j * 8 + 6]) << 8 |
                  (unsigned long long int)(block[j * 8 + 7]);
        }
        for (int j = 16; j < 80; j++) {
            unsigned long long int s0 = ((w[j - 15] >> 1) | (w[j - 15] << 63)) ^ ((w[j - 15] >> 8) | (w[j - 15] << 56)) ^ (w[j - 15] >> 7);
            unsigned long long int s1 = ((w[j - 2] >> 19) | (w[j - 2] << 45)) ^ ((w[j - 2] >> 61) | (w[j - 2] << 3)) ^ (w[j - 2] >> 6);
            w[j] = w[j - 16] + s0 + w[j - 7] + s1;
        }
        a = h0;
        b = h1;
        c = h2;
        d = h3;
        e = h4;
        f = h5;
        g = h6;
        h = h7;
        for (int j = 0; j < 80; j++) {
            t1 = h + (((e >> 14) | (e << 50)) ^ ((e >> 18) | (e << 46)) ^ ((e >> 41) | (e << 23))) + ((e & f) ^ (~e & g)) + k[j] + w[j];
            t2 = (((a >> 28) | (a << 36)) ^ ((a >> 34) | (a << 30)) ^ ((a >> 39) | (a << 25))) + ((a & b) ^ (a & c) ^ (b & c));
            h = g;
            g = f;
            f = e;
            e = d + t1;
            d = c;
            c = b;
            b = a;
            a = t1 + t2;
        }
        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;
        h4 += e;
        h5 += f;
        h6 += g;
        h7 += h;
    }
    free(padded);
    digest[0] = (h0 >> 56) & 0xff;
    digest[1] = (h0 >> 48) & 0xff;
    digest[2] = (h0 >> 40) & 0xff;
    digest[3] = (h0 >> 32) & 0xff;
    digest[4] = (h0 >> 24) & 0xff;
    digest[5] = (h0 >> 16) & 0xff;
    digest[6] = (h0 >> 8) & 0xff;
    digest[7] = h0 & 0xff;
    digest[8] = (h1 >> 56) & 0xff;
    digest[9] = (h1 >> 48) & 0xff;
    digest[10] = (h1 >> 40) & 0xff;
    digest[11] = (h1 >> 32) & 0xff;
    digest[12] = (h1 >> 24) & 0xff;
    digest[13] = (h1 >> 16) & 0xff;
    digest[14] = (h1 >> 8) & 0xff;
    digest[15] = h1 & 0xff;
    digest[16] = (h2 >> 56) & 0xff;
    digest[17] = (h2 >> 48) & 0xff;
    digest[18] = (h2 >> 40) & 0xff;
    digest[19] = (h2 >> 32) & 0xff;
    digest[20] = (h2 >> 24) & 0xff;
    digest[21] = (h2 >> 16) & 0xff;
    digest[22] = (h2 >> 8) & 0xff;
    digest[23] = h2 & 0xff;
    digest[24] = (h3 >> 56) & 0xff;
    digest[25] = (h3 >> 48) & 0xff;
    digest[26] = (h3 >> 40) & 0xff;
    digest[27] = (h3 >> 32) & 0xff;
    digest[28] = (h3 >> 24) & 0xff;
    digest[29] = (h3 >> 16) & 0xff;
    digest[30] = (h3 >> 8) & 0xff;
    digest[31] = h3 & 0xff;
    digest[32] = (h4 >> 56) & 0xff;
    digest[33] = (h4 >> 48) & 0xff;
    digest[34] = (h4 >> 40) & 0xff;
    digest[35] = (h4 >> 32) & 0xff;
    digest[36] = (h4 >> 24) & 0xff;
    digest[37] = (h4 >> 16) & 0xff;
    digest[38] = (h4 >> 8) & 0xff;
    digest[39] = h4 & 0xff;
    digest[40] = (h5 >> 56) & 0xff;
    digest[41] = (h5 >> 48) & 0xff;
    digest[42] = (h5 >> 40) & 0xff;
    digest[43] = (h5 >> 32) & 0xff;
    digest[44] = (h5 >> 24) & 0xff;
    digest[45] = (h5 >> 16) & 0xff;
    digest[46] = (h5 >> 8) & 0xff;
    digest[47] = h5 & 0xff;
    digest[48] = (h6 >> 56) & 0xff;
    digest[49] = (h6 >> 48) & 0xff;
    digest[50] = (h6 >> 40) & 0xff;
    digest[51] = (h6 >> 32) & 0xff;
    digest[52] = (h6 >> 24) & 0xff;
    digest[53] = (h6 >> 16) & 0xff;
    digest[54] = (h6 >> 8) & 0xff;
    digest[55] = h6 & 0xff;
    digest[56] = (h7 >> 56) & 0xff;
    digest[57] = (h7 >> 48) & 0xff;
    digest[58] = (h7 >> 40) & 0xff;
    digest[59] = (h7 >> 32) & 0xff;
    digest[60] = (h7 >> 24) & 0xff;
    digest[61] = (h7 >> 16) & 0xff;
    digest[62] = (h7 >> 8) & 0xff;
    digest[63] = h7 & 0xff;
}

int main() {
    unsigned char message[] = "The quick brown fox jumps over the lazy dog";
    unsigned char digest[64];
    sha512(message, sizeof(message) - 1, digest);
    printf("Message: %s\n", message);
    printf("Digest: ");
    for (int i = 0; i < 64; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");
    return 0;
}