//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

static const uint32_t k[8] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
    0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5
};

static uint32_t h[8] = {
    0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
    0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
};

static void sha256_transform(uint32_t *state, const uint8_t *data)
{
    uint32_t a, b, c, d, e, f, g, h;
    uint32_t w[64];
    int i, j;

    a = state[0];
    b = state[1];
    c = state[2];
    d = state[3];
    e = state[4];
    f = state[5];
    g = state[6];
    h = state[7];

    for (i = 0; i < 16; i++) {
        w[i] = (data[4 * i] << 24) | (data[4 * i + 1] << 16) | (data[4 * i + 2] << 8) | data[4 * i + 3];
    }

    for (i = 16; i < 64; i++) {
        uint32_t s0 = ROTL(w[i - 15], 7) ^ ROTL(w[i - 15], 18) ^ (w[i - 15] >> 3);
        uint32_t s1 = ROTL(w[i - 2], 17) ^ ROTL(w[i - 2], 19) ^ (w[i - 2] >> 10);
        w[i] = w[i - 16] + s0 + w[i - 7] + s1;
    }

    for (i = 0; i < 64; i++) {
        uint32_t s1 = ROTL(e, 6) ^ ROTL(e, 11) ^ ROTL(e, 25);
        uint32_t ch = (e & f) ^ (~e & g);
        uint32_t temp1 = h + s1 + ch + k[i] + w[i];
        uint32_t s0 = ROTL(a, 2) ^ ROTL(a, 13) ^ ROTL(a, 22);
        uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
        uint32_t temp2 = s0 + maj;

        h = g;
        g = f;
        f = e;
        e = d + temp1;
        d = c;
        c = b;
        b = a;
        a = temp1 + temp2;
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

static void sha256_init(uint32_t *state)
{
    memcpy(state, h, sizeof(h));
}

static void sha256_update(uint32_t *state, const uint8_t *data, size_t len)
{
    size_t i, j;
    uint8_t buf[64];

    for (i = 0, j = 0; i < len; i++, j++) {
        buf[j] = data[i];
        if (j == 63) {
            sha256_transform(state, buf);
            j = 0;
        }
    }

    if (j != 0) {
        memset(buf + j, 0, 64 - j);
        sha256_transform(state, buf);
    }
}

static void sha256_final(uint32_t *state, uint8_t *digest)
{
    size_t i;
    uint8_t buf[64];

    buf[0] = 0x80;
    memset(buf + 1, 0, 63);
    sha256_transform(state, buf);

    for (i = 0; i < 8; i++) {
        digest[i * 4] = (state[i] >> 24) & 0xff;
        digest[i * 4 + 1] = (state[i] >> 16) & 0xff;
        digest[i * 4 + 2] = (state[i] >> 8) & 0xff;
        digest[i * 4 + 3] = state[i] & 0xff;
    }
}

int main(int argc, char **argv)
{
    uint32_t state[8];
    uint8_t digest[32];
    int i;

    sha256_init(state);
    sha256_update(state, argv[1], strlen(argv[1]));
    sha256_final(state, digest);

    printf("SHA256 digest: ");
    for (i = 0; i < 32; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");

    return 0;
}