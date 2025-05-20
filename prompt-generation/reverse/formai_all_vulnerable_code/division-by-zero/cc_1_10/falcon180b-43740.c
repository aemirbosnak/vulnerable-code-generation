//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PRIME 1000000
#define MAX_SIZE 200

int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int generate_prime(int n) {
    int prime = 0;
    while (!prime) {
        prime = rand() % MAX_PRIME + 2;
        if (is_prime(prime)) {
            break;
        }
    }
    return prime;
}

int generate_key(int prime) {
    int private_key = 0;
    while (!private_key) {
        private_key = rand() % (prime - 2) + 2;
        for (int i = 2; i <= prime - 3; i++) {
            if (private_key % i == 0) {
                private_key = 0;
                break;
            }
        }
    }
    return private_key;
}

int encrypt(int message, int private_key, int prime) {
    int encrypted_message = (message * private_key) % prime;
    return encrypted_message;
}

int decrypt(int encrypted_message, int private_key, int prime) {
    int message = (encrypted_message * private_key - 1) / prime;
    return message;
}

int main() {
    int prime = generate_prime(MAX_PRIME);
    int private_key = generate_key(prime);
    int message = 123;
    int encrypted_message = encrypt(message, private_key, prime);
    int decrypted_message = decrypt(encrypted_message, private_key, prime);

    printf("Prime: %d\n", prime);
    printf("Private key: %d\n", private_key);
    printf("Message: %d\n", message);
    printf("Encrypted message: %d\n", encrypted_message);
    printf("Decrypted message: %d\n", decrypted_message);

    return 0;
}