//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to hold RSA keys
typedef struct {
    long long n;    // Modulus
    long long e;    // Public exponent
    long long d;    // Private exponent
} RSAKey;

// Function prototypes
long long gcd(long long a, long long b);
long long modInverse(long long a, long long m);
long long power(long long base, long long exp, long long mod);
void generateKeys(RSAKey *key);
void encryptMessage(const char *message, RSAKey *key, long long *encryptedMessage);
void decryptMessage(long long *encryptedMessage, size_t length, RSAKey *key, char *decryptedMessage);

int main() {
    RSAKey key;
    generateKeys(&key);
    
    const char *message = "Hello, RSA!";
    size_t messageLength = strlen(message);
    long long *encryptedMessage = malloc(messageLength * sizeof(long long));
    
    encryptMessage(message, &key, encryptedMessage);
    
    printf("Encrypted Message:\n");
    for (size_t i = 0; i < messageLength; i++) {
        printf("%lld ", encryptedMessage[i]);
    }
    printf("\n");
    
    char *decryptedMessage = malloc(messageLength + 1);
    decryptMessage(encryptedMessage, messageLength, &key, decryptedMessage);
    
    printf("Decrypted Message: %s\n", decryptedMessage);
    
    free(encryptedMessage);
    free(decryptedMessage);
    
    return 0;
}

// Function to calculate gcd
long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Function to find modular inverse
long long modInverse(long long a, long long m) {
    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;
    
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

// Function to calculate (base^exp) % mod
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

// Function to generate RSA keys
void generateKeys(RSAKey *key) {
    // Choose two distinct prime numbers
    long long p = 61; // Example prime
    long long q = 53; // Example prime

    // Calculate n and phi
    key->n = p * q;
    long long phi = (p - 1) * (q - 1);
    
    // Choose e such that 1 < e < phi and e is coprime to phi
    key->e = 17; // Example e

    // Calculate d, the mod inverse of e
    key->d = modInverse(key->e, phi);
}

// Encrypt message using RSA
void encryptMessage(const char *message, RSAKey *key, long long *encryptedMessage) {
    size_t length = strlen(message);
    for (size_t i = 0; i < length; i++) {
        encryptedMessage[i] = power(message[i], key->e, key->n);
    }
}

// Decrypt message using RSA
void decryptMessage(long long *encryptedMessage, size_t length, RSAKey *key, char *decryptedMessage) {
    for (size_t i = 0; i < length; i++) {
        decryptedMessage[i] = (char)power(encryptedMessage[i], key->d, key->n);
    }
    decryptedMessage[length] = '\0'; // Null terminate the string
}