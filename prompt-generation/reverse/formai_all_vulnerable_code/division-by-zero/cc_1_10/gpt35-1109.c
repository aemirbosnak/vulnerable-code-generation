//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Generate random prime number between 1 and 100
int getPrime() {
    srand(time(0));
    int num = (rand() % 100) + 1;
    int i;
    for(i = 2; i <= num/2; i++) {
        if(num % i == 0) {
            num = getPrime();
        }
    }
    return num;
}

// Computes GCD of two numbers
int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

// Computes modular exponentiation
int modulo(int base, int exponent, int modulus) {
    int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent = exponent / 2;
    }
    return result;
}

// Generate public and private keys using random prime numbers
void generateKeys(int *publicKey, int *privateKey) {
    int p, q;
    // Generate two distinct prime numbers
    p = getPrime();
    do {
        q = getPrime();
    } while (q == p);

    // Calculate n
    int n = p * q;

    // Calculate totient
    int totient = (p-1) * (q-1);

    // Find public key e
    int e;
    do {
        e = rand() % totient;
    } while (gcd(e, totient) != 1);

    // Find private key d
    int d = 0;
    while ((d * e) % totient != 1) {
        d++;
    }

    // Set public key and private key
    *publicKey = e;
    *privateKey = d;
}

int main() {
    int publicKey, privateKey;
    generateKeys(&publicKey, &privateKey);

    printf("Public key: %d\n", publicKey);
    printf("Private key: %d\n\n", privateKey);

    int message;
    printf("Enter message to be encrypted: ");
    scanf("%d", &message);

    // Encrypt message
    int encrypted = modulo(message, publicKey, 187);

    // Decrypt message
    int decrypted = modulo(encrypted, privateKey, 187);

    printf("\nOriginal message: %d", message);
    printf("\nEncrypted message: %d", encrypted);
    printf("\nDecrypted message: %d", decrypted);

    return 0;
}