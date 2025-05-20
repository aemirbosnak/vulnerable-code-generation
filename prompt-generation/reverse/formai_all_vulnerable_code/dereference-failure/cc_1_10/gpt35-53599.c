//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTLEFT(a, b) ((a << b) | (a >> (32 - b)))

void sha256_hash(const uint8_t* data, size_t length, uint8_t hash[32])
{
    // Initial hash values (first 32 bits of the fractional parts of the square roots of the first 8 primes 2..19)
    const uint32_t hashValues[8] = { 0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19 }; 

    // Constants (first 32 bits of the fractional parts of the cube roots of the first 64 primes 2..311)
    const uint32_t w[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};

    uint32_t workSpc[64];    // Message schedule (section 6.2)
    uint32_t a, b, c, d, e, f, g, h;    // Working variables (section 6.2)
    uint32_t t1, t2;        // Temporary storage variables (section 6.2)

    // Hash values (section 6.2)
    uint32_t H[8];
    memcpy(H, hashValues, sizeof(hashValues));

    // Padding (section 5.1.1)
    uint8_t* padding = (uint8_t*)malloc(length + 64);
    memcpy(padding, data, length);
    padding[length] = 0x80;         // Append a single '1' bit
    size_t msgLength = length + 1;  
    while (msgLength % 64 != 56)     // Append '0' bits until message length in bits ≡ 448 (mod 512)
    {
        padding[msgLength++] = 0x00;
    }
    // Append length of message (before pre-processing), in bits, as 64-bit big-endian integer
    uint64_t bitLen = length * 8;
    memcpy(padding + msgLength, &bitLen, sizeof(bitLen));
    msgLength += sizeof(bitLen);

    // Process the message in successive 512-bit chunks (section 6.2)
    for (size_t chunkStart = 0; chunkStart < msgLength; chunkStart += 64)
    {
        // Prepare the message schedule (section 6.2)
        for (size_t i = 0; i < 16; i++)
        {
            workSpc[i] = (padding[chunkStart + i * 4 + 0] << 24) |
                (padding[chunkStart + i * 4 + 1] << 16) |
                (padding[chunkStart + i * 4 + 2] << 8) |
                (padding[chunkStart + i * 4 + 3] << 0);
        }
        for (size_t i = 16; i < 64; i++)
        {
            uint32_t s0 = ROTLEFT(workSpc[i - 15], 7) ^ ROTLEFT(workSpc[i - 15], 18) ^ (workSpc[i - 15] >> 3);
            uint32_t s1 = ROTLEFT(workSpc[i - 2], 17) ^ ROTLEFT(workSpc[i - 2], 19) ^ (workSpc[i - 2] >> 10);
            workSpc[i] = workSpc[i - 16] + s0 + workSpc[i - 7] + s1;
        }

        // Initialize working variables to current hash value (section 6.2)
        a = H[0];
        b = H[1];
        c = H[2];
        d = H[3];
        e = H[4];
        f = H[5];
        g = H[6];
        h = H[7];

        // Compression function main loop (section 6.2)
        for (size_t i = 0; i < 64; i++)
        {
            uint32_t S1 = ROTLEFT(e, 6) ^ ROTLEFT(e, 11) ^ ROTLEFT(e, 25);
            uint32_t ch = (e & f) ^ (~e & g);
            uint32_t temp1 = h + S1 + ch + w[i] + w[i] + w[i];
            uint32_t S0 = ROTLEFT(a, 2) ^ ROTLEFT(a, 13) ^ ROTLEFT(a, 22);
            uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
            uint32_t temp2 = S0 + maj;

            h = g;
            g = f;
            f = e;
            e = d + temp1;
            d = c;
            c = b;
            b = a;
            a = temp1 + temp2;
        }

        // Add the compressed chunk to the current hash value (section 6.2)
        H[0] += a;
        H[1] += b;
        H[2] += c;
        H[3] += d;
        H[4] += e;
        H[5] += f;
        H[6] += g;
        H[7] += h;
    }

    free(padding);

    // Produce the final hash value (big-endian) (section 6.2.2)
    for (size_t i = 0; i < 8; i++)
    {
        hash[i * 4 + 0] = (H[i] >> 24) & 0xff;
        hash[i * 4 + 1] = (H[i] >> 16) & 0xff;
        hash[i * 4 + 2] = (H[i] >> 8) & 0xff;
        hash[i * 4 + 3] = (H[i] >> 0) & 0xff;
    }
}

int main()
{
    uint8_t data[] = { 0x68, 0x65, 0x6c, 0x6c, 0x6f }; // "hello"
    uint8_t hash[32];
    sha256_hash(data, sizeof(data), hash);
    for (size_t i = 0; i < 32; i++)
    {
        printf("%02x", hash[i]);
    }
    printf("\n");  // Output: "185f8db32271fe25f561a6fc938b2e264306ec304eda518007d1764826381969"
    return 0;
}