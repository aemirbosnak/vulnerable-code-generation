//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

// Function to compute GCD of two numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to compute modular multiplicative inverse using Extended Euclidean Algorithm
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1; // Shouldn't reach here for valid inputs
}

// Function to generate prime numbers using the Sieve of Eratosthenes
void generatePrimes(int limit, int* primes, int* primeCount) {
    bool* isPrime = malloc((limit+1) * sizeof(bool));
    for (int i = 0; i <= limit; i++)
        isPrime[i] = true;
    for (int p = 2; p * p <= limit; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= limit; i += p)
                isPrime[i] = false;
        }
    }
    *primeCount = 0;
    for (int p = 2; p <= limit; p++) {
        if (isPrime[p]) {
            primes[(*primeCount)++] = p;
        }
    }
    free(isPrime);
}

// Function to generate public and private keys
void generateKeys(int* publicKey, int* privateKey) {
    int p, q, n, phi, e, d;
    int primes[100], primeCount;

    generatePrimes(100, primes, &primeCount);
    srand(time(NULL));
    p = primes[rand() % primeCount];
    q = primes[rand() % primeCount];
    while (p == q) {
        q = primes[rand() % primeCount];
    }

    n = p * q;
    phi = (p - 1) * (q - 1);

    // Choosing e value
    for (e = 2; e < phi; e++) {
        if (gcd(e, phi) == 1)
            break;
    }
    
    // Calculate d
    d = modInverse(e, phi);

    publicKey[0] = e;
    publicKey[1] = n;
    privateKey[0] = d;
    privateKey[1] = n;
}

// Encrypts the plaintext message using the public key
int encrypt(int message, int* publicKey) {
    int e = publicKey[0];
    int n = publicKey[1];
    int ciphertext = 1;
    for (int i = 0; i < e; i++) {
        ciphertext = (ciphertext * message) % n;
    }
    return ciphertext;
}

// Decrypts the ciphertext message using the private key
int decrypt(int ciphertext, int* privateKey) {
    int d = privateKey[0];
    int n = privateKey[1];
    int plaintext = 1;
    for (int i = 0; i < d; i++) {
        plaintext = (plaintext * ciphertext) % n;
    }
    return plaintext;
}

int main() {
    int publicKey[2], privateKey[2];
    generateKeys(publicKey, privateKey);
    
    printf("Public Key: (e = %d, n = %d)\n", publicKey[0], publicKey[1]);
    printf("Private Key: (d = %d, n = %d)\n", privateKey[0], privateKey[1]);
    
    int message;
    printf("Enter a message to encrypt (as an integer): ");
    scanf("%d", &message);
    
    int encrypted = encrypt(message, publicKey);
    printf("Encrypted Message: %d\n", encrypted);
    
    int decrypted = decrypt(encrypted, privateKey);
    printf("Decrypted Message: %d\n", decrypted);

    return 0;
}