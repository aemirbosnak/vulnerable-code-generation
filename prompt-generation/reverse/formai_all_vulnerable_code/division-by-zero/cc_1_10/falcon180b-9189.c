//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_LENGTH 32
#define MAX_MESSAGE_LENGTH 1024

// Function to generate a random key of specified length
void generate_key(char* key, int length) {
    for (int i = 0; i < length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[length] = '\0';
}

// Function to encrypt a message using the specified key
void encrypt_message(char* message, char* key) {
    int message_length = strlen(message);
    int key_index = 0;
    for (int i = 0; i < message_length; i++) {
        message[i] = toupper(message[i]);
        if (isalpha(message[i])) {
            message[i] = 'a' + (message[i] - 'A' + key_index) % 26;
            key_index = (key_index + 1) % strlen(key);
        }
    }
}

// Function to decrypt a message using the specified key
void decrypt_message(char* message, char* key) {
    int message_length = strlen(message);
    int key_index = 0;
    for (int i = 0; i < message_length; i++) {
        message[i] = toupper(message[i]);
        if (isalpha(message[i])) {
            message[i] = 'a' + (message[i] - 'A' - key_index + 26) % 26;
            key_index = (key_index + 1) % strlen(key);
        }
    }
}

// Function to generate a random message of specified length
void generate_message(char* message, int length) {
    for (int i = 0; i < length; i++) {
        message[i] = rand() % 26 + 'a';
    }
    message[length] = '\0';
}

// Function to print a message
void print_message(char* message) {
    printf("%s\n", message);
}

int main() {
    srand(time(NULL));

    // Generate a key and a message
    char key[MAX_KEY_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    generate_key(key, strlen(key));
    generate_message(message, strlen(message));

    // Encrypt the message
    encrypt_message(message, key);
    printf("Encrypted message: ");
    print_message(message);

    // Decrypt the message
    decrypt_message(message, key);
    printf("Decrypted message: ");
    print_message(message);

    return 0;
}