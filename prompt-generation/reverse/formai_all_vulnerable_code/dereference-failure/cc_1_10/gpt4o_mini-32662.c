//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL(x,n) ((x << n) | (x >> (32 - n)))
#define CH(x,y,z) ((x & y) ^ (~x & z))
#define MAJ(x,y,z) ((x & y) ^ (x & z) ^ (y & z))
#define SIGMA0(x) (ROTL(x, 30) ^ ROTL(x, 19) ^ (x >> 10))
#define SIGMA1(x) (ROTL(x, 26) ^ ROTL(x, 21) ^ (x >> 7))
#define sig0(x) (ROTL(x, 25) ^ ROTL(x, 14) ^ (x >> 3))
#define sig1(x) (ROTL(x, 15) ^ ROTL(x, 13) ^ (x >> 10))
#define HASH_SIZE 32

static const uint32_t k[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0x394f97c7, 0x0bef903c, 0x2c90ebf0, 
    0x4f1bcf1a, 0x0a1c5256, 0x13c424c5, 0x52660a1b, 0x79b7c9a7, 0x1eab9431, 
    0x3e31f39b, 0x2e56e660, 0x8d09fbc8, 0x1b0e2292, 0x5d1db590, 0x8023093e, 
    0x26c1b2e1, 0x442f28b5, 0x5a2efde0, 0xf7a94321, 0x8f2a2086, 0xbc596a14, 
    0x6d9b293f, 0x6f87858a, 0x9e71b37a, 0x23ebd0b8, 0x8023f23c, 0xf5146540, 
    0xa8433ec5, 0x4cccc434, 0xf52e834b, 0xe91d62b5, 0x7cd8052f, 0xd90f8267, 
    0x7ea1de13, 0x58297125, 0xbab3e5c1, 0x294b6cd4, 0x9aa7d345, 0x38732fa0, 
    0x57112f7e, 0xfcbc0e1b, 0xcc3c69d5, 0x95bc95e2, 0x7bb45f85, 0x9dd1b15f, 
    0x1e2d3d5a, 0x370b9b5e, 0x83bcf3e2, 0xf575d3d9, 0x1a29c59e, 0x285c0f26, 
    0x6c16cc6f, 0x8adecd5e, 0x9dfb5bcc, 0x1b19e085, 0xf2785322, 0xa651933e
};

void preprocess(uint8_t *msg, size_t msg_len, uint8_t **msg_padded, size_t *new_len)
{
    size_t orig_len = msg_len * 8;
    size_t pad_len = (448 - orig_len % 512 + 512) % 512;
    pad_len = pad_len + 64;  // 64 bits for length
    *new_len = msg_len + pad_len / 8;
    *msg_padded = calloc(*new_len, sizeof(uint8_t));

    memcpy(*msg_padded, msg, msg_len);
    (*msg_padded)[msg_len] = 0x80;

    for (int i = 0; i < 8; i++)
    {
        (*msg_padded)[*new_len - 1 - i] = (orig_len >> (i * 8)) & 0xff;
    }
}

void hash(uint8_t *data, size_t len, uint8_t *out_hash)
{
    uint32_t H[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    for (size_t i = 0; i < len; i += 64)
    {
        uint32_t W[64] = {0};

        for (size_t j = 0; j < 16; j++)
        {
            W[j] = (data[i + j * 4] << 24) |
                   (data[i + j * 4 + 1] << 16) |
                   (data[i + j * 4 + 2] << 8) |
                   data[i + j * 4 + 3];
        }

        for (size_t j = 16; j < 64; j++)
        {
            W[j] = sig1(W[j - 2]) + W[j - 7] + sig0(W[j - 15]) + W[j - 16];
        }

        uint32_t a = H[0], b = H[1], c = H[2], d = H[3],
                 e = H[4], f = H[5], g = H[6], h = H[7];

        for (size_t j = 0; j < 64; j++)
        {
            uint32_t T1 = h + SIGMA1(e) + CH(e, f, g) + k[j] + W[j];
            uint32_t T2 = SIGMA0(a) + MAJ(a, b, c);
            h = g; g = f; f = e;
            e = d + T1; d = c; c = b; b = a;
            a = T1 + T2;
        }

        H[0] += a; H[1] += b; H[2] += c; H[3] += d;
        H[4] += e; H[5] += f; H[6] += g; H[7] += h;
    }

    for (size_t i = 0; i < 8; i++)
    {
        out_hash[i * 4] = (H[i] >> 24) & 0xff;
        out_hash[i * 4 + 1] = (H[i] >> 16) & 0xff;
        out_hash[i * 4 + 2] = (H[i] >> 8) & 0xff;
        out_hash[i * 4 + 3] = H[i] & 0xff;
    }
}

void print_hash(uint8_t *hash, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

int main()
{
    const char *message = "Mind-bending hash!";
    size_t message_len = strlen(message);
    uint8_t *padded_message;
    size_t padded_len;

    preprocess((uint8_t *)message, message_len, &padded_message, &padded_len);

    uint8_t hash_result[HASH_SIZE];
    hash(padded_message, padded_len, hash_result);

    printf("Original Message: %s\n", message);
    printf("SHA-256 Hash: ");
    print_hash(hash_result, HASH_SIZE);

    free(padded_message);
    return 0;
}