//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define KEY_SIZE 16
#define MESSAGE_SIZE 256

// Structure to hold the message and key
typedef struct {
    char message[MESSAGE_SIZE];
    char key[KEY_SIZE];
} message_t;

// Function to encrypt the message
void encrypt(message_t *message) {
    int i, j, k;
    char temp;

    // Initialize the cipher
    for (i = 0; i < MESSAGE_SIZE; i++) {
        message->message[i] = (i % 2 == 0) ? message->message[i] + (message->key[i % KEY_SIZE] - 'A') : message->message[i] + (message->key[i % KEY_SIZE] - 'a');
    }

    // Shuffle the message
    for (i = 0; i < MESSAGE_SIZE; i++) {
        j = rand() % MESSAGE_SIZE;
        temp = message->message[i];
        message->message[i] = message->message[j];
        message->message[j] = temp;
    }

    // Encrypt the message
    for (i = 0; i < MESSAGE_SIZE; i++) {
        k = message->key[i % KEY_SIZE];
        message->message[i] = (k == 'A' || k == 'a') ? (message->message[i] - 'A' + 'Z') : (message->message[i] - 'a' + 'z');
    }
}

// Function to decrypt the message
void decrypt(message_t *message) {
    int i, j, k;
    char temp;

    // Initialize the cipher
    for (i = 0; i < MESSAGE_SIZE; i++) {
        message->message[i] = (i % 2 == 0) ? message->message[i] - (message->key[i % KEY_SIZE] - 'A') : message->message[i] - (message->key[i % KEY_SIZE] - 'a');
    }

    // Shuffle the message
    for (i = 0; i < MESSAGE_SIZE; i++) {
        j = rand() % MESSAGE_SIZE;
        temp = message->message[i];
        message->message[i] = message->message[j];
        message->message[j] = temp;
    }

    // Decrypt the message
    for (i = 0; i < MESSAGE_SIZE; i++) {
        k = message->key[i % KEY_SIZE];
        message->message[i] = (k == 'Z' || k == 'z') ? (message->message[i] - 'Z' + 'A') : (message->message[i] - 'z' + 'a');
    }
}

int main() {
    message_t message;

    // Set the message and key
    strcpy(message.message, "Hello, World!");
    strcpy(message.key, "This is a secret key!");

    // Encrypt the message
    encrypt(&message);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message.message);

    // Decrypt the message
    decrypt(&message);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message.message);

    return 0;
}