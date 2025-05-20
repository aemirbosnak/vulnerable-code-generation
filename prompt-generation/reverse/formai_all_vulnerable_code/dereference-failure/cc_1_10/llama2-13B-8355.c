//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define KEY_LENGTH 16
#define MESSAGE_LENGTH 32

// Define a struct to hold the message and the key
typedef struct {
    char message[MESSAGE_LENGTH];
    char key[KEY_LENGTH];
} message_t;

// Function to encrypt the message
void encrypt(message_t *message) {
    // Generate a random key if one is not provided
    if (message->key[0] == '\0') {
        srand(time(NULL));
        for (int i = 0; i < KEY_LENGTH; i++) {
            message->key[i] = (char)rand() % 26 + 'A';
        }
    }

    // Encrypt the message
    for (int i = 0; i < MESSAGE_LENGTH; i++) {
        message->message[i] = (char)((message->message[i] + message->key[i]) % 26 + 'A');
    }
}

// Function to decrypt the message
void decrypt(message_t *message) {
    // Encrypt the message
    for (int i = 0; i < MESSAGE_LENGTH; i++) {
        message->message[i] = (char)((message->message[i] - message->key[i]) % 26 + 'A');
    }
}

int main() {
    // Create a message struct
    message_t message = {"Hello, World!"};

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