//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL(a,b) (((a) << (b)) | ((a) >> (32-(b))))

uint32_t F(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) | (~x & z);
}

uint32_t G(uint32_t x, uint32_t y, uint32_t z) {
    return (x & z) | (y & ~z);
}

uint32_t H(uint32_t x, uint32_t y, uint32_t z) {
    return x ^ y ^ z;
}

uint32_t I(uint32_t x, uint32_t y, uint32_t z) {
    return y ^ (x | ~z);
}

void transform(uint32_t *state, uint32_t *block) {
    uint32_t a = state[0], b = state[1], c = state[2], d = state[3], i;

    for(i = 0; i < 64; i++) {
        uint32_t f, g;
        if (i < 16) {
            f = F(b, c, d);
            g = i;
        } else if (i < 32) {
            f = G(b, c, d);
            g = (5*i + 1) % 16;
        } else if (i < 48) {
            f = H(b, c, d);
            g = (3*i + 5) % 16;
        } else {
            f = I(b, c, d);
            g = (7*i) % 16;
        }

        uint32_t temp = d;
        d = c;
        c = b;

        uint32_t t = a + f + block[g] + 0x5A827999;
        b = b + ROTL(t, 5);
        a = temp;
    }

    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
}

void md5(uint8_t *initial_msg, size_t initial_len, uint8_t *digest) {
    uint32_t h0, h1, h2, h3;
    uint8_t *msg = NULL;

    uint32_t *padded_msg = NULL;
    size_t new_len, offset;
    uint32_t K[] = {
        0xD76AA478, 0xE8C7B756, 0x242070DB, 0xC1BDCEEE, 0xF57C0FAF, 0x4787C62A, 
        0xA8304613, 0xFD469501, 0x698098D8, 0x8B44F7AF, 0xFFFF5BB1, 0x895CD7BE, 
        0x6B901122, 0xFD987193, 0xA679438E, 0x49B40821, 0xF61E2562, 0xC040B340, 
        0x265E5A51, 0xE9B6C7AA, 0xD62F105D, 0x02441453, 0xD8A1E681, 0xE7D3FBC8, 
        0x21E1CDE6, 0xC33707D6, 0xF4D50D87, 0x455A14ED, 0xA9E3E905, 0xFCEFA3F8, 
        0x676F02D9, 0x8D2A4C8A, 0xFFFA3942, 0x8771F681, 0x6D9D6122, 0xFDE5380C, 
        0xA4BEEA44, 0x4BDECFA9, 0xF6BB4B60, 0xBEBFBC70, 0x289B7EC6, 0xEAA127FA, 
        0xD4EF3085, 0x04881D05, 0xD9D4D039, 0xE6DB99E5, 0x1FA27CF8, 0xC4AC5665, 
        0xF4292244, 0x432AFF97, 0xAB9423A7, 0xFC93A039, 0x655B59C3, 0x8F0CCC92, 
        0xFFEFF47D, 0x85845DD1, 0x6FA87E4F, 0xFE2CE6E0, 0xA3014314, 0x4E0811A1, 
        0xF7537E82, 0xBD3AF235, 0x2AD7D2BB, 0xEB86D391
    };
    int i;

    h0 = 0x67452301;
    h1 = 0xEFCDAB89;
    h2 = 0x98BADCFE;
    h3 = 0x10325476;

    new_len = ((((initial_len + 8) / 64) + 1) * 64) - 8;

    msg = (uint8_t *)malloc(new_len);
    memcpy(msg, initial_msg, initial_len);
    msg[initial_len] = 0x80;
    for (i = initial_len + 1; i < new_len; i++)
        msg[i] = 0;

    padded_msg = (uint32_t *)msg;
    padded_msg[new_len/4] = initial_len*8;

    for (offset = 0; offset < new_len; offset += (512/8)) {
        uint32_t *block = (uint32_t *)(&msg[offset]);
        uint32_t a = h0, b = h1, c = h2, d = h3;
        transform(&a, block);
        transform(&b, block);
        transform(&c, block);
        transform(&d, block);
        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;
    }

    free(msg);

    uint8_t *p = (uint8_t *)(&h0);
    for (i = 0; i < 4; i++) {
        digest[i] = *p++;
        digest[i+4] = *p++;
        digest[i+8] = *p++;
        digest[i+12] = *p++;
    }
}

int main(int argc, char **argv) {
    printf("Enter the message: ");
    char message[1000];
    fgets(message, 1000, stdin);
    message[strcspn(message, "\n")] = 0;

    uint8_t digest[16];
    md5(message, strlen(message), digest);

    printf("MD5 Hash of '%s': ", message);
    for(int i=0; i<16; i++)
        printf("%02x", digest[i]);

    printf("\n");

    return 0;
}