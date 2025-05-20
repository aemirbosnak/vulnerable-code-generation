//Falcon2-11B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random prime number
int generate_prime(int n) {
    int i, j, k;
    int prime = 0;
    int limit = (int)sqrt(n);

    for (i = 2; i <= limit; i++) {
        if (n % i == 0) {
            prime = 1;
            break;
        }
    }

    if (prime == 1) {
        return 0;
    }

    for (j = 2; j <= limit; j++) {
        if (n % j == 0) {
            prime = 0;
            break;
        }
    }

    return prime;
}

// Function to generate a random number
int generate_random_number(int n) {
    int i;
    int random_number = 0;
    for (i = 0; i < n; i++) {
        random_number = random_number * 100 + rand();
    }
    return random_number;
}

// Function to generate a public-private key pair
void generate_key_pair(int n, int *pub_key, int *priv_key) {
    int i;
    int prime = generate_prime(n);
    int pub_key_prime = generate_random_number(n);
    int priv_key_prime = generate_random_number(n);

    // Check if the primes are coprime
    if (gcd(pub_key_prime, prime) == 1 && gcd(priv_key_prime, prime) == 1) {
        *pub_key = pub_key_prime * prime;
        *priv_key = priv_key_prime * prime;
        printf("Public key: %d\n", *pub_key);
        printf("Private key: %d\n", *priv_key);
    } else {
        printf("Failed to generate a valid key pair\n");
    }
}

// Function to encrypt a message using the public key
void encrypt(int pub_key, char *message, int n) {
    int i, j;
    int ciphertext[n];

    for (i = 0; i < n; i++) {
        ciphertext[i] = message[i] * pub_key;
    }

    printf("Ciphertext: ");
    for (j = 0; j < n; j++) {
        printf("%d ", ciphertext[j]);
    }
    printf("\n");
}

// Function to decrypt a ciphertext using the private key
void decrypt(int priv_key, char *ciphertext, int n) {
    int i, j;
    int plaintext[n];

    for (i = 0; i < n; i++) {
        plaintext[i] = ciphertext[i] / priv_key;
    }

    printf("Plaintext: ");
    for (j = 0; j < n; j++) {
        printf("%d ", plaintext[j]);
    }
    printf("\n");
}

// Function to calculate the greatest common divisor
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

// Main function
int main() {
    int n = 10; // size of the message
    int pub_key = 0;
    int priv_key = 0;
    char message[] = "Hello World!";
    int len = strlen(message);

    generate_key_pair(n, &pub_key, &priv_key);
    encrypt(pub_key, message, len);
    decrypt(priv_key, message, len);

    return 0;
}