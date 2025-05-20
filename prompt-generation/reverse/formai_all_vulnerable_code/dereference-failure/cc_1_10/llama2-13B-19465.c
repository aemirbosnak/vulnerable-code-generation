//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY_SIZE 16
#define MESSAGE_SIZE 256

typedef struct {
    char key[KEY_SIZE];
    char message[MESSAGE_SIZE];
} message_t;

void setup_key(message_t *msg);
void encrypt(message_t *msg);
void decrypt(message_t *msg);

int main() {
    message_t message;
    char encrypted_message[MESSAGE_SIZE];

    // Setup key
    setup_key(&message);

    // Encrypt message
    encrypt(&message);

    // Print encrypted message
    printf("Encrypted message: %s\n", encrypted_message);

    // Decrypt message
    decrypt(&message);

    // Print decrypted message
    printf("Decrypted message: %s\n", message.message);

    return 0;
}

void setup_key(message_t *msg) {
    // Generate random key
    for (int i = 0; i < KEY_SIZE; i++) {
        msg->key[i] = rand() % 256;
    }
}

void encrypt(message_t *msg) {
    // Loop through each character of the message
    for (int i = 0; i < MESSAGE_SIZE; i++) {
        // XOR each character of the message with the corresponding character of the key
        msg->message[i] = msg->message[i] ^ msg->key[i];
    }
}

void decrypt(message_t *msg) {
    // Loop through each character of the encrypted message
    for (int i = 0; i < MESSAGE_SIZE; i++) {
        // XOR each character of the encrypted message with the corresponding character of the key (in reverse order)
        msg->message[i] = msg->message[i] ^ msg->key[KEY_SIZE - 1 - i];
    }
}