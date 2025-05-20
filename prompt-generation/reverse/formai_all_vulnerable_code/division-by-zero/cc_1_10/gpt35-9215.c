//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50

int power(int a, int b, int mod)
{
    // This function computes a raised to the power of b mod mod.
    long long x = 1, y = a;
    while (b > 0)
    {
        if (b%2 == 1)
        {
            x = (x*y) % mod;
        }
        y = (y*y) % mod;
        b /= 2;
    }
    return (int) x % mod;
}

int isPrime(int n, int t)
{
    // This function checks if n is prime using the Miller-Rabin probabilistic primality test.
    if (n < 2)
    {
        return 0;
    }
    if (n != 2 && n%2 == 0)
    {
        return 0;
    }
    int d = n-1;
    while (d%2 == 0)
    {
        d /= 2;
    }
    for (int i = 0; i < t; i++)
    {
        int a = rand() % (n-1) + 1, temp = d;
        int x = power(a, temp, n);
        while (temp != n-1 && x != 1 && x != n-1)
        {
            x = (x*x) % n;
            temp *= 2;
        }
        if (x != n-1 && temp%2 == 0)
        {
            return 0;
        }
    }
    return 1;
}

int generatePrime()
{
    // This function generates a random prime number between 2^30 and 2^31.
    int p = rand() % (1<<31 - 1<<30) + 1<<30;
    while (!isPrime(p, 5))
    {
        p = rand() % (1<<31 - 1<<30) + 1<<30;
    }
    return p;
}

int gcd(int a, int b)
{
    // This function computes the greatest common divisor of a and b.
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a%b);
}

int modInverse(int a, int m)
{
    // This function computes the modular multiplicative inverse of a mod m using the extended Euclidean algorithm.
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    if (m == 1)
    {
        return 0;
    }
    while (a > 1)
    {
        q = a/m;
        t = m;
        m = a%m, a = t;
        t = x0;
        x0 = x1 - q*x0;
        x1 = t;
    }
    if (x1 < 0)
    {
        x1 += m0;
    }
    return x1;
}

struct PublicKey
{
    int n;
    int e;
};

struct PrivateKey
{
    int n;
    int d;
};

struct KeyPair
{
    struct PublicKey publicKey;
    struct PrivateKey privateKey;
};

struct KeyPair generateKeyPair()
{
    // This function generates a public-private key pair for the RSA cryptosystem.
    srand(time(NULL));
    struct KeyPair keyPair;

    int p = generatePrime();
    int q = generatePrime();
    int n = p*q;
    int phi = (p-1)*(q-1);
    int e = rand() % (phi-2) + 2;
    while (gcd(e, phi) != 1)
    {
        e = rand() % (phi-2) + 2;
    }
    int d = modInverse(e, phi);

    keyPair.publicKey.n = n;
    keyPair.publicKey.e = e;
    keyPair.privateKey.n = n;
    keyPair.privateKey.d = d;

    return keyPair;
}

int encrypt(int m, struct PublicKey publicKey)
{
    // This function encrypts the message m using the public key.
    return power(m, publicKey.e, publicKey.n);
}

int decrypt(int c, struct PrivateKey privateKey)
{
    // This function decrypts the ciphertext c using the private key.
    return power(c, privateKey.d, privateKey.n);
}

int main()
{
    printf("Generating key pair...\n");
    struct KeyPair keyPair = generateKeyPair();
    printf("Public key: n = %d, e = %d\n", keyPair.publicKey.n, keyPair.publicKey.e);
    printf("Private key: n = %d, d = %d\n", keyPair.privateKey.n, keyPair.privateKey.d);
    int m = 1234;
    printf("Original message: %d\n", m);
    int c = encrypt(m, keyPair.publicKey);
    printf("Ciphertext: %d\n", c);
    int a = decrypt(c, keyPair.privateKey);
    printf("Decrypted message: %d\n", a);
    return 0;
}