//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_PRIME 10000
#define MAX_P 1000
#define MAX_Q 1000
#define MAX_E 1000
#define MAX_N 1000

typedef struct {
    int prime;
    int p;
    int q;
    int e;
    int n;
} RSA;

int isPrime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

RSA* generateRSA(int bitSize) {
    RSA *rsa = (RSA *)malloc(sizeof(RSA));
    rsa->prime = 0;
    rsa->p = 0;
    rsa->q = 0;
    rsa->e = 0;
    rsa->n = 0;

    int count = 0;
    while (count < MAX_PRIME && rsa->prime == 0) {
        int n = rand() % MAX_N + 1;
        if (isPrime(n)) {
            rsa->prime = n;
        }
        count++;
    }

    rsa->p = rsa->prime - 1;
    rsa->q = rsa->prime - 1;

    while (!isPrime(rsa->p) ||!isPrime(rsa->q)) {
        rsa->p = rand() % MAX_P + 1;
        rsa->q = rand() % MAX_Q + 1;
    }

    rsa->e = rand() % (rsa->prime - 1) + 1;
    rsa->n = rsa->p * rsa->q;

    return rsa;
}

void printRSA(RSA *rsa) {
    printf("Prime: %d\n", rsa->prime);
    printf("P: %d\n", rsa->p);
    printf("Q: %d\n", rsa->q);
    printf("E: %d\n", rsa->e);
    printf("N: %d\n", rsa->n);
}

int main() {
    int bitSize = 2048;
    RSA *rsa = generateRSA(bitSize);
    printf("Generating RSA key pair with bit size %d...\n", bitSize);
    printRSA(rsa);

    return 0;
}