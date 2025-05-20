//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1024

typedef struct {
    int n;
    int e;
    int d;
    int p;
    int q;
    int phi;
} RSA;

void generate_keys(RSA *rsa) {
    int p = 0, q = 0, phi = 0;
    int e = 65537;
    do {
        p = rand() % MAX_SIZE;
        q = rand() % MAX_SIZE;
        phi = (p - 1) * (q - 1);
    } while (phi % e!= 0);

    rsa->n = p * q;
    rsa->e = e;
    rsa->d = (1 + phi / e) * e;
    rsa->p = p;
    rsa->q = q;
    rsa->phi = phi;
}

int gcd(int a, int b) {
    return b? gcd(b, a % b) : a;
}

int power(int a, int b) {
    int r = 1;
    while (b) {
        if (b & 1)
            r = (r * a) % MAX_SIZE;
        a = (a * a) % MAX_SIZE;
        b >>= 1;
    }
    return r;
}

void encrypt(RSA *rsa, int message, int *cipher) {
    *cipher = power(message, rsa->e) % rsa->n;
}

int decrypt(RSA *rsa, int cipher) {
    return power(cipher, rsa->d) % rsa->n;
}

int main() {
    RSA rsa;
    generate_keys(&rsa);

    int message = 42;
    int cipher = 0;

    printf("Encrypting message...\n");
    encrypt(&rsa, message, &cipher);
    printf("Cipher: %d\n", cipher);

    printf("Decrypting cipher...\n");
    int decrypted = decrypt(&rsa, cipher);
    printf("Decrypted message: %d\n", decrypted);

    return 0;
}