//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000
#define PRIME_NUMBER 101

typedef struct {
    char *data;
    int size;
    int prime;
} Message;

void generate_prime(int *prime) {
    int i = 2;
    while (i <= MAX_SIZE) {
        if (isPrime(i)) {
            *prime = i;
            break;
        }
        i++;
    }
}

int isPrime(int n) {
    if (n <= 1)
        return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

void encrypt(Message *message, int prime) {
    int i;
    for (i = 0; i < message->size; i++) {
        message->data[i] = message->data[i] ^ prime;
    }
}

void decrypt(Message *message, int prime) {
    int i;
    for (i = 0; i < message->size; i++) {
        message->data[i] = message->data[i] ^ prime;
    }
}

int main() {
    Message message;
    int prime;
    generate_prime(&prime);
    message.data = (char *)malloc(MAX_SIZE * sizeof(char));
    message.size = 0;
    message.prime = prime;

    printf("Enter message: ");
    fgets(message.data, MAX_SIZE, stdin);
    message.size = strlen(message.data);

    encrypt(&message, prime);

    printf("Encrypted message: %s\n", message.data);

    decrypt(&message, prime);

    printf("Decrypted message: %s\n", message.data);

    free(message.data);
    return 0;
}