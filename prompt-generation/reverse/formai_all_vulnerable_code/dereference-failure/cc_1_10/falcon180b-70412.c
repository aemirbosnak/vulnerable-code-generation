//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_LENGTH 16
#define BLOCK_LENGTH 8
#define ROUNDS 10

// Function prototypes
void generate_key(char* key);
void encrypt(char* message, char* key, char* encrypted_message);
void decrypt(char* encrypted_message, char* key, char* decrypted_message);

int main() {
    char message[1000];
    char encrypted_message[1000];
    char decrypted_message[1000];
    char key[KEY_LENGTH];

    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    generate_key(key);
    encrypt(message, key, encrypted_message);
    printf("Encrypted message: %s\n", encrypted_message);

    decrypt(encrypted_message, key, decrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}

// Generates a random key of length KEY_LENGTH
void generate_key(char* key) {
    srand(time(NULL));
    for (int i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[KEY_LENGTH] = '\0';
}

// Encrypts message using Caesar cipher with key and block length BLOCK_LENGTH
void encrypt(char* message, char* key, char* encrypted_message) {
    int message_length = strlen(message);
    int encrypted_message_length = message_length + 1;
    encrypted_message[encrypted_message_length - 1] = '\0';

    for (int i = 0; i < message_length; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            encrypted_message[i] = message[i] + key[i % KEY_LENGTH] - 'a' + 'A';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            encrypted_message[i] = message[i] + key[i % KEY_LENGTH] - 'A' + 'a';
        } else {
            encrypted_message[i] = message[i];
        }
    }
}

// Decrypts message using Caesar cipher with key and block length BLOCK_LENGTH
void decrypt(char* encrypted_message, char* key, char* decrypted_message) {
    int encrypted_message_length = strlen(encrypted_message);
    int decrypted_message_length = encrypted_message_length + 1;
    decrypted_message[decrypted_message_length - 1] = '\0';

    for (int i = 0; i < encrypted_message_length; i++) {
        if (encrypted_message[i] >= 'A' && encrypted_message[i] <= 'Z') {
            decrypted_message[i] = encrypted_message[i] - key[i % KEY_LENGTH] - 'A' + 'a';
        } else if (encrypted_message[i] >= 'a' && encrypted_message[i] <= 'z') {
            decrypted_message[i] = encrypted_message[i] - key[i % KEY_LENGTH] - 'a' + 'A';
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }
}