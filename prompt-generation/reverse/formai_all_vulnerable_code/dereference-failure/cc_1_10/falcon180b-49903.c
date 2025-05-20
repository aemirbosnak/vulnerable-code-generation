//Falcon-180B DATASET v1.0 Category: Encryption ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KEY_LENGTH 16
#define BLOCK_SIZE 8

char* generate_key() {
    char* key = malloc(KEY_LENGTH + 1);
    srand(time(NULL));
    for (int i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[KEY_LENGTH] = '\0';
    return key;
}

void encrypt(char* message, char* key) {
    int message_length = strlen(message);
    int key_index = 0;
    char* encrypted_message = malloc(message_length + 1);
    for (int i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            encrypted_message[i] = ((message[i] - 'a' + key[key_index] - 'a') % 26) + 'a';
            key_index = (key_index + 1) % KEY_LENGTH;
        } else {
            encrypted_message[i] = message[i];
        }
    }
    encrypted_message[message_length] = '\0';
    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char* encrypted_message, char* key) {
    int encrypted_message_length = strlen(encrypted_message);
    int key_index = 0;
    char* decrypted_message = malloc(encrypted_message_length + 1);
    for (int i = 0; i < encrypted_message_length; i++) {
        if (isalpha(encrypted_message[i])) {
            decrypted_message[i] = ((encrypted_message[i] - 'a' + ('z' - key[key_index] + 26)) % 26) + 'a';
            key_index = (key_index + 1) % KEY_LENGTH;
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }
    decrypted_message[encrypted_message_length] = '\0';
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char* message = "This is a secret message!";
    char* key = generate_key();
    encrypt(message, key);
    decrypt(message, key);
    free(message);
    free(key);
    return 0;
}