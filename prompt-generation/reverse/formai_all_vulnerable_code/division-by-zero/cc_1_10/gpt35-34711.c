//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

/* Define a type for large integers */
typedef uint64_t largeint;

/* Define a maximum value for large integers */
#define MAX_LARGEINT (largeint)~0

/* Define a structure for public and private keys */
typedef struct {
    largeint n;
    largeint e;
} pubkey_t;

typedef struct {
    largeint n;
    largeint d;
} privkey_t;

/* Define a function to generate a random prime number */
bool is_prime(largeint n);
largeint rand_prime(largeint min, largeint max);

/* Define a function to calculate GCD using Euclid's algorithm */
largeint gcd(largeint a, largeint b);

/* Define a function to calculate the modular inverse using Euclid's extended algorithm */
largeint mod_inverse(largeint a, largeint m);

/* Define a function to generate a public/private key pair */
bool generate_keys(pubkey_t *pubkey, privkey_t *privkey);

/* Define main function */
int main(void) {
    /* Seed random number generator */
    srand((unsigned int)time(NULL));
    
    /* Generate a public/private key pair */
    pubkey_t pubkey;
    privkey_t privkey;
    
    if (!generate_keys(&pubkey, &privkey)) {
        fprintf(stderr, "Error generating keys\n");
        return EXIT_FAILURE;
    }
    
    /* Print the public key */
    printf("Public key: (%llu, %llu)\n", pubkey.n, pubkey.e);
    
    /* Print the private key */
    printf("Private key: (%llu, %llu)\n", privkey.n, privkey.d);
    
    return EXIT_SUCCESS;
}

/* Function: is_prime
 * ------------------
 * Tests whether a number is prime.
 */
bool is_prime(largeint n) {
    if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (largeint i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

/* Function: rand_prime
 * --------------------
 * Generates a random prime number between min and max (inclusive).
 */
largeint rand_prime(largeint min, largeint max) {
    while (true) {
        largeint n = (rand() % (max - min + 1)) + min;
        if (is_prime(n)) {
            return n;
        }
    }
}

/* Function: gcd
 * -------------
 * Calculates the greatest common divisor of two numbers using Euclid's algorithm.
 */
largeint gcd(largeint a, largeint b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

/* Function: mod_inverse
 * ---------------------
 * Calculates the modular inverse of a number using Euclid's extended algorithm.
 */
largeint mod_inverse(largeint a, largeint m) {
    largeint m0 = m;
    largeint x = 1, y = 0;
    if (m == 1) {
        return 0;
    }
    while (a > 1 && m != 0) {
        largeint q = a / m;
        largeint t = m;
        m = a % m;
        a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (a != 1) {
        return 0;
    }
    if (x < 0) {
        x += m0;
    }
    return x;
}

/* Function: generate_keys
 * -----------------------
 * Generates a public/private key pair.
 */
bool generate_keys(pubkey_t *pubkey, privkey_t *privkey) {
    /* Choose two prime numbers */
    largeint p = rand_prime(1, sqrt(MAX_LARGEINT));
    largeint q = rand_prime(1, sqrt(MAX_LARGEINT));
    
    /* Calculate n (the modulus) */
    pubkey->n = p * q;
    
    /* Calculate phi(n) */
    largeint phi = (p - 1) * (q - 1);
    
    /* Choose an integer e (the public exponent) such that 1 < e < phi(n) and gcd(e, phi(n)) = 1 */
    pubkey->e = rand_prime(2, phi - 1);
    while (gcd(pubkey->e, phi) != 1) {
        pubkey->e = rand_prime(2, phi - 1);
    }
    
    /* Calculate d (the private exponent) such that d ≡ e^(-1) (mod phi(n)) */
    privkey->n = pubkey->n;
    privkey->d = mod_inverse(pubkey->e, phi);
    
    if (privkey->d == 0) {
        return false;
    }
    
    return true;
}