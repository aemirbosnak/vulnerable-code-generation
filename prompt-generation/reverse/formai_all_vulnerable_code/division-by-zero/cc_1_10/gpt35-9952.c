//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int p;
    int q;
    int e;
    int n;
    int totient;
    int d;
} RSAKeys;

int gcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int modularInverse(int a, int m) {
    int i, x, y, gcd, temp;
    x = 0; y = 1; gcd = m;
    for (i = 1; gcd != 1; i++) {
        temp = gcd;
        gcd = a % gcd;
        a = temp;
        temp = x;
        x = y - (a / temp) * x;
        y = temp;
    }
    if (y < 0)
        y += m;
    return y;
}

int isPrime(int n) {
    int i;
    if (n < 2)
        return 0;
    for (i = 2; i <= n/2; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int generatePrime() {
    int number = rand() % 1000;
    int i;
    while(1) {
        if (isPrime(number))
            return number;
        number++;
    }
}

RSAKeys generateKeys() {
    RSAKeys keys;
    keys.p = generatePrime();
    keys.q = generatePrime();
    keys.n = keys.p*keys.q;
    keys.totient = (keys.p-1)*(keys.q-1);
    keys.e = 2;
    while (gcd(keys.e, keys.totient) != 1) {
        keys.e++;
    }
    keys.d = modularInverse(keys.e, keys.totient);
    return keys;
}

int encrypt(int message, RSAKeys keys) {
    int cipher = 1;
    int i;
    for (i = 0; i < keys.e; i++) {
        cipher = (cipher * message) % keys.n;
    }
    return cipher;
}

int decrypt(int cipher, RSAKeys keys) {
    int message = 1;
    int i;
    for (i = 0; i < keys.d; i++) {
        message = (message * cipher) % keys.n;
    }
    return message;
}

int main() {
    RSAKeys keys = generateKeys();
    int message = 1234;
    int cipher = encrypt(message, keys);
    int decryptedMessage = decrypt(cipher, keys);
    printf("Original Message: %d\n", message);
    printf("Encrypted Message: %d\n", cipher);
    printf("Decrypted Message: %d\n", decryptedMessage);
    return 0;
}