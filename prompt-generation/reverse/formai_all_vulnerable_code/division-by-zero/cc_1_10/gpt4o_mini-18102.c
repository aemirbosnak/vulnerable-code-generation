//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PRIME_COUNT 5
#define MAX_PRIME_LEN 10

// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i*i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

// Function to generate a prime number
int generate_prime() {
    int num;
    do {
        num = rand() % 100 + 1; // generate number between 1 and 100
    } while (!is_prime(num));
    return num;
}

// Function to compute modular inverse
int mod_inverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    
    if (m == 1) return 0;

    while (a > 1) {
        q = a / m;
        t = m;
        
        m = a % m, a = t;
        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0) x1 += m0;

    return x1;
}

// Structure for RSA key pair
typedef struct {
    int e; // Public exponent
    int d; // Private exponent
    int n; // Modulus
} RSAKeyPair;

// Function to generate RSA key pair
RSAKeyPair generate_keypair() {
    RSAKeyPair keys;
    int p = generate_prime();
    int q = generate_prime();
    
    keys.n = p * q; // n = p * q
    int phi = (p - 1) * (q - 1);

    // Choosing e
    keys.e = 3; // Small prime for the public exponent

    // Compute d, the mod inverse of e
    keys.d = mod_inverse(keys.e, phi);

    return keys;
}

// Function to encrypt a message
int encrypt(int message, RSAKeyPair pubkey) {
    int encrypted = 1;
    for (int i = 0; i < pubkey.e; i++) {
        encrypted = (encrypted * message) % pubkey.n;
    }
    return encrypted;
}

// Function to decrypt a message
int decrypt(int encrypted_message, RSAKeyPair privkey) {
    int decrypted = 1;
    for (int i = 0; i < privkey.d; i++) {
        decrypted = (decrypted * encrypted_message) % privkey.n;
    }
    return decrypted;
}

int main() {
    srand(time(0)); // Seed for random number generation

    // Generate RSA keys
    RSAKeyPair keys = generate_keypair();
    
    printf("Public Key (e: %d, n: %d)\n", keys.e, keys.n);
    printf("Private Key (d: %d)\n", keys.d);

    // Sample message to encrypt
    int message = 42;
    printf("Original Message: %d\n", message);

    // Encrypt the message
    int encrypted_message = encrypt(message, keys);
    printf("Encrypted Message: %d\n", encrypted_message);

    // Decrypt the message
    int decrypted_message = decrypt(encrypted_message, keys);
    printf("Decrypted Message: %d\n", decrypted_message);

    return 0;
}