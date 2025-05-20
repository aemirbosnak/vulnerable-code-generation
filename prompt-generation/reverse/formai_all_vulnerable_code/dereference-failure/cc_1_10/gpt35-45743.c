//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to perform modular exponentiation */
long long int modular_pow(long long int base, long long int exponent, long long int modulus) {
    long long int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent = exponent / 2;
    }
    return result;
}

/* Function to perform encryption */
void encrypt(char* plaintext, char* key, char* ciphertext) {
    int n = strlen(plaintext);
    int k = strlen(key);
    int i;
    
    /* Check if key length is less than or equal to plaintext length */
    if (k <= n) {
        printf("Error: Key length should be greater than plaintext length");
        exit(1);
    }
    
    for (i = 0; i < n; i++) {
        int p = plaintext[i] - 'a';  /* Convert character to integer */
        int q = key[i] - 'a';
        int r = (p + q) % 26;  /* Perform encryption */
        ciphertext[i] = r + 'a';  /* Convert integer back to character */
    }
    ciphertext[i] = '\0';  /* Add null termination to ciphertext string */
}

/* Function to perform decryption */
void decrypt(char* ciphertext, char* key, char* plaintext) {
    int n = strlen(ciphertext);
    int k = strlen(key);
    int i;
    
    /* Check if key length is less than or equal to ciphertext length */
    if (k <= n) {
        printf("Error: Key length should be greater than ciphertext length");
        exit(1);
    }
    
    for (i = 0; i < n; i++) {
        int c = ciphertext[i] - 'a';  /* Convert character to integer */
        int q = key[i] - 'a';
        int r = (c - q + 26) % 26;  /* Perform decryption */
        plaintext[i] = r + 'a';  /* Convert integer back to character */
    }
    plaintext[i] = '\0';  /* Add null termination to plaintext string */
}

/* Main function */
int main() {
    char plaintext[] = "hello";
    char key[] = "secretkey";
    char ciphertext[strlen(plaintext)];
    char decryptedtext[strlen(ciphertext)];
    int n = strlen(plaintext);
    
    /* Generate a random number less than n */
    long long int a = rand() % n;
    
    /* Generate a random number prime number p */
    long long int p = 7;
    while (modular_pow(2, p-1, p) != 1) {
        p++;
    }
    
    /* Generate a random number prime number q */
    long long int q = 11;
    while (modular_pow(2, q-1, q) != 1 || q == p) {
        q++;
    }
    
    /* Calculate public key and private key */
    long long int N = p * q;
    long long int phi = (p-1) * (q-1);
    long long int e = phi - 1;
    while (e % phi != 1) {
        e += phi;
    }
    long long int d = modular_pow(e, -1, phi);
    
    /* Print public key and private key */
    printf("Public Key: (%lld, %lld)\n", e, N);
    printf("Private Key: (%lld, %lld)\n", d, N);
    
    /* Convert key to numeric value */
    long long int key_num = 0;
    int i;
    for (i = 0; i < strlen(key); i++) {
        key_num = key_num * 26 + (key[i] - 'a');
    }
    
    /* Encrypt plaintext */
    encrypt(plaintext, key, ciphertext);
    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);
    
    /* Decrypt ciphertext */
    decrypt(ciphertext, key, decryptedtext);
    printf("Decrypted text: %s\n", decryptedtext);
    
    return 0;
}