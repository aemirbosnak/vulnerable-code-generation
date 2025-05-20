//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PRIME_LIMIT 10000
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct _keypair_t {
    unsigned int public_key;
    unsigned int private_key;
} keypair_t;

/** Generates a list of primes up to limit (inclusive) using sieve of Eratosthenes */
unsigned int* generate_prime_list(unsigned int limit, unsigned int *num_primes) {
    unsigned char *sieve = calloc(limit + 1, sizeof(unsigned char));
    unsigned int *primes = malloc(sizeof(unsigned int) * PRIME_LIMIT);
    unsigned int i, j, p;

    sieve[0] = 1;
    sieve[1] = 1;

    p = 0;
    for (i = 2; i <= limit && p < PRIME_LIMIT; i++) {
        if (!sieve[i]) {
            primes[p++] = i;

            for (j = i * 2; j <= limit; j += i)
                sieve[j] = 1;
        }
    }

    free(sieve);
    *num_primes = p;

    return primes;
}

/** Calculates the greatest common divisor of a and b using Euclid's algorithm */
unsigned int gcd(unsigned int a, unsigned int b) {
    unsigned int temp;

    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

/** Generates a random prime number between min and max (inclusive) */
unsigned int generate_random_prime(unsigned int min, unsigned int max) {
    unsigned int i, p;
    unsigned int num_primes;
    unsigned int *primes = generate_prime_list(max, &num_primes);

    do {
        i = rand() % num_primes;
        p = primes[i];
    } while (p < min);

    free(primes);
    return p;
}

/** Generates a keypair using the specified primes p and q */
keypair_t generate_keypair(unsigned int p, unsigned int q) {
    keypair_t pair = {0};
    unsigned int n = p * q;
    unsigned int phi = (p - 1) * (q - 1);
    unsigned int e = 0;
    unsigned int d = 0;

    /* Choose public key e such that e is relatively prime to phi */
    do {
        e = rand() % phi;
    } while (gcd(e, phi) != 1);

    /* Calculate private key d using extended Euclidean algorithm */
    {
        unsigned int x, y;
        unsigned int a = e, b = phi;

        if (b == 0) {
            d = 1;
            x = 0;
            y = 1;
        } else {
            unsigned int q, r;
            unsigned int x1 = 0, x2 = 1, y1 = 1, y2 = 0;

            while (b > 0) {
                q = a / b;
                r = a - q * b;
                x = x2 - q * x1;
                y = y2 - q * y1;
                a = b;
                b = r;
                x2 = x1;
                x1 = x;
                y2 = y1;
                y1 = y;
            }

            d = a;
            x = x2;
            y = y2;
        }

        if (y < 0)
            y += phi;

        pair.private_key = y;
    }

    pair.public_key = e;

    return pair;
}

/** Encrypts the specified message using the specified public key and n */
unsigned int* encrypt_message(const char *message, size_t message_len,
                              unsigned int public_key, unsigned int n,
                              size_t *encrypted_len) {
    unsigned int i;
    unsigned char *input = (unsigned char*) message;
    unsigned int *encrypted = malloc(sizeof(unsigned int) * message_len);
    *encrypted_len = 0;

    for (i = 0; i < message_len; i++) {
        encrypted[i] = (unsigned int) pow(input[i], public_key) % n;
        (*encrypted_len)++;
    }

    return encrypted;
}

/** Decrypts the specified message using the specified private key and n */
char* decrypt_message(const unsigned int *encrypted, size_t encrypted_len,
                      unsigned int private_key, unsigned int n) {
    unsigned int i;
    unsigned char *output = malloc(sizeof(unsigned char) * encrypted_len);
    size_t output_len = 0;

    for (i = 0; i < encrypted_len; i++) {
        output[i] = (unsigned char) pow(encrypted[i], private_key) % n;
        output_len++;
    }

    output[output_len] = '\0';

    return (char*) output;
}

int main() {
    unsigned int prime1, prime2;
    keypair_t pair;

    srand(time(NULL));

    /* Generate two random primes */
    prime1 = generate_random_prime(2, 100);
    prime2 = generate_random_prime(2, 100);

    printf("Generating keypair using primes %d and %d...\n", prime1, prime2);

    /* Generate keypair using primes */
    pair = generate_keypair(prime1, prime2);

    printf("Public key: %u\n", pair.public_key);
    printf("Private key: %u\n", pair.private_key);

    /* Encrypt a message */
    {
        const char *message = "Hello, world!";
        size_t message_len = strlen(message);
        unsigned int *encrypted;
        size_t encrypted_len;

        printf("\nEncrypting message \"%s\"...\n", message);

        encrypted = encrypt_message(message, message_len, pair.public_key, prime1 * prime2, &encrypted_len);

        printf("Encrypted message: ");
        for (int i = 0; i < encrypted_len; i++)
            printf("%u ", encrypted[i]);

        printf("\n");

        /* Decrypt the message */
        {
            char *decrypted;

            decrypted = decrypt_message(encrypted, encrypted_len, pair.private_key, prime1 * prime2);

            printf("Decrypted message: %s\n", decrypted);

            free(decrypted);
        }

        free(encrypted);
    }

    return 0;
}