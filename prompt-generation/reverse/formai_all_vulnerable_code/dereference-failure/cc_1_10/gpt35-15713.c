//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define HASH_LENGTH 64

uint64_t mix(uint64_t a, uint64_t b, uint64_t c)
{
    a -= b; a -= c; a ^= (c >> 43);
    b -= c; b -= a; b ^= (a << 9);
    c -= a; c -= b; c ^= (b >> 8);
    a -= b; a -= c; a ^= (c >> 38);
    b -= c; b -= a; b ^= (a << 23);
    c -= a; c -= b; c ^= (b >> 5);
    a -= b; a -= c; a ^= (c >> 35);
    b -= c; b -= a; b ^= (a << 49);
    c -= a; c -= b; c ^= (b >> 11);
    a -= b; a -= c; a ^= (c >> 12);
    b -= c; b -= a; b ^= (a << 18);
    c -= a; c -= b; c ^= (b >> 22);
    return c;
}

int hasher(char *message, char *result)
{
    uint64_t x[16];
    uint64_t a, b, c, d;
    char hash[HASH_LENGTH + 1];
    int offset;
    int i;

    /* initialize */
    a = 0x736f6d6570736575;
    b = 0x646f72616e646f6d;
    c = 0x6c7967656e657261;
    d = 0x7465646279746573;

    /* message consumption */
    for (offset = 0; offset < strlen(message); offset += 128) {
        for (i = 0; i < 16; i++) {
            x[i] = *((uint64_t*) (message + offset + i*8));
        }
        a = mix(a,x[0],x[1]); b = mix(b,x[2],x[3]);
        c = mix(c,x[4],x[5]); d = mix(d,x[6],x[7]);
        a = mix(a,x[8],x[9]); b = mix(b,x[10],x[11]);
        c = mix(c,x[12],x[13]); d = mix(d,x[14],x[15]);
    }

    /* finalization */
    a ^= b; c ^= d; b = mix(b,c,a);
    d = mix(d,a,c); a ^= b; c ^= d;
    b = mix(b,c,a); d = mix(d,a,c);
    a ^= b; c ^= d; b = mix(b,c,a);
    d = mix(d,a,c);
    memcpy(hash, &a, 8);
    memcpy(hash + 8, &b, 8);
    memcpy(hash + 16, &c, 8);
    memcpy(hash + 24, &d, 8);
    for (i = 32; i < HASH_LENGTH; i++) {
        hash[i] = 0;
    }

    /* write to result char array */
    memcpy(result, hash, HASH_LENGTH + 1);

    return 0;
}

int main()
{
    char message[] = "This is a secret message!";

    char result[HASH_LENGTH + 1];
    memset(result, 0, HASH_LENGTH + 1);

    hasher(message, result);

    printf("Message: %s\n", message);
    printf("Hash:    %s\n", result);

    return 0;
}