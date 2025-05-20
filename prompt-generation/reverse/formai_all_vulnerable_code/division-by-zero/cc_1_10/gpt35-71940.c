//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the public key algorithm struct
typedef struct {
    int p;
    int q;
    int e;
    int d;
} PublicKeyAlgorithm;

// Generate a random prime number
int generatePrime() {
    int prime = rand() % 100;
    int is_prime = 0;
    while (!is_prime) {
        is_prime = 1;
        for (int i = 2; i <= prime / 2; i++) {
            if (prime % i == 0) {
                is_prime = 0;
                prime++;
                break;
            }
        }
    }
    return prime;
}

// Calculate the greatest common divisor using Euclid's Algorithm
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

// Generate the public and private keys
void generateKeys(PublicKeyAlgorithm *algorithm) {
    int p = generatePrime();
    int q = generatePrime();

    while (p == q) {
        q = generatePrime();
    }

    algorithm->p = p;
    algorithm->q = q;

    int n = p * q;
    int phi = (p - 1) * (q - 1);

    int e = rand() % (phi - 2) + 2;

    while (gcd(e, phi) != 1) {
        e = rand() % (phi - 2) + 2;
    }

    algorithm->e = e;

    int d = 1;

    while ((d * e) % phi != 1) {
        d++;
    }

    algorithm->d = d;
}

// Encrypt a message using the public key
void encrypt(int *message, int n, int e) {
    for (int i = 0; i < strlen(message); i++) {
        message[i] = (int) message[i];
        int result = 1;

        for (int j = 1; j <= e; j++) {
            result = (result * message[i]) % n;
        }

        message[i] = result;
    }
}

// Decrypt a message using the private key
void decrypt(int *message, int n, int d) {
    for (int i = 0; i < strlen(message); i++) {
        int result = 1;

        for (int j = 1; j <= d; j++) {
            result = (result * message[i]) % n;
        }

        message[i] = result;
        message[i] = (char) message[i];
    }
}

int main() {
    PublicKeyAlgorithm algorithm;
    generateKeys(&algorithm);

    int message[] = {72, 101, 108, 108, 111, 32, 87, 111, 114, 108, 100};

    printf("Original Message: %s\n", message);

    encrypt(message, algorithm.p * algorithm.q, algorithm.e);

    printf("Encrypted Message: %s\n", message);

    decrypt(message, algorithm.p * algorithm.q, algorithm.d);

    printf("Decrypted Message: %s\n", message);

    return 0;
}