//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sha512(const char* message, unsigned char* digest)
{
    const unsigned long long k[] = {
        0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f, 0xe9b5dba58189dbbc,
        0x3956c25bf348b538, 0x59f111f1b605d019, 0x923f82a4af194f9b, 0xab1c5ed5da6d8118,
        0xd807aa98a3030242, 0x12835b0145706fbe, 0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2,
        0x72be5d74f27b896f, 0x80deb1fe3b1696b1, 0x9bdc06a725c71235, 0xc19bf174cf692694,
        0xe49b69c19ef14ad2, 0xefbe4786384f25e3, 0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65,
        0x2de92c6f592b0275, 0x4a7484aa6ea6e483, 0x5cb0a9dcbd41fbd4, 0x76f988da831153b5,
        0x983e5152ee66dfab, 0xa831c66d2db43210, 0xb00327c898fb213f, 0xbf597fc7beef0ee4,
        0xc6e00bf33da88fc2, 0xd5a79147930aa725, 0x06ca6351e003826f, 0x142929670a0e6e70,
        0x27b70a8546d22ffc, 0x2e1b21385c26c926, 0x4d2c6dfc5ac42aed, 0x53380d139d95b3df,
        0x650a73548baf63de, 0x766a0abb3c77b2a8, 0x81c2c92e47edaee6, 0x92722c851482353b,
        0xa2bfe8a14cf10364, 0xa81a664bbc423001, 0xc24b8b70d0f89791, 0xc76c51a30654be30,
        0xd192e819d6ef5218, 0xd69906245565a910, 0xf40e35855771202a, 0x106aa07032bbd1b8,
        0x19a4c116b8d2d0c8, 0x1e376c085141ab53, 0x2748774cdf8eeb99, 0x34b0bcb5e19b48a8,
        0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb, 0x5b9cca4f7763e373, 0x682e6ff3d6b2b8a3,
        0x748f82ee5defb2fc, 0x78a5636f43172f60, 0x84c87814a1f0ab72, 0x8cc702081a6439ec,
        0x90befffa23631e28, 0xa4506cebde82bde9, 0xbef9a3f7b2c67915, 0xc67178f2e372532b,
        0xca273eceea26619c, 0xd186b8c721c0c207, 0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178,
        0x06f067aa72176fba, 0x0a637dc5a2c898a6, 0x113f9804bef90dae, 0x1b710b35131c471b,
        0x28db77f523047d84, 0x32caab7b40c72493, 0x3c9ebe0a15c9bebc, 0x431d67c49c100d4c,
        0x4cc5d4becb3e42b6, 0x597f299cfc657e2a, 0x5fcb6fab3ad6faec, 0x6c44198c4a475817
    };
    const char* padding = "\x80\0\0\0\0\0\0\0";
    const unsigned long long message_length = strlen(message);
    unsigned long long padded_length = message_length + 1;
    while (padded_length % 128 != 112) 
    {
        padded_length++;
    }
    unsigned char* padded_message = calloc(padded_length + 16, 1);
    memcpy(padded_message, message, message_length);
    memcpy(&padded_message[message_length], padding, padded_length - message_length);
    const unsigned long long bit_length = message_length * 8;
    for (int i = 0; i < 8; i++) 
    {
        padded_message[padded_length + i] = bit_length >> ((7 - i) * 8);
    }
    unsigned long long message_blocks = padded_length / 128;
    unsigned long long state[8] = {
        0x6a09e667f3bcc908, 0xbb67ae8584caa73b, 0x3c6ef372fe94f82b, 0xa54ff53a5f1d36f1,
        0x510e527fade682d1, 0x9b05688c2b3e6c1f, 0x1f83d9abfb41bd6b, 0x5be0cd19137e2179
    };
    for (unsigned long long block = 0; block < message_blocks; block++) 
    {
        unsigned long long words[80] = {0};
        memcpy(&words, &padded_message[block * 128], 128);
        for (int i = 16; i < 80; i++) 
        {
            unsigned long long s0 = words[i - 15] >> 1 | words[i - 15] << 63;
            unsigned long long s1 = words[i - 2] >> 19 | words[i - 2] << 45;
            unsigned long long x0 = words[i - 16];
            unsigned long long x1 = words[i - 7];
            unsigned long long x2 = words[i - 15];
            unsigned long long x3 = words[i - 2];
            unsigned long long sum = x0 + x1 + x2 + x3 + s0 + s1;
            words[i] = sum;
        }
        unsigned long long a = state[0];
        unsigned long long b = state[1];
        unsigned long long c = state[2];
        unsigned long long d = state[3];
        unsigned long long e = state[4];
        unsigned long long f = state[5];
        unsigned long long g = state[6];
        unsigned long long h = state[7];
        for (int i = 0; i < 80; i++) 
        {
            unsigned long long s0 = a >> 28 | a << 36;
            unsigned long long s1 = a >> 34 | a << 30;
            unsigned long long E = e >> 14 | e << 50;
            unsigned long long a_sum = s1 ^ s0 ^ (a >> 23);
            unsigned long long maj = (a & b) ^ (a & c) ^ (b & c);
            unsigned long long t2 = a_sum + maj;
            unsigned long long t1 = h + E;
            unsigned long long ch = (e & f) ^ (~e & g);
            unsigned long long sE = e >> 18 | e << 46;
            unsigned long long sA = a >> 19 | a << 45;
            unsigned long long Ech = sE ^ sA ^ (a >> 6);
            h = g;
            g = f;
            f = e;
            e = d + t1;
            d = c;
            c = b;
            b = a;
            a = t1 + t2;
        }
        state[0] += a;
        state[1] += b;
        state[2] += c;
        state[3] += d;
        state[4] += e;
        state[5] += f;
        state[6] += g;
        state[7] += h;
    }
    for (int i = 0; i < 8; i++) 
    {
        unsigned char* block = (unsigned char*)&state[i];
        for (int j = 0; j < 8; j++) 
        {
            digest[i * 8 + j] = block[7 - j];
        }
    }
    free(padded_message);
}

int main()
{
    char* message = "Hello, world!";
    unsigned char digest[64] = {0};
    sha512(message, digest);
    printf("Message: %s\n", message);
    printf("Digest: ");
    for (int i = 0; i < 64; i++) 
    {
        printf("%02hhx", digest[i]);
    }
    printf("\n");
    return 0;
}