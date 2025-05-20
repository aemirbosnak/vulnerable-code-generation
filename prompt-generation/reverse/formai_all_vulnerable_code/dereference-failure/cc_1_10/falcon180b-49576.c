//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int *public_key;
    int *private_key;
} KeyPair;

KeyPair generate_keys() {
    KeyPair keys;
    int *public_key = (int *)malloc(sizeof(int) * MAX_SIZE);
    int *private_key = (int *)malloc(sizeof(int) * MAX_SIZE);

    for (int i = 0; i < MAX_SIZE; i++) {
        public_key[i] = rand() % 1000;
        private_key[i] = rand() % 1000;
    }

    keys.public_key = public_key;
    keys.private_key = private_key;

    return keys;
}

void encrypt(int *message, int *public_key, int *encrypted_message, int message_size) {
    for (int i = 0; i < message_size; i++) {
        encrypted_message[i] = message[i] ^ public_key[i];
    }
}

void decrypt(int *encrypted_message, int *private_key, int *decrypted_message, int message_size) {
    for (int i = 0; i < message_size; i++) {
        decrypted_message[i] = encrypted_message[i] ^ private_key[i];
    }
}

int main() {
    KeyPair keys = generate_keys();
    int message[MAX_SIZE];
    int encrypted_message[MAX_SIZE];
    int decrypted_message[MAX_SIZE];

    printf("Enter message to encrypt: ");
    for (int i = 0; i < MAX_SIZE; i++) {
        scanf("%d", &message[i]);
    }

    encrypt(message, keys.public_key, encrypted_message, MAX_SIZE);

    printf("Encrypted message: ");
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d ", encrypted_message[i]);
    }

    decrypt(encrypted_message, keys.private_key, decrypted_message, MAX_SIZE);

    printf("\nDecrypted message: ");
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d ", decrypted_message[i]);
    }

    free(keys.public_key);
    free(keys.private_key);
    free(encrypted_message);
    free(decrypted_message);

    return 0;
}