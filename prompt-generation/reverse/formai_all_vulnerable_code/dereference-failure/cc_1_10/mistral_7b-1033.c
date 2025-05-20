//MISTRAL-7B DATASET v1.0 Category: Cryptographic hash function ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define HASH_SIZE 10000007
#define BUF_SIZE 1024

unsigned long long xorshift128plus() {
    static unsigned long long x = 0x853c49e6748fea9b, y = 0xda3e39cb94b95bdb;
    unsigned long long z;

    z = x ^ (x << 11);
    x = y;
    y = y ^ (y >> 14) ^ (z >> 18) ^ (z >> 31);
    return z;
}

void hash_string(char *str, unsigned long long *hash) {
    unsigned char buffer[BUF_SIZE];
    unsigned long long sum = 0, seed;
    int len = strlen(str);

    if (len > BUF_SIZE - 1) {
        fprintf(stderr, "Input string too long!\n");
        exit(1);
    }

    memcpy(buffer, str, len + 1);

    seed = xorshift128plus();

    for (int i = 0; i < len; i++) {
        sum += (unsigned long long)buffer[i] * pow(31, i) + seed;
        seed = xorshift128plus();
    }

    *hash = sum % HASH_SIZE;
}

int main(int argc, char *argv[]) {
    unsigned long long hash;

    if (argc < 2) {
        printf("Usage: %s <string>\n", argv[0]);
        exit(1);
    }

    clock_t start = clock();

    hash_string(argv[1], &hash);

    printf("Hash of '%s': %llu\n", argv[1], hash);

    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Computation time: %.12fs\n", time_taken);

    return 0;
}