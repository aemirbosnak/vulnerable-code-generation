//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

// Function to generate a random prime number
int generatePrime() {
    int prime, flag;
    srand(clock());
    do {
        prime = rand() % 100;
        flag = 0;
        for (int i = 2; i <= prime/2; i++) {
            if (prime % i == 0) {
                flag = 1;
                break;
            }
        }
    } while (flag == 1);
    return prime;
}

// Function to generate random pubic and private keys
void generateKeys() {
    int p = generatePrime();
    int q = generatePrime();
    int n = p * q;
    int phi = (p-1) * (q-1);
    int e, d;

    // Finding a valid public key
    do {
        e = rand() % phi;
    } while (e == 1 || e == 0);
    // Finding the corresponding private key
    for (int i = 1; i <= phi; i++) {
        if ((i * e) % phi == 1) {
            d = i;
            break;
        }
    }

    // Printing keys
    printf("Public key: (%d, %d)\n", e, n);
    printf("Private key: (%d, %d)\n", d, n);
}

int main() {
    generateKeys();
    return 0;
}