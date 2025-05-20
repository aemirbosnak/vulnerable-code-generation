//Falcon-180B DATASET v1.0 Category: Encryption ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 16
#define KEY_SIZE 16

void encrypt(char *message, char *key, char *ciphertext) {
    int message_length = strlen(message);
    int key_index = 0;
    int i, j;

    for (i = 0; i < message_length; i += BLOCK_SIZE) {
        for (j = 0; j < BLOCK_SIZE && i + j < message_length; j++) {
            ciphertext[i + j] = message[i + j] ^ key[key_index % KEY_SIZE];
            key_index++;
        }
    }
}

void decrypt(char *ciphertext, char *key, char *message) {
    int ciphertext_length = strlen(ciphertext);
    int key_index = 0;
    int i, j;

    for (i = 0; i < ciphertext_length; i += BLOCK_SIZE) {
        for (j = 0; j < BLOCK_SIZE && i + j < ciphertext_length; j++) {
            message[i + j] = ciphertext[i + j] ^ key[key_index % KEY_SIZE];
            key_index++;
        }
    }
}

int main() {
    char message[] = "This is a secret message.";
    char key[] = "Secret key 12345678";
    char ciphertext[strlen(message)];

    encrypt(message, key, ciphertext);

    printf("Encrypted message: %s\n", ciphertext);

    char decrypted_message[strlen(message)];

    decrypt(ciphertext, key, decrypted_message);

    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}