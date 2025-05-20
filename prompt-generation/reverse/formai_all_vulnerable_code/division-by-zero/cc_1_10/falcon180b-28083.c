//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1024

typedef struct {
    int *e;
    int *n;
} PublicKey;

typedef struct {
    int *d;
    int *n;
} PrivateKey;

PublicKey* generatePublicKey(int p, int q) {
    int phi = (p - 1) * (q - 1);
    int e = 2;
    while (gcd(e, phi)!= 1) {
        e++;
    }
    PublicKey* key = malloc(sizeof(PublicKey));
    key->e = malloc(sizeof(int));
    *key->e = e;
    key->n = malloc(sizeof(int));
    *key->n = p * q;
    return key;
}

PrivateKey* generatePrivateKey(PublicKey* publicKey, int p, int q) {
    int phi = (p - 1) * (q - 1);
    int d = 0;
    while (gcd(d, phi)!= 1) {
        d++;
    }
    PrivateKey* key = malloc(sizeof(PrivateKey));
    key->d = malloc(sizeof(int));
    *key->d = d;
    key->n = malloc(sizeof(int));
    *key->n = publicKey->n;
    return key;
}

int encrypt(int m, PublicKey* publicKey) {
    return powmod(m, publicKey->e, publicKey->n);
}

int decrypt(int c, PrivateKey* privateKey) {
    return powmod(c, privateKey->d, privateKey->n);
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int powmod(int a, int b, int c) {
    int result = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % c;
        }
        a = (a * a) % c;
        b /= 2;
    }
    return result;
}

int main() {
    int p = 31;
    int q = 43;
    PublicKey* publicKey = generatePublicKey(p, q);
    PrivateKey* privateKey = generatePrivateKey(publicKey, p, q);
    int m = 123;
    int c = encrypt(m, publicKey);
    int m2 = decrypt(c, privateKey);
    printf("Original message: %d\n", m);
    printf("Encrypted message: %d\n", c);
    printf("Decrypted message: %d\n", m2);
    return 0;
}