//Falcon-180B DATASET v1.0 Category: Encryption ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEY_SIZE 50
#define MAX_MESSAGE_SIZE 1000

void generate_key(char *key, int key_size) {
    srand(time(NULL));
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_size] = '\0';
}

void encrypt(char *message, char *key, char *encrypted_message) {
    for (int i = 0; i < strlen(message); i++) {
        encrypted_message[i] = message[i] + (key[i % strlen(key)] - 'a');
    }
    encrypted_message[strlen(message)] = '\0';
}

void decrypt(char *encrypted_message, char *key, char *decrypted_message) {
    for (int i = 0; i < strlen(encrypted_message); i++) {
        decrypted_message[i] = encrypted_message[i] - (key[i % strlen(key)] - 'a');
    }
    decrypted_message[strlen(encrypted_message)] = '\0';
}

int main() {
    char key[MAX_KEY_SIZE];
    char message[MAX_MESSAGE_SIZE];
    char encrypted_message[MAX_MESSAGE_SIZE];
    char decrypted_message[MAX_MESSAGE_SIZE];

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_MESSAGE_SIZE, stdin);

    printf("Enter a key (must be a string of lowercase letters): ");
    fgets(key, MAX_KEY_SIZE, stdin);

    generate_key(key, strlen(key));
    encrypt(message, key, encrypted_message);

    printf("Encrypted message: %s\n", encrypted_message);

    decrypt(encrypted_message, key, decrypted_message);

    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}