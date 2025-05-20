//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEY_SIZE 16

void generate_key(char key[MAX_KEY_SIZE]) {
    int i;
    for (i = 0; i < MAX_KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'A';
    }
}

void encrypt(char message[MAX_KEY_SIZE], char key[MAX_KEY_SIZE]) {
    int i;
    for (i = 0; i < strlen(message); i++) {
        message[i] = (message[i] + key[i % MAX_KEY_SIZE]) % 26 + 'A';
    }
}

void decrypt(char ciphertext[MAX_KEY_SIZE], char key[MAX_KEY_SIZE]) {
    int i;
    for (i = 0; i < strlen(ciphertext); i++) {
        ciphertext[i] = (ciphertext[i] - key[i % MAX_KEY_SIZE] + 26) % 26 + 'A';
    }
}

int main() {
    char message[MAX_KEY_SIZE];
    char key[MAX_KEY_SIZE];
    char ciphertext[MAX_KEY_SIZE];
    int i;

    // Generate key
    srand(time(NULL));
    generate_key(key);

    // Encrypt message
    printf("Enter message to encrypt: ");
    scanf("%s", message);
    encrypt(message, key);

    // Print encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt message
    decrypt(message, key);

    // Print decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}