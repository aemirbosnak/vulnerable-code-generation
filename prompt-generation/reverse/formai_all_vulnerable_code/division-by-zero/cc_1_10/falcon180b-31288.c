//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define PRIME_NUMBER 31

typedef struct {
    int publicKey;
    int privateKey;
} KeyPair;

int generatePublicKey(int privateKey) {
    int publicKey = 1;
    int factor = 2;
    while (publicKey == 1) {
        if (privateKey % factor == 0) {
            publicKey = factor;
        }
        factor++;
    }
    return publicKey;
}

int generatePrivateKey(int publicKey) {
    int privateKey = 0;
    int factor = 2;
    while (privateKey == 0) {
        if (publicKey % factor == 0) {
            privateKey = factor;
        }
        factor++;
    }
    return privateKey;
}

int encrypt(int message, int publicKey) {
    int encryptedMessage = 0;
    int factor = 1;
    while (message > 0) {
        encryptedMessage += factor * (message % publicKey);
        message /= publicKey;
        factor++;
    }
    return encryptedMessage;
}

int decrypt(int encryptedMessage, int privateKey) {
    int decryptedMessage = 0;
    int factor = 1;
    while (encryptedMessage > 0) {
        decryptedMessage += factor * (encryptedMessage % privateKey);
        encryptedMessage /= privateKey;
        factor++;
    }
    return decryptedMessage;
}

void generateKeys(KeyPair* keyPair) {
    srand(time(NULL));
    int privateKey = rand() % MAX_SIZE;
    int publicKey = generatePublicKey(privateKey);
    keyPair->publicKey = publicKey;
    keyPair->privateKey = privateKey;
}

void encryptAndDecrypt(KeyPair* keyPair, char* message) {
    int encryptedMessage = encrypt(atoi(message), keyPair->publicKey);
    printf("Encrypted message: %d\n", encryptedMessage);
    int decryptedMessage = decrypt(encryptedMessage, keyPair->privateKey);
    printf("Decrypted message: %d\n", decryptedMessage);
}

int main() {
    KeyPair keyPair;
    generateKeys(&keyPair);
    printf("Public key: %d\n", keyPair.publicKey);
    printf("Private key: %d\n", keyPair.privateKey);
    char message[MAX_SIZE];
    printf("Enter a message: ");
    scanf("%s", message);
    encryptAndDecrypt(&keyPair, message);
    return 0;
}