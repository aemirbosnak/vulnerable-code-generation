//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    int *keys;
    int size;
} PublicKey;

PublicKey generate_keys() {
    PublicKey key;
    int *prime_factors = (int *) malloc(MAX_SIZE * sizeof(int));
    int num_factors = 0;
    int i, j, is_prime;

    srand(time(NULL));
    key.size = rand() % MAX_SIZE + 1;

    for (i = 2; num_factors < key.size; i++) {
        is_prime = 1;
        for (j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) {
            prime_factors[num_factors++] = i;
        }
    }

    key.keys = (int *) malloc(key.size * sizeof(int));
    for (i = 0; i < key.size; i++) {
        key.keys[i] = prime_factors[i];
    }

    free(prime_factors);
    return key;
}

int main() {
    PublicKey public_key = generate_keys();
    printf("Public key:\n");
    for (int i = 0; i < public_key.size; i++) {
        printf("%d ", public_key.keys[i]);
    }
    printf("\n");

    return 0;
}