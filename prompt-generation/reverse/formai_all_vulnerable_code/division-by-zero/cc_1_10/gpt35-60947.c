//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PRIME 100

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int modularInverse(int a, int m) {
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

int isPrime(int num) {
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int generatePrime() {
    int num;
    do {
        num = rand() % MAX_PRIME + 1;
    } while (!isPrime(num));
    return num;
}

void generateKeys(int *e, int *d, int *n) {
    int p = generatePrime();
    int q = generatePrime();
    *n = p * q;
    int phi = (p - 1) * (q - 1);
    do {
        *e = rand() % phi;
    } while (gcd(*e, phi) != 1);
    *d = modularInverse(*e, phi);
}

int powmod(int a, int b, int m) {
    int result = 1;
    while (b > 0) {
        if (b & 1) {
            result = (result * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return result;
}

void encrypt(int *cipherText, int message, int e, int n) {
    *cipherText = powmod(message, e, n);
}

void decrypt(int *message, int cipherText, int d, int n) {
    *message = powmod(cipherText, d, n);
}

int main() {
    int e, d, n;
    srand(time(NULL));
    generateKeys(&e, &d, &n);
    printf("Public Key (e,n): (%d,%d)\n", e, n);
    printf("Private Key (d,n): (%d,%d)\n", d, n);

    char plaintext[101];
    printf("Enter message to encrypt (max 100 characters): ");
    fgets(plaintext, 101, stdin);
    plaintext[strcspn(plaintext, "\n")] = 0;

    int len = strlen(plaintext);
    int cipherText[len];

    for (int i = 0; i < len; i++) {
        encrypt(&cipherText[i], plaintext[i], e, n);
    }

    printf("Encrypted Message: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", cipherText[i]);
    }
    printf("\n");

    printf("Decrypted Message: ");
    for (int i = 0; i < len; i++) {
        int ch;
        decrypt(&ch, cipherText[i], d, n);
        printf("%c", ch);
    }
    printf("\n");

    return 0;
}