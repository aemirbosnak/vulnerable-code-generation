//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
    int n; // modulus
    int e; // public exponent
    int d; // private exponent
} RSAKey;

// Function to compute gcd of two numbers
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Function to compute modular exponentiation
int mod_exp(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1; // exp = exp / 2
        base = (base * base) % mod;
    }
    return result;
}

// Function to generate a prime number using the Sieve of Eratosthenes
void generate_primes(int limit, int* primes, int* prime_count) {
    int* is_prime = (int*)malloc((limit + 1) * sizeof(int));
    
    for (int i = 0; i <= limit; i++) {
        is_prime[i] = 1;
    }

    is_prime[0] = is_prime[1] = 0; // 0 and 1 are not prime numbers

    for (int p = 2; p * p <= limit; p++) {
        if (is_prime[p]) {
            for (int multiple = p * p; multiple <= limit; multiple += p) {
                is_prime[multiple] = 0;
            }
        }
    }

    *prime_count = 0;
    for (int i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            primes[(*prime_count)++] = i;
        }
    }

    free(is_prime);
}

// Function to compute modular inverse using Extended Euclidean Algorithm
int mod_inverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1) return 0;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0) x1 += m0;

    return x1;
}

// Function to generate RSA keys
RSAKey generate_RSA_keys(int p, int q) {
    RSAKey key;
    key.n = p * q;
    int phi = (p - 1) * (q - 1);
    
    for (key.e = 2; key.e < phi; key.e++) {
        if (gcd(key.e, phi) == 1) break;
    }
    
    key.d = mod_inverse(key.e, phi);
    return key;
}

// Function to encrypt plaintext using public key
int encrypt(int plaintext, RSAKey pub_key) {
    return mod_exp(plaintext, pub_key.e, pub_key.n);
}

// Function to decrypt ciphertext using private key
int decrypt(int ciphertext, RSAKey priv_key) {
    return mod_exp(ciphertext, priv_key.d, priv_key.n);
}

// Main program
int main() {
    int primes[100], prime_count;
    generate_primes(100, primes, &prime_count);
    
    srand(time(0));
    int p = primes[rand() % prime_count];
    int q;
    
    // Ensure p and q are distinct
    do {
        q = primes[rand() % prime_count];
    } while (p == q);
    
    RSAKey keys = generate_RSA_keys(p, q);
    
    printf("Public Key: (n = %d, e = %d)\n", keys.n, keys.e);
    printf("Private Key: (n = %d, d = %d)\n", keys.n, keys.d);
    
    int plaintext;
    printf("Enter plaintext (integer): ");
    scanf("%d", &plaintext);
    
    int ciphertext = encrypt(plaintext, keys);
    printf("Ciphertext: %d\n", ciphertext);
    
    int decryptedtext = decrypt(ciphertext, keys);
    printf("Decrypted Text: %d\n", decryptedtext);
    
    return 0;
}