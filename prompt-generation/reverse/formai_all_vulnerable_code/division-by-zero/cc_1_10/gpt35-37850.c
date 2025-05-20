//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: medieval
/*
 * C Program to Implement RSA Algorithm
 * Created by [Your Name]
 * [Current Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function to find greatest common divisor of two numbers
long int gcd(long int a, long int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

// Function to generate random prime number
long int generatePrime(int n) {
    long int prime;
    int i, randNum;
    time_t t;

    srand((unsigned) time(&t));

    while (1) {
        // Generate random integer from 1 to (2^n)-1
        randNum = rand() % ((int)pow(2, n)-1) + 1;
        
        // Check if random integer is prime
        for (i = 2; i <= sqrt(randNum); i++) {
            if (randNum % i == 0) {
                break;
            }
        }
        if (i > sqrt(randNum)) {
            prime = randNum;
            break;
        }
    }

    return prime;
}

// Function to generate public and private keys
void generateKeyPair(long int p, long int q, long int *n, long int *e, long int *d) {
    long int phi, gcdValue;
    time_t t;

    srand((unsigned) time(&t));

    // Calculate totient of n
    phi = (p-1) * (q-1);

    // Generate random integer e
    while (1) {
        *e = rand() % phi;
        gcdValue = gcd(*e, phi);
        if (gcdValue == 1) {
            break;
        }
    }

    // Calculate modular inverse of e
    *d = 0;
    for (int i = 0; i < phi; i++) {
        if ((*e * i) % phi == 1) {
            *d = i;
            break;
        }
    }

    *n = p * q;
}

// Function to encrypt message using public key
long int encrypt(long int message, long int e, long int n) {
    long int i, encryptedMessage = 1;
    for (i = 0; i < e; i++) {
        encryptedMessage = (encryptedMessage * message) % n;
    }
    return encryptedMessage;
}

// Function to decrypt message using private key
long int decrypt(long int encryptedMessage, long int d, long int n) {
    long int i, decryptedMessage = 1;
    for (i = 0; i < d; i++) {
        decryptedMessage = (decryptedMessage * encryptedMessage) % n;
    }
    return decryptedMessage;
}

int main() {
    long int p, q, n, e, d, message, encryptedMessage, decryptedMessage;

    // Generate two random prime numbers of around 4 bits each
    p = generatePrime(4);
    q = generatePrime(4);

    // Generate public and private keys using prime numbers
    generateKeyPair(p, q, &n, &e, &d);

    // Read message from user
    printf("Enter a message: ");
    scanf("%ld", &message);

    // Encrypt message using public key
    encryptedMessage = encrypt(message, e, n);
    printf("Encrypted message: %ld\n", encryptedMessage);

    // Decrypt message using private key
    decryptedMessage = decrypt(encryptedMessage, d, n);
    printf("Decrypted message: %ld\n", decryptedMessage);

    return 0;
}