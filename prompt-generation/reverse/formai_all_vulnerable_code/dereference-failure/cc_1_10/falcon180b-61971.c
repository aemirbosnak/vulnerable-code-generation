//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KEY_LENGTH 16
#define BLOCK_SIZE 64

void encrypt(char* message, char* key) {
    int i, j;
    char output[100];
    int message_length = strlen(message);
    int key_index = 0;
    for (i = 0; i < message_length; i++) {
        output[i] = message[i] ^ key[key_index];
        key_index = (key_index + 1) % KEY_LENGTH;
    }
    output[message_length] = '\0';
    printf("Encrypted message: %s\n", output);
}

void decrypt(char* encrypted_message, char* key) {
    int i, j;
    char output[100];
    int encrypted_message_length = strlen(encrypted_message);
    int key_index = 0;
    for (i = 0; i < encrypted_message_length; i++) {
        output[i] = encrypted_message[i] ^ key[key_index];
        key_index = (key_index + 1) % KEY_LENGTH;
    }
    output[encrypted_message_length] = '\0';
    printf("Decrypted message: %s\n", output);
}

char* generate_key() {
    char* key = malloc(KEY_LENGTH * sizeof(char));
    int i;
    srand(time(NULL));
    for (i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'a';
    }
    return key;
}

int main() {
    char* message = "Hello, world! ";
    char* key = generate_key();
    encrypt(message, key);
    decrypt(message, key);
    free(key);
    return 0;
}