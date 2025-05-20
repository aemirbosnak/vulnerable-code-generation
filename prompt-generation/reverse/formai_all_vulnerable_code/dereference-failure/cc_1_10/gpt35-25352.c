//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Define constants
#define ROTL(x, n) ((x) << (n)) | ((x) >> (32 - (n)))
#define ROTR(x, n) ((x) >> (n)) | ((x) << (32 - (n)))
#define CH(x, y, z) ((x) & (y)) ^ (~(x) & (z))
#define MAJ(x, y, z) ((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z))
#define EP0(x) ROTR((x), 2) ^ ROTR((x), 13) ^ ROTR((x), 22)
#define EP1(x) ROTR((x), 6) ^ ROTR((x), 11) ^ ROTR((x), 25)
#define SIG0(x) ROTR((x), 7) ^ ROTR((x), 18) ^ ((x) >> 3)
#define SIG1(x) ROTR((x), 17) ^ ROTR((x), 19) ^ ((x) >> 10)

// Initialize constants
static const uint32_t K[64] = {
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

// Initialize hash values
static uint32_t H[8] = {
    0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
    0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
};

// Define the message schedule structure
typedef struct {
    uint32_t words[16];
} message_schedule_t;

// Define the SHA-256 structure
typedef struct {
    uint32_t hash[8];
    uint32_t data[16];
    uint32_t len;
} sha256_ctx_t;

// Define the SHA-256 compression function
static void sha256_compress(sha256_ctx_t* ctx)
{
    message_schedule_t* m;
    uint32_t temp1, temp2, a, b, c, d, e, f, g, h, i;

    // Allocate memory for the message schedule
    m = (message_schedule_t*) malloc(sizeof(message_schedule_t));

    // Prepare the message schedule
    for (i = 0; i < 16; i++) {
        m->words[i] = ctx->data[i];
    }

    for (i = 16; i < 64; i++) {
        m->words[i] = SIG1(m->words[i - 2]) + m->words[i - 7] +
            SIG0(m->words[i - 15]) + m->words[i - 16];
    }

    // Initialize working variables
    a = H[0];
    b = H[1];
    c = H[2];
    d = H[3];
    e = H[4];
    f = H[5];
    g = H[6];
    h = H[7];

    // Perform round calculations
    for (i = 0; i < 64; i++) {
        temp1 = h + EP1(e) + CH(e, f, g) + K[i] + m->words[i];
        temp2 = EP0(a) + MAJ(a, b, c);
        h = g;
        g = f;
        f = e;
        e = d + temp1;
        d = c;
        c = b;
        b = a;
        a = temp1 + temp2;
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

    // Free memory
    free(m);
}

// Define the SHA-256 initialization function
static void sha256_init(sha256_ctx_t* ctx)
{
    ctx->hash[0] = H[0];
    ctx->hash[1] = H[1];
    ctx->hash[2] = H[2];
    ctx->hash[3] = H[3];
    ctx->hash[4] = H[4];
    ctx->hash[5] = H[5];
    ctx->hash[6] = H[6];
    ctx->hash[7] = H[7];
    ctx->len = 0;
    memset(&(ctx->data), 0, sizeof(ctx->data));
}

// Define the SHA-256 update function
static void sha256_update(sha256_ctx_t* ctx, const uint8_t* data, uint32_t len)
{
    uint32_t i;

    for (i = 0; i < len; i++) {
        ctx->data[(ctx->len / 4) % 16] <<= 8;
        ctx->data[(ctx->len / 4) % 16] |= data[i];
        ctx->len++;
        if (ctx->len % 64 == 0) {
            sha256_compress(ctx);
        }
    }
}

// Define the SHA-256 finalization function
static void sha256_finalize(sha256_ctx_t* ctx, uint8_t* digest)
{
    uint32_t len;
    uint32_t i;

    // Pad message
    ctx->data[(ctx->len / 4) % 16] <<= 8;
    ctx->data[(ctx->len / 4) % 16] |= 0x80;
    len = ctx->len + 1;

    while (len % 64 != 56) {
        ctx->data[(len / 4) % 16] = 0;
        len++;
    }

    ctx->data[14] = (ctx->len >> 29);
    ctx->data[15] = (ctx->len << 3);

    // Perform final compression
    sha256_compress(ctx);

    // Copy hash values to digest
    for (i = 0; i < 8; i++) {
        digest[i * 4 + 0] = (ctx->hash[i] >> 24);
        digest[i * 4 + 1] = (ctx->hash[i] >> 16);
        digest[i * 4 + 2] = (ctx->hash[i] >> 8);
        digest[i * 4 + 3] = (ctx->hash[i] >> 0);
    }

    // Clean up
    memset(ctx, 0, sizeof(ctx));
}

// Define the test function
static void sha256_test(const char* data, const char* expected)
{
    sha256_ctx_t* ctx;
    uint8_t digest[32];
    uint32_t i;

    // Allocate memory for SHA-256 context
    ctx = (sha256_ctx_t*) malloc(sizeof(sha256_ctx_t));

    // Initialize SHA-256 context
    sha256_init(ctx);

    // Update SHA-256 context with data
    sha256_update(ctx, (const uint8_t*) data, strlen(data));

    // Finalize SHA-256 context and get digest
    sha256_finalize(ctx, digest);

    // Print calculated hash
    printf("Calculated hash: ");
    for (i = 0; i < 32; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");

    // Compare digest with expected value
    if (memcmp(digest, expected, 32) == 0) {
        printf("Test passed!\n");
    } else {
        printf("Test failed!\n");
    }

    // Free memory
    free(ctx);
}

int main()
{
    sha256_test("", "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855");
    sha256_test("a", "ca978112ca1bbdcafac231b39a23dc4da786eff8147c4e72b9807785afee48bb");
    sha256_test("abcdefghijklmnopqrstuvwxyz", "c4c5d05a0c4c7f02531ecf63c401fe04f1e0cedf8e5e7f87c23b2a0610872c25");
    sha256_test("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789",
        "d5a04ae6c2361b5aee6b1921d9f4d7d0b88b31e0333d8a84c85f43eceddc13c0");
    sha256_test("12345678901234567890123456789012345678901234567890123456789012345678901234567890",
        "ddbcc5c7e43ab8abff1f964b96b2ccd8e825de2d697d0f14fda6e02a84281001");
    return 0;
}