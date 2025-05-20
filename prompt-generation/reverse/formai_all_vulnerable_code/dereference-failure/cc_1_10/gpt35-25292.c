//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdbool.h>

// Define a struct for a public key
typedef struct {
    int e;
    int n;
} PublicKey;

// Define a function to generate a public key using two prime numbers
PublicKey generatePublicKey(int p, int q) {
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e = 2;

    // Find a value for e that is relatively prime to phi
    while (e < phi) {
        bool isRelativelyPrime = true;
        for (int i = 2; i < e; i++) {
            if ((e % i == 0) && (phi % i == 0)) {
                isRelativelyPrime = false;
                break;
            }
        }
        if (isRelativelyPrime) {
            break;
        } else {
            e++;
        }
    }

    PublicKey publicKey = {e, n};
    return publicKey;
}

// Define a function to encrypt a message using a public key
int* encryptMessage(char* message, int messageLength, PublicKey publicKey) {
    int* encryptedMessage = malloc(sizeof(int) * messageLength);

    for (int i = 0; i < messageLength; i++) {
        encryptedMessage[i] = (message[i] ^ publicKey.e) % publicKey.n;
    }

    return encryptedMessage;
}

int main() {
    int p = 61;
    int q = 53;
    char* message = "Hello, world!";
    int messageLength = strlen(message);

    PublicKey publicKey = generatePublicKey(p, q);
    int* encryptedMessage = encryptMessage(message, messageLength, publicKey);

    printf("Public key: e=%d, n=%d\n", publicKey.e, publicKey.n);
    printf("Message: %s\n", message);
    printf("Encrypted message: ");
    for (int i = 0; i < messageLength; i++) {
        printf("%d ", encryptedMessage[i]);
    }

    free(encryptedMessage);

    return 0;
}