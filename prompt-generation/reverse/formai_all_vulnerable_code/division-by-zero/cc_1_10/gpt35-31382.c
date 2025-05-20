//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define BIT 1024
#define BLOCK 128

/* Calculates GCD of two numbers a and b */
int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

/* Calculates power of integer base raised to exponent mod modulo */
int power_mod(int base, int exponent, int modulo) {
    int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % modulo;
        base = (base * base) % modulo;
        exponent = exponent / 2;
    }
    return result;
}

/* Generates random prime number with bit length n */
int generate_prime(int n) {
    int i, num, prime = 0;
    while (prime == 0) {
        num = rand() % (int)pow(2, n - 1) + (int)pow(2, n - 2);
        for (i = 2; i < num / 2; i++) {
            if (num % i == 0) {
                break;
            }
        }
        if (i == num / 2)
            prime = num;
    }
    return prime;
}

/* Generates public/private key pair */
void generate_rsa_key(int *public_key, int *private_key) {
    int p, q, n, phi, e, d;
    p = generate_prime(BIT / 2);
    q = generate_prime(BIT / 2);
    n = p * q;
    phi = (p - 1) * (q - 1);
    e = rand() % (phi - 3) + 2;
    while (gcd(e, phi) != 1)
        e = rand() % (phi - 3) + 2;
    d = 0;
    while ((d * e) % phi != 1)
        d++;
    public_key[0] = e;
    public_key[1] = n;
    private_key[0] = d;
    private_key[1] = n;
}

/* Encrypts plaintext with public key */
void encrypt(int *public_key, char *plaintext, char *ciphertext) {
    int i, j = 0, n = public_key[1], e = public_key[0];
    int *blocks = (int*)calloc(BLOCK, sizeof(int));
    char *temp = (char*)calloc(BLOCK, sizeof(char));
    for (i = 0; plaintext[i] != '\0'; i++) {
        blocks[j] = blocks[j] * 10 + plaintext[i];
        if (i % 3 == 2) j++;
    }
    for (i = 0; i <= j; i++)
        temp[i] = (char)power_mod(blocks[i], e, n);
    sprintf(ciphertext, "%s", temp);
    free(blocks);
    free(temp);
}

/* Decrypts ciphertext with private key */
void decrypt(int *private_key, char *ciphertext, char *plaintext) {
    int i, j = 0, n = private_key[1], d = private_key[0];
    int *blocks = (int*)calloc(BLOCK, sizeof(int));
    char *temp = (char*)calloc(BLOCK, sizeof(char));
    for (i = 0; ciphertext[i] != '\0'; i++) {
        blocks[j] = blocks[j] * 10 + ciphertext[i];
        if (i % 3 == 2) j++;
    }
    for (i = 0; i <= j; i++)
        temp[i] = (char)power_mod(blocks[i], d, n);
    sprintf(plaintext, "%s", temp);
    free(blocks);
    free(temp);
}

int main() {
    srand(time(NULL));
    int public_key[2], private_key[2];
    generate_rsa_key(public_key, private_key);

    char plaintext[1024] = "Hello World!";
    char ciphertext[1024];
    char result[1024];
    encrypt(public_key, plaintext, ciphertext);
    decrypt(private_key, ciphertext, result);

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);
    printf("Result: %s\n", result);

    return 0;
}