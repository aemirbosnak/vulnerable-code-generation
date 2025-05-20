//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function to find greatest common divisor of two integers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a%b);
}

// function to generate prime numbers
int* generatePrimes(int n, int* numPrimes) {
    int* primes = malloc(n * sizeof(int));
    int isPrime = 1;
    int count = 0;
    primes[count] = 2;
    count++;
    for (int i = 3; i <= n; i += 2) {
        for (int j = 0; j < count; j++) {
            if (i % primes[j] == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime == 1) {
            primes[count] = i;
            count++;
        }
        isPrime = 1;
    }
    *numPrimes = count;
    return primes;
}

// function to generate a random prime number
int generateRandomPrime(int* primes, int numPrimes) {
    int index = rand() % numPrimes;
    return primes[index];
}

// function to generate public/private key pair
void generateKeys(int n, int* e, int* d, int* phi) {
    int* primes;
    int numPrimes;
    int p = 0;
    int q = 0;
    int nTotient = 0;
    int publicKey = 0;
    int privateKey = 0;
    primes = generatePrimes(sqrt(n), &numPrimes);
    while (p == q) {
        p = generateRandomPrime(primes, numPrimes);
        q = generateRandomPrime(primes, numPrimes);
    }
    *phi = (p - 1) * (q - 1);
    nTotient = p * q;
    publicKey = 65537; // common value for e
    while (gcd(publicKey, *phi) != 1) {
        publicKey = generateRandomPrime(primes, numPrimes);
    }
    privateKey = (int)(fmod(pow(publicKey, -1), *phi));
    *e = publicKey;
    *d = privateKey;
}

// function to encrypt a message
int* encryptMessage(char* message, int length, int e, int n, int* numCiphers) {
    int* ciphers = malloc(length * sizeof(int));
    int exponent = 1;
    *numCiphers = length;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < e; j++) {
            exponent = (exponent * (int)message[i]) % n;
        }
        ciphers[i] = exponent;
        exponent = 1;
    }
    return ciphers;
}

// function to decrypt a message
char* decryptMessage(int* ciphers, int length, int d, int n) {
    char* decryptedMessage = malloc(length * sizeof(char));
    int exponent = 1;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < d; j++) {
            exponent = (exponent * ciphers[i]) % n;
        }
        decryptedMessage[i] = (char)exponent;
        exponent = 1;
    }
    return decryptedMessage;
}

int main() {
    int e = 0;
    int d = 0;
    int n = 238033;
    int phi = 0;
    generateKeys(n, &e, &d, &phi);
    
    char message[] = "Hello, World!";
    int length = sizeof(message) / sizeof(char);
    int numCiphers = 0;
    int* ciphers = encryptMessage(message, length, e, n, &numCiphers);
    char* decryptedMessage = decryptMessage(ciphers, numCiphers, d, n);
    
    printf("Message: %s\n", message);
    printf("Encrypted: ");
    for (int i = 0; i < numCiphers; i++) {
        printf("%d ", ciphers[i]);
    }
    printf("\n");
    printf("Decrypted: %s\n", decryptedMessage);
    
    return 0;
}