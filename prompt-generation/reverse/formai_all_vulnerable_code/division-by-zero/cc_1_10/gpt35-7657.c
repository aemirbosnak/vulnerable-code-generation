//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/* Define the maximum prime number for generating keys */
#define PRIME_MAX 1000000

/* Function to generate a random prime number */
int generate_prime() {
    int n, i, flag;

    /* Generate a random number */
    n = rand() % PRIME_MAX;

    /* Check if the number is prime */
    while (1) {
        flag = 1;
        for (i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            return n;
        }
        n++;
    }
}

/* Function to calculate the greatest common divsor */
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    /* Initialize random seed */
    srand(time(0));

    /* Generate two prime numbers */
    int p = generate_prime();
    int q = generate_prime();

    /* Calculate n and phi(n) */
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    /* Choose a random value for e */
    int e;
    do {
        e = rand() % phi;
    } while (gcd(e, phi) != 1);

    /* Calculate d */
    int d = 1;
    while ((d * e) % phi != 1) {
        d++;
    }

    /* Print the public and private keys */
    printf("Public key: (%d, %d)\n", n, e);
    printf("Private key: (%d, %d)\n", n, d);

    return 0;
}