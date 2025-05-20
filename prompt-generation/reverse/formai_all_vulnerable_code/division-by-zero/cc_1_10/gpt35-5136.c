//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to check if a number is prime or not
int isPrime(int n) {
    int i;
    if (n <= 1) {
        return 0;
    }
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to generate a random prime number
int generatePrime() {
    int num;
    do {
        num = rand() % 100;
    } while (!isPrime(num));
    return num;
}

// Function to calculate gcd of two numbers
int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

// Function to generate a random number coprime to the given number
int generateCoprime(int n) {
    int num;
    do {
        num = rand() % (n - 2) + 2;
    } while (gcd(num, n) != 1);
    return num;
}

// Function to calculate modular exponentiation
int modExp(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}

// Function to encrypt a message
int* encrypt(int msg, int e, int n) {
    int *ciphertext = malloc(2 * sizeof(int));
    ciphertext[0] = modExp(msg, e, n);
    ciphertext[1] = e;
    return ciphertext;
}

// Function to decrypt a message
int decrypt(int *ciphertext, int d, int n) {
    int msg = modExp(ciphertext[0], d, n);
    return msg;
}

int main() {
    srand(time(NULL));
    // Generate two prime numbers and calculate their product
    int p = generatePrime();
    int q = generatePrime();
    int n = p * q;
    // Calculate Euler's totient function
    int phi_n = (p - 1) * (q - 1);
    // Generate a random number coprime to phi_n and calculate its inverse modulo phi_n
    int e = generateCoprime(phi_n);
    int d = 0;
    int k = 1;
    while (1) {
        d = (1 + k * phi_n) / e;
        if (gcd(e, phi_n) == 1 && (e * d) % phi_n == 1) {
            break;
        }
        k++;
    }
    // Print the public key and private key
    printf("Public key: {%d, %d}\n", e, n);
    printf("Private key: {%d, %d}\n", d, n);
    // Encrypt and decrypt a message
    int msg = 123;
    int *ciphertext = encrypt(msg, e, n);
    printf("Encrypted message: {%d, %d}\n", ciphertext[0], ciphertext[1]);
    int decrypted_msg = decrypt(ciphertext, d, n);
    printf("Decrypted message: %d\n", decrypted_msg);
    free(ciphertext);
    return 0;
}