//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_SIZE 10
#define MESSAGE_SIZE 20

// Define a struct to hold the key and message
struct EncryptionData {
    char key[KEY_SIZE];
    char message[MESSAGE_SIZE];
};

// Function to encrypt the message
void encrypt(struct EncryptionData *data) {
    // Generate a random key if one is not provided
    if (data->key[0] == '\0') {
        for (int i = 0; i < KEY_SIZE; i++) {
            data->key[i] = 'a' + (rand() % 26);
        }
    }

    // Initialize the encrypted message
    data->message[0] = '\0';

    // Iterate through the message and encrypt each character
    for (int i = 0; i < MESSAGE_SIZE; i++) {
        // Calculate the index of the corresponding key character
        int key_index = (data->message[i] - 'a') % KEY_SIZE;

        // XOR the key character with the message character
        data->message[i] = data->key[key_index] ^ data->message[i];
    }
}

// Function to decrypt the message
void decrypt(struct EncryptionData *data) {
    // Initialize the decrypted message
    data->message[0] = '\0';

    // Iterate through the encrypted message and decrypt each character
    for (int i = 0; i < MESSAGE_SIZE; i++) {
        // Calculate the index of the corresponding key character
        int key_index = (data->message[i] - 'a') % KEY_SIZE;

        // XOR the key character with the message character
        data->message[i] = data->key[key_index] ^ data->message[i];
    }
}

int main() {
    // Create a struct to hold the key and message
    struct EncryptionData data;

    // Set the key and message
    data.key[0] = 'G';
    data.key[1] = 'R';
    data.key[2] = 'E';
    data.key[3] = 'E';
    data.message[0] = 'H';
    data.message[1] = 'E';
    data.message[2] = 'L';
    data.message[3] = 'L';
    data.message[4] = 'O';

    // Encrypt the message
    encrypt(&data);

    // Print the encrypted message
    printf("Encrypted message: %s\n", data.message);

    // Decrypt the message
    decrypt(&data);

    // Print the decrypted message
    printf("Decrypted message: %s\n", data.message);

    return 0;
}