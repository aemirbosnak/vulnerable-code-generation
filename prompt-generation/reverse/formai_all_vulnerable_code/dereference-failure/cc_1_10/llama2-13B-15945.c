//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: random
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define KEY_LENGTH 16
#define MAX_MESSAGE_LENGTH 100

// Define a struct to hold the message and its encryption
struct message {
    char *text;
    char key[KEY_LENGTH];
};

// Function to generate a random key
void generate_key(struct message *msg) {
    int i;
    for (i = 0; i < KEY_LENGTH; i++) {
        msg->key[i] = (char)rand() % 26 + 'A';
    }
}

// Function to encrypt the message
void encrypt(struct message *msg) {
    int i, j;
    char c, d, temp;

    // Iterate through the message and replace each character with its
    // corresponding cipher character based on the key
    for (i = 0; i < strlen(msg->text); i++) {
        c = msg->text[i];
        for (j = 0; j < KEY_LENGTH; j++) {
            d = msg->key[j];
            if (c == d) {
                temp = c;
                c = msg->key[j + i % KEY_LENGTH];
                msg->text[i] = temp;
                break;
            }
        }
    }
}

// Function to decrypt the message
void decrypt(struct message *msg) {
    int i, j;
    char c, d, temp;

    // Iterate through the message and replace each character with its
    // corresponding original character based on the key
    for (i = 0; i < strlen(msg->text); i++) {
        c = msg->text[i];
        for (j = 0; j < KEY_LENGTH; j++) {
            d = msg->key[j];
            if (c == d) {
                temp = c;
                c = msg->key[j + i % KEY_LENGTH];
                msg->text[i] = temp;
                break;
            }
        }
    }
}

int main() {
    struct message msg;

    // Generate a random key
    generate_key(&msg);

    // Encrypt the message
    encrypt(&msg);

    // Print the encrypted message
    printf("Encrypted message: %s\n", msg.text);

    // Decrypt the message
    decrypt(&msg);

    // Print the decrypted message
    printf("Decrypted message: %s\n", msg.text);

    return 0;
}