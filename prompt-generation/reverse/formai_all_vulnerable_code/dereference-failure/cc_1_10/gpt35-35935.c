//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

typedef unsigned char byte;

byte *padding(const byte *message, size_t *newLen) {
    *newLen = BLOCK_SIZE - ((*newLen + 1) % BLOCK_SIZE);
    byte *newMessage = (byte *)malloc(*newLen + 1 + sizeof(size_t));
    memset(newMessage, 0, *newLen + 1 + sizeof(size_t));
    memcpy(newMessage, message, *newLen - sizeof(size_t));
    *(size_t *)(&newMessage[*newLen - sizeof(size_t)]) = *newLen - sizeof(size_t);
    newMessage[*newLen] = 0x80;
    *newLen += BLOCK_SIZE;
    return newMessage;
}

byte *hash(const byte *message, size_t messageLen) {
    byte *paddedMessage = padding(message, &messageLen);
    size_t blockCount = messageLen / BLOCK_SIZE;
    byte *H = (byte *)calloc(1, BLOCK_SIZE / 8);
    byte *W = (byte *)malloc(BLOCK_SIZE);
    byte *temp = (byte *)malloc(BLOCK_SIZE / 8);

    for (size_t i = 0; i < blockCount; i++) {
        memcpy(W, &paddedMessage[i * BLOCK_SIZE], BLOCK_SIZE);
        for (size_t j = 16; j < 80; j++) {
            size_t k = W[j - 16] ^ W[j - 14] ^ W[j - 8] ^ W[j - 3];
            W[j] = (byte)((k << 1) | (k >> 31));
        }
        byte a = H[0];
        byte b = H[1];
        byte c = H[2];
        byte d = H[3];
        byte e = H[4];
        byte f = H[5];
        byte g = H[6];
        byte h = H[7];

        for (size_t j = 0; j < 80; j++) {
            size_t t1 = ((h + ((e & f) ^ (~e & g)) + ((e & f) ^ (e & g))) & 0xffffffff);
            size_t t2 = ((a << 5 | a >> 27) + ((b & c) ^ (~b & d)) + e + W[j] + t1) & 0xffffffff;
            h = g;
            g = f;
            f = e;
            e = (byte)(d + t1);
            d = c;
            c = b;
            b = a;
            a = (byte)t2;
        }
        H[0] += a;
        H[1] += b;
        H[2] += c;
        H[3] += d;
        H[4] += e;
        H[5] += f;
        H[6] += g;
        H[7] += h;
    }

    free(paddedMessage);
    free(W);
    free(temp);
    return H;
}

void printHash(const byte *hash) {
    for (size_t i = 0; i < BLOCK_SIZE / 8; i++) {
        printf("%02x", hash[i]);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <message>\n", argv[0]);
        return 1;
    }

    byte *message = (byte *)argv[1];
    size_t messageLen = strlen(argv[1]);

    byte *hashValue = hash(message, messageLen);

    printHash(hashValue);
    printf("\n");

    free(hashValue);

    return 0;
}