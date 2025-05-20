//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main() {

    // Initialize variables
    int p, q, n, phi, e, d;
    bool isPrime;

    // Seed the randomizer with current time
    srand(time(NULL));

    // Generate a random prime number for p
    do {
        p = rand() % 1000 + 1;
        isPrime = true;
        for (int i = 2; i <= p / 2; i++) {
            if (p % i == 0) {
                isPrime = false;
                break;
            }
        }
    } while (!isPrime);

    // Generate a random prime number for q
    do {
        q = rand() % 1000 + 1;
        isPrime = true;
        for (int i = 2; i <= q / 2; i++) {
            if (q % i == 0) {
                isPrime = false;
                break;
            }
        }
    } while (!isPrime);

    // Calculate n
    n = p * q;

    // Calculate phi
    phi = (p - 1) * (q - 1);

    // Generate random number for e
    do {
        e = rand() % phi + 1;
    } while (gcd(e, phi) != 1);

    // Calculate d
    d = mod_inverse(e, phi);

    // Print out results
    printf("p = %d\nq = %d\nn = %d\nphi = %d\ne = %d\nd = %d\n", p, q, n, phi, e, d);

    return 0;
}

/*
 * Function to calculate greatest common divisor
 * Used for checking if a number is coprime with another
 */
int gcd(int a, int b) {

    while (a != 0 && b != 0) {
        if (a > b) {
            a %= b;
        } else {
            b %= a;
        }
    }

    if (a == 0) {
        return b;
    } else {
        return a;
    }
}

/*
 * Function to calculate modular inverse
 */
int mod_inverse(int a, int m) {

    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1) {
        return 0;
    }

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0) {
        x1 += m0;
    }

    return x1;
}