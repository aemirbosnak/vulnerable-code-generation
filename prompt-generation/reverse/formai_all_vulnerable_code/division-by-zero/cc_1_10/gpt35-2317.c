//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate random prime number */
int get_prime_number() {
    int prime_number, is_prime_number;

    do {
        prime_number = rand() % 1000;
        is_prime_number = 1;

        for (int i = 2; i < prime_number; i++) {
            if (prime_number % i == 0) {
                is_prime_number = 0;
                break;
            }
        }
    } while (is_prime_number == 0);

    return prime_number;
}

/* Function to calculate GCD */
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

/* Function to calculate exponentiation */
int expmod(int base, int exponent, int modulus) {
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

/* Function to generate public and private keys */
void generate_keys(int *public_key, int *private_key, int p, int q) {
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e, d;

    do {
        e = rand() % phi;
    } while (gcd(e, phi) != 1);

    for (int i = 1; i < phi; i++) {
        if ((i * e) % phi == 1) {
            d = i;
            break;
        }
    }

    *public_key = e;
    *private_key = d;
}

/* Function to encrypt message */
int encrypt(int message, int public_key, int n) {
    return expmod(message, public_key, n);
}

/* Function to decrypt message */
int decrypt(int encrypted_message, int private_key, int n) {
    return expmod(encrypted_message, private_key, n);
}

int main() {
    printf("Welcome to the Public-Key Algorithm Example Program!\n");

    srand(time(NULL));
    int p = get_prime_number();
    int q = get_prime_number();
    int public_key, private_key;

    generate_keys(&public_key, &private_key, p, q);

    printf("p = %d, q = %d\n", p, q);
    printf("Public key: %d\n", public_key);
    printf("Private key: %d\n\n", private_key);

    int message = 123;
    printf("Original message: %d\n", message);

    int encrypted_message = encrypt(message, public_key, p * q);
    printf("Encrypted message: %d\n", encrypted_message);

    int decrypted_message = decrypt(encrypted_message, private_key, p * q);
    printf("Decrypted message: %d\n", decrypted_message);

    printf("\nThank you for using the Public-Key Algorithm Example Program!\n");

    return 0;
}