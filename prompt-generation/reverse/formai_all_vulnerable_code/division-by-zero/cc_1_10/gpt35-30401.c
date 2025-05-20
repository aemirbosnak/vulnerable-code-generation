//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    // Declare variables
    int p, q, n, phiN, e, d, message, encryptedMsg, decryptedMsg;
    srand(time(NULL));

    // Generate prime numbers p and q
    do {
        p = rand() % 100;
    } while (!isPrime(p));
    do {
        q = rand() % 100;
    } while (!isPrime(q));

    // Calculate n and phi(n)
    n = p * q;
    phiN = (p - 1) * (q - 1);

    // Generate public key e
    do {
        e = rand() % phiN;
    } while (gcd(e, phiN) != 1);

    // Calculate private key d
    d = modInverse(e, phiN);

    printf("Public key (e, n): (%d, %d)\n", e, n);
    printf("Private key (d, n): (%d, %d)\n", d, n);

    // Ask user for message to encrypt
    printf("Enter message to encrypt: ");
    scanf("%d", &message);

    // Encrypt message
    encryptedMsg = modPow(message, e, n);
    printf("Encrypted message: %d\n", encryptedMsg);

    // Decrypt message
    decryptedMsg = modPow(encryptedMsg, d, n);
    printf("Decrypted message: %d\n", decryptedMsg);

    return 0;
}

/* Function to check if a number is prime */
int isPrime(int num)
{
    int i;
    for (i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

/* Function to calculate greatest common divisor (GCD) */
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

/* Function to calculate modular inverse */
int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

/* Function to calculate modular exponentiation */
int modPow(int b, int e, int m) {
    int result = 1;

    b = b % m;

    while (e > 0) {
        if (e & 1)
            result = (result * b) % m;
        e = e >> 1;
        b = (b * b) % m;
    }

    return result;
}