//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1024

// Function to generate a random prime number
int generate_prime(int size) {
    int num = rand() % size + 2;
    while (num % 2 == 0)
        num += 1;
    return num;
}

// Function to calculate the modular exponentiation
int mod_exp(int a, int b, int n) {
    int result = 1;
    while (b > 0) {
        if (b % 2 == 1)
            result = (result * a) % n;
        a = (a * a) % n;
        b /= 2;
    }
    return result;
}

// Function to generate the public and private keys
void generate_keys(int *public_key, int *private_key, int size) {
    *public_key = generate_prime(size);
    *private_key = generate_prime(size);
}

// Function to encrypt the message using the public key
void encrypt(int message, int public_key, int size) {
    int encrypted_message = mod_exp(message, public_key, size);
    printf("Encrypted message: %d\n", encrypted_message);
}

// Function to decrypt the message using the private key
void decrypt(int encrypted_message, int private_key, int size) {
    int decrypted_message = mod_exp(encrypted_message, private_key, size);
    printf("Decrypted message: %d\n", decrypted_message);
}

int main() {
    int size, public_key, private_key, message, choice;
    printf("Enter the size of the key: ");
    scanf("%d", &size);
    printf("Enter 1 for generating keys and encrypting message or 2 for decrypting message: ");
    scanf("%d", &choice);
    if (choice == 1) {
        generate_keys(&public_key, &private_key, size);
        printf("Public key: %d\nPrivate key: %d\n", public_key, private_key);
    }
    else {
        printf("Enter the encrypted message: ");
        scanf("%d", &message);
        decrypt(message, private_key, size);
    }
    return 0;
}