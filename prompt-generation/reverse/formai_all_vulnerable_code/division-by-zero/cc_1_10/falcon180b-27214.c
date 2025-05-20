//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000

// Function to calculate gcd of two numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to calculate modular inverse of a number
int modinv(int a, int p) {
    int x, y, temp;
    int g = gcd(a, p);
    if (g == 1)
        return 1;
    if (g == p)
        return -1;
    x = (a / g) % p;
    y = (p - 1) / g;
    temp = 1;
    while (y!= 0) {
        temp = (temp * temp) % p;
        y--;
    }
    return (temp * x) % p;
}

// Function to generate prime numbers
int isPrime(int n) {
    int i;
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

// Function to generate public and private keys
void generateKeys() {
    int p, q, n, phi, e, d;
    int i;
    char *message;
    FILE *fp;

    // Generate two prime numbers
    p = rand() % MAX_SIZE + 1;
    while (!isPrime(p))
        p = rand() % MAX_SIZE + 1;
    q = rand() % MAX_SIZE + 1;
    while (!isPrime(q))
        q = rand() % MAX_SIZE + 1;

    // Calculate n and phi
    n = p * q;
    phi = (p - 1) * (q - 1);

    // Choose a random number e as the public key
    e = rand() % phi + 1;

    // Calculate modular inverse of e
    d = modinv(e, phi);

    // Print public and private keys
    printf("Public key: (%d, %d)\n", e, n);
    printf("Private key: (%d, %d)\n", d, n);

    // Encrypt message
    message = "Hello, world! ";
    fp = fopen("message.txt", "wb");
    fwrite(message, strlen(message), 1, fp);
    fclose(fp);

    // Encrypt message using public key
    fp = fopen("message.txt", "rb");
    while ((i = fgetc(fp))!= EOF) {
        i = (i * e) % n;
        fputc(i, fp);
    }
    fclose(fp);
    remove("message.txt");
    rename("message.enc", "message.txt");

    // Decrypt message using private key
    fp = fopen("message.txt", "rb");
    while ((i = fgetc(fp))!= EOF) {
        i = (i * d) % n;
        printf("%c", i);
    }
    fclose(fp);
}

int main() {
    generateKeys();
    return 0;
}