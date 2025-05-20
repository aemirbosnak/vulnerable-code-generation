//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Define a structure for the public and private keys
struct RSAKey {
    int n;
    int e;
    int d;
};

// Generate a random prime number
int generatePrime() {
    srand(time(NULL) ^ getpid());
    int p = rand() % 100 + 1;
    int i;
    for (i = 2; i<=p/2; i++) {
        if (p % i == 0) {
            p = generatePrime();
            break;
        }
    }
    return p;
}

// Find the gcd of two integers
int gcd(int a, int b) {
    if (a == 0) {
        return b;
    } else if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

// Find a number e such that e and phi(n) are relatively prime
int generateE(int phi) {
    int e = rand() % (phi - 2) + 2;
    while (gcd(e, phi) != 1) {
        e = rand() % (phi - 2) + 2;
    }
    return e;
}

// Find the modular inverse of e, or d
int modInverse(int e, int phi) {
    int d, temp;
    int x1 = 1, y1 = 0;
    int x2 = 0, y2 = 1;
    while (phi != 0) {
        int quotient = e / phi;
        temp = phi;
        phi = e % phi;
        e = temp;
        temp = x1;
        x1 = x2 - quotient * x1;
        x2 = temp;
        temp = y1;
        y1 = y2 - quotient * y1;
        y2 = temp;
    }
    d = x2;
    if (d < 0) {
        d += phi;
    }
    return d;
}

// Generate public and private keys
struct RSAKey generateKeys() {
    struct RSAKey keys;
    int p = generatePrime();
    int q = generatePrime();
    while (q == p) {
        q = generatePrime();
    }
    int n = p * q;
    int phi = (p-1) * (q-1);
    int e = generateE(phi);
    int d = modInverse(e, phi);
    keys.n = n;
    keys.e = e;
    keys.d = d;
    return keys;
}

// Encrypt a message
int encrypt(int m, int e, int n) {
    int c = 1, i;
    for (i = 0; i < e; i++) {
        c = (c * m) % n;
    }
    return c;
}

// Decrypt a message
int decrypt(int c, int d, int n) {
    int m = 1, i;
    for (i = 0; i < d; i++) {
        m = (m * c) % n;
    }
    return m;
}

int main() {
    struct RSAKey keys = generateKeys();
    int message, encrypted, decrypted;
    printf("Public Key: (%d, %d)\nPrivate Key: (%d)\n\nEnter a message to encrypt: ", keys.n, keys.e, keys.d);
    scanf("%d", &message);
    encrypted = encrypt(message, keys.e, keys.n);
    printf("Encrypted Message: %d\n", encrypted);
    decrypted = decrypt(encrypted, keys.d, keys.n);
    printf("Decrypted Message: %d\n", decrypted);
    return 0;
}