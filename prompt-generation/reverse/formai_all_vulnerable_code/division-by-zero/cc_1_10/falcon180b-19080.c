//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000
#define ALPHABET_LENGTH 26

// Function to encrypt message using Caesar cipher
void encrypt(char message[], char key[], char encrypted_message[]) {
    int i, j, shift;
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            shift = (int) key[i % strlen(key)] - 65;
            encrypted_message[i] = (char) (((int) message[i] - 65 + shift) % 26 + 65);
        } else {
            encrypted_message[i] = message[i];
        }
    }
    encrypted_message[i] = '\0';
}

// Function to decrypt message using Caesar cipher
void decrypt(char encrypted_message[], char key[], char decrypted_message[]) {
    int i, j, shift;
    for (i = 0; encrypted_message[i]!= '\0'; i++) {
        if (isalpha(encrypted_message[i])) {
            shift = (int) key[i % strlen(key)] - 65;
            decrypted_message[i] = (char) (((int) encrypted_message[i] - 65 - shift + 26) % 26 + 65);
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }
    decrypted_message[i] = '\0';
}

// Function to generate a random key
void generate_key(char key[]) {
    srand(time(NULL));
    int i;
    for (i = 0; i < strlen(key); i++) {
        key[i] = (char) (rand() % 26 + 65);
    }
    key[strlen(key)] = '\0';
}

int main() {
    char message[MAX_MESSAGE_LENGTH], key[MAX_KEY_LENGTH], encrypted_message[MAX_MESSAGE_LENGTH], decrypted_message[MAX_MESSAGE_LENGTH];
    int message_length, key_length;

    // Get message from user
    printf("Enter message to encrypt/decrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    message_length = strlen(message);

    // Get key from user
    printf("Enter key for encryption/decryption: ");
    fgets(key, MAX_KEY_LENGTH, stdin);
    key_length = strlen(key);

    // Encrypt message
    encrypt(message, key, encrypted_message);
    printf("Encrypted message: %s\n", encrypted_message);

    // Decrypt message
    decrypt(encrypted_message, key, decrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}