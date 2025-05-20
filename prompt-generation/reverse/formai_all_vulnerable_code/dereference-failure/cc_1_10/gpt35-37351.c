//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PublicKeyAlgorithm PublicKeyAlgorithm;

struct PublicKeyAlgorithm {
    unsigned long p;   // First prime number
    unsigned long q;   // Second prime number
    unsigned long n;   // Public key
    unsigned long e;   // Public key exponent
    unsigned long d;   // Private key exponent
};

// Euclid's Algorithm to find the greatest common divisor
unsigned long euclidAlgorithm(unsigned long a, unsigned long b) {
    unsigned long r, temp;
    if (a < b) {
        temp = a;
        a = b;
        b = temp;
    }
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// Extended Euclid's Algorithm to find the modular multiplicative inverse
unsigned long extendedEuclidAlgorithm(unsigned long a, unsigned long b, long *x, long *y) {
    if (a < b) {
        unsigned long temp1, temp2;
        temp1 = a;
        a = b;
        b = temp1;
        temp2 = *x;
        *x = *y;
        *y = temp2;
    }
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    else {
        unsigned long r, xx, yy;
        r = extendedEuclidAlgorithm(b, a % b, &xx, &yy);
        *x = yy;
        *y = xx - (a / b) * yy;
        return r;
    }
}

// Generate Public and Private Keys
PublicKeyAlgorithm generateKeys() {
    unsigned long p = 43, q = 59, n = p * q, phi = (p - 1) * (q - 1);
    unsigned long e = 0, d = 0;  
    int i;
    for (i = 2; i < phi; i++) {  // Generate e with coprime of phi(n)
        if (euclidAlgorithm(i, phi) == 1) {
            e = i;
            break;
        }
    }
    extendedEuclidAlgorithm(e, phi, &d, &i);  // Generate d as the modular multiplicative inverse of e mod phi(n) 
    PublicKeyAlgorithm keys = {p, q, n, e, d};
    return keys;
}

// Encrypt Function
unsigned long encrypt(unsigned long message, unsigned long exponent, unsigned long modulus) {
    unsigned long c = 1;
    for (int i = 0; i < exponent; i++) {
        c = (c * message) % modulus;
    }
    return c;
}

// Decrypt Function
unsigned long decrypt(unsigned long ciphertext, unsigned long exponent, unsigned long modulus) {
    unsigned long m = 1;
    for (int i = 0; i < exponent; i++) {
        m = (m * ciphertext) % modulus;
    }
    return m;
}

// Main Function
int main() {
    PublicKeyAlgorithm keys = generateKeys();
    unsigned long message = 12345;
    printf("Original Message: %lu\n", message);
    unsigned long ciphertext = encrypt(message, keys.e, keys.n);
    printf("Encrpyted Message: %lu\n", ciphertext);
    unsigned long plaintext = decrypt(ciphertext, keys.d, keys.n);
    printf("Decrypted Message: %lu\n", plaintext);
    return 0;
}