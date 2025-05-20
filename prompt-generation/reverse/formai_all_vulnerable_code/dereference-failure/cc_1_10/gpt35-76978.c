//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int public_key;
    int private_key;
} KeyPair;

int isPrime(int num) {
    if (num == 2 || num == 3) {
        return 1;
    }
    if (num < 2 || num % 2 == 0) {
        return 0;
    }
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int findE(int phi) {
    int e = 2;
    while (e < phi) {
        if (gcd(e, phi) == 1) {
            return e;
        } else {
            e++;
        }
    }
}

int findD(int e, int phi) {
    int d = 1;
    while ((d * e) % phi != 1) {
        d++;
    }
    return d;
}

KeyPair* generateKeys(int p, int q) {
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e = findE(phi);
    int d = findD(e, phi);

    KeyPair* keys = (KeyPair*)malloc(sizeof(KeyPair));
    keys->public_key = e;
    keys->private_key = d;

    return keys;
}

int encrypt(int plaintext, int public_key, int n) {
    int ciphertext = 1;
    for (int i = 0; i < public_key; i++) {
        ciphertext = (ciphertext * plaintext) % n;
    }
    return ciphertext;
}

int decrypt(int ciphertext, int private_key, int n) {
    int plaintext = 1;
    for (int i = 0; i < private_key; i++) {
        plaintext = (plaintext * ciphertext) % n;
    }
    return plaintext;
}

int main() {
    int p, q;
    printf("Enter two prime numbers: ");
    scanf("%d %d", &p, &q);

    if (!isPrime(p) || !isPrime(q)) {
        printf("Both numbers must be prime.\n");
        return 1;
    }

    KeyPair* keys = generateKeys(p, q);

    printf("Public key: %d\nPrivate key: %d\n", keys->public_key, keys->private_key);

    int plaintext;
    printf("Enter plaintext: ");
    scanf("%d", &plaintext);

    int ciphertext = encrypt(plaintext, keys->public_key, p * q);

    printf("Ciphertext: %d\n", ciphertext);

    int decrypted = decrypt(ciphertext, keys->private_key, p * q);

    printf("Decrypted: %d\n", decrypted);

    free(keys);

    return 0;
}