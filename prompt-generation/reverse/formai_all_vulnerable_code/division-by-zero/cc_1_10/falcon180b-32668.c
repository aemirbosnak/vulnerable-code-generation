//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int prime;
    int public_key;
    int private_key;
} KeyPair;

int isPrime(int n) {
    int count = 0;
    for (int i = 2; i <= n/2; i++) {
        if (n % i == 0) {
            count++;
        }
    }

    if (count == 0) {
        return 1;
    } else {
        return 0;
    }
}

void generateKeys(KeyPair* keyPair) {
    int prime = 0;
    int public_key = 0;
    int private_key = 0;

    while (!isPrime(prime)) {
        prime = rand() % MAX_SIZE + 1;
    }

    keyPair->prime = prime;
    keyPair->public_key = rand() % prime;
    while (public_key == 0 || public_key == 1) {
        public_key = rand() % prime;
    }
    keyPair->private_key = public_key - 1;
}

int encrypt(int message, KeyPair* keyPair) {
    int public_key = keyPair->public_key;
    int private_key = keyPair->private_key;

    int encrypted_message = (message * public_key) % keyPair->prime;

    return encrypted_message;
}

int decrypt(int encrypted_message, KeyPair* keyPair) {
    int public_key = keyPair->public_key;
    int private_key = keyPair->private_key;

    int decrypted_message = (encrypted_message * private_key) % keyPair->prime;

    return decrypted_message;
}

int main() {
    KeyPair keyPair;
    generateKeys(&keyPair);

    int message = 42;
    int encrypted_message = encrypt(message, &keyPair);
    int decrypted_message = decrypt(encrypted_message, &keyPair);

    printf("Message: %d\n", message);
    printf("Encrypted Message: %d\n", encrypted_message);
    printf("Decrypted Message: %d\n", decrypted_message);

    return 0;
}