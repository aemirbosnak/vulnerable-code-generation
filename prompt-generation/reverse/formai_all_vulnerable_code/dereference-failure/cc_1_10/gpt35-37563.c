//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: bold
#include <stdint.h>
#include <string.h>

#define ROUNDS 10
#define BLOCK_SIZE 64

#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32 - n)))

#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

#define FF(a, b, c, d, x, s, ac) \
    {                            \
        (a) += F((b), (c), (d)) + (x) + (uint32_t)(ac); \
        (a) = ROTATE_LEFT((a), (s)); \
        (a) += (b); \
    }
#define GG(a, b, c, d, x, s, ac) \
    {                            \
        (a) += G((b), (c), (d)) + (x) + (uint32_t)(ac); \
        (a) = ROTATE_LEFT((a), (s)); \
        (a) += (b); \
    }
#define HH(a, b, c, d, x, s, ac) \
    {                            \
        (a) += H((b), (c), (d)) + (x) + (uint32_t)(ac); \
        (a) = ROTATE_LEFT((a), (s)); \
        (a) += (b); \
    }
#define II(a, b, c, d, x, s, ac) \
    {                            \
        (a) += I((b), (c), (d)) + (x) + (uint32_t)(ac); \
        (a) = ROTATE_LEFT((a), (s)); \
        (a) += (b); \
    }

void calculate_md5(uint8_t *initial_msg, size_t initial_len, uint8_t *digest) {

    uint32_t h0, h1, h2, h3;

    h0 = 0x67452301;
    h1 = 0xEFCDAB89;
    h2 = 0x98BADCFE;
    h3 = 0x10325476;

    uint8_t *msg = NULL;

    size_t new_len, offset;
    uint32_t w[BLOCK_SIZE];

    int i;
    for (new_len = initial_len + 1; new_len % BLOCK_SIZE != 56; new_len++);
    new_len += 8;

    msg = calloc(new_len + BLOCK_SIZE, 1);
    memcpy(msg, initial_msg, initial_len);
    msg[initial_len] = 0x80;
    offset = new_len - 8;

    for (i = 0; i < 8; i++) {
        msg[offset + i] = (uint8_t)(initial_len << (8 * i));
    }

    for (i = 0; i < new_len; i += 64) {

        uint32_t *chunk = (uint32_t *)(msg + i);

        uint32_t a = h0, b = h1, c = h2, d = h3;

        int j;
        for (j = 0; j < 64; j++) {
            if (j < 16) {
                w[j] = chunk[j];
            } else {
                w[j] = w[j - 16] + ROTATE_LEFT(w[j - 15] ^ w[j - 13] ^ w[j - 8] ^ w[j - 2], 1);
            }

            if (j < 16) {
                FF(a, b, c, d, w[j], 7, 0xd76aa478);
            } else if (j < 32) {
                GG(a, b, c, d, w[(5 * j + 1) % 16], 12, 0xe8c7b756);
            } else if (j < 48) {
                HH(a, b, c, d, w[(3 * j + 5) % 16], 17, 0x242070db);
            } else {
                II(a, b, c, d, w[(7 * j) % 16], 22, 0xc1bdceee);
            }
        }

        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;
    }

    free(msg);

    uint8_t *p;
    p = (uint8_t *)&h0;
    digest[0] = p[0];
    digest[1] = p[1];
    digest[2] = p[2];
    digest[3] = p[3];
    p = (uint8_t *)&h1;
    digest[4] = p[0];
    digest[5] = p[1];
    digest[6] = p[2];
    digest[7] = p[3];
    p = (uint8_t *)&h2;
    digest[8] = p[0];
    digest[9] = p[1];
    digest[10] = p[2];
    digest[11] = p[3];
    p = (uint8_t *)&h3;
    digest[12] = p[0];
    digest[13] = p[1];
    digest[14] = p[2];
    digest[15] = p[3];
}

int main() {
    char *msg = "Hello, world! This is a test message for the MD5 hash function.";
    uint8_t digest[16] = {0};

    calculate_md5((unsigned char *)msg, strlen(msg), digest);

    printf("Message: %s\n", msg);
    printf("Hash: ");
    for (int i = 0; i < 16; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");

    return 0;
}