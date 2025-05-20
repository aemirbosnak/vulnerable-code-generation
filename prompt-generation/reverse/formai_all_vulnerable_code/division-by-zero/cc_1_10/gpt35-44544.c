//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Initialize random seed

    int p, q, n, phi, e, d, message, encrypted_message, decrypted_message;

    // Prompt user to input prime numbers p and q
    printf("Enter the value of p: ");
    scanf("%d", &p);
    printf("Enter the value of q: ");
    scanf("%d", &q);

    // Calculate n and phi
    n = p * q;
    phi = (p - 1) * (q - 1);

    // Generate a random integer e such that gcd(e, phi) = 1
    do {
        e = rand() % (phi - 2) + 2; // Picks a random number between 2 and phi-1
    } while (gcd(e, phi) != 1);
 
    // Calculate d such that d*e = 1 (mod phi)
    d = modular_inverse(e, phi);

    // Prompt user to input a message to encrypt
    printf("Enter the message you want to encrypt: ");
    scanf("%d", &message);

    // Encrypt message using public key (n, e)
    encrypted_message = modular_power(message, e, n);

    // Decrypt message using private key (n, d)
    decrypted_message = modular_power(encrypted_message, d, n);

    // Print out the encrypted and decrypted messages
    printf("The encrypted message is: %d\n", encrypted_message);
    printf("The decrypted message is: %d\n", decrypted_message);

    return 0;
}

// Function to calculate the greatest common denominator of two numbers a and b
int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

// Function to calculate the modular inverse of a number a (mod m)
int modular_inverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1) {
        return 0;
    }

    // Apply extended Euclidean algorithm
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    // Make sure x1 is positive
    if (x1 < 0) {
        x1 += m0;
    }

    return x1;
}

// Function to calculate the modular exponentiation of a number x raised to the power of y (mod m)
int modular_power(int x, int y, int m) {
    int result = 1;

    x = x % m;

    while (y > 0) {
        if (y & 1) {
            result = (result*x) % m;
        }

        y = y >> 1;
        x = (x*x) % m;
    }

    return result;
}