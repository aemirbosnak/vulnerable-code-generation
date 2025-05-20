//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define P 61 // Prime number
#define G 11 // Primitive root of P

// Function to calculate modular exponentiation
int power(int x, int y, int p) {
    int res = 1;

    // Compute (x^y) % p in O(log y) time complexity
    while (y > 0) {
        if (y & 1) // If y is odd
            res = (res * x) % p;
        y >>= 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

// Function to generate a random private key
int generatePrivateKey() {
    return rand() % (P - 1) + 1; // 1 to P-1 inclusive
}

// Function to generate public key
int generatePublicKey(int privateKey) {
    return power(G, privateKey, P); // (G^privateKey) % P
}

// Function to generate shared secret key
int generateSharedSecretKey(int privateKey, int publicKey) {
    return power(publicKey, privateKey, P); // (publicKey^privateKey) % P
}

int main() {
    // Allocate memory for dynamic arrays
    int *privateKeys = (int *)malloc(sizeof(int) * 2);
    int *publicKeys = (int *)malloc(sizeof(int) * 2);
    int *sharedSecretKeys = (int *)malloc(sizeof(int) * 2);

    // Generate keys for two parties
    for (int i = 0; i < 2; i++) {
        privateKeys[i] = generatePrivateKey();
        publicKeys[i] = generatePublicKey(privateKeys[i]);
    }

    // Generate shared secret key for each party
    for (int i = 0; i < 2; i++) {
        sharedSecretKeys[i] = generateSharedSecretKey(privateKeys[(i+1)%2], publicKeys[i]);
    }

    // Print the keys
    printf("Private Key 1: %d\nPublic Key 1: %d\nPrivate Key 2: %d\nPublic Key 2: %d\nShared Secret Key 1: %d\nShared Secret Key 2: %d", 
           privateKeys[0], publicKeys[0], privateKeys[1], publicKeys[1], sharedSecretKeys[0], sharedSecretKeys[1]);

    // Deallocate memory
    free(privateKeys);
    free(publicKeys);
    free(sharedSecretKeys);

    return 0;
}