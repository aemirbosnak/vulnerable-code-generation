//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

#define CHUNK_SIZE 64

void sha256(unsigned char *message, size_t message_len, unsigned char *hash) {
    unsigned int h[8] = {
        0x6a09e667,
        0xbb67ae85,
        0x3c6ef372,
        0xa54ff53a,
        0x510e527f,
        0x9b05688c,
        0x1f83d9ab,
        0x5be0cd19
    };
    unsigned int w[64];
    unsigned int a, b, c, d, e, f, g, h_temp, i, j, t1, t2;

    size_t new_message_len = ((((message_len + 8) / CHUNK_SIZE) + 1) * CHUNK_SIZE) - 8;
    unsigned char *new_message = calloc(new_message_len + 8, 1);
    memcpy(new_message, message, message_len);

    new_message[message_len] = 0x80;

    unsigned int bits_len = message_len * 8;
    memcpy(&new_message[new_message_len], &bits_len, 4);

    for(i = 0; i < new_message_len; i += CHUNK_SIZE) {
        memcpy(w, &new_message[i], CHUNK_SIZE);

        for(j = 16; j < 64; j++) {
            w[j] = w[j-16] + ROTATE_LEFT(w[j-15], 7) + w[j-7] + ROTATE_LEFT(w[j-2], 15);
        }

        a = h[0];
        b = h[1];
        c = h[2];
        d = h[3];
        e = h[4];
        f = h[5];
        g = h[6];
        h_temp = h[7];

        for(j = 0; j < 64; j++) {
            t1 = h_temp + ROTATE_LEFT(e, 6) + ((e & f) ^ (~e & g)) +
                 0x428a2f98 + w[j];

            t2 = ROTATE_LEFT(a, 2) + ((a & b) ^ (a & c) ^ (b & c));

            h_temp = g;
            g = f;
            f = e;
            e = d + t1;
            d = c;
            c = b;
            b = a;
            a = t1 + t2;
        }

        h[0] += a;
        h[1] += b;
        h[2] += c;
        h[3] += d;
        h[4] += e;
        h[5] += f;
        h[6] += g;
        h[7] += h_temp;
    }

    free(new_message);

    for(i = 0; i < 8; i++) {
        hash[i * 4] = (h[i] >> 24) & 0xff;
        hash[i * 4 + 1] = (h[i] >> 16) & 0xff;
        hash[i * 4 + 2] = (h[i] >> 8) & 0xff;
        hash[i * 4 + 3] = h[i] & 0xff;
    }
}

int main() {
    unsigned char message[] = "The quick brown fox jumps over the lazy dog.";
    size_t message_len = strlen((const char *)message);
    unsigned char hash[32];

    sha256(message, message_len, hash);

    printf("Message: %s\n", message);
    for(int i = 0; i < 32; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}