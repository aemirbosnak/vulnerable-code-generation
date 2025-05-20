//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define KEY_SIZE 10
#define MESSAGE_SIZE 20

// Define a struct to hold the message and key
typedef struct {
    char message[MESSAGE_SIZE];
    char key[KEY_SIZE];
} message_t;

// Function to encrypt the message
void encrypt(message_t *message) {
    // Generate a random key
    srand(time(NULL));
    for (int i = 0; i < KEY_SIZE; i++) {
        message->key[i] = (char)rand() % 26 + 'A';
    }

    // Encrypt the message
    for (int i = 0; i < MESSAGE_SIZE; i++) {
        message->message[i] = (char)((message->message[i] + message->key[i]) % 26 + 'A');
    }
}

// Function to decrypt the message
void decrypt(message_t *message) {
    // Generate a random key
    srand(time(NULL));
    for (int i = 0; i < KEY_SIZE; i++) {
        message->key[i] = (char)rand() % 26 + 'A';
    }

    // Decrypt the message
    for (int i = 0; i < MESSAGE_SIZE; i++) {
        message->message[i] = (char)((message->message[i] - message->key[i]) % 26 + 'A');
    }
}

int main() {
    message_t message;
    char encrypted_message[MESSAGE_SIZE];

    // Set the message and key
    strcpy(message.message, "Hello, world!");
    strcpy(message.key, "Greetings!");

    // Encrypt the message
    encrypt(&message);

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);

    // Decrypt the message
    decrypt(&message);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message.message);

    return 0;
}