//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MESSAGE_LENGTH 100
#define MAX_KEY_LENGTH 20

// Function to generate a random key
void generate_key(char *key) {
    int i;
    for (i = 0; i < MAX_KEY_LENGTH; i++) {
        key[i] = 'a' + (rand() % 26);
    }
}

// Function to encrypt the message
void encrypt(char *message, char *key) {
    int i, j, k;
    for (i = 0; i < strlen(message); i++) {
        // Shift the message by the corresponding position in the key
        j = (int) (message[i] - 'a');
        k = (int) (key[j] - 'a');
        message[i] = (char) (k + 'a');
    }
}

// Function to decrypt the message
void decrypt(char *message, char *key) {
    int i, j, k;
    for (i = 0; i < strlen(message); i++) {
        // Shift the message by the corresponding position in the key
        j = (int) (message[i] - 'a');
        k = (int) (key[j] - 'a');
        message[i] = (char) (k - 'a');
    }
}

int main() {
    char message[] = "This is a secret message";
    char key[] = "The quick brown fox jumps over the lazy dog";

    // Generate a random key
    generate_key(key);

    // Encrypt the message
    encrypt(message, key);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt(message, key);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}