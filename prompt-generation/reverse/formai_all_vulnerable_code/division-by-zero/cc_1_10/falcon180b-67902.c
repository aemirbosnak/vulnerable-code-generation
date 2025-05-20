//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000
#define MAX_CIPHER_LENGTH (MAX_MESSAGE_LENGTH + 1)

// Function to generate a random key of length keylen
void generate_key(char *key, int keylen) {
    for (int i = 0; i < keylen; i++) {
        key[i] = rand() % 26 + 'A';
    }
    key[keylen] = '\0';
}

// Function to encrypt a message using the Caesar cipher
void encrypt(char *message, int message_length, char *key, char *cipher) {
    for (int i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            cipher[i] = 'A' + ((message[i] - 'A' + key[i % strlen(key)]) % 26);
        } else {
            cipher[i] = message[i];
        }
    }
    cipher[message_length] = '\0';
}

// Function to decrypt a message using the Caesar cipher
void decrypt(char *cipher, int cipher_length, char *key, char *message) {
    for (int i = 0; i < cipher_length; i++) {
        if (isalpha(cipher[i])) {
            message[i] = 'A' + ((cipher[i] - 'A' - key[i % strlen(key)]) % 26 + 26) % 26;
        } else {
            message[i] = cipher[i];
        }
    }
    message[cipher_length] = '\0';
}

int main() {
    srand(time(NULL));

    char key[MAX_KEY_LENGTH];
    generate_key(key, strlen(key));

    char message[MAX_MESSAGE_LENGTH];
    printf("Enter a message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    message[strcspn(message, "\n")] = '\0';

    char cipher[MAX_CIPHER_LENGTH];
    encrypt(message, strlen(message), key, cipher);

    printf("Encrypted message: %s\n", cipher);

    char decrypted_message[MAX_MESSAGE_LENGTH];
    decrypt(cipher, strlen(cipher), key, decrypted_message);

    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}