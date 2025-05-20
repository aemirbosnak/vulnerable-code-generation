//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100
#define KEY 42

void encrypt(char *message, int key) {
    int i, j;
    char encrypted[SIZE];

    for (i = 0, j = 0; message[i]!= '\0'; i++, j++) {
        if (j == SIZE) {
            j = 0;
        }
        encrypted[j] = message[i] ^ key;
    }
    encrypted[j] = '\0';

    printf("Encrypted message: %s\n", encrypted);
}

void decrypt(char *encrypted_message, int key) {
    int i, j;
    char decrypted[SIZE];

    for (i = 0, j = 0; encrypted_message[i]!= '\0'; i++, j++) {
        if (j == SIZE) {
            j = 0;
        }
        decrypted[j] = encrypted_message[i] ^ key;
    }
    decrypted[j] = '\0';

    printf("Decrypted message: %s\n", decrypted);
}

int main() {
    srand(time(0));
    char message[SIZE];
    char encrypted_message[SIZE];
    int key;

    // Generate random message
    for (int i = 0; i < SIZE; i++) {
        message[i] = rand() % 26 + 'a';
    }
    message[SIZE - 1] = '\0';

    printf("Original message: %s\n", message);

    // Encrypt message
    key = rand() % 26 + 1;
    encrypt(message, key);

    // Decrypt message
    key = rand() % 26 + 1;
    decrypt(encrypted_message, key);

    return 0;
}