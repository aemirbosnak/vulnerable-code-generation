//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEY_SIZE 32
#define MAX_MESSAGE_SIZE 1000

// Function to generate a random key
void generate_key(char* key, int key_size) {
    srand(time(NULL));
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_size] = '\0';
}

// Function to encrypt the message using the key
void encrypt(char* message, char* key, char* encrypted_message) {
    int message_len = strlen(message);
    int key_len = strlen(key);
    int encrypted_len = message_len + key_len;

    for (int i = 0; i < message_len; i++) {
        encrypted_message[i] = message[i] ^ key[i % key_len];
    }

    for (int i = message_len; i < encrypted_len; i++) {
        encrypted_message[i] = key[i - message_len % key_len];
    }

    encrypted_message[encrypted_len - 1] = '\0';
}

// Function to decrypt the message using the key
void decrypt(char* encrypted_message, char* key, char* decrypted_message) {
    int encrypted_len = strlen(encrypted_message);
    int key_len = strlen(key);
    int decrypted_len = encrypted_len - key_len;

    for (int i = 0; i < encrypted_len; i++) {
        decrypted_message[i] = encrypted_message[i] ^ key[i % key_len];
    }

    decrypted_message[decrypted_len] = '\0';
}

int main() {
    char key[MAX_KEY_SIZE];
    char message[MAX_MESSAGE_SIZE];
    char encrypted_message[MAX_MESSAGE_SIZE];
    char decrypted_message[MAX_MESSAGE_SIZE];

    // Generate a random key
    generate_key(key, rand() % MAX_KEY_SIZE + 1);

    // Get the message from the user
    printf("Enter the message: ");
    fgets(message, MAX_MESSAGE_SIZE, stdin);

    // Encrypt the message using the key
    encrypt(message, key, encrypted_message);

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);

    // Decrypt the message using the key
    decrypt(encrypted_message, key, decrypted_message);

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}