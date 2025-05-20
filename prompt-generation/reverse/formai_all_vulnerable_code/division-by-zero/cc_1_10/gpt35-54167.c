//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void generate_keys() {
    long int p, q, n, phi, e, d;
    int bit_len = 1024;

    srand(time(NULL));

    // Generate two random prime numbers p and q
    p = rand() % (1 << (bit_len / 2));
    q = rand() % (1 << (bit_len / 2));

    // Calculate n, phi, and e
    n = p * q;
    phi = (p - 1) * (q - 1);

    for (int i = 2; i < phi; i++) {
        if (phi % i == 0) continue;

        int is_coprime = 1;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                is_coprime = 0;
                break;
            }
        }

        if (is_coprime) {
            e = i;
            break;
        }
    }

    // Calculate d
    int k = 1;
    while ((1 + k * phi) % e != 0) {
        k++;
    }

    d = (1 + k * phi) / e;

    // Print out public and private keys
    printf("Public Key: (%ld, %ld)\n", n, e);
    printf("Private Key: (%ld, %ld)\n", n, d);
}

int main() {
    printf("Let's generate some Public and Private keys using the Public-Key Algorithm!\n");
    generate_keys();
    return 0;
}