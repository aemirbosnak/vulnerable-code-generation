//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PRIME_LENGTH 512

// Function to check if a number is prime
int isPrime(unsigned long n) {
    if (n <= 1)
        return 0;
    if (n <= 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    for (unsigned long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    }
    return 1;
}

// Function to generate prime numbers
unsigned long generatePrime(void) {
    unsigned long prime;
    do {
        prime = rand() % (1 << PRIME_LENGTH) + 1;
    } while (!isPrime(prime));
    return prime;
}

// Function to calculate gcd
unsigned long gcd(unsigned long a, unsigned long b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

// Function to calculate modular exponentiation
unsigned long modPow(unsigned long a, unsigned long b, unsigned long n) {
    unsigned long res = 1;
    a = a % n;
    while (b > 0) {
        if (b % 2 == 1)
            res = (res * a) % n;
        b = b >> 1;
        a = (a * a) % n;
    }
    return res;
}

// Function to check if a number is a primitive root modulo p
int isPrimitiveRoot(unsigned long a, unsigned long p) {
    if (gcd(a, p) != 1)
        return 0;
    unsigned long phi = p - 1;
    unsigned long factors[100];
    int count = 0;
    for (unsigned long i = 2; i * i <= phi; i++) {
        if (phi % i == 0) {
            factors[count++] = i;
            while (phi % i == 0)
                phi /= i;
        }
    }
    if (phi > 1)
        factors[count++] = phi;
    for (unsigned long i = 0; i < count; i++) {
        unsigned long exp = (p - 1) / factors[i];
        if (modPow(a, exp, p) == 1)
            return 0;
    }
    return 1;
}

// Function to generate a primitive root modulo p
unsigned long generatePrimitiveRoot(unsigned long p) {
    for (unsigned long i = 2; i < p; i++) {
        if (isPrimitiveRoot(i, p)) {
            return i;
        }
    }
}

// Function to generate public and private keys
void generateKeys(unsigned long* p, unsigned long* g, unsigned long* x, unsigned long* y) {
    *p = generatePrime();
    *g = generatePrimitiveRoot(*p);
    *x = rand() % (*p - 1) + 1;
    *y = modPow(*g, *x, *p);
}

// Function for public-key cryptography
unsigned long encrypt(unsigned long message, unsigned long y, unsigned long p, unsigned long g) {
    unsigned long k = rand() % (p - 1) + 1;
    unsigned long a = modPow(g, k, p);
    unsigned long b = message * modPow(y, k, p) % p;
    return a << 32 | b;
}

// Function for public-key cryptography
unsigned long decrypt(unsigned long ciphertext, unsigned long x, unsigned long p) {
    unsigned long a = ciphertext >> 32;
    unsigned long b = ciphertext & 0xFFFFFFFF;
    unsigned long a1 = modPow(a, p - 1 - x, p);
    unsigned long message = b * a1 % p;
    return message;
}

int main() {
    srand(time(NULL));
    unsigned long p, g, x, y;
    generateKeys(&p, &g, &x, &y);

    printf("p: %lu\n", p);
    printf("g: %lu\n", g);
    printf("x: %lu\n", x);
    printf("y: %lu\n", y);

    unsigned long message = 1234567890;
    printf("Original message: %lu\n", message);

    unsigned long ciphertext = encrypt(message, y, p, g);
    printf("Ciphertext: %lu\n", ciphertext);

    unsigned long decrypted = decrypt(ciphertext, x, p);
    printf("Decrypted message: %lu\n", decrypted);

    return 0;
}