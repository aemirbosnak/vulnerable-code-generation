//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int get_random_prime() {
    /*
    This function generates a random prime number between 1 and 100.
    */
    int prime = rand() % 100 + 1;
    for(int i = 2; i < prime; i++) {
        if(prime % i == 0) {
            return get_random_prime();
        }
    }
    return prime;
}

int gcd(int a, int b) {
    /*
    This function calculates the greatest common divisor of a and b.
    */
    if(b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int get_public_key(int phi) {
    /*
    This function gets a public key e such that e is co-prime to phi.
    */
    int e = rand() % phi;
    while(gcd(e, phi) != 1) {
        e = rand() % phi;
    }
    return e;
}

int get_private_key(int e, int phi) {
    /*
    This function gets a private key d such that d is the multiplicative inverse of e mod phi.
    */
    int d = 0;
    while((d * e) % phi != 1) {
        d++;
    }
    return d;
}

int encrypt(int plaintext, int e, int n) {
    /*
    This function encrypts the plaintext using the public key (e, n).
    */
    int ciphertext = plaintext;
    for(int i = 1; i < e; i++) {
        ciphertext = (ciphertext * plaintext) % n;
    }
    return ciphertext;
}

int decrypt(int ciphertext, int d, int n) {
    /*
    This function decrypts the ciphertext using the private key (d, n).
    */
    int plaintext = ciphertext;
    for(int i = 1; i < d; i++) {
        plaintext = (plaintext * ciphertext) % n;
    }
    return plaintext;
}

int main() {
    srand(time(NULL));

    int p = get_random_prime();
    int q = get_random_prime();
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    int e = get_public_key(phi);
    int d = get_private_key(e, phi);

    int plaintext = 42;
    int ciphertext = encrypt(plaintext, e, n);
    int decrypted_plaintext = decrypt(ciphertext, d, n);

    printf("Public key: (%d, %d)\n", e, n);
    printf("Private key: (%d, %d)\n", d, n);
    printf("Plaintext: %d\n", plaintext);
    printf("Ciphertext: %d\n", ciphertext);
    printf("Decrypted plaintext: %d\n", decrypted_plaintext);

    return 0;
}