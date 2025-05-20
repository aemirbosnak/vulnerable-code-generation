//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to find gcd of two numbers
int gcd(int x, int y) {
    int remainder;
    while (y != 0) {
        remainder = x % y;
        x = y;
        y = remainder;
    }
    return x;
}

// Function to generate public and private key pairs
void generate_key_pair(int p, int q, int *n, int *e, int *d) {
    // Calculate n
    *n = p * q;

    // Calculate totient(n)
    int totient_n = (p - 1) * (q - 1);

    // Choose e such that 1 < e < totient_n and gcd(e, totient_n) = 1
    srand(time(NULL));
    do {
        *e = rand() % totient_n + 1;
    } while (gcd(*e, totient_n) != 1);

    // Calculate d such that d*e = 1 mod totient_n
    int k = 1;
    while (((k * totient_n) + 1) % *e != 0) {
        k++;
    }
    *d = ((k * totient_n) + 1) / *e;
}

// Function to encrypt plain text using RSA algorithm
void encrypt(int n, int e, char *plain_msg, int *cipher_msg) {
    int i, j;
    int length = strlen(plain_msg);

    for (i = 0; i < length; i++) {
        // Apply modular exponentiation to each character in the plain text message
        int c = 1;
        for (j = 0; j < e; j++) {
            c = (c * plain_msg[i]) % n;
        }
        cipher_msg[i] = c;
    }
}

// Function to decrypt cipher text using RSA algorithm
void decrypt(int n, int d, int *cipher_msg, char *decoded_msg) {
    int i, j;
    int length = strlen(decoded_msg);

    for (i = 0; i < length; i++) {
        // Apply modular exponentiation to each character in the cipher text message
        int m = 1;
        for (j = 0; j < d; j++) {
            m = (m * cipher_msg[i]) % n;
        }
        decoded_msg[i] = m;
    }
}

int main() {
    int p, q, n, e, d;
    int cipher_msg[100];
    char plain_msg[100], decoded_msg[100];

    printf("Enter two prime numbers (p and q):\n");
    scanf("%d %d", &p, &q);

    // Generate the public and private key pairs
    generate_key_pair(p, q, &n, &e, &d);

    printf("Public Key: (%d,%d)\n", n, e);
    printf("Private Key: (%d,%d)\n", n, d);

    printf("Enter the plain text message:\n");
    scanf("%s", plain_msg);

    // Encrypt the plain text message
    encrypt(n, e, plain_msg, cipher_msg);
    printf("Cipher Text Message: ");
    for (int i = 0; i < strlen(plain_msg); i++) {
        printf("%d ", cipher_msg[i]);
    }

    // Decrypt the cipher text message
    decrypt(n, d, cipher_msg, decoded_msg);
    decoded_msg[strlen(plain_msg)] = '\0';
    printf("\nDecoded Message: %s\n", decoded_msg);

    return 0;
}