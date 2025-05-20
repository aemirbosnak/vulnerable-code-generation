//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 32
#define BLOCK_SIZE 16

void hash(char* message, int length, char* digest) {
    int i, j;
    unsigned char buffer[BLOCK_SIZE];
    unsigned char hash_value[HASH_SIZE];
    unsigned int a, b, c, d, e, temp;
    char* hex_digits = "0123456789abcdef";

    for (i = 0; i < length; i += BLOCK_SIZE) {
        if (i + BLOCK_SIZE > length) {
            memset(buffer + i, 0, BLOCK_SIZE - i % BLOCK_SIZE);
            memcpy(buffer + i, message + i, length - i);
        } else {
            memcpy(buffer, message + i, BLOCK_SIZE);
        }

        a = b = c = d = e = 0x67452301;

        for (j = 0; j < BLOCK_SIZE; j++) {
            unsigned char t = buffer[j];
            temp = a;
            a = b;
            b = c;
            c = d;
            d = e;
            e = t ^ (a + (t & (b ^ c ^ d))) + 0x5a827999;
        }

        for (j = 0; j < HASH_SIZE; j++) {
            sprintf(digest + j * 2, "%02x", (unsigned int)hash_value[j]);
        }
    }
}

int main() {
    char message[] = "The quick brown fox jumps over the lazy dog";
    char digest[HASH_SIZE * 2 + 1];

    hash(message, strlen(message), digest);

    printf("Message: %s\n", message);
    printf("Digest: %s\n", digest);

    return 0;
}