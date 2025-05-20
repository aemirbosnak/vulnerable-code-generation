//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: enthusiastic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdint.h>

// Function to perform SHA256 Hashing
void sha256(char* initial_message, uint32_t initial_len, uint32_t* hash)
{
    // Initialize variables
    uint32_t w[64];
    uint32_t a, b, c, d, e, f, g, h, T1, T2;

    // Initialize variables with initial hash values
    uint32_t H[] = {
        0x6a09e667,
        0xbb67ae85,
        0x3c6ef372,
        0xa54ff53a,
        0x510e527f,
        0x9b05688c,
        0x1f83d9ab,
        0x5be0cd19
    };

    // Initialize Constants
    uint64_t K[] = {
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
        0xa2bfe8a14cf10364, 0xa81a664bbcb4bf16, 0xc24b8b70d0f89791, 0xc76c51a30654be30,
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

    // Pre-Processing
    uint32_t K_offset = initial_len >> 29;
    uint32_t bit_len = initial_len * 8;
    uint32_t padding = (initial_len % 64 < 56) ? (64 - ((initial_len + 8) % 64)) : (128 - ((initial_len + 8) % 64));
    uint32_t new_len = initial_len + padding + 8;
    unsigned char* message = calloc(new_len, sizeof(char));
    memcpy(message, initial_message, initial_len);
    message[initial_len] = 0x80;
    for (int i = initial_len + 1; i < new_len - 8; ++i)
    {
        message[i] = 0x00;
    }
    for (int i = new_len - 8; i < new_len; ++i)
    {
        message[i] = (bit_len >> ((new_len - i - 1) * 8)) & 0xff;
    }

    // Message Scheduling
    for (int i = 0; i < new_len; i += 64)
    {
        for (int j = 0; j < 16; ++j)
        {
            w[j] = message[i + j * 4 + 0] << 24;
            w[j] |= message[i + j * 4 + 1] << 16;
            w[j] |= message[i + j * 4 + 2] << 8;
            w[j] |= message[i + j * 4 + 3] << 0;
        }
        for (int j = 16; j < 64; ++j)
        {
            uint32_t s0 = ((w[j - 15] >> 7) | (w[j - 15] << 25)) ^ ((w[j - 15] >> 18) | (w[j - 15] << 14)) ^ (w[j - 15] >> 3);
            uint32_t s1 = ((w[j - 2] >> 17) | (w[j - 2] << 15)) ^ ((w[j - 2] >> 19) | (w[j - 2] << 13)) ^ (w[j - 2] >> 10);
            w[j] = w[j - 16] + s0 + w[j - 7] + s1;
        }

        // Initialize variables
        a = H[0];
        b = H[1];
        c = H[2];
        d = H[3];
        e = H[4];
        f = H[5];
        g = H[6];
        h = H[7];

        // Compression
        for (int j = 0; j < 64; ++j)
        {
            T1 = h + (((e >> 6) | (e << 26)) ^ ((e >> 11) | (e << 21)) ^ ((e >> 25) | (e << 7))) + ((e & f) ^ (~e & g)) + K[j + K_offset] + w[j];
            T2 = (((a >> 2) | (a << 30)) ^ ((a >> 13) | (a << 19)) ^ ((a >> 22) | (a << 10))) + ((a & b) ^ (a & c) ^ (b & c));
            h = g;
            g = f;
            f = e;
            e = d + T1;
            d = c;
            c = b;
            b = a;
            a = T1 + T2;
        }

        // Update hash values
        H[0] += a;
        H[1] += b;
        H[2] += c;
        H[3] += d;
        H[4] += e;
        H[5] += f;
        H[6] += g;
        H[7] += h;
    }

    // Endianness Correction
    for (int i = 0; i < 8; ++i)
    {
        hash[i] = ((H[i] >> 24) & 0xff) | ((H[i] >> 8) & 0xff00) | ((H[i] << 8) & 0xff0000) | ((H[i] << 24) & 0xff000000);
    }
    free(message);
}

// Main Function
int main()
{
    // Sample Input Message
    char message[] = "Hello, World!";

    // Initialize Hash Value
    uint32_t hash_value[8];

    // Compute Hash Value
    sha256(message, strlen(message), hash_value);

    // Print Hash Value
    printf("SHA-256 Hash of '%s' : \n", message);
    for (int i = 0; i < 8; ++i)
    {
        printf(" %08x", hash_value[i]);
    }
    printf("\n");

    return 0;
}