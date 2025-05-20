//GEMINI-pro DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    unsigned int p;
    unsigned int q;
    unsigned int n;
    unsigned int phi;
    unsigned int e;
    unsigned int d;
} rsa_key;

unsigned int gcd(unsigned int a, unsigned int b) {
    unsigned int r;
    while (b > 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

unsigned int lcm(unsigned int a, unsigned int b) {
    return (a * b) / gcd(a, b);
}

unsigned int modpow(unsigned int base, unsigned int exponent, unsigned int modulus) {
    unsigned int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent /= 2;
    }
    return result;
}

rsa_key generate_rsa_key(unsigned int bitlength) {
    rsa_key key;

    // Generate two random prime numbers, p and q.
    key.p = (1 << bitlength) + rand() % (1 << (bitlength - 1));
    key.q = (1 << bitlength) + rand() % (1 << (bitlength - 1));

    // Compute the modulus, n = p * q.
    key.n = key.p * key.q;

    // Compute the Euler totient, phi = (p - 1) * (q - 1).
    key.phi = (key.p - 1) * (key.q - 1);

    // Find a public exponent, e, that is relatively prime to phi and less than phi.
    key.e = 65537;  // A common choice for e is 65537.

    // Compute the private exponent, d, such that d * e = 1 mod phi.
    key.d = modpow(key.e, -1, key.phi);

    return key;
}

unsigned int encrypt(unsigned int plaintext, rsa_key key) {
    // Compute the ciphertext, ciphertext = plaintext^e mod n.
    return modpow(plaintext, key.e, key.n);
}

unsigned int decrypt(unsigned int ciphertext, rsa_key key) {
    // Compute the plaintext, plaintext = ciphertext^d mod n.
    return modpow(ciphertext, key.d, key.n);
}

int main() {
    // Generate an RSA key with a 1024-bit modulus.
    rsa_key key = generate_rsa_key(1024);

    // Encrypt and decrypt a plaintext message.
    unsigned int plaintext = 12345;
    unsigned int ciphertext = encrypt(plaintext, key);
    unsigned int decryptedtext = decrypt(ciphertext, key);

    // Print the original plaintext, the ciphertext, and the decrypted plaintext.
    printf("Plaintext: %d\n", plaintext);
    printf("Ciphertext: %d\n", ciphertext);
    printf("Decrypted plaintext: %d\n", decryptedtext);

    return 0;
}