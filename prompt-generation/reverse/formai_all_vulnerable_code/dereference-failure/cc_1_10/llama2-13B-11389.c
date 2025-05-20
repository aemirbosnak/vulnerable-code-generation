//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <time.h>

#define KEY_SIZE 16
#define MESSAGE_SIZE 32

// Define a struct to hold the message and key
typedef struct {
    char message[MESSAGE_SIZE];
    char key[KEY_SIZE];
} message_t;

// Function to encrypt the message
void encrypt(message_t *message) {
    // Generate a random key
    srandom(time(NULL));
    for (int i = 0; i < KEY_SIZE; i++) {
        message->key[i] = 'a' + (random() % 26);
    }

    // Encrypt the message
    for (int i = 0; i < MESSAGE_SIZE; i++) {
        char c = message->message[i];
        message->message[i] = (c + message->key[i]) % 26;
    }
}

// Function to decrypt the message
void decrypt(message_t *message) {
    // Generate a random key
    srandom(time(NULL));
    for (int i = 0; i < KEY_SIZE; i++) {
        message->key[i] = 'a' + (random() % 26);
    }

    // Decrypt the message
    for (int i = 0; i < MESSAGE_SIZE; i++) {
        char c = message->message[i];
        message->message[i] = (c - message->key[i]) % 26;
    }
}

int main() {
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