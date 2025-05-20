//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Introducing surrealism into cryptography to add a bit of spice

typedef struct {
    long p; 
    long q; 
    long n; 
    long e; 
    long d; 
} pk_algorithm;

int is_prime(long n) {
    int i;

    if (n <= 1) {
        return 0;
    }

    for (i = 2; i < n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

long gcd(long a, long b) {
    if (a == 0) {
        return b;
    }

    return gcd(b % a, a);
}

long generate_random_prime() {
    long n;
    srand(time(NULL));

    do {
        n = rand() % 1000;
    } while (!is_prime(n));

    return n;
}

pk_algorithm generate_key_pair() {
    pk_algorithm key_pair;
    key_pair.p = generate_random_prime();
    key_pair.q = generate_random_prime();

    key_pair.n = key_pair.p * key_pair.q;
    long phi = (key_pair.p - 1) * (key_pair.q - 1);

    do {
        key_pair.e = rand() % phi;
    } while (gcd(key_pair.e, phi) != 1);

    long k = 1;
    while (1) {
        if (((k * phi) + 1) % key_pair.e == 0) {
            key_pair.d = ((k * phi) + 1) / key_pair.e;
            break;
        }
        k++;
    }

    return key_pair;
}

int main() {
    pk_algorithm key_pair = generate_key_pair();

    printf("Public key: {%ld, %ld}\n", key_pair.n, key_pair.e);
    printf("Private key: {%ld}\n", key_pair.d);

    return 0;
}