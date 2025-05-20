//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to get GCD of two numbers
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Function to find modular inverse
int mod_inverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1; // return -1 if no modular inverse exists
}

// Function to perform modular exponentiation
long long power_mod(int base, int exp, int mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;  // equivalent to exp = exp / 2
        base = (base * base) % mod;
    }
    return result;
}

// Function to generate prime numbers using Sieve of Eratosthenes
void sieve_of_eratosthenes(int limit, int* primes, int* num_primes) {
    int* is_prime = (int*)malloc((limit + 1) * sizeof(int));
    for (int i = 0; i <= limit; i++)
        is_prime[i] = 1;
    
    is_prime[0] = is_prime[1] = 0; // 0 and 1 are not primes
    for (int p = 2; p * p <= limit; p++) {
        if (is_prime[p]) {
            for (int multiple = p * p; multiple <= limit; multiple += p) {
                is_prime[multiple] = 0;
            }
        }
    }

    *num_primes = 0;
    for (int p = 2; p <= limit; p++) {
        if (is_prime[p]) {
            primes[(*num_primes)++] = p;
        }
    }
    free(is_prime);
}

// Function to generate RSA keys
void generate_rsa_keys(int* e, int* d, int* n) {
    int p, q;
    int primes[100];
    int num_primes;

    sieve_of_eratosthenes(100, primes, &num_primes);

    // Select two distinct prime numbers p and q
    p = primes[rand() % num_primes];
    q = primes[rand() % num_primes];
    while (p == q) {
        q = primes[rand() % num_primes];
    }

    *n = p * q; // n = p * q
    int phi = (p - 1) * (q - 1); // phi(n) = (p-1)*(q-1)

    // Choose e such that 1 < e < phi and gcd(e, phi) = 1
    do {
        *e = 2 + rand() % (phi - 2);
    } while (gcd(*e, phi) != 1);

    // Calculate d, the modular inverse of e modulo phi
    *d = mod_inverse(*e, phi);
}

// Function to encrypt a message
long long encrypt(long long message, int e, int n) {
    return power_mod(message, e, n);
}

// Function to decrypt a message
long long decrypt(long long encrypted_message, int d, int n) {
    return power_mod(encrypted_message, d, n);
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    int e, d, n; // Public and private keys
    generate_rsa_keys(&e, &d, &n);

    printf("Public key (e, n): (%d, %d)\n", e, n);
    printf("Private key (d): %d\n", d);

    long long message;
    printf("Enter a message to encrypt (integer): ");
    scanf("%lld", &message);

    long long encrypted = encrypt(message, e, n);
    printf("Encrypted message: %lld\n", encrypted);

    long long decrypted = decrypt(encrypted, d, n);
    printf("Decrypted message: %lld\n", decrypted);

    return 0;
}