//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define PRIME1 65537 // First prime number for key generation
#define PRIME2 257 // Second prime number for key generation

// Greatest common denominator calculation using Euclid's algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Calculate the modular multiplicative inverse using the extended Euclidean algorithm
// Used for determining the private key
int mod_inverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        q = a / m;
        t = m;

        m = a % m;
        a = t;

        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

// Generate public and private keys
void generate_keys(int *public_key, int *private_key, int prime1, int prime2) {
    int phi = (prime1 - 1) * (prime2 - 1);
    int n = prime1 * prime2;
    int e = 3; // Public key exponent

    while (gcd(phi, e) > 1) { // Ensure e is relatively prime to phi
        e += 2;
    }

    int d = mod_inverse(e, phi); // Private key

    *public_key = n | (e << 16); // Store public key as upper 16 bits: exponent, lower 16 bits: modulus
    *private_key = d;
}

// Encrypt a message using the public key
int *encrypt(char *message, int length, int public_key) {
    int *encrypted = malloc(length * sizeof(int));
    int modulus = public_key & 0xFFFF;
    int exponent = public_key >> 16;

    for (int i = 0; i < length; i++) {
        encrypted[i] = 1;
        for (int j = 0; j < exponent; j++) {
            encrypted[i] *= message[i]; // Encrypt message, byte by byte
            encrypted[i] %= modulus;
        }
    }

    return encrypted;
}

// Decrypt a message using the private key
char *decrypt(int *encrypted, int length, int private_key) {
    char *decrypted = malloc(length * sizeof(char));
    int modulus = encrypted[0] & 0xFFFF;
    int exponent = private_key;

    for (int i = 0; i < length; i++) {
        decrypted[i] = 1;
        for (int j = 0; j < exponent; j++) {
            decrypted[i] *= encrypted[i]; // Decrypt message, byte by byte
            decrypted[i] %= modulus;
        }
    }

    return decrypted;
}

int main() {
    int public_key, private_key;
    generate_keys(&public_key, &private_key, PRIME1, PRIME2);

    // Example usage
    char message[] = "Hello, world!";
    int length = sizeof(message);
    int *encrypted = encrypt(message, length, public_key);
    char *decrypted = decrypt(encrypted, length, private_key);

    printf("Original message: %s\n", message);
    printf("Encrypted message: ");
    for (int i = 0; i < length; i++) {
        printf("%02X", encrypted[i]);
    }
    printf("\n");
    printf("Decrypted message: %s\n", decrypted);

    free(encrypted);
    free(decrypted);

    return 0;
}