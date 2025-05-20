//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 10

typedef struct {
    int *numbers;
    int size;
} NumberArray;

void generateRandomNumbers(NumberArray *array) {
    srand(time(NULL));
    array->numbers = (int *)malloc(MAX_NUMBERS * sizeof(int));
    array->size = 0;

    for (int i = 0; i < MAX_NUMBERS && array->size < 2; i++) {
        int number = rand() % 100;
        if (number!= 0 && number!= 1) {
            array->numbers[array->size] = number;
            array->size++;
        }
    }
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void generatePublicPrivateKeys(int publicKey[], int privateKey[], int prime) {
    int e = 2;

    while (gcd(e, prime - 1)!= 1) {
        e++;
    }

    publicKey[0] = e;
    privateKey[0] = prime - 1;
    privateKey[1] = e - 1;
}

int encrypt(int message, int publicKey[], int prime) {
    return (int)pow(message, publicKey[0]) % prime;
}

int decrypt(int encryptedMessage, int privateKey[], int prime) {
    return (int)pow(encryptedMessage, privateKey[1]) % prime;
}

int main() {
    NumberArray numbers;
    generateRandomNumbers(&numbers);

    int prime = numbers.numbers[0];
    int publicKey[2];
    int privateKey[2];

    generatePublicPrivateKeys(publicKey, privateKey, prime);

    int encryptedMessage = encrypt(numbers.numbers[1], publicKey, prime);
    int decryptedMessage = decrypt(encryptedMessage, privateKey, prime);

    printf("Prime number: %d\n", prime);
    printf("Public key: (%d, %d)\n", publicKey[0], publicKey[1]);
    printf("Private key: (%d, %d)\n", privateKey[0], privateKey[1]);
    printf("Encrypted message: %d\n", encryptedMessage);
    printf("Decrypted message: %d\n", decryptedMessage);

    free(numbers.numbers);
    return 0;
}