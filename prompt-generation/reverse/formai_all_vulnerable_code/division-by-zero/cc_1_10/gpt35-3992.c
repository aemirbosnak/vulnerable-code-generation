//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to generate prime number
int is_prime(int a) {
    int i;
    for (i = 2; i<sqrt(a); i++) {
        if (a%i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to generate random prime number
int generate_prime() {
    int prime;
    do {
        prime = rand() % 100;
    } while (!is_prime(prime));
    return prime;
}

// Function to calculate GCD of two numbers
int gcd(int a, int b) {
    int r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// Function to generate a random number less than n that is co-prime with n
int generate_coprime(int n) {
    int coprime;
    do {
        coprime = rand() % n;
    } while (gcd(coprime, n) != 1);
    return coprime;
}

// Function to perform modulo exponential operation
int perform_modular_exponential(int a, int b, int n) {
    int c = 1;
    while (b > 0) {
        if (b & 1) {
            c = (c * a) % n;
        }
        a = (a * a) % n;
        b >>= 1;
    }
    return c % n;
}

// The main function
int main() {
    int p, q, n, phi, e, d, m, c, decrypted;
    // Generating random prime numbers
    srand(time(0));
    do {
        p = generate_prime();
        q = generate_prime();
    } while (p == q);
    // Calculating n and phi
    n = p * q;
    phi = (p - 1) * (q - 1);
    // Generating a random co-prime number less than phi
    e = generate_coprime(phi);
    // Calculating the modular inverse of e
    int i;
    for (i = 1; i < phi; i++) {
        if ((i * e) % phi == 1) {
            d = i;
            break;
        }
    }
    // Encryption process
    printf("Enter the message you want to encrypt: ");
    scanf("%d", &m);
    c = perform_modular_exponential(m, e, n);
    printf("The encrypted message is: %d\n", c);
    // Decryption process
    decrypted = perform_modular_exponential(c, d, n);
    printf("The decrypted message is: %d\n", decrypted);
    return 0;
}