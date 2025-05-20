//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a prime number
int generatePrime() {
    int num = rand() % 100;
    int isPrime = 0;
    while(isPrime == 0) {
        if(num <= 1) {
            num = rand() % 100;
            continue;
        }
        isPrime = 1;
        for(int i = 2; i <= num / 2; i++) {
            if(num % i == 0) {
                isPrime = 0;
                num = rand() % 100;
                break;
            }
        }
    }
    return num;
}

// Function to calculate greatest common divisor
int gcd(int a, int b) {
    int temp;
    while(b > 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to generate the public and private keys
void generateKeys(int p, int q, int *n, int *e, int *d) {
    *n = p * q;
    int phi = (p - 1) * (q - 1);
    do {
        *e = rand() % (phi - 2) + 2;
    } while(gcd(*e, phi) != 1);
    int k = 1;
    while((k * phi + 1) % *e != 0) {
        k++;
    }
    *d = (k * phi + 1) / *e;
}

// Function to encrypt the message
int encrypt(int message, int e, int n) {
    int result = 1;
    for(int i = 0; i < e; i++) {
        result = (result * message) % n;
    }
    return result;
}

// Function to decrypt the message
int decrypt(int message, int d, int n) {
    int result = 1;
    for(int i = 0; i < d; i++) {
        result = (result * message) % n;
    }
    return result;
}

int main() {
    srand(time(NULL));
    int p = generatePrime();
    int q = generatePrime();
    int n, e, d;
    generateKeys(p, q, &n, &e, &d);
    printf("p: %d\nq: %d\nn: %d\ne: %d\nd: %d\n", p, q, n, e, d);
    int message = 9;
    int encrypted = encrypt(message, e, n);
    int decrypted = decrypt(encrypted, d, n);
    printf("Original message: %d\nEncrypted message: %d\nDecrypted message: %d\n", message, encrypted, decrypted);
    return 0;
}