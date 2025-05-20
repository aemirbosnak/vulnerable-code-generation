//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_PRIME 1000

int is_prime(long num) {
    if (num <= 1)
        return 0;
    if (num == 2)
        return 1;
    if (num % 2 == 0)
        return 0;
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

long gcd(long a, long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long lcm(long a, long b) {
    return (a * b) / gcd(a, b);
}

long generate_prime() {
    long prime;
    srand((unsigned int) time(NULL));
    do {
        prime = rand() % MAX_PRIME;
    } while (!is_prime(prime));
    return prime;
}

void generate_key_pairs(long *p, long *q, long *n, long *e, long *d) {
    *p = generate_prime();
    *q = generate_prime();
    *n = *p * *q;
    long phi = lcm(*p - 1, *q - 1);
    srand((unsigned int) time(NULL));

    do {
        *e = rand() % phi;
    } while (gcd(*e, phi) != 1);

    long k = 1;
    do {
        *d = (k * phi + 1) / *e;
        k++;
    } while (gcd(*e, *d) != 1);
}

int main() {
    long p, q, n, e, d;
    generate_key_pairs(&p, &q, &n, &e, &d);
    printf("Public Key: (%ld,%ld)\n", e, n);
    printf("Private Key: (%ld,%ld)\n", d, n);
    return 0;
}