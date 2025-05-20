//Falcon2-11B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate a random prime number
int generatePrime(int n) {
    int prime = 2;
    while (n > 2) {
        if (prime == 2) {
            prime = 3;
        } else if (n % prime == 0) {
            prime = prime + 2;
        } else {
            prime = prime + 1;
        }
        n--;
    }
    return prime;
}

// Function to generate a random private key
int generatePrivateKey(int n) {
    int privateKey = 0;
    for (int i = 0; i < n; i++) {
        privateKey = (privateKey + 1) * (rand() / RAND_MAX);
    }
    return privateKey;
}

// Function to generate a random public key
int generatePublicKey(int privateKey, int prime) {
    int publicKey = privateKey * (rand() / RAND_MAX) % prime;
    return publicKey;
}

// Function to encrypt a message using the public key
char* encryptMessage(char* message, int publicKey, int prime) {
    char encryptedMessage[strlen(message) + 1];
    int len = strlen(message);
    for (int i = 0; i < len; i++) {
        encryptedMessage[i] = message[i] + publicKey;
        if (encryptedMessage[i] > 'z') {
            encryptedMessage[i] = encryptedMessage[i] - 'z' + 'a';
        }
    }
    encryptedMessage[len] = '\0';
    return encryptedMessage;
}

// Function to decrypt a message using the private key
char* decryptMessage(char* encryptedMessage, int privateKey, int prime) {
    char decryptedMessage[strlen(encryptedMessage) + 1];
    int len = strlen(encryptedMessage);
    for (int i = 0; i < len; i++) {
        decryptedMessage[i] = encryptedMessage[i] - privateKey;
        if (decryptedMessage[i] < 'a') {
            decryptedMessage[i] = decryptedMessage[i] + 'z' - 'a';
        }
    }
    decryptedMessage[len] = '\0';
    return decryptedMessage;
}

// Main function
int main() {
    int n = 10; // Number of bits for the private key
    int prime = generatePrime(n); // Generate a random prime number
    int privateKey = generatePrivateKey(n); // Generate a random private key
    int publicKey = generatePublicKey(privateKey, prime); // Generate a random public key
    char* message = "Hello, World!"; // Message to be encrypted
    char encryptedMessage[strlen(message) + 1];
    char decryptedMessage[strlen(message) + 1];
    strcpy(encryptedMessage, encryptMessage(message, publicKey, prime)); // Encrypt the message
    strcpy(decryptedMessage, decryptMessage(encryptedMessage, privateKey, prime)); // Decrypt the message
    printf("Encrypted message: %s\n", encryptedMessage);
    printf("Decrypted message: %s\n", decryptedMessage);
    return 0;
}