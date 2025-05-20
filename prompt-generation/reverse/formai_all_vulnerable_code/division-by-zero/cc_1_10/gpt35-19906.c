//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>

// Function to generate random prime numbers
int generatePrime() {
    int num;
    srand(time(NULL));
    num = rand() % 1000;
    if (num == 2 || num == 3 || num == 5 || num == 7) {
        return num;
    } 
    if (num % 2 == 0 || num % 3 == 0 || num % 5 == 0 || num % 7 == 0) {
        generatePrime();
    }
    return num;
}

// Function to calculate modular exponentiation
int modpow(int base, int exponent, int modulus) {
    int result = 1;
    while (exponent > 0) {
        if (exponent & 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent >>= 1;
    }
    return result;
}

int main() {
    int p, q, n, totient_n, e, d, message, encrypted, decrypted;
    char msg[100];

    // Generating two random prime numbers
    p = generatePrime();
    q = generatePrime();

    // Calculating n and totient of n
    n = p * q;
    totient_n = (p - 1) * (q - 1);

    // Generating random number e which is relatively prime to totient_n
    srand(time(NULL));
    do {
        e = rand() % totient_n;
    } while (fmod(totient_n, e) == 0);

    // Calculating d, the modular multiplicative inverse of e
    int k = 1;
    while (1) {
        k += totient_n;
        if (fmod(k, e) == 0) {
            d = k / e;
            break;
        }
    }

    printf("Public Key: {%d,%d}\n", n, e);
    printf("Private Key: {%d,%d}\n", n, d);

    // Encrypting the message
    printf("Enter your message: ");
    scanf("%[^\n]s", msg);
    for (int i = 0; msg[i] != '\0'; i++) {
        message = (int) msg[i];
        encrypted = modpow(message, e, n);
        printf("%d ", encrypted);
    }
    printf("\n");

    // Decrypting the encrypted message
    for (int i = 0; msg[i] != '\0'; i++) {
        message = (int) msg[i];
        encrypted = modpow(message, e, n);
        decrypted = modpow(encrypted, d, n);
        printf("%c", decrypted);
    }
    printf("\n");

    return 0;
}