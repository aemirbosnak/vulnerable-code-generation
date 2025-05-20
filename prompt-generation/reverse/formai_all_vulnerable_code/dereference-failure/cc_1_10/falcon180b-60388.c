//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct {
    int n;
    int e;
    int d;
} RSA;

RSA* generate_keys() {
    RSA* rsa = malloc(sizeof(RSA));
    rsa->n = 0;
    rsa->e = rand() % 100 + 1;
    while (gcd(rsa->e, 100)!= 1) {
        rsa->e = rand() % 100 + 1;
    }
    rsa->d = rand() % (100 - rsa->e) + 1;
    while (gcd(rsa->d, 100)!= 1) {
        rsa->d = rand() % (100 - rsa->e) + 1;
    }
    rsa->n = rsa->e * rsa->d;
    return rsa;
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void encrypt(char* message, RSA* rsa) {
    int m = strlen(message);
    int k = 0;
    char* encrypted = malloc(MAX_SIZE);
    for (int i = 0; i < m; i++) {
        encrypted[k++] = message[i] ^ rsa->e;
    }
    encrypted[k] = '\0';
    printf("Encrypted message: %s\n", encrypted);
}

void decrypt(char* message, RSA* rsa) {
    int m = strlen(message);
    int k = 0;
    char* decrypted = malloc(MAX_SIZE);
    for (int i = 0; i < m; i++) {
        decrypted[k++] = message[i] ^ rsa->d;
    }
    decrypted[k] = '\0';
    printf("Decrypted message: %s\n", decrypted);
}

int main() {
    RSA* rsa = generate_keys();
    char message[] = "Hello, world!";
    printf("Public key: %d, %d\n", rsa->e, rsa->n);
    encrypt(message, rsa);
    decrypt(message, rsa);
    free(rsa);
    return 0;
}